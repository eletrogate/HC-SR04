int PinTrigger = 2; // Pino usado para disparar os pulsos do sensor
int PinEcho = 3; // pino usado para ler a saida do sensor
float TempoEcho = 0;
const float VelocidadeSom_mpors = 340; // em metros por segundo
const float VelocidadeSom_mporus = 0.000340; // em metros por microsegundo

void setup(){
  // Configura pino de Trigger como saída e inicializa com nível baixo
  pinMode(PinTrigger, OUTPUT);
  digitalWrite(PinTrigger, LOW);
  pinMode(PinEcho, INPUT); // configura pino ECHO como entrada

  // Inicializa a porta serial
  Serial.begin(9600);

  delay(100);
}

void loop(){
  // Envia pulso para o disparar o sensor
  DisparaPulsoUltrassonico();
  // Mede o tempo de duração do sinal no pino de leitura(us)
  TempoEcho = pulseIn(PinEcho, HIGH);
  Serial.println("Distancia em metros: ");
  Serial.println(CalculaDistancia(TempoEcho));
  Serial.println("Distancia em centimetros: ");
  Serial.println(CalculaDistancia(TempoEcho)*100);

  // aguarda um pouco antes de começar tudo de novo
  delay(2000);
}

// Funçao para enviar o pulso de trigger
void DisparaPulsoUltrassonico(){
  // Para fazer o HC-SR04 enviar um pulso ultrassonico, nos temos
  // que enviar para o pino de trigger um sinal de nivel alto
  // com pelo menos 10us de duraçao
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
  }

// Função para calcular a distancia em metros
float CalculaDistancia(float tempo_us){
  return((tempo_us*VelocidadeSom_mporus)/2);
}
