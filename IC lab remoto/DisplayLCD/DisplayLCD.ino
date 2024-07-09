#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int pot1 = 0;       // Valor lido do potenciômetro 1
int pot2 = 0;       // Valor lido do potenciômetro 2
float potPrev1 = 0; // Valor anterior do potenciômetro 1
int potPrev2 = 0;   // Valor anterior do potenciômetro 2

void setup() {
  lcd.begin(16, 2); // Inicializa o display com 16 colunas e 2 linhas
  lcd.clear();      // Limpa o display
  pinMode(A3, INPUT); 
  pinMode(A2, INPUT); 
}

void loop() {
  // Variáveis para somar as leituras dos potenciômetros
  int sumPot1 = 0;
  int sumPot2 = 0;
  
  // Melhor precisão leitura
  for (int i = 0; i < 20; i++) {
    sumPot1 += analogRead(A3);
    sumPot2 += analogRead(A2);
    delay(5); 
  }
  
  // Calcula a média das leituras
  pot1 = sumPot1 / 20;
  pot2 = sumPot2 / 20;

  // Mapeia as leituras
  float potMapped1 = map(pot1, 0, 1023, 200, 800) / 10.0;
  int potMapped2 = map(pot2, 0, 1023, 0, 1000) / 10 ;

  // Se o valor mapeado da frequência mudou, atualiza o display
  if (potPrev1 != potMapped1) {
    lcd.setCursor(0, 0);
    lcd.print("Freq: ");
    lcd.print(potMapped1);
    lcd.print(" Hz  "); 

    // Atualiza o valor anterior
    potPrev1 = potMapped1;
  }

  // Se o valor mapeado da tensão mudou, atualiza o display
  if (potPrev2 != potMapped2) {
    lcd.setCursor(0, 1);
    lcd.print("Tensao: ");
    lcd.print(potMapped2);
    lcd.print(" %   "); 

    // Atualiza o valor anterior
    potPrev2 = potMapped2;
  }

  delay(100);
}
