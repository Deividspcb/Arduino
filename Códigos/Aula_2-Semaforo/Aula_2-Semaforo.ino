// Definição dos pinos para cada LED
#define ledgreen 10
#define ledyellow 9
#define ledred 8

void setup() {
  // Configuração dos pinos como saídas
  pinMode(8, OUTPUT);   // Configura o pino 8 como saída, para controlar o LED vermelho
  pinMode(9, OUTPUT);   // Configura o pino 9 como saída, para controlar o LED amarelo
  pinMode(10, OUTPUT);  // Configura o pino 10 como saída, para controlar o LED verde
}

// Função para acender o LED vermelho por um período de tempo específico
void red(int tmp) {
  digitalWrite(8, HIGH);   // Liga o LED vermelho (pino 8)
  digitalWrite(9, LOW);    // Desliga o LED amarelo (pino 9)
  digitalWrite(10, LOW);   // Desliga o LED verde (pino 10)
  delay(tmp);              // Aguarda 'tmp' milissegundos
}

// Função para acender o LED verde por um período de tempo específico
void green(int tmp) {
  digitalWrite(8, LOW);    // Desliga o LED vermelho (pino 8)
  digitalWrite(9, LOW);    // Desliga o LED amarelo (pino 9)
  digitalWrite(10, HIGH);  // Liga o LED verde (pino 10)
  delay(tmp);              // Aguarda 'tmp' milissegundos
}

// Função para acender o LED amarelo por um período de tempo específico
void yellow(int tmp) {
  digitalWrite(8, LOW);    // Desliga o LED vermelho (pino 8)
  digitalWrite(9, HIGH);   // Liga o LED amarelo (pino 9)
  digitalWrite(10, LOW);   // Desliga o LED verde (pino 10)
  delay(tmp);              // Aguarda 'tmp' milissegundos
}

void loop() {
  red(5000);    // Chama a função 'red' para acender o LED vermelho por 5000 milissegundos (5 segundos)
  green(7000);  // Chama a função 'green' para acender o LED verde por 7000 milissegundos (7 segundos)
  yellow(2000); // Chama a função 'yellow' para acender o LED amarelo por 2000 milissegundos (2 segundos)
}
