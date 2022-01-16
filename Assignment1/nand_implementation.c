#include <stdio.h>

unsigned char nand(unsigned char a, unsigned char b){
    return ~(a&b);
}

int main()
{
	unsigned char A=0x01,B=0x01,C=0x00,D=0x00; //INPUTS TAKEN TO CHECK THE OUTPUT
	unsigned char one=0x01; //used for displaying the output in bit
	unsigned char output;
	unsigned char A1,A2;
	
	//NAND GATE IMPLEMENTATION
	A1=nand(nand(A,B),(!C));
	A2=nand(nand((!A),(!B)),nand(C,D));

	output=nand(A1,A2);
	
	//Implementation of POS using NAND gate and its output is
	printf("output using nand=%x\n",one&output);
	
	return 0;
}