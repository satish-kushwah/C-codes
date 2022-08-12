#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct name {char s[10];} mydic[100];	
main()
{	
char t[10],nm[10]; 
FILE *dic;
int i,n,j,c,tr;
//dic load
dic=fopen("dict.txt","r");
fscanf(dic,"%d\n",&n);
for(i=0;i<n;i++)
fscanf(dic,"%s\n",mydic[i].s);
//choice
do
{
printf("\n1 for adding new name\n2 for deleting a name\n3 to display all name\n0 to exit\n");
scanf("%d",&c);
switch (c)
{case 1: 
  {    printf("enter name: ");
       scanf("%s",nm);
       if(strcmp(mydic[0].s,nm)>0)
          {for(i=(n-1);i>=0;i--)
           strcpy(mydic[i+1].s,mydic[i].s);
           strcpy(mydic[0].s,nm);
          }
       else if(strcmp(nm,mydic[n-1].s)>0)
       strcpy(mydic[n].s,nm);
       else
        {
        for(i=0;i<(n-1);i++)
        if((strcmp(mydic[i].s,nm)<0)&&(strcmp(mydic[i+1].s,nm)>0))
         {  for(j=(n-1);j>=(i+1);j--)
         strcpy(mydic[j+1].s,mydic[j].s);   break;
         }
        strcpy(mydic[i+1].s,nm);
        }
     n++; 
  } break;
case 2:
        { if(n==0) {printf("no name\n"); break;}
         printf("enter name to delete: ");
         scanf("%s",nm);                  tr=0; 
         for(i=0;i<n;i++)
         if(strcmp(mydic[i].s,nm)==0) 
         {for(j=i;j<(n-1);j++)                
        strcpy(mydic[j].s,mydic[j+1].s);  tr=1; 
          }  if(tr==1) n--; 
       } break;

case 3: 
       {if(n==0) {printf("no name\n"); break;}
       for(i=0;i<n;i++)
       printf("%s\n",mydic[i].s); 
       } break;
case 0: goto write;
}
} while(c!=0);
write:
{dic=fopen("dict.txt","w");
fprintf(dic,"%d\n",n);
for(i=0;i<n;i++)
fprintf(dic,"%s\n",mydic[i].s); return;
}
}
