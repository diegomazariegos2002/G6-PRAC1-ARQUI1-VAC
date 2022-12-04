int fila[] = {22,23,24,25,26,27,28,29,30,31};
int column[] = {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
int cont = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT);
  for(int i = 0; i < 10 ; i++){
    pinMode(fila[i], OUTPUT);
    digitalWrite(fila[i], HIGH);
    
  }
  for(int i = 0; i < 22 ; i++){
    pinMode(column[i], OUTPUT);
    digitalWrite(column[i], LOW);
   }
}


String generarCadena(String frase){
  String cadena ="";
  for(int i =0; i < 22; i++){
    cadena+="0000000000";
    }
  for(int i =0; i < frase.length() ; i++){
    if (frase[i] == 'A'){
      cadena += "001111111100111111111100011000110001100011000110001100011000110001100000111111110011111111";
    }
    else if (frase[i] == 'E'){
      cadena += "111111111111111111111100100011110010001111001000111100100011110010001111001000111100100011";
      }
    else if (frase[i] == 'D'){
      cadena += "111111111111111111111100000011110000001111000000111100000011011111111001111111100111111110";
      }
    cadena +="0000000000";
    cadena +="0000000000";
    }
    return cadena;
  }

void loop() {
  // put your main code here, to run repeatedly:
  int valor = digitalRead(A1);
  String frase = "ade";
  frase.toUpperCase();
  String cadena = generarCadena(frase);

  if (valor == HIGH){
    Serial.println(cadena);
  for (int c = 21; c >= 0 ; c--){
    digitalWrite(column[c],HIGH);
    for (int f = 0; f < 10 ; f++){
      if(cadena[cont%cadena.length()] == '1'){
      digitalWrite(fila[f],LOW);
      delay(2);
      digitalWrite(fila[f],HIGH);
      }
      cont++;
    }
    digitalWrite(column[c],LOW);
  }
  cont = cont - 210;
  }
}