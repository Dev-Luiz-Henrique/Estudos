       IDENTIFICATION DIVISION.
       PROGRAM-ID.     EX07.
       AUTHOR.         LUIZ HENRIQUE DE SANTANA 
                       GABRIEL GOMES DA CRUZ
                       NICOLE CARVALHO FUKUSHIMA.
       INSTALLATION.   FATEC-SP.
       DATE-WRITTEN.   13/11/2023.
       DATE-COMPILED.
       SECURITY.       APENAS O AUTOR PODE MODIFICA-LO.
      *REMARKS         LER O ARQUIVO DE ENTRADA CADALU E GERAR O
      *                RELATORIO DE SAIDA RELALU, ORDENANDO-O POR
      *                CODIGO E TURMA EM ORDEM ASCENDENTE, ALEM DE
      *                CALCULAR A MEDIA DOS ALUNOS E EXIBIR OS
      *                APROVADOS E REPROVADOS.


      *================================================================* 


       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       SOURCE-COMPUTER.    IBM-PC.
       OBJECT-COMPUTER.    IBM-PC.
       SPECIAL-NAMES.      DECIMAL-POINT IS COMMA.

       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
       SELECT CADALU ASSIGN TO DISK ORGANIZATION IS LINE SEQUENTIAL.
       SELECT TRAB ASSIGN TO DISK.
       SELECT RELALU ASSIGN TO DISK.


      *================================================================*


       DATA DIVISION.
       FILE SECTION.
       FD CADALU LABEL RECORD ARE STANDARD
           VALUE OF FILE-ID IS "CADALU.DAT".
       01 REG-ENT.
           02 TURMA-ENT        PIC 9(03).
           02 COD-ENT          PIC 9(07).
           02 NOME-ENT         PIC X(30).
           02 NOTA1-ENT        PIC 99V99.
           02 NOTA2-ENT        PIC 99V99.
           02 NOTA3-ENT        PIC 99V99.
           02 NOTA4-ENT        PIC 99V99.


      *================================================================*


       SD TRAB.
       01 REG-TRAB.
           02 TURMA-TRAB       PIC 9(03).
           02 COD-TRAB         PIC 9(07).
           02 COD-TRAB-RED REDEFINES COD-TRAB.
             03 COD1-TRAB      PIC 9(03).
             03 COD2-TRAB      PIC 9(03).
             03 COD3-TRAB      PIC 9.
           02 NOME-TRAB        PIC X(30).
           02 NOTA1-TRAB        PIC 99V99.
           02 NOTA2-TRAB        PIC 99V99.
           02 NOTA3-TRAB        PIC 99V99.
           02 NOTA4-TRAB        PIC 99V99.       

       FD RELALU LABEL RECORD IS OMITTED.
       01 REG-ATR.
           02 REL-ATR          PIC X(80).

       WORKING-STORAGE SECTION.
       77 PERMIT-ROD-TURMA     PIC 9 VALUE ZEROS.
       77 FIM-ARQ              PIC X(03) VALUE "NAO".
       77 CT-LIN               PIC 99 VALUE 0.
       77 CT-PAG               PIC 99 VALUE ZEROS.

       77 CT-SOMA              PIC 99V99 VALUE ZEROS.
       77 CT-MEDIA             PIC 99V999 VALUE ZEROS.
       77 CT-REPROVADOS        PIC 99V99 VALUE ZEROS.
       77 CT-APROVADOS         PIC 99V99 VALUE ZEROS.
       77 WTURMA               PIC 999.
       77 SOMA-GERAL           PIC 9(03)V99.
       77 WMEDIA-GERAL         PIC 9(02)V99.
       77 WALUNOS-TURMA        PIC 9(03).
      

      *================================================================*


       01 CAB-TITULO.
           02 FILLER           PIC X(30) VALUE SPACES.
           02 FILLER           PIC X(19) VALUE "RELAÇÃO DE ALUNOS".
           02 FILLER           PIC X(23) VALUE SPACES.
           02 FILLER           PIC X(05) VALUE "PAG. ".
           02 VAR-PAG          PIC 9(03).


      *================================================================*


       01 CAB-TURMA.
           02 FILLER           PIC X(07) VALUE "TURMA: ".
           02 VAR-TURMA        PIC 9(03).
           02 FILLER           PIC X(70) VALUE SPACES.


      *================================================================*


       01 CAB-DADOS.
           02 FILLER           PIC X(03) VALUE SPACES.
           02 FILLER           PIC X(06) VALUE "CODIGO".
           02 FILLER           PIC X(28) VALUE SPACES.
           02 FILLER           PIC X(04) VALUE "NOME".
           02 FILLER           PIC X(32) VALUE SPACES.
           02 FILLER           PIC X(06) VALUE "MEDIA ".


      *================================================================*


       01 DETALHE.
           02 FILLER           PIC X(01) VALUE SPACES.
           02 VAR-COD1         PIC 9(03).
           02 FILLER           PIC X(01) VALUE ".".
           02 VAR-COD2         PIC 9(03).
           02 FILLER           PIC X(01) VALUE "-".
           02 VAR-COD3         PIC 9.
           02 FILLER           PIC X(13) VALUE SPACES.
           02 VAR-NOME         PIC X(30).
           02 FILLER           PIC X(20) VALUE SPACES.
           02 VAR-MEDIA        PIC Z9,99 VALUE ZEROES.
           02 FILLER           PIC X(01) VALUE SPACES.


      *================================================================*


       01 RODAPE-APROVADOS.
           02 FILLER           PIC X(47) VALUE SPACES.
           02 FILLER           PIC X(27) 
              VALUE "TOTAL DE ALUNOS APROVADOS  ".
           02 VAR-APROVADOS    PIC 9(4).
           02 FILLER           PIC X(01) VALUE SPACES.


      *================================================================*


       01 RODAPE-REPROVADOS.
           02 FILLER           PIC X(46) VALUE SPACES.
           02 FILLER           PIC X(28) 
             VALUE "TOTAL DE ALUNOS REPROVADOS  ".
           02 VAR-REPROVADOS   PIC 9(04).
           02 FILLER           PIC X(01) VALUE SPACES.


      *================================================================*

       
       01 RODAPE-MEDIA.
           02 FILLER           PIC X(61) VALUE SPACES.
           02 FILLER           PIC X(12) VALUE "MEDIA GERAL ".
           02 VAR-MEDIA-GERAL  PIC Z9,99.
           02 FILLER           PIC X(01) VALUE SPACES.


      *================================================================*


       PROCEDURE DIVISION.
       PGM-EX07.
       SORT TRAB
           ASCENDING KEY TURMA-TRAB, COD-TRAB
           USING CADALU
           OUTPUT PROCEDURE ROT-SAI.
       STOP RUN.

      
      *================================================================*

       ROT-SAI SECTION.
           PERFORM INICIO.
           PERFORM PRINCIPAL UNTIL FIM-ARQ EQUAL "SIM".
           PERFORM FIM.


      *================================================================* 


       INICIO SECTION.
           OPEN OUTPUT RELALU
           PERFORM LEITURA.


      *================================================================* 


       LEITURA SECTION.
           RETURN TRAB AT END MOVE "SIM" TO FIM-ARQ.


      *================================================================* 


       PRINCIPAL SECTION.
           PERFORM IMPRESSAO.
           PERFORM LEITURA.


      *================================================================* 


       CALCULO-MEDIA SECTION.
           ADD NOTA1-TRAB NOTA2-TRAB NOTA3-TRAB NOTA4-TRAB
               GIVING CT-SOMA.
           DIVIDE CT-SOMA BY 4 GIVING CT-MEDIA.
           

           IF CT-MEDIA NOT LESS THAN 7
               ADD 1 TO CT-APROVADOS
           ELSE
               ADD 1 TO CT-REPROVADOS
           END-IF.

           ADD 1 TO WALUNOS-TURMA.
           ADD CT-MEDIA TO SOMA-GERAL.


      *================================================================* 
      
      
       IMPRESSAO SECTION.
           IF CT-LIN GREATER THAN 40
               PERFORM IMPRESSAO-TITULO.
           
           IF WTURMA NOT EQUAL TURMA-TRAB
               IF PERMIT-ROD-TURMA EQUAL 1
                   PERFORM IMP-ROD-TOT-APROV
                   PERFORM IMP-ROD-TOT-REPROV
                   PERFORM IMP-ROD-MED-GERAL
                   MOVE ZEROES TO CT-MEDIA
                   MOVE ZEROES TO CT-APROVADOS
                   MOVE ZEROES TO CT-REPROVADOS
               ELSE
                   MOVE 1 TO PERMIT-ROD-TURMA
               END-IF
           
               PERFORM IMPRESSAO-TITULO
               PERFORM IMPRESSAO-TURMA
               PERFORM IMPRESSAO-DADOS
               MOVE TURMA-TRAB TO WTURMA
           END-IF.

           
           PERFORM CALCULO-MEDIA.
           PERFORM IMPRESSAO-DETALHE.
           

      *================================================================*


       IMPRESSAO-TITULO SECTION.
           ADD 1 TO CT-PAG.
           MOVE CT-PAG TO VAR-PAG.
           MOVE SPACES TO REG-ATR.
           WRITE REG-ATR FROM CAB-TITULO AFTER ADVANCING 2 LINES.
           MOVE ZEROES TO CT-LIN.
           
           
      *================================================================*

       IMPRESSAO-TURMA SECTION.
           MOVE TURMA-TRAB TO VAR-TURMA.
           WRITE REG-ATR FROM CAB-TURMA AFTER ADVANCING 2 LINES.
           
           
      *================================================================* 

       IMPRESSAO-DADOS SECTION.
           WRITE REG-ATR FROM CAB-DADOS AFTER ADVANCING 2 LINES.


      *================================================================*
      
       
       IMPRESSAO-DETALHE SECTION.
           MOVE COD1-TRAB TO VAR-COD1.
           MOVE COD2-TRAB TO VAR-COD2.
           MOVE COD3-TRAB TO VAR-COD3.
           MOVE NOME-TRAB TO VAR-NOME.
           MOVE CT-MEDIA  TO VAR-MEDIA.
           WRITE REG-ATR FROM DETALHE AFTER ADVANCING 1 LINE.
           

      *================================================================*     


       IMP-ROD-TOT-APROV SECTION.
           MOVE CT-APROVADOS TO VAR-APROVADOS.
           WRITE REG-ATR FROM RODAPE-APROVADOS 
               AFTER ADVANCING 2 LINES.


      *================================================================* 

           
       IMP-ROD-TOT-REPROV SECTION.
           MOVE CT-REPROVADOS TO VAR-REPROVADOS.
           WRITE REG-ATR FROM RODAPE-REPROVADOS 
               AFTER ADVANCING 1 LINE. 


      *================================================================*


       IMP-ROD-MED-GERAL SECTION.
           MOVE CT-MEDIA TO VAR-MEDIA-GERAL. 
           WRITE REG-ATR FROM RODAPE-MEDIA AFTER ADVANCING 1 LINE.
           

      *================================================================*


       FIM SECTION.
           PERFORM IMP-ROD-TOT-APROV
           PERFORM IMP-ROD-TOT-REPROV
           PERFORM IMP-ROD-MED-GERAL.
           CLOSE RELALU.
           
       
      *================================================================* 