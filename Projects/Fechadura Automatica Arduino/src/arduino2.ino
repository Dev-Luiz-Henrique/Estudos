#include <Wire.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12); //Pinos Display LCD

//Variaveis usadas na comunicação
byte x = 0;
char c;
void setup(){
    lcd.begin(16,2);
    
    //Pinos LEDs
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
    
    //Pinos Sensor de Distância Ultrassônico
    pinMode(13, OUTPUT);
    pinMode(A3, INPUT);
    
    //Pino Temperatura
    pinMode(A1, INPUT);
    
    Wire.begin(8); //Adiciona o Arduino no I2C com o endereço 8
    Wire.onReceive(receiveEvent); //Recebe dados do outro Arduino
    Serial.begin(9600);
}

String falhas;

//Metodo para ler os dados recebidos
void receiveEvent(int bytes){
    falhas = "";
    
    while (1 < Wire.available()) { //Faz o loop até terminar todos os valores do i2C
    c = Wire.read(); //Recebe os dados como char
    falhas = falhas + c ;
    }
    x = Wire.read(); //Recebe o byte como inteiro
    falhas = falhas + x;
    Serial.println(falhas);
}

//Variáveis Sensor de Distância Ultrassônico
int pos;
float dist;

//Metodo para calcular a distância
void distancia(){
    //Emissão de pulso do sensor
    digitalWrite(13, HIGH);
    delayMicroseconds(10);
    digitalWrite(13, LOW);
    
    //Conversão de distância do sensor
    dist = pulseIn(A3,HIGH);
    dist=dist/2;
    dist=dist*0.034;
}

//Metodo que retorna a Temperatura
float temperatura(){
    int temp = analogRead(A1); //Executa a leitura dos dados do sensor
    float voltage = temp * (5000 / 1024.0); //Converte os dados em voltagem
    float celsius = (voltage - 500) / 10; //Converte a voltagem em celsius
    delay(500);
    
    return celsius;
}

void loop(){
    distancia();
    if(dist<100){
        lcd.setCursor(0,1); //Acrescenta a Temperatura no Display LCD
        lcd.print("Temp. " + String(round(temperatura())));
    
        lcd.setCursor(0,0); //Acrescenta o Nome da Dupla no Display LCD
        lcd.print("Debora e Luiz");
        
        if(falhas==""){
            digitalWrite(5, HIGH); //Liga os LEDs azuis
        }
        
        else if(falhas=="Falhas: 1"){
            digitalWrite(5, LOW); //Desliga os LEDs azuis
            digitalWrite(2, HIGH); //Liga um LED vermelho
        }
        
        else if(falhas=="Falhas: 2"){
            digitalWrite(3, HIGH); //Liga +um LED vermelho
        }
        
        else if(falhas=="Falhas: 3"){
            digitalWrite(4, HIGH); //Liga +um LED vermelho
        }
    }
    else{
        digitalWrite(5, LOW);
    }
}