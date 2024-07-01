#define ldr A0     // Define a macro 'ldr' para representar o pino A0 (sensor de luz)
#define led 2      // Define a macro 'led' para representar o pino 2 (LED)

int vldr = 0;     // Declaração e inicialização da variável 'vldr' que armazenará o valor lido do sensor de luz

void setup() {
  // put your setup code here, to run once:
  pinMode(ldr, INPUT);    // Configura o pino 'ldr' (A0) como entrada
  pinMode(led, OUTPUT);   // Configura o pino 'led' (2) como saída
  Serial.begin(9600);     // Inicia a comunicação serial a 9600 bps
}

void loop() {
  // put your main code here, to run repeatedly:
  vldr = analogRead(ldr);  // Lê o valor analógico do pino 'ldr' (A0) e armazena em 'vldr'
  if (vldr > 950) {       // Se o valor lido for maior que 950
    digitalWrite(led, LOW); // Apaga o LED
  } else {                 // Caso contrário
    digitalWrite(led, HIGH);// Acende o LED
  }
  Serial.println(vldr);    // Imprime o valor lido do sensor de luz na Serial Monitor
  delay(100);              // Aguarda 100 milissegundos antes de repetir o loop
}
