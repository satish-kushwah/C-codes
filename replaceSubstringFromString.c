#include "stdio.h" //for standard input output
#include "string.h" //for strlen function
//main function
int main(){   
    char str[1000],substr[6]="EGYPT",newstr[1000]; //declaration of string variable 
    int i=0,j=0;
    printf("Enter string to replace EGYPT: ");
    scanf("%s",str); //taking input string from user
    //running while loop until string ends
    //iterating through string char by char
    while(i < strlen(str)){  
    	//checking for "EGYPT" substring
    	if(i<(strlen(str)-5) && str[i]=='E' && str[i+1]=='G' && str[i+2]=='Y' && str[i+3]=='P' && str[i+4]=='T'){
    		newstr[j]=' '; //if EGYPT found then replace by space
    		i=i+5;       //increasing index of str by 5 because EGYPT is of length 5
    		j=j+1;  //increase index of newstr by 1
    	}
    	else{
		    newstr[j]=str[i]; //if EGYPT not found at current index copy char to newstr
		    i=i+1; //increase index of str by 1
		    j=j+1; //increase index of newstr by 1
		}
    }
    printf("%s",newstr ); //printing newstr after replacing EGYPT by space from old str
    return 0; //returning 0 in main and exit program
}