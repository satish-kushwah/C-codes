#include "stdio.h"
#include "math.h"

int main() {
    char hexnum[20];
    int decnum=0,l=0;
    printf("Please input a hex number: ");
  	scanf("%s",hexnum);
  	for(int i=0; hexnum[i]!='\0'; i++) {
  		l++;
  	}
  	for(int i=0; i<l; i++) {
  		switch(hexnum[i]){
  			case '0': decnum=decnum+0*pow(16,(l-i-1)); break; 
  			case '1': decnum=decnum+1*pow(16,(l-i-1)); break;
  			case '2': decnum=decnum+2*pow(16,(l-i-1)); break;
  			case '3': decnum=decnum+3*pow(16,(l-i-1)); break;
  			case '4': decnum=decnum+4*pow(16,(l-i-1)); break;
  			case '5': decnum=decnum+5*pow(16,(l-i-1)); break;
  			case '6': decnum=decnum+6*pow(16,(l-i-1)); break;
  			case '7': decnum=decnum+7*pow(16,(l-i-1)); break;
  			case '8': decnum=decnum+8*pow(16,(l-i-1)); break;
  			case '9': decnum=decnum+9*pow(16,(l-i-1)); break;
  			case 'A': decnum=decnum+10*pow(16,(l-i-1)); break;
  			case 'B': decnum=decnum+11*pow(16,(l-i-1)); break;
  			case 'C': decnum=decnum+12*pow(16,(l-i-1)); break;
  			case 'D': decnum=decnum+13*pow(16,(l-i-1)); break;
  			case 'E': decnum=decnum+14*pow(16,(l-i-1)); break;
  			case 'F': decnum=decnum+15*pow(16,(l-i-1)); break;
  		}	
  	}
  	printf("Its corresponding decimal is %d\n",decnum);
    return 0;
}