/******************************************************************************

ANNU,EE21RESCH01010
*******************************************************************************/
#include<stdio.h>
#include<stdbool.h>
int main()
{
    //inputs declaration
    bool a=false,b,c,sop_res,nand_out;
    printf("A B C | ouput for SOP form -minterms output|-nand gate\n");

//taking three inputs ,possible 8 combinations
    for(int k=0;k<=7;++k)
    {   
		b=false;
		c=false;
		if(k>=4)
			a=true;
		if(k==0 || k==1 || k==3 || k==7) // minterm sops 
			b=true;
		if(k%2==1)
			c=true;
        sop_res=((!a)&(!b)&(!c))|((!a)&(!b)&c)|((!a)&b&c)|(a&b&c);
        //nand gate output
        nand_out=!((!((!a)&(!b)&(!c))))&(!((!a)&(!b)&c))&(!((!a)&b&c))&(!(a&b&c));
        printf("%d %d %d          %d                  %d\n", a,b,c,sop_res,nand_out);
        c=true;
    }
    return 0;
}