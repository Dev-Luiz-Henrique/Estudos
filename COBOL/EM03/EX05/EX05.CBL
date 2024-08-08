       IDENTIFICATION DIVISION.
       PROGRAM-ID. EX05.
       AUTHOR.         LUIZ HENRIQUE DE SANTANA 
                       GABRIEL GOMES DA CRUZ
                       NICOLE CARVALHO FUKUSHIMA.
       INSTALLATION.   FATEC-SP.
       DATE-WRITTEN.   11/11/2023.
       DATE-COMPILED.
       SECURITY.       APENAS O AUTOR PODE MODIFICAR.
      *REMARKS.        LER O ARQUIVO DE ENTRADA VENDA.DAT E 
      *                CLASSIFICAR OS DADOS EM ORDEM ASCENDENTE POR
      *                ESTADO E NUMERO DE VENDEDOR E IMPRIMIR O
      *                RESULTADO NO RELATORIO DE SAIDA RELVENDA.
       
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
           SOURCE-COMPUTER. DESKTOP-PC.
           OBJECT-COMPUTER. DESKTOP-PC.
           SPECIAL-NAMES. DECIMAL-POINT IS COMMA.

       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
       SELECT ARQVENDA ASSIGN TO DISK
           ORGANIZATION IS LINE SEQUENTIAL.

       SELECT RELVENDA ASSIGN TO DISK
           ORGANIZATION IS LINE SEQUENTIAL.

       SELECT TRAB ASSIGN TO DISK.

       DATA DIVISION.
       FILE SECTION.

       FD ARQVENDA LABEL RECORD ARE STANDARD
        VALUE OF FILE-ID IS "VENDA.DAT".
       01 REG-ENT.
           02 ESTADO-ENT          PIC X(02).
           02 NR-VENDEDOR         PIC 9(05).
           02 NOME-VENDEDOR       PIC X(20).
           02 VALOR-VENDA         PIC 9(07)V99.

       SD TRAB.
       01 REG-TRAB.
           02 ESTADO-TRAB        PIC X(02).
           02 NR-VENDEDOR-TRAB   PIC 9(05).
           02 NOME-VENDEDOR-TRAB PIC X(20).
           02 VALOR-VENDA-TRAB   PIC 9(07)V99.

       FD RELVENDA LABEL RECORD ARE OMITTED.
       01 REG-ATR.
           02 REL-ATR PIC X(80).

       WORKING-STORAGE SECTION.
       77 FIM-ARQ PIC X(03) VALUE "NAO".
       77 CT-I PIC 99 VALUE 1.
       77 CT-LIN PIC 99 VALUE 21.
       77 CT-PAG PIC 99 VALUE ZEROES.

       77 WNR-VENDEDOR PIC 9(05) VALUE ZEROES.
       77 W-ESTADO PIC X(02) VALUE SPACES.

       77 WTOT-ESTADO PIC 9(07)V99.
       77 WTOT-VENDEDOR PIC 9(07)V99.
       77 WTOT-COMP PIC 9(07)V99.
 
       01 CAB-01.
           02 FILLER PIC X(19) VALUE SPACES.
           02 FILLER PIC X(35) VALUE 
             "VENDAS TOTAIS POR ESTADO - VENDEDOR".
           02 FILLER PIC X(20) VALUE SPACES.
           02 FILLER PIC X(04) VALUE "PAG.".
           02 VAR-PAG PIC 9(02) VALUE ZEROES.

       01 CAB-02.
           02 FILLER PIC X(08) VALUE "ESTADO: ".
           02 ESTADO-CAB PIC X(19).
           02 FILLER PIC X(53) VALUE SPACES.

       01 CAB-03.
           02 FILLER PIC X(05) VALUE SPACES.
           02 FILLER PIC X(15) VALUE "NRO DO VENDEDOR".
           02 FILLER PIC X(12) VALUE SPACES.
           02 FILLER PIC X(16) VALUE "NOME DO VENDEDOR".
           02 FILLER PIC X(18) VALUE SPACES.
           02 FILLER PIC X(14) VALUE "VALOR DA VENDA".

       01 DET-01.
           02 FILLER PIC X(10) VALUE SPACES.
           02 NRO-RELAT PIC X(05).
           02 FILLER PIC X(16) VALUE SPACES.
           02 NOME-RELAT PIC X(20).
           02 FILLER PIC X(19) VALUE SPACES.
           02 VENDA-RELAT PIC 9(07)V99.
           02 FILLER PIC X(03) VALUE SPACES.

       01 RODAPE-01.
           02 FILLER PIC X(52) VALUE SPACES.
           02 FILLER PIC X(19) VALUE "TOTAL DO VENDEDOR: ".
           02 TOT-VENDA PIC 9(07)V99.

       01 RODAPE-02.
           02 FILLER PIC X(54) VALUE SPACES.
           02 FILLER PIC X(17) VALUE "TOTAL DO ESTADO: ".
           02 TOT-ESTADO PIC 9(07)V99.

       01 RODAPE-03.
           02 FILLER PIC X(51) VALUE SPACES.
           02 FILLER PIC X(20) VALUE "TOTAL DA COMPANHIA: ".
           02 TOT-COMP PIC 9(07)V99.

       01 TABELA.
         02 TAB-SIGLAS-ESTADOS.
           03 FILLER PIC X(21) VALUE "ACACRE               ".
           03 FILLER PIC X(21) VALUE "ALALAGOAS            ".
           03 FILLER PIC X(21) VALUE "AMAMAZONAS           ".
           03 FILLER PIC X(21) VALUE "APAMAPA              ".
           03 FILLER PIC X(21) VALUE "BABAHIA              ".
           03 FILLER PIC X(21) VALUE "CECEARA              ".
           03 FILLER PIC X(21) VALUE "DFDISTRITO FEDERAL   ".
           03 FILLER PIC X(21) VALUE "ESESPIRITO SANTO     ".
           03 FILLER PIC X(21) VALUE "GOGOIAS              ".
           03 FILLER PIC X(21) VALUE "MAMARANHAO           ".
           03 FILLER PIC X(21) VALUE "MGMINAS GERAIS       ".
           03 FILLER PIC X(21) VALUE "MSMATO GROSSO DO SUL ".
           03 FILLER PIC X(21) VALUE "MTMATO GROSSO        ".
           03 FILLER PIC X(21) VALUE "PAPARA               ".
           03 FILLER PIC X(21) VALUE "PBPARAIBA            ".
           03 FILLER PIC X(21) VALUE "PEPERNAMBUCO         ".
           03 FILLER PIC X(21) VALUE "PIPIAUI              ".
           03 FILLER PIC X(21) VALUE "PRPARANA             ".
           03 FILLER PIC X(21) VALUE "RJRIO DE JANEIRO     ".
           03 FILLER PIC X(21) VALUE "RNRIO GRANDE DO NORTE".
           03 FILLER PIC X(21) VALUE "RORONDONIA           ".
           03 FILLER PIC X(21) VALUE "RRRORAIMA            ".
           03 FILLER PIC X(21) VALUE "RSRIO GRANDE DO SUL  ".
           03 FILLER PIC X(21) VALUE "SCSANTA CATARINA     ".
           03 FILLER PIC X(21) VALUE "SESERGIPE            ".
           03 FILLER PIC X(21) VALUE "SPSAO PAULO          ".
           03 FILLER PIC X(21) VALUE "TOTOCANTINS          ".

       01 TAB-ESTADOS REDEFINES TABELA OCCURS 27 TIMES.
           02 SIGLA  PIC X(02).
           02 ESTADO PIC X(19).

       PROCEDURE DIVISION.
       PGM-EX5.
           SORT TRAB
            ASCENDING KEY ESTADO-TRAB
            ASCENDING KEY NR-VENDEDOR-TRAB
            USING ARQVENDA
            OUTPUT PROCEDURE ROT-SAIDA.
           STOP RUN.

      *================================================================*
       
       ROT-SAIDA SECTION.
           PERFORM INICIO.
           PERFORM PRINCIPAL UNTIL FIM-ARQ EQUAL "SIM".
           PERFORM FIM.

      *================================================================*

       INICIO SECTION.
           OPEN OUTPUT RELVENDA.
           PERFORM LEITURA.

      *================================================================*

       LEITURA SECTION.
           RETURN TRAB AT END MOVE "SIM" TO FIM-ARQ.

      *================================================================*

       PRINCIPAL SECTION.
           PERFORM IMPRESSAO.
           PERFORM LEITURA.

      *================================================================*

       IMPRESSAO SECTION.
           IF CT-LIN GREATER THAN 20
               PERFORM CABECALHO.

           IF ESTADO-TRAB NOT EQUAL W-ESTADO
               PERFORM IMP-RODAPE-VEND
               MOVE 0 TO WNR-VENDEDOR
               
               PERFORM IMP-RODAPE-ESTD
               PERFORM IMP-CAB-ESTADO
               MOVE ESTADO-TRAB TO W-ESTADO
           END-IF.

           IF NR-VENDEDOR-TRAB NOT EQUAL WNR-VENDEDOR
               PERFORM IMP-RODAPE-VEND
               MOVE NR-VENDEDOR-TRAB TO WNR-VENDEDOR

               WRITE REG-ATR FROM CAB-03 AFTER ADVANCING 2 LINES

               MOVE NR-VENDEDOR-TRAB TO NRO-RELAT
               MOVE NOME-VENDEDOR-TRAB TO NOME-RELAT
               PERFORM IMP-DET
               MOVE ALL SPACES TO NRO-RELAT
               MOVE ALL SPACES TO NOME-RELAT
           ELSE
               PERFORM IMP-DET.

      *================================================================* 

       IMP-DET SECTION.
           ADD   VALOR-VENDA-TRAB TO WTOT-VENDEDOR.
           ADD   VALOR-VENDA-TRAB TO WTOT-ESTADO.
           ADD   VALOR-VENDA-TRAB TO WTOT-COMP.
           MOVE  VALOR-VENDA-TRAB TO VENDA-RELAT.
           WRITE REG-ATR FROM DET-01 AFTER ADVANCING 1 LINE.
           ADD 1 TO CT-LIN.

      *================================================================* 

       IMP-CAB-ESTADO SECTION.
           PERFORM BUSCA-ESTADO UNTIL CT-I GREATER THAN 27.
           MOVE 1 TO CT-I.
           WRITE REG-ATR FROM CAB-02 AFTER ADVANCING 2 LINES.

      *================================================================* 

       BUSCA-ESTADO SECTION.
           IF SIGLA(CT-I) EQUAL ESTADO-TRAB
               MOVE ESTADO(CT-I) TO ESTADO-CAB
               MOVE 99 TO CT-I
           ELSE
               ADD 1 TO CT-I.
               IF CT-I EQUAL 27
                   MOVE "ESTADO INVALIDO    " TO ESTADO-CAB.

      *================================================================*

       CABECALHO SECTION.
           ADD 1 TO CT-PAG.
           MOVE CT-PAG TO VAR-PAG.
           MOVE SPACES TO REG-ATR.
           WRITE REG-ATR FROM CAB-01 AFTER ADVANCING 2 LINES.
           MOVE ZEROES TO CT-LIN.

      *================================================================*

       IMP-RODAPE-VEND SECTION.
           IF WNR-VENDEDOR NOT EQUAL 0
               MOVE WTOT-VENDEDOR TO TOT-VENDA
               WRITE REG-ATR FROM RODAPE-01 AFTER ADVANCING 2 LINES
               MOVE ZEROES TO WTOT-VENDEDOR.

      *================================================================*

       IMP-RODAPE-ESTD SECTION.
           IF W-ESTADO NOT EQUAL SPACES 
               MOVE WTOT-ESTADO TO TOT-ESTADO
               WRITE REG-ATR FROM RODAPE-02 AFTER ADVANCING 2 LINES
               MOVE ZEROES TO TOT-ESTADO
               MOVE ZEROES TO WTOT-ESTADO.
      *================================================================*
       
       IMP-RODAPE-COMP SECTION.
           MOVE WTOT-COMP TO TOT-COMP.
           WRITE REG-ATR FROM RODAPE-03 AFTER ADVANCING 2 LINES.
           
      *================================================================*
           
       FIM SECTION.
           PERFORM IMP-RODAPE-VEND.
           PERFORM IMP-RODAPE-ESTD.
           PERFORM IMP-RODAPE-COMP.
           CLOSE RELVENDA.