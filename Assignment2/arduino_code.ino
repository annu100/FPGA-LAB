#include<Arduino.h>
#define A 2
#define B 3
#define C 4
#define D 5
#define NAND_OUTPUT 12

//defining Variables

int a , b, c ,d , kmap_output , nand_output, temp1,temp2;

//Function for NAND

int NAND(int i1 , int i2)
{
        return !(i1 && i2);
}

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(NAND_OUTPUT,OUTPUT);
  pinMode(A,INPUT);
  pinMode(B,INPUT);
  pinMode(C,INPUT);
  pinMode(D,INPUT);


  // put your setup code here, to run once:
}

void loop() {
        a = digitalRead(A);
        b = digitalRead(B);
        c = digitalRead(C);
        d = digitalRead(D);

        kmap_output = ((a|d)&((~a)|b)&((~b)|(~c))&(b|c|(a))&(a|c|(~d)));

        temp1=NAND(NAND(a,b),(!c));
        temp2=NAND(NAND((!a),(!b)),NAND(c,d));
        nand_output = NAND(temp1,temp2);

        if (kmap_output ==1)
                digitalWrite(LED_BUILTIN,HIGH);
        else
                digitalWrite(LED_BUILTIN, LOW);
        if(nand_output ==1)
                digitalWrite(NAND_OUTPUT, HIGH);
        else
                digitalWrite(NAND_OUTPUT,LOW);
}
