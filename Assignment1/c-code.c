/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

// function for NAND  operation
bool NAND(bool x,bool y){
    bool z=!(x && y);
    return z;
}
bool NAND2(bool x,bool y, bool z)
{
    bool r=!(x&&y&&z);
    return r;
}

int main() {
    unsigned char X; //output
    unsigned char X_; //output
    unsigned char one = 0x01;//used for displaying the output in bit
    unsigned char  A=0x00,B=0x00,C=0x01,D=0x01; //inputs in hex
    //Calculated POS EXPRESSION IS
    X=((A|D)&((~A)|B)&((~B)|(~C))&(B|C|(A))&(A|C|(~D)));
    printf("%x%x%x%x",one&A,one&B,one&C,one&D);
    printf(" ");
    printf("%x\n" ,one&X);


  

  //Implementation of POS using NAND gate
   //X_=((NAND(NAND(A,B),(~C)),NAND((~A),NAND((~B),NAND(C,D))));
   X_=NAND((!A),(!B))&NAND(A,(!B))&NAND(B,C)&NAND2((!A),(!B),(!C))&NAND2((!A),(!C),D);
   printf("OUTPUT:%d",X_);


return 0;

}
