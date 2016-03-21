#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_AZUL 4
#define LED_VERMELHO 5
#define TAMANHO_SEQUENCIA 4
#define BOTAO_VERDE 8
#define BOTAO_AMARELO 9
#define BOTAO_AZUL 10
#define BOTAO_VERMELHO 11

int sequenciaLuzes[TAMANHO_SEQUENCIA]; //Define uma variavel sequencia em escopo global

void setup() {
   iniciaPortas();
   iniciaJogo();
   Serial.begin(9600);
}

void loop() {
    int estado = digitalRead(BOTAO_VERDE);
    Serial.println(estado);
}

//Função Para piscar os leds
//@param = Número da porta digital do Led
void piscaLed(int portaLed){
    digitalWrite(portaLed, HIGH); //Altera a porta para ligada
    delay(1000); //Espera 1 Sec
    digitalWrite(portaLed, LOW); //Altera a porta para desligada
    delay(500); //Espera 0,5 sec
    Serial.println(portaLed); //Imprime a porta
  }
  
//Define e Inicia todas as portas que serão utilizadas
void iniciaPortas() {
   pinMode(LED_VERDE, OUTPUT); 
   pinMode(LED_AMARELO, OUTPUT); 
   pinMode(LED_AZUL, OUTPUT); 
   pinMode(LED_VERMELHO, OUTPUT); 
   pinMode(BOTAO_VERDE,INPUT_PULLUP);
   pinMode(BOTAO_AMARELO,INPUT_PULLUP);
   pinMode(BOTAO_VERMELHO,INPUT_PULLUP);
   pinMode(BOTAO_AZUL,INPUT_PULLUP);
  }
//Define uma sequencia que os leds piscaram no começo do jogo
void iniciaJogo() {
    sequenciaLuzes[0] = LED_AZUL;
    sequenciaLuzes[1] = LED_AMARELO;
    sequenciaLuzes[2] = LED_VERMELHO;
    sequenciaLuzes[3] = LED_VERDE;
  }
//Define uma sequencia onde todos os leds piscam Simultaneamente
void piscaSequencia2() { 
    //Ascende todos os leds
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE, HIGH);
    delay(1000); //Espera 1sec
    //Apaga todos os leds
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, LOW);
  }
  
