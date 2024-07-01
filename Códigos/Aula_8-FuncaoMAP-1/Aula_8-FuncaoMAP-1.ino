#define pot A5                      // Define a macro 'pot' para representar o pino A5
int leds[] = { 2, 3, 4, 5, 6, 7 };  // Define um array de pinos de LEDs
int val;                            // Declaração da variável 'val' para armazenar o valor lido do potenciômetro

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 6; i++) {  // Declaração da variável 'i' no loop for
    pinMode(leds[i], OUTPUT);    // Configura os pinos dos LEDs como saída
  }
  pinMode(pot, INPUT);           // Configura o pino 'pot' (A5) como entrada
}

void acender(int x) {
  int i;
  for (i = 0; i < x; i++) {
    digitalWrite(leds[i], HIGH);  // Acende os LEDs até o valor x
  }
  for (i = x; i < 6; i++) {
    digitalWrite(leds[i], LOW);   // Apaga os LEDs a partir do valor x
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(pot);               // Lê o valor analógico do pino 'pot' (A5)
  acender(map(analogRead(pot), 0, 1023, 0, 6));    // Mapeia o valor lido para o intervalo de 0 a 6 e chama a função acender
}
