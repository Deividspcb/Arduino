#define led 3       // Define 'led' como pino 3 no microcontrolador
#define maximo 32   // Define 'maximo' como o valor máximo de PWM
#define minimo 0    // Define 'minimo' como o valor mínimo de PWM
#define tmp 100     // Define 'tmp' como o tempo de atraso em milissegundos

void setup() {
  pinMode(led, OUTPUT); // Configura o pino 'led' como uma saída
}

void loop() {
  // Diminui gradualmente o brilho do LED de 'maximo' para 'minimo'
  for(int i = maximo; i > minimo; i--){
    analogWrite(led, i); // Define o brilho do LED para 'i'
    delay(tmp);          // Espera por 'tmp' milissegundos
  }
  
  // Aumenta gradualmente o brilho do LED de 'minimo' para 'maximo'
  for(int i = minimo; i < maximo; i++){
    analogWrite(led, i); // Define o brilho do LED para 'i'
    delay(tmp);          // Espera por 'tmp' milissegundos
  }
}
