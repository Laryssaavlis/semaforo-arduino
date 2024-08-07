// Definindo os pinos dos LEDs
const int ledVermelho = 0; // D0
const int ledAmarelo = 1;  // D1
const int ledVerde = 2;    // D2

// Definindo o pino do sensor PIR
const int pirPin = 3; // D3

// Variável para armazenar o estado do sensor PIR
int pirState = LOW;

void setup() {
  // Configurando os pinos dos LEDs como saída
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  // Configurando o pino do sensor PIR como entrada
  pinMode(pirPin, INPUT);

  // Iniciando o LED vermelho aceso
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);

  // Iniciando a comunicação serial (opcional)
  Serial.begin(9600);
}

void loop() {
  // Lendo o estado do sensor PIR
  pirState = digitalRead(pirPin);
  Serial.println(pirState); // Exibe o estado do sensor PIR

  if (pirState == HIGH) {
    Serial.println("Movimento detectado! Esperando 4 segundos...");
    delay(4000); // Aguarda 4 segundos para confirmar a presença do objeto

    // Verifica se o objeto ainda está presente
    if (digitalRead(pirPin) == HIGH) {
      Serial.println("Presença confirmada. Acendendo LED verde.");
      digitalWrite(ledVermelho, LOW); // Apaga o LED vermelho
      digitalWrite(ledVerde, HIGH);   // Acende o LED verde

      delay(3000); // Mantém o LED verde aceso por 3 segundos

      // Apaga o LED verde e acende o LED vermelho novamente
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, HIGH);
      Serial.println("LED verde apagado. LED vermelho aceso novamente.");
    }
  }
  delay(100); // Pequeno delay para evitar leituras muito rápidas
}