int led = 10; // Declaração da variável 'led' e atribuição do valor 10, que representa o pino digital ao qual o LED está conectado

void setup() {
  pinMode(led, OUTPUT); // Configura o pino 'led' como saída, para controlar o LED
}

void loop() {
  digitalWrite(led, HIGH); // Liga o LED, colocando o pino 'led' em nível alto (HIGH)
  delay(2000); // Aguarda 2000 milissegundos (2 segundos)

  digitalWrite(led, LOW); // Desliga o LED, colocando o pino 'led' em nível baixo (LOW)
  delay(2000); // Aguarda 2000 milissegundos (2 segundos)
}
