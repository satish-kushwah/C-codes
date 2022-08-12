//remove subs
#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct {char temp[15];}ssent[20];
main()
{
char s[80], subs[10]; int k=0,i=0,j=0; 
printf("entr string: ");
gets(s); 
printf("remove pattern "); 
gets(subs);
while(s[i]!='\0')
{while(!isspace(s[i]))
  {ssent[j].temp[k]=s[i]; i++; k++; }
 k=0; j++; i++; 
}
for(i=0;i<=(j-1);i++)
{if(strcmp(ssent[i].temp,subs)!=0)
printf("%s ",ssent[i].temp);
}
printf("\n");
}
