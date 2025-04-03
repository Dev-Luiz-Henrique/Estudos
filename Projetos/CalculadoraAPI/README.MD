# CalculadoraAPI

Este projeto consiste em um aplicativo Android desenvolvido como parte de uma etapa de um processo seletivo. A aplicação realiza cálculos básicos e armazena os resultados através do consumo de uma API externa.

## 📱 Funcionalidades

1. **Realização de Operações Matemáticas:**
   - Soma, Subtração, Multiplicação e Divisão entre dois números informados pelo usuário.
   - Exibição de mensagens de erro para entradas inválidas (valores em branco, letras ou caracteres especiais).

2. **Armazenamento de Cálculos:**
   - Envio dos dados para uma API REST por meio de requisições HTTP usando o Retrofit.
   - Resposta bem-sucedida exibe mensagem de confirmação com o ID gerado pela API.

3. **Visualização do Histórico:**
   - Exibição dos cálculos armazenados em uma lista dinâmica (RecyclerView) apresentada de forma vertical.
   - Formatação personalizada: números com duas casas decimais e data exibida no formato "dd/mm/aaaa hh:mm:ss".

4. **Exclusão de Registros:**
   - Possibilidade de remover um cálculo específico do histórico utilizando seu ID.

---

## 🛠 Tecnologias Utilizadas

- **Linguagem:** Java 17
- **SDK:** Android SDK mais recente
- **Bibliotecas:**
  - Retrofit (para consumo da API)
  - RecyclerView (para exibição do histórico)
  - ConstraintLayout (para construção das interfaces)

---

## 🔌 Arquitetura e Estrutura

O aplicativo foi dividido em **Fragments**, visando melhor organização e reutilização de componentes. A escolha por Fragments foi feita por familiaridade e para facilitar a separação lógica entre as telas.

- **Tela Principal:** Formulário de entrada com dois campos numéricos e botões para operações matemáticas.
- **Tela de Histórico:** Lista dos cálculos realizados, com suporte para exclusão individual de registros.

O uso de **RecyclerView** foi escolhido para garantir eficiência na renderização de listas dinâmicas.

---

## 🌐 Consumo da API

O aplicativo se comunica com uma API REST que disponibiliza os seguintes endpoints:

- `POST`: Armazena um cálculo matemático.
- `GET`: Retorna a lista de cálculos armazenados.
- `DELETE`: Remove um cálculo específico pelo seu ID.

### 🔑 Chave de API
Para consumo dos endpoints, é necessário utilizar uma URL e chave de API específicas, que não divulgarei por questões de segurança.

A chave deve ser inserida manualmente no arquivo `CalculationController` e a URL no `CalculationAPI`.

---

## 🔍 Desafios Enfrentados

1. **Requisições Assíncronas:**
   - Para capturar o ID retornado pela API após um cálculo, foi necessário implementar callbacks devido à natureza assíncrona do Retrofit.
   - Foi implementada uma interface com funções `onSuccess` e `onError` para tratar os resultados adequadamente.

2. **RecyclerView e Adapter:**
   - A implementação do Adapter exigiu cuidado na manipulação da lista e atualização da interface.
   - Foram utilizados métodos adequados como `notifyItemRemoved` e `notifyDataSetChanged` para manter a consistência visual.

3. **Apresentação dos Dados:**
   - Em vez de uma tabela, os dados foram exibidos em blocos verticais para melhor aproveitamento do espaço e estética da interface.

---

## 🚀 Como Executar o Projeto

1. Clone o repositório:  
```
git clone https://github.com/Dev-Luiz-Henrique/CalculadoraAPI.git
```

2. Abra o projeto no Android Studio.

3. Insira a chave de API no arquivo e a URL.

4. Execute o projeto em um emulador ou dispositivo físico.

---

## 📂 Estrutura de Pastas

```
app/src/main
├───java/com/devluiz/calculadoraapi
│   ├───adapters        // Adapter para a RecyclerView
│   ├───controllers     // Controlador para requisições HTTP via Retrofit
│   ├───interfaces      // Interfaces de callback
│   ├───models          // Modelos de dados
│   ├───network         // Configuração da API
│   └───views           // Fragments (Calculator e History)
└───res                 // Recursos (layouts, drawables, etc.)
```

---

## 📜 Licença
Este projeto foi desenvolvido exclusivamente para o processo seletivo e não possui licença específica.

---

## 📞 Contato
Luiz Henrique de Santana: dev.luizhenrique@outlook.com

Se precisar de alguma coisa, estou à disposição!
