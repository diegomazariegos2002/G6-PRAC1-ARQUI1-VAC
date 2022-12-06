int fila[] = {22,23,24,25,26,27,28,29,30,31};
int column[] = {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
int cont = 0;
String frase;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, INPUT); 
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
  for(int i =0; i < 22 ; i++){
    cadena += "000";
    }
  for(int i =0; i < frase.length() ; i++){
    if (frase[i] == 'A'){
      cadena += "1FF2102102101FF";
    }
    else if (frase[i] == 'B'){
      cadena += "3FF2212212211DE";
      }
    else if (frase[i] == 'C'){
      cadena += "1FE201201201186";
      }
    else if (frase[i] == 'D'){
      cadena += "3FF2012011020FC";
      }      
    else if (frase[i] == 'E'){
      cadena += "3FF221221221201";
      }
    else if (frase[i] == 'F'){
      cadena += "3FF220220220200";
      }
    else if (frase[i] == 'G'){
      cadena += "1FE20122122123E";
      }
    
    cadena +="000000";
    }
    return cadena;
  }

String generarBinario(String hexdec){
  String cadena ="";
  int i = 0;
 
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            cadena+="0000";
            break;
        case '1':
            cadena+="0001";
            break;
        case '2':
            cadena+="0010";
            break;
        case '3':
            cadena+="0011";
            break;
        case '4':
            cadena+="0100";
            break;
        case '5':
            cadena+="0101";
            break;
        case '6':
            cadena+="0110";
            break;
        case '7':
            cadena+="0111";
            break;
        case '8':
            cadena+="1000";
            break;
        case '9':
            cadena+="1001";
            break;
        case 'A':
        case 'a':
            cadena+="1010";
            break;
        case 'B':
        case 'b':
            cadena+="1011";
            break;
        case 'C':
        case 'c':
            cadena+="1100";
            break;
        case 'D':
        case 'd':
            cadena+="1101";
            break;
        case 'E':
        case 'e':
            cadena+="1110";
            break;
        case 'F':
        case 'f':
            cadena+="1111";
            break;
        default:
            break;
        }
        i++;
    }
    return cadena;
  }



void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() == 0){}
  frase = Serial.readString();
  frase.toUpperCase();
  String cadena = generarCadena(frase);

  while (digitalRead(13) == HIGH){
  for (int c = 21; c >= 0 ; c--){
    digitalWrite(column[c],HIGH);
    String hexa = "";
    hexa+=cadena[cont%cadena.length()];
    hexa+=cadena[(cont+1)%cadena.length()];
    hexa+=cadena[(cont+2)%cadena.length()];
    String letraBinario = generarBinario(hexa); 
    letraBinario = letraBinario.substring(2, letraBinario.length());
    for (int f = 0; f < 10 ; f++){
        if(letraBinario[f] == '1'){
          digitalWrite(fila[f],LOW);
          delay(1);
          digitalWrite(fila[f],HIGH);
       }
    }
    cont = cont + 3;
    digitalWrite(column[c],LOW);
  }
  cont = cont - 63;
  }
  cont = 0;
}
