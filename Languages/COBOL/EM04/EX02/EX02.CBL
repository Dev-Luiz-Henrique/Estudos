       IDENTIFICATION DIVISION.
       PROGRAM-ID.     EX02.
       AUTHOR.         LUIZ HENRIQUE DE SANTANA
                       GABRIEL GOMES DA CRUZ.
       INSTALLATION.   FATEC-SP.
       DATE-WRITTEN.   24/11/2023.
       DATE-COMPILED.
       SECURITY.       APENAS O AUTOR PODE MODIFICA-LO.
      *REMARKS.        FAZER O BALANCE-LINE, GERANDO UM ARQUIVO
      *                ATUALIZADO E UM RELATORIO DE ATUALIZACAO.

       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       SOURCE-COMPUTER. IBM-PC.
       OBJECT-COMPUTER. IBM-PC.
       SPECIAL-NAMES. DECIMAL-POINT IS COMMA.

       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
           SELECT CADANT ASSIGN TO DISK ORGANIZATION 
               IS LINE SEQUENTIAL.
           SELECT ARQMOV ASSIGN TO DISK ORGANIZATION 
               IS LINE SEQUENTIAL.
           SELECT CADATU ASSIGN TO DISK ORGANIZATION 
               IS LINE SEQUENTIAL.
           SELECT RELOCORR ASSIGN TO DISK.

       DATA DIVISION.
       FILE SECTION.
       
       FD CADANT LABEL RECORD ARE STANDARD
           VALUE OF FILE-ID IS "CADANT.DAT".
       01 REG-ANT.
          02 CC-ANT        PIC 9(03).
          02 TIPO-ANT      PIC X(01).
          02 ENDER-ANT     PIC X(50).
       
       FD ARQMOV LABEL RECORD ARE STANDARD
           VALUE OF FILE-ID IS "ARQMOV.DAT".
       01 REG-MOV.
           02 CC-MOV       PIC 9(03).
           02 TIPO-MOV     PIC X(01).
           02 ENDER-MOV    PIC X(50).
             
       FD CADATU LABEL RECORD ARE STANDARD
           VALUE OF FILE-ID IS "CADATU.DAT".
       01 REG-ATU.
           02 CC-ATU       PIC 9(03).
           02 TIPO-ATU     PIC X(01).
           02 ENDER-ATU    PIC X(50).

       FD RELOCORR LABEL RECORD IS OMITTED.
       01 DET-OCCOR        PIC X(80).
       
       WORKING-STORAGE SECTION.
       77 CH-CADANT        PIC X(04) VALUE SPACES.
       77 CH-ARQMOV        PIC X(04) VALUE SPACES.
       77 CT-PAG           PIC 9(03) VALUE ZEROS.
       77 CT-LIN           PIC 9(02) VALUE 41.
       
       01 CAB-01.
           02 FILLER PIC X(26) VALUE SPACES.
           02 FILLER PIC X(26) VALUE "Relação de atualização".
           02 FILLER PIC X(14) VALUE SPACES.
           02 FILLER PIC X(05) VALUE "Pag. ".
           02 VAR-PAG PIC ZZ9.
           02 FILLER PIC X(06) VALUE SPACES.

       01 CAB-02.
           02 FILLER PIC X(06) VALUE SPACES.
           02 FILLER PIC X(06) VALUE "codigo".
           02 FILLER PIC X(06) VALUE SPACES.
           02 FILLER PIC X(04) VALUE "tipo".
           02 FILLER PIC X(15) VALUE SPACES.
           02 FILLER PIC X(08) VALUE "mensagem".
           02 FILLER PIC X(35) VALUE SPACES.

       01 DETALHE.
           02 FILLER PIC X(08) VALUE SPACES.
           02 CC-DET PIC 999.
           02 FILLER PIC X(08) VALUE SPACES.
           02 TIPO-DET PIC X(01).
           02 FILLER PIC X(08) VALUE SPACES.
           02 MENSAGEM-DET PIC X(40).
           02 FILLER PIC X(12) VALUE SPACES.

       PROCEDURE DIVISION.
       PGM-EX02.
           PERFORM INICIO.
           PERFORM PRINCIPAL UNTIL CH-CADANT EQUAL HIGH-VALUES AND
                               CH-ARQMOV EQUAL HIGH-VALUES.
           PERFORM TERMINO.
           STOP RUN.

      *================================================================*

       INICIO.
              OPEN INPUT CADANT ARQMOV OUTPUT CADATU RELOCORR.
              PERFORM LER-CADANT.
              PERFORM LER-ARQMOV.
      *================================================================*

       LER-CADANT.
           READ CADANT AT END MOVE HIGH-VALUES TO CH-CADANT.
           IF CH-CADANT EQUAL HIGH-VALUES
               NEXT SENTENCE
           ELSE
               MOVE CC-ANT TO CH-CADANT
           END-IF.
      
       LER-ARQMOV.
           READ ARQMOV AT END MOVE HIGH-VALUES TO CH-ARQMOV.
           IF CH-ARQMOV EQUAL HIGH-VALUES
               NEXT SENTENCE
           ELSE
               MOVE CC-MOV TO CH-ARQMOV
           END-IF.
      *================================================================*
       
       PRINCIPAL.
           IF CT-LIN GREATER 40
               PERFORM CABECALHO.

           IF CH-CADANT EQUAL CH-ARQMOV
               PERFORM CADANT-IGUAL-ARQMOV
               PERFORM LER-CADANT
               PERFORM LER-ARQMOV
           ELSE
               IF CH-CADANT LESS CH-ARQMOV
                   PERFORM CADANT-MENOR
                   PERFORM LER-CADANT
               ELSE
                   PERFORM ARQMOV-MENOR
                   PERFORM LER-ARQMOV
               END-IF
           END-IF.
      *================================================================*

       CADANT-IGUAL-ARQMOV.
           EVALUATE TRUE
             WHEN TIPO-MOV EQUAL 'A'
               MOVE "REGISTRO SUBSTITUIDO" TO MENSAGEM-DET
               MOVE CC-ANT TO CC-DET
               MOVE TIPO-ANT TO TIPO-DET
               WRITE DET-OCCOR FROM DETALHE AFTER ADVANCING 1 LINE
               ADD 1 TO CT-LIN
               
               MOVE "REGISTRO SUBSTITUTO" TO MENSAGEM-DET
               MOVE CC-MOV TO CC-DET
               MOVE TIPO-MOV TO TIPO-DET
               PERFORM GRAVAR-ARQMOV-CADATU

             WHEN TIPO-MOV EQUAL 'E'
               MOVE "REGISTRO EXCLUIDO" TO MENSAGEM-DET
               MOVE CC-ANT TO CC-DET
               MOVE TIPO-ANT TO TIPO-DET

             WHEN TIPO-MOV EQUAL 'I'
               MOVE "INCLUSÃO P/REG. JÁ EXISTENTE" TO MENSAGEM-DET               
               MOVE CC-MOV TO CC-DET
               MOVE TIPO-MOV TO TIPO-DET
               PERFORM GRAVAR-CADANT-CADATU
           END-EVALUATE.

           WRITE DET-OCCOR FROM DETALHE AFTER ADVANCING 1 LINE.
           ADD 1 TO CT-LIN.

       CADANT-MENOR.
           PERFORM GRAVAR-CADANT-CADATU.

       ARQMOV-MENOR.
           MOVE CC-MOV TO CC-DET.
           MOVE TIPO-MOV TO TIPO-DET.

           EVALUATE TRUE
             WHEN TIPO-MOV EQUAL 'A'
               MOVE "ALTERAÇÃO P/REG. INEXISTENTE" TO MENSAGEM-DET
               WRITE DET-OCCOR FROM DETALHE AFTER ADVANCING 1 LINE
               ADD 1 TO CT-LIN

             WHEN TIPO-MOV EQUAL 'E'
               MOVE "EXCLUSÃO P/REG. INEXISTENTE" TO MENSAGEM-DET
               WRITE DET-OCCOR FROM DETALHE AFTER ADVANCING 1 LINE
               ADD 1 TO CT-LIN

             WHEN TIPO-MOV EQUAL 'I'
               MOVE "REGISTRO INCLUIDO" TO MENSAGEM-DET
               WRITE DET-OCCOR FROM DETALHE AFTER ADVANCING 1 LINE
               ADD 1 TO CT-LIN
               PERFORM GRAVAR-ARQMOV-CADATU
           END-EVALUATE.

      *================================================================*

       GRAVAR-CADANT-CADATU.
           MOVE CC-ANT     TO CC-ATU.
           MOVE TIPO-ANT   TO TIPO-ATU.
           MOVE ENDER-ANT  TO ENDER-ATU.
           WRITE REG-ATU.

       GRAVAR-ARQMOV-CADATU.
           MOVE CC-MOV     TO CC-ATU.
           MOVE TIPO-MOV   TO TIPO-ATU.
           MOVE ENDER-MOV  TO ENDER-ATU.
           WRITE REG-ATU.
      *================================================================*

       CABECALHO.
           ADD 1 TO CT-PAG.
           MOVE CT-PAG TO VAR-PAG.
           MOVE SPACES TO DET-OCCOR.
           WRITE DET-OCCOR AFTER ADVANCING PAGE.
           WRITE DET-OCCOR FROM CAB-01 AFTER ADVANCING 1 LINE.
           WRITE DET-OCCOR FROM CAB-02 AFTER ADVANCING 2 LINES.
           MOVE 0 TO CT-LIN.
      *================================================================*

       TERMINO.
           CLOSE CADANT ARQMOV CADATU RELOCORR.