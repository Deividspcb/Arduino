#define an5 A5

void setup() {
  pinMode(an5, INPUT);    // Configura o pino an5 (A5) como entrada.
  Serial.begin(9600);     // Inicia a comunicação serial com uma taxa de transmissão de 9600 bps.
}

void loop() {
  Serial.println(analogRead(an5)); // Lê o valor analógico do pino an5 (A5) e imprime na porta serial.
  delay(100);                      // Aguarda 100 milissegundos antes de repetir o loop.
}
