/******************************************************************************

ANNU,EE21RESCH01010
*******************************************************************************/
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// function for NOR operation
bool NAND(bool x,bool y){
    bool z=!(x && y);
    return z;
}

int main() {
    unsigned char X; //output
    unsigned char one = 0x01;//used for displaying the output in bit
    unsigned char  A=0x00,B=0x00,C=0x01,D=0x01; //inputs in hex
    //Calculated POS EXPRESSION IS
    X=((A|D)&((~A)|B)&((~B)|(~C))&(B|C|(A))&(A|C|(~D)));
    printf("%x%x%x%x",one&A,one&B,one&C,one&D);
    printf(" ");
    printf("%x\n" ,one&X);
    return 0;

  

  //Implementation of POS using NAND gate
   X=(NAND(NAND(A,B),(~C)),NAND((~A),NAND((~B),NAND(C,D))));
   printf("OUTPUT:%d",X);


return 0;

}
