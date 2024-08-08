       IDENTIFICATION DIVISION.
       PROGRAM-ID.     EX06.
       AUTHOR.         LUIZ HENRIQUE DE SANTANA 
                       GABRIEL GOMES DA CRUZ
                       NICOLE CARVALHO FUKUSHIMA.
       INSTALLATION.   FATEC-SP.
       DATE-WRITTEN.   12/11/2023.
       DATE-COMPILED.
       SECURITY.       APENAS O AUTOR PODE MODIFICA-LO.
      *REMARKS         LER O ARQUIVO DE ENTRADA CADVEND.DAT E
      *                REALIZAR OS CALCULOS PARA OBTER O SALARIO
      *                BRUTO, LIQUIDO E A COMISSAO, EXIBINDO-OS DE
      *                ACORDO COM A PESSOA EM QUESTAO, ORDENANDO
      *                POR DEPARTAMENTO E SECAO EM ORDEM ASCENDENTE.

       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       OBJECT-COMPUTER.    IBM-PC.
       SOURCE-COMPUTER.    IBM-PC.
       SPECIAL-NAMES.      DECIMAL-POINT IS COMMA.

       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
       SELECT CADVEND ASSIGN TO DISK
           ORGANIZATION IS LINE SEQUENTIAL.
       SELECT TRAB ASSIGN TO DISK.
       SELECT REL-PAG ASSIGN TO DISK.

       DATA DIVISION.
       FILE SECTION.
       FD CADVEND LABEL RECORD ARE STANDARD
       VALUE OF FILE-ID IS "CADVEND.DAT".
       01 REG-ENT.
           02 COD-DEP-ENT          PIC X(01).
           02 COD-SEC-ENT          PIC X(01).
           02 COD-VEN-ENT          PIC 9(05).
           02 NOME-ENT             PIC X(20).
           02 VENDA-ENT            PIC 9(07)V99.
           02 SALARIO-ENT          PIC 9(07)V99.
           02 DESCONTO-ENT         PIC 9(05)V99.
       
       SD TRAB.
       01 REG-TRAB.
           02 COD-DEP-TRAB         PIC X(01).
           02 COD-SEC-TRAB         PIC X(01).
           02 COD-VEN-TRAB         PIC 9(05).
           02 NOME-TRAB            PIC X(20).
           02 VENDA-TRAB           PIC 9(07)V99.
           02 SALARIO-TRAB         PIC 9(07)V99.
           02 DESCONTO-TRAB        PIC 9(05)V99.

       FD REL-PAG LABEL RECORD IS OMITTED.
       01 REG-ATR.
           02 REL-ART              PIC X(80).

       WORKING-STORAGE SECTION.
       77 FIM-ARQ                  PIC X(03) VALUE "NAO".
       77 PERMITE-ROD-DEP          PIC 9 VALUE 0.
       77 PERMITE-ROD-SEC          PIC 9 VALUE 0.
       77 CT-PAG                   PIC 99 VALUE ZEROS.
       77 CT-LIN                   PIC 99 VALUE 41.

       77 WCOMISSAO                PIC 9999999V99 VALUE ZEROS. 
       77 WSAL-LIQUIDO             PIC 9999999V99 VALUE ZEROS. 
       77 WSAL-BRUTO               PIC 9999999V99 VALUE ZEROS. 

       77 WDEPARTAMENTO            PIC X VALUE SPACE. 
       77 WSECAO                   PIC X VALUE SPACE.
       77 WSAL-SEC                 PIC 9(09)V99 VALUE ZEROES.
       77 WSAL-DEP                 PIC 9(12)V99 VALUE ZEROES.

       01 CAB-TITULO.
           02 FILLER           PIC X(26) VALUE SPACES.
           02 FILLER           PIC X(23) 
            VALUE "RELATÓRIO DE PAGAMENTO".
           02 FILLER           PIC X(23) VALUE SPACES.
           02 FILLER           PIC X(6) VALUE "PÁG. ".
           02 VAR-PAG          PIC 9(02).
       
       01 CAB-DEPARTAMENTO.
           02 FILLER           PIC X(16) VALUE "DEPARTAMENTO = ".
           02 VAR-DEP-REL      PIC 9(01).
           02 FILLER           PIC X(63) VALUE SPACES.
         
       01 CAB-SECAO.
           02 FILLER           PIC X(07) VALUE "SEÇÃO".
           02 FILLER           PIC X(11) VALUE "        = ".
           02 VAR-SEC-REL      PIC 9(01).
           02 FILLER           PIC X(61) VALUE SPACES.
       
       01 CAB-DADOS.
           02 FILLER           PIC X(06) VALUE "CODIGO".
           02 FILLER           PIC X(09) VALUE SPACES.
           02 FILLER           PIC X(04) VALUE "NOME".
           02 FILLER           PIC X(08) VALUE SPACES.
           02 FILLER           PIC X(08) VALUE "SAL.FIXO".
           02 FILLER           PIC X(03) VALUE SPACES.
           02 FILLER           PIC X(08) VALUE "COMISSAO".
           02 FILLER           PIC X(02) VALUE SPACES.
           02 FILLER           PIC X(09) VALUE "SAL.BRUTO".
           02 FILLER           PIC X(02) VALUE SPACES.
           02 FILLER           PIC X(08) VALUE "DESCONTO". 
           02 FILLER           PIC X(01) VALUE SPACES.
           02 FILLER           PIC X(11) VALUE "SAL.LIQUIDO".

       01 DETALHE.
           02 COD-REL          PIC 9(05).
           02 FILLER           PIC X(01) VALUE SPACES.
           02 NOME-REL         PIC X(20).
           02 FILLER           PIC X(01) VALUE SPACES.
           02 SAL-FIXO-REL     PIC ZZZZZZ9,99.
           02 FILLER           PIC X(01) VALUE SPACES.
           02 COMISSAO-REL     PIC ZZZZZZ9,99.
           02 FILLER           PIC X(01) VALUE SPACES.
           02 SAL-BRUTO-REL    PIC ZZZZZZ9,99.
           02 FILLER           PIC X(01) VALUE SPACES.
           02 DESCONTO-REL     PIC ZZZZ9,99.
           02 FILLER           PIC X(01) VALUE SPACES.
           02 SAL-LIQ-REL      PIC ZZZZZZ9,99.
           02 FILLER           PIC X(05) VALUE SPACES.

       01 RODAPE-SAL-SEC.
           02 FILLER           PIC X(19) VALUE "TOTAL DE SALÁRIOS ".
           02 FILLER           PIC X(12) VALUE "DA SEÇÃO: ".
           02 SAL-SEC-REL      PIC 999999999,99.
           02 FILLER           PIC X(38) VALUE SPACES.

       01 RODAPE-SAL-DEP.
           02 FILLER           PIC X(19) VALUE "TOTAL DE SALÁRIOS ".
           02 FILLER           PIC X(17) VALUE "DO DEPARTAMENTO: ".
           02 SAL-DEP-REL     PIC 999999999999,99.
           02 FILLER           PIC X(29) VALUE SPACES.
           

       PROCEDURE DIVISION. 
       PGM-EX06.
           SORT TRAB ASCENDING KEY COD-DEP-TRAB, 
               COD-SEC-TRAB, COD-VEN-TRAB
               USING CADVEND OUTPUT PROCEDURE ROT-SAI.
           STOP RUN.
                        
      *================================================================*      

       ROT-SAI SECTION.
           PERFORM INICIO.
           PERFORM PRINCIPAL UNTIL FIM-ARQ EQUAL "SIM".
           PERFORM FIM.
          
      *================================================================*
       
       INICIO SECTION.
           OPEN OUTPUT REL-PAG.
           PERFORM LEITURA.
             
      *================================================================* 
        
       LEITURA SECTION.
           RETURN TRAB AT END MOVE "SIM" TO FIM-ARQ.
            
      *================================================================* 
       
       PRINCIPAL SECTION.
           PERFORM CALCULO-SAL.
           PERFORM IMPRESSAO.
           PERFORM LEITURA.
           
      *================================================================* 

       CALCULO-SAL SECTION.

      * CALCULO COMISSAO 
           IF VENDA-TRAB NOT GREATER THAN 1000,00
               MULTIPLY VENDA-TRAB BY 0,05 GIVING WCOMISSAO

           ELSE
               IF VENDA-TRAB GREATER THAN 1000,00 AND 
                  VENDA-TRAB NOT GREATER THAN 3000,00
                   MULTIPLY VENDA-TRAB BY 0,10 GIVING WCOMISSAO
                   
               ELSE 
                   MULTIPLY VENDA-TRAB BY 0,15 GIVING WCOMISSAO.

      * CALCULO SALARIO BRUTO             
           ADD SALARIO-TRAB WCOMISSAO GIVING WSAL-BRUTO.

      * CALCULO SALARIO LIQUIDO             
           SUBTRACT WSAL-BRUTO FROM DESCONTO-TRAB GIVING WSAL-LIQUIDO.

      *================================================================* 

       IMPRESSAO SECTION.
           IF CT-LIN GREATER THAN 40
               PERFORM IMP-CAB-TIT.  

           IF WDEPARTAMENTO NOT EQUAL COD-DEP-TRAB 
               IF PERMITE-ROD-DEP EQUAL 1
                   PERFORM IMP-ROD-SAL-SEC
                   PERFORM IMP-ROD-SAL-DEP
                   MOVE 0 TO PERMITE-ROD-SEC
               END-IF
               
               PERFORM IMP-CAB-DEP
               MOVE COD-DEP-TRAB TO WDEPARTAMENTO

               MOVE 1 TO PERMITE-ROD-DEP
           END-IF.

           IF WSECAO NOT EQUAL COD-SEC-TRAB
               IF PERMITE-ROD-SEC EQUAL 1
                   PERFORM IMP-ROD-SAL-SEC
               ELSE
                   MOVE 1 TO PERMITE-ROD-SEC
               END-IF
               
               PERFORM IMP-CAB-SEC
               MOVE COD-SEC-TRAB TO WSECAO
               PERFORM IMP-CAB-DET
           END-IF.

           PERFORM IMP-DET.
            
      *================================================================*       

       IMP-CAB-TIT SECTION.
           ADD 1 TO CT-PAG.
           MOVE CT-PAG TO VAR-PAG.
           MOVE SPACES TO REG-ATR.
           WRITE REG-ATR AFTER ADVANCING PAGE.
           WRITE REG-ATR FROM CAB-TITULO AFTER ADVANCING 2 LINES.     
           MOVE ZEROES TO CT-LIN.

      *================================================================*      

       IMP-CAB-SEC SECTION.
           MOVE COD-SEC-TRAB TO VAR-SEC-REL.      
           WRITE REG-ATR FROM CAB-SECAO
               AFTER ADVANCING 2 LINES.   

      *================================================================* 
       
       IMP-CAB-DEP SECTION.
           IF PERMITE-ROD-DEP EQUAL 1
               PERFORM IMP-CAB-TIT.

           MOVE COD-DEP-TRAB TO VAR-DEP-REL.      
           WRITE REG-ATR FROM CAB-DEPARTAMENTO 
               AFTER ADVANCING 2 LINES.

      *================================================================*    
       
       IMP-CAB-DET SECTION.
           WRITE REG-ATR FROM CAB-DADOS AFTER ADVANCING 2 LINES.
           
      *================================================================*
      
       IMP-DET SECTION.
           MOVE COD-DEP-TRAB TO COD-REL.
           MOVE NOME-TRAB TO NOME-REL.
           MOVE SALARIO-TRAB TO SAL-FIXO-REL.
           MOVE WCOMISSAO TO COMISSAO-REL.
           MOVE WSAL-BRUTO TO SAL-BRUTO-REL.
           MOVE DESCONTO-TRAB TO DESCONTO-REL.
           MOVE WSAL-LIQUIDO TO SAL-LIQ-REL.
           WRITE REG-ATR FROM DETALHE AFTER ADVANCING 1 LINE.
           ADD WSAL-LIQUIDO TO WSAL-SEC.

      *================================================================*     
       
       IMP-ROD-SAL-SEC SECTION.
           MOVE WSAL-SEC TO SAL-SEC-REL.
           WRITE REG-ATR FROM RODAPE-SAL-SEC 
               AFTER ADVANCING 2 LINES
           ADD WSAL-SEC TO WSAL-DEP.
           MOVE ZEROS TO WSAL-SEC.

      *================================================================*     
       
       IMP-ROD-SAL-DEP SECTION.
           MOVE WSAL-DEP TO SAL-DEP-REL.
           WRITE REG-ATR FROM RODAPE-SAL-DEP 
               AFTER ADVANCING 1 LINE
           MOVE ZEROS TO WSAL-DEP.

      *================================================================*

       FIM SECTION.
           CLOSE REL-PAG.

      *================================================================*     