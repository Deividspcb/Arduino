#define led 3          // Define o pino 3 como o pino do LED
#define bottom 4       // Define o pino 4 como o pino do botão
int btnclicado = 0;    // Variável para indicar se o botão foi clicado
int btnliberado = 0;   // Variável para indicar se o botão foi liberado

// Função para alternar o estado do LED
void trocaled() {
  if (digitalRead(led) == HIGH) { // Se o LED estiver ligado
    digitalWrite(led, LOW);       // Desliga o LED
  } else {
    digitalWrite(led, HIGH);      // Liga o LED
  }
}

void keyup() {
  // Se o botão foi clicado e liberado
  if ((btnclicado == 1) && (btnliberado == 1)) {
    btnclicado = 0;     // Reseta a variável de clique do botão
    btnliberado = 0;    // Reseta a variável de liberação do botão
    trocaled();         // Alterna o estado do LED
  }
}

void setup() {
  // Configura o pino do LED como saída
  pinMode(led, OUTPUT);
  // Configura o pino do botão como entrada
  pinMode(bottom, INPUT);
}

void loop() {
  // Verifica o estado do botão
  if (digitalRead(bottom) == HIGH) {  // Corrigido de digitalReal para digitalRead
    btnclicado = 1;   // Define que o botão foi clicado
    btnliberado = 0;  // Reseta a variável de liberação
  } else {
    btnliberado = 1;  // Define que o botão foi liberado
  }
  keyup(); // Corrigido de keyuo para keyup
}
