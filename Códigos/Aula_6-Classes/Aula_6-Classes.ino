´´#define ledR 2  // Define o pino do LED vermelho
#define ledB 3  // Define o pino do LED azul
#define ledG 4  // Define o pino do LED verde
#define botao 7  // Define o pino do botão

// Classe para gerenciar o botão
class Btn {
  public:
    int btnclicado, btnliberado, pino;  // Variáveis para armazenar o estado do botão e o pino do botão
    
    // Construtor da classe Btn
    Btn(int p) {
      pino = p;  // Define o pino do botão
      btnclicado = btnliberado = 0;  // Inicializa os estados do botão como 0 (não clicado/não liberado)
    }
    
    // Método para verificar se o botão foi pressionado e liberado
    bool press() {
      if (digitalRead(pino) == HIGH) {  // Se o botão está pressionado
        btnclicado = 1;  // Define btnclicado como 1
        btnliberado = 0;  // Define btnliberado como 0
      } else {  // Se o botão não está pressionado
        btnliberado = 1;  // Define btnliberado como 1
      }
      // Se o botão foi pressionado e liberado
      if ((btnclicado == 1) && (btnliberado == 1)) {
        btnclicado = 0;  // Reseta btnclicado para 0
        btnliberado = 0;  // Reseta btnliberado para 0
        return true;  // Retorna true indicando que o botão foi pressionado e liberado
      } else {
        return false;  // Retorna false indicando que o botão não foi pressionado e liberado
      }
    }
};

// Classe para gerenciar as cores dos LEDs
class Cor {
  public:
    int pinoR, pinoB, pinoG, ciclo, maximo;  // Variáveis para armazenar os pinos dos LEDs, o ciclo atual e o número máximo de ciclos
    
    // Construtor da classe Cor
    Cor(int pr, int pb, int pg) : pinoR(pr), pinoG(pg), pinoB(pb) {
      ciclo = 0;  // Inicializa o ciclo como 0
      maximo = 3;  // Define o número máximo de ciclos como 3 (vermelho, azul, verde)
    }
    
    // Método para trocar a cor do LED
    void trocaLed() {
      if (ciclo == 0) {
        corLed(HIGH, LOW, LOW);  // Liga o LED vermelho
      } else if (ciclo == 1) {
        corLed(LOW, LOW, HIGH);  // Liga o LED azul
      } else if (ciclo == 2) {
        corLed(LOW, HIGH, LOW);  // Liga o LED verde
      }
      ciclo++;  // Incrementa o ciclo
      if (ciclo > maximo - 1) {
        ciclo = 0;  // Reseta o ciclo se ultrapassar o número máximo
      }
    }
    
  private:
    // Método para definir a cor do LED
    void corLed(int r, int b, int g) {
      digitalWrite(pinoR, r);  // Define o estado do LED vermelho
      digitalWrite(pinoB, b);  // Define o estado do LED azul
      digitalWrite(pinoG, g);  // Define o estado do LED verde
    }
};

// Instancia o objeto btn da classe Btn para gerenciar o botão
Btn btn(botao);
// Instancia o objeto cor da classe Cor para gerenciar as cores dos LEDs
Cor cor(ledR, ledG, ledB);

void setup() {
  // Configura os pinos dos LEDs como saída
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  // Configura o pino do botão como entrada
  pinMode(botao, INPUT);
}

void loop() {
  // Verifica continuamente o estado do botão e troca a cor do LED quando o botão é pressionado e liberado
  if (btn.press()) {
    cor.trocaLed();
  }
}
