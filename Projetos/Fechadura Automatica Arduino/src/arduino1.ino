#include <Keypad.h>
#include <Wire.h>;
#include <Servo.h>
Servo servo; 

const byte numRows= 4; //Numero de linhas
const byte numCols= 4; //Numero de colunas

//Matriz para mapear o teclado
char keymap[numRows][numCols] = 
{
  {'1', '2', '3', 'A'}, 
  {'4', '5', '6', 'B'}, 
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Pinos das linhas e colunas
byte rowPins[numRows] = {9,8,7,6}; 
byte colPins[numCols]= {5,4,3,2}; 

//Variavel Keypad para identificar o mapeamento teclado com os pinos
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

//Variaveis da Senha
String senha = "2567";
String senhaDigitada = "";

byte x = 0;
void setup(){
    //Coloca o servo na posição inicial
    servo.attach(12); 
    servo.write(0);
    
    //Pino Buzzer
    pinMode(11, OUTPUT);
    
    //Pino Motor CC
    pinMode(10, OUTPUT);
    
    //Pino para Ativar LEDs no outro Arduino
    pinMode(8, OUTPUT);
    
    Wire.begin();
    Serial.begin(9600);
}

byte falhas = 0;
void loop(){
    //Variavel para saber a tecla pressionada
    char keypressed = myKeypad.getKey();
    if (keypressed != NO_KEY)
    {
        if(keypressed == 'C') //Verifica se o 'confirma' foi apertado
        {   
            if(senhaDigitada==senha)
            {
                Serial.println("Senha confirmada!");
                servo.write(90); //Destranca a Fechadura
                
                //Abre e Fecha a Porta
                digitalWrite(10, HIGH);
                delay(5000); //Tempo para Abrir a Porta
                digitalWrite(10, LOW);
            } 
            
            else //Caso a senha esteja incorreta
            { 
                Serial.println("Senha incorreta!");
                
                falhas++;
                Wire.beginTransmission(8); // começa a transmissão de dados para o dispositivo com endereço
                Wire.write("Falhas: "); // envia 5 bytes
                Wire.write(falhas); // envia um byte byte
                Wire.endTransmission(); // para a transmissão
                
                if(falhas>3)
                {
                    tone(11,261);
                }
            }
            senhaDigitada = ""; //Limpa a variavel senha    
        } 
        
        else 
        { 
            if(keypressed == 'D') //Verifica se o 'deleta' foi apertado
            {
                Serial.println("Senha apagada!");
                senhaDigitada = ""; //Limpa a variavel senha
            }
            
            else //Caso outra tecla tenha sido pressionada
            {
                Serial.println(keypressed); //Exibe a tecla pressionada
                senhaDigitada = senhaDigitada + keypressed; //Atualiza a senha
            }
        }
    }
}
