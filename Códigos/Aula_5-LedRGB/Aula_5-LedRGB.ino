#define ledR 2
#define ledB 3
#define ledG 4
#define botao 7
#define maximo 7  // Ajustado para incluir todas as novas cores

int btnclicado = 0;
int btnliberado = 0;
int ciclo = 0;

// Funções para controlar os LEDs
void vermelho() {
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledG, LOW);
}
void verde() {
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledG, HIGH);
}
void azul() {
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledG, LOW);
}
void amarelo() {
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledG, HIGH);
}
void ciano() {
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledG, HIGH);
}
void magenta() {
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledG, LOW);
}
void branco() {
  digitalWrite(ledR, HIGH);
  digitalWrite(ledB, HIGH);
  digitalWrite(ledG, HIGH);
}

// Função para trocar o LED ligado
void trocaled() {
  if (ciclo == 0) {
    vermelho();
  } else if (ciclo == 1) {
    verde();
  } else if (ciclo == 2) {
    azul();
  } else if (ciclo == 3) {
    amarelo();
  } else if (ciclo == 4) {
    ciano();
  } else if (ciclo == 5) {
    magenta();
  } else if (ciclo == 6) {
    branco();
  }
  ciclo++;
  if (ciclo > maximo - 1) {
    ciclo = 0;
  }
}

// Função para verificar o estado do botão
void verificabtn() {
  if (digitalRead(botao) == HIGH) {
    btnclicado = 1;
    btnliberado = 0;
  } else {
    btnliberado = 1;
  }
  if ((btnclicado == 1) && (btnliberado == 1)) {
    btnclicado = 0;
    btnliberado = 0;
    trocaled();
  }
}

void setup() {
  // Configura os pinos como saída ou entrada
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  // Verifica o estado do botão repetidamente
  verificabtn();
}
