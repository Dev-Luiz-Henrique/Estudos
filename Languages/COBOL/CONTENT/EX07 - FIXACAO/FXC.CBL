       IDENTIFICATION DIVISION.
       PROGRAM-ID.             FXC.
       AUTHOR.                 LUIZ HENRIQUE DE SANTANA.
       INSTALLATION.           FATEC-SP.
       DATE-WRITTEN.           23/10/2023.
       DATE-COMPILED.
       SECURITY.               APENAS O AUTOR PODE MODIFICAR.
      *REMARKS
       
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
           OBJECT-COMPUTER.    LG-PC.
           SOURCE-COMPUTER.    LG-PC.
           SPECIAL-NAMES.      DECIMAL-POINT IS COMMA.

       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
           SELECT CADENT ASSIGN TO DISK ORGANIZATION IS LINE
               SEQUENTIAL.
           SELECT RELSAI ASSIGN TO DISK.

       DATA DIVISION.
       FILE SECTION.
       
       FD CADENT LABEL RECORD ARE STANDARD 
           VALUE OF FILE-ID IS "CADENT.DAT".
       
           01 REG-ENT.
             02 CPF-ENT           PIC 9(11).
             02 RED-CPF-ENT REDEFINES CPF-ENT.
               03 NUM-CPF         PIC 9(09).
               03 DIGITOS-CPF     PIC 9(02).
             02 NOME-CLIE-ENT     PIC X(30).
             02 ESTADO-ENT        PIC X(02).
             02 CIDADE-ENT        PIC X(30).
             02 TELL-ENT          PIC 9(08).
             02 DT-VISIT-ENT      PIC 9(08).
             02 RED-DT-VISOT-ENT REDEFINES DT-VISIT-ENT.
               03 DD-ENT          PIC 9(02).
               03 MM-ENT          PIC 9(02).
               03 AAAA-ENT        PIC 9(04).
           
       FD RELSAI LABEL RECORD IS OMITTED.
           01 REL-SAI PIC X(80).

       WORKING-STORAGE SECTION.
           77 FIM-ARQ             PIC X(03) VALUE "NAO".
           77 CT-LIN              PIC 9(02) VALUE 41.
           77 CT-PAG              PIC 9(02) VALUE ZEROS.
           77 CT-CLIE             PIC 9(05) VALUE ZEROS.

           01 CAB-01.
             02 FILLER PIC X(70) VALUE SPACES.
             02 FILLER PIC X(05) VALUE "PAG. ".
             02 VAR-PAG PIC 999.
             02 FILLER PIC X(02) VALUE SPACES.

           01 CAB-02.
             02 FILLER PIC X(32) VALUE SPACES.
             02 FILLER PIC X(17) VALUE "TURISMAR TURISMOS".
             02 FILLER PIC X(33) VALUE SPACES.

           01 CAB-03.
             02 FILLER PIC X(22) VALUE SPACES.
             02 FILLER PIC X(24) VALUE "CLIENTES NO PERIODO DE: ".
             02 FILLER PIC X(11) VALUE "2010 A 2011".
             02 FILLER PIC X(23) VALUE SPACES.

           01 CAB-04.
             02 FILLER PIC X(17) VALUE SPACES.
             02 FILLER PIC X(04) VALUE "NOME".
             02 FILLER PIC X(22) VALUE SPACES.
             02 FILLER PIC X(03) VALUE "CPF".
             02 FILLER PIC X(09) VALUE SPACES.
             02 FILLER PIC X(21) VALUE "DATA DA ULTIMA VISITA".
             02 FILLER PIC X(04) VALUE SPACES.

           01 CAB-05.
             02 FILLER PIC X(58) VALUE SPACES.
             02 FILLER PIC X(15) VALUE "DIA / MES / ANO".
             02 FILLER PIC X(07) VALUE SPACES.

           01 DETALHE.
             02 FILLER PIC X(04) VALUE SPACES.
             02 DET-NOME PIC X(30).
             02 FILLER PIC X(04) VALUE SPACES.
             02 DET-CPF-NUM PIC 999.999.999.
             02 FILLER PIC X VALUE "/".
             02 DET-CPF-DIGITOS PIC 99.
             02 FILLER PIC X(04) VALUE SPACES.
             02 DET-DATA.
               03 DET-DD PIC 99.
               03 FILLER PIC XXX VALUE " / ".
               03 DET-MM PIC X(09).
               03 FILLER PIC XXX VALUE " / ".
               03 DET-AAAA PIC 9999.
             02 FILLER PIC X(03) VALUE SPACES.

           01 ROD-01.
             02 FILLER PIC X(04) VALUE SPACES.
             02 FILLER PIC X(19) VALUE "TOTAL DE CLIENTES: ".
             02 VAR-CLIE PIC 9999.
             02 FILLER PIC X(53) VALUE SPACES.

           01 TABELA-MESES.
             02 DEF-MESES.
               03 FILLER PIC X(09) VALUE "  JANEIRO".
               03 FILLER PIC X(09) VALUE "FEVEREIRO".
               03 FILLER PIC X(09) VALUE "    MARCO".
               03 FILLER PIC X(09) VALUE "    ABRIL".
               03 FILLER PIC X(09) VALUE "     MAIO".
               03 FILLER PIC X(09) VALUE "    JUNHO".
               03 FILLER PIC X(09) VALUE "    JULHO".
               03 FILLER PIC X(09) VALUE "   AGOSTO".
               03 FILLER PIC X(09) VALUE " SETEMBRO".
               03 FILLER PIC X(09) VALUE "  OUTUBRO".
               03 FILLER PIC X(09) VALUE " NOVEMBRO".
               03 FILLER PIC X(09) VALUE " DEZEMBRO".
               
           01 RED-TABELA-MESES REDEFINES TABELA-MESES.
             02 MESES PIC X(09) OCCURS 12 TIMES.

       PROCEDURE DIVISION.
       PGM-FIXAR.
           PERFORM INICIO.
           PERFORM PRINCIPAL UNTIL FIM-ARQ EQUAL "SIM".
           PERFORM TERMINO.
           STOP RUN.

       INICIO.
           OPEN INPUT CADENT OUTPUT RELSAI.
           PERFORM LEITURA.

       LEITURA.
           READ CADENT AT END MOVE "SIM" TO FIM-ARQ.
       
       PRINCIPAL.
           PERFORM IMPRESSAO.
           PERFORM LEITURA.

       IMPRESSAO.
           IF CT-LIN GREATER THAN 40
               PERFORM CABECALHO.
           PERFORM IMP-DET.

       CABECALHO.
           MOVE 1 TO CT-LIN.
           ADD 1 TO CT-PAG.
           MOVE CT-PAG TO VAR-PAG.
           MOVE SPACES TO REL-SAI.
           WRITE REL-SAI AFTER ADVANCING PAGE.
           WRITE REL-SAI FROM CAB-01 AFTER ADVANCING 1 LINE.
           WRITE REL-SAI FROM CAB-02 AFTER ADVANCING 2 LINES.
           WRITE REL-SAI FROM CAB-03 AFTER ADVANCING 2 LINES.
           WRITE REL-SAI FROM CAB-04 AFTER ADVANCING 1 LINE.
           WRITE REL-SAI FROM CAB-05 AFTER ADVANCING 1 LINE.
           MOVE ALL "-" TO REL-SAI.
           WRITE REL-SAI.
           MOVE SPACES TO REL-SAI.
           WRITE REL-SAI.

       IMP-DET.
           MOVE NOME-CLIE-ENT TO DET-NOME.
           MOVE NUM-CPF TO DET-CPF-NUM.
           MOVE DIGITOS-CPF TO DET-CPF-DIGITOS.
           MOVE DD-ENT TO DET-DD.
           MOVE MESES(MM-ENT) TO DET-MM.
           MOVE AAAA-ENT TO DET-AAAA.
           WRITE REL-SAI FROM DETALHE AFTER ADVANCING 1 LINE.   
           ADD 1 TO CT-LIN.
           ADD 1 TO CT-CLIE.
           
       RODAPE.
           MOVE CT-CLIE TO VAR-CLIE.
           WRITE REL-SAI FROM ROD-01 AFTER ADVANCING 3 LINE.

       TERMINO.
           PERFORM RODAPE.
           CLOSE CADENT RELSAI.