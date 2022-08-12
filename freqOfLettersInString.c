#include<stdio.h>
#include<string.h>

int main(){
    int i,freq[26];
    //storing freq of each letter in an array
    //where 0th index stores freq of a or A
    //and 25th index stores freq of z or Z and likewise
    for(i=0;i<26;i++)
       freq[i]=0;//assuming freq of each letter to 0
    char *str;
    printf("Please input a string:\n");
    gets(str);//scaning sentence
    for(i=0;i<strlen(str);i++){//checking occurance of letters
       //if letter is between a or z increase freq of corresponding letter
       if(str[i]>='a' && str[i]<='z')
         freq[str[i]-'a']++;
       //if letter is between A or Z increase freq of corresponding letter
       else if(str[i]>='A' && str[i]<='Z')
         freq[str[i]-'A']++;
    }
    //printing freq of each letter
    for(i=0;i<26;i++)
       printf("Letter %c or %c appears %d times\n",'a'+i,'A'+i,freq[i]);
    return 0;
}