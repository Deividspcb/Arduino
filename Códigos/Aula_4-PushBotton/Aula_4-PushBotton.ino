#define led 3       // Define a macro 'led' para representar o pino 3
#define bottom 4    // Define a macro 'bottom' para representar o pino 4 (botão)
int btnclicado = 0; // Variável para indicar se o botão foi clicado
int btnliberado = 0;// Variável para indicar se o botão foi liberado

void trocaled() {
  // Função para alternar o estado do LED
  if (digitalRead(led) == HIGH) {
    digitalWrite(led, LOW);  // Se o LED está aceso, apaga
  } else {
    digitalWrite(led, HIGH); // Se o LED está apagado, acende
  }
}

void keyup() {
  // Função para verificar se o botão foi clicado e liberado
  if ((btnclicado == 1) && (btnliberado == 1)) {
    btnclicado = 0;
    btnliberado = 0;
    trocaled(); // Alterna o estado do LED
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);   // Configura o pino 'led' como saída
  pinMode(bottom, INPUT); // Configura o pino 'bottom' como entrada
}

void loop() {
  // put your main code here, to run repeatedly
  if (digitalRead(bottom) == HIGH) {
    btnclicado = 1;      // Se o botão está pressionado, indica que foi clicado
    btnliberado = 0;     // Reseta a variável de liberação
  } else {
    btnliberado = 1;     // Se o botão está liberado, indica que foi liberado
  }
  keyup();               // Chama a função para verificar e alternar o LED
}
