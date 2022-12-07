int fila[] = {22,23,24,25,26,27,28,29,30,31};
int column[] = {32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53};
int cont = 0;
unsigned long tiempo;
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


String generarCadena(String frase)
{
    String cadena = "";
    for (int i = 0; i < 22; i++)
    {
        cadena += "000";
    }
    for (int i = 0; i < frase.length(); i++)
    {
        if (frase[i] == 'A')
        {
            cadena += "1FF2102102101FF";
        }
        else if (frase[i] == 'B')
        {
            cadena += "3FF2212212211DE";
        }
        else if (frase[i] == 'C')
        {
            cadena += "1FE201201201186";
        }
        else if (frase[i] == 'D')
        {
            cadena += "3FF2012011020FC";
        }
        else if (frase[i] == 'E')
        {
            cadena += "3FF221221221201";
        }
        else if (frase[i] == 'F')
        {
            cadena += "3FF220220220200";
        }
        else if (frase[i] == 'G')
        {
            cadena += "1FE20122122123E";
        }
        else if (frase[i] == 'H')
        {
            cadena += "3FF0200200203FF";
        }
        else if (frase[i] == 'I')
        {
            cadena += "2012013FF201201";
        }
        else if (frase[i] == 'J')
        {
            cadena += "21F2013FF200200";
        }
        else if (frase[i] == 'K')
        {
            cadena += "3FF060090108207";
        }
        else if (frase[i] == 'L')
        {
            cadena += "3FF001001001001";
        }
        else if (frase[i] == 'M')
        {
            cadena += "3FF1000801003FF";
        }
        else if (frase[i] == 'N')
        {
            cadena += "3FF1000FE0013FF";
        }
        else if (frase[i] == 'Ñ')
        {
            cadena += "2FF28027E2012FF";
        }
        else if (frase[i] == 'O')
        {
            cadena += "1FE3032013031FE";
        }
        else if (frase[i] == 'P')
        {
            cadena += "3FF2202202201C0";
        }
        else if (frase[i] == 'Q')
        {
            cadena += "1FE20220A2061FF";
        }
        else if (frase[i] == 'R')
        {
            cadena += "3FF2202302281C7";
        }
        else if (frase[i] == 'S')
        {
            cadena += "1C622122122119E";
        }
        else if (frase[i] == 'T')
        {
            cadena += "2002003FF200200";
        }
        else if (frase[i] == 'U')
        {
            cadena += "3FE0010010013FE";
        }
        else if (frase[i] == 'V')
        {
            cadena += "3FC0020010023FC";
        }
        else if (frase[i] == 'W')
        {
            cadena += "3FF0020040023FF";
        }
        else if (frase[i] == 'X')
        {
            cadena += "38F05002005038F";
        }
        else if (frase[i] == 'Y')
        {
            cadena += "38004003F040380";
        }
        else if (frase[i] == 'Z')
        {
            cadena += "203205279281301";
        }
        else if (frase[i] == '0')
        {
            cadena += "1FE2012012011FE";
        }
        else if (frase[i] == '1')
        {
            cadena += "0400801002003FF";
        }
        else if (frase[i] == '2')
        {
            cadena += "1C32052092111E1";
        }
        else if (frase[i] == '3')
        {
            cadena += "1262212212211DE";
        }
        else if (frase[i] == '4')
        {
            cadena += "0600A01202203FF";
        }
        else if (frase[i] == '5')
        {
            cadena += "3E322122122121E";
        }
        else if (frase[i] == '6')
        {
            cadena += "3FF22122122121E";
        }
        else if (frase[i] == '7')
        {
            cadena += "2002202202203FF";
        }
        else if (frase[i] == '8')
        {
            cadena += "3DF2212212213DF";
        }
        else if (frase[i] == '9')
        {
            cadena += "3E02202202203FF";
        }
        else if (frase[i] == '=')
        {
            cadena += "048048048048048";
        }
        else if (frase[i] == '%')
        {
            cadena += "18118E0301C6206";
        }
        else if (frase[i] == '&')
        {
            cadena += "0CC13222D142085";
        }
        else if (frase[i] == '#')
        {
            cadena += "0443FF0443FF044";
        }
        else if (frase[i] == '!')
        {
            cadena += "0000003FA000000";
        }
        else if (frase[i] == '?')
        {
            cadena += "0C010020D1100E0";
        }
        else if (frase[i] == '+')
        {
            cadena += "0100100FE010010";
        }
        else if (frase[i] == '-')
        {
            cadena += "000010010010000";
        }
        else if (frase[i] == '*')
        {
            cadena += "1500E01F00E0150";
        }
        else if (frase[i] == '/')
        {
            cadena += "00100E0301C0200";
        }
        else if (frase[i] == '^')
        {
            cadena += "0200C01000C0020";
        }
        else if (frase[i] == ' ')
        {
            cadena += "000000000";
        }
        else
        {
            cadena += "0EC1122391120EC"; //sorpresa :v
        }
        cadena += "000000";
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
          //tiempo = millis();
          //while(millis() < 1+tiempo){}
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
