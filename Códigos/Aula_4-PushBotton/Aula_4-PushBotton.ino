#define led 3
#define bottom 4
int btnclicado = 0;
int btnliberado = 0;

void trocaled() {
  if (digitalRead(led) == HIGH) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}
void keyup(){
  if((btnclicado==1)and(btnliberado==1)){
    btnclicado = 0;
    btnliberado = 0;
    trocaled();
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(bottom, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  if (digitalRead(bottom) == HIGH){
    btnclicado =1;
    btnliberado = 0;
  } else {
    btnliberado =1;
  }
  keyup();
}
