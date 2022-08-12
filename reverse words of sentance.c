#include "stdio.h"
#include "string.h"
int main(){
	char str[1000000]; 
	int i,j,l=0,r=-1;
	scanf("%[^\n]",str); //input string with space
	for (i =0 ; i <strlen(str) ; i++)
	{if(str[i]==' '){
		l=r+1; r=i;
		for(j=(r-1);j>=l;j--) //printing word in reverse
			printf("%c",str[j]);
		printf(" ");
		}
	}
	l=r+1; r=i;
	for(j=(r-1);j>=l;j--) //printing last word in reverse
		printf("%c",str[j]);
return 0;
}
