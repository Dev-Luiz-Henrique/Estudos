# Manual de Usuário

## 1. Introdução

Diante dos requisitos apresentados para a realização do projeto final da disciplina de Sistemas Embarcados, foi desenvolvido um sistema funcional de fechadura automática utilizando componentes aprendidos durante o curso. O sistema é composto por hardware e software para trancar e destrancar uma porta com base em uma senha.

## 2. Funcionamento

O sistema é ativado automaticamente quando detecta a presença de uma pessoa a uma distância menor que 100 cm, utilizando um sensor ultrassônico. Quando ativado, os LEDs azuis acendem para indicar que o sistema está pronto, e o display LCD exibe a temperatura ambiente e uma mensagem de boas-vindas.

### 2.1. Requisitos para operação

- **Senha correta:** Para destrancar a porta, o usuário deve digitar a senha correta no teclado 4x4 (senha padrão: `2567`) e pressionar o botão `C` para confirmar.
- **Senha incorreta:** Se uma senha incorreta for digitada, o sistema emitirá um aviso e acenderá LEDs vermelhos sequencialmente para cada tentativa falha. Após três erros consecutivos, o alarme sonoro será ativado.
- **Cancelar entrada:** O usuário pode pressionar o botão `D` para cancelar a digitação e recomeçar.

### 2.2. Componentes utilizados

- **2 Arduinos Uno R3:** Controladores principais para sensores e atuadores.
- **1 teclado 4x4:** Para entrada da senha pelo usuário.
- **1 bateria 9V:** Fonte de energia para o sistema.
- **1 display LCD:** Para exibir mensagens e informações de status.
- **1 sensor de temperatura:** Mede a temperatura ambiente.
- **3 LEDs RGB:** Indicadores visuais de status (azul para pronto, vermelho para erro).
- **1 buzzer:** Alarme sonoro ativado após três falhas consecutivas.
- **5 resistores de 200Ω e 1 resistor de 1kΩ:** Para limitar a corrente nos LEDs e sensores.
- **1 micro servo:** Simula a tranca da porta.
- **1 motor CC:** Simula a abertura física da porta.
- **1 transistor:** Controla o acionamento do motor CC.
- **1 protoboard grande:** Para conexões dos componentes.
- **1 sensor ultrassônico:** Detecta a presença do usuário.
- **Cabos diversos:** Para realizar as conexões entre os componentes.

### 2.3. Operação do sistema

1. **Inicialização:**
   - Ao ligar o sistema, aguarde aproximadamente 3 segundos para que todas as configurações sejam ajustadas.
   - O sistema entra em modo de espera até detectar presença.

2. **Ativação do sistema:**
   - Aproxime-se do sensor ultrassônico a uma distância menor que 100 cm para ativar os componentes.
   - O display exibe uma mensagem de boas-vindas e a temperatura ambiente. Os LEDs azuis acendem.

3. **Entrada da senha:**
   - Digite a senha `2567` no teclado 4x4.
   - Pressione `C` para confirmar.
   - Caso digite incorretamente, pressione `D` para reiniciar a entrada.

4. **Resposta do sistema:**
   - **Senha correta:** O display exibe "Senha correta!", o micro servo destranca a porta, e o motor CC abre a porta.
   - **Senha incorreta:** O display exibe "Senha incorreta!" e acende um LED vermelho para cada tentativa errada. Após três erros, o buzzer é ativado.

## 3. Considerações Finais

- O sistema foi desenvolvido utilizando a plataforma online **Tinkercad**, com o código inteiramente comentado para facilitar o entendimento.
- Para o circuito, as conexões foram organizadas com fios coloridos para maior clareza.
- A implementação do teclado 4x4 foi baseada no exemplo encontrado em: [Teclado 4x4 no Tinkercad](https://www.tinkercad.com/things/iGxovc3JQVe-keypad-4x4-arduino).
- A comunicação serial entre os dois Arduinos foi implementada com base no material: [Protocolo I2C - UDESC](https://www.udesc.br/arquivos/cct/documentos/_Hands_On____Arduino_UNO___Arduino_Mega___Protocolo_I2C___i9___N_cleo_Estudantil_de_Inova__o_Tecnol_gica_15244942814491_1944.pdf).

Para acessar o projeto completo, visite o link no Tinkercad: [Fechadura Automática](https://www.tinkercad.com/things/9pD70zoJXGh-projeto-final-sebi-fechadura-automatica/editel?sharecode=GcYOzYtr4Cu_uegFV6Hz6SHH51iFGnT9zcrj3Pb7gPc).
