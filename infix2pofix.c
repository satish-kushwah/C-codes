#include<stdio.h>
struct stack{int top;
             char data[50];}; 
struct stack s;
int i,j=0;
char infx[50],pstfx[50];
//push
void push(char t)
{if((1+s.top)<50) 
  {s.top++;
  s.data[s.top]=t; 
  }
}
//pop
char pop()
{if(s.top>=0)
 {s.top--; return(s.data[s.top+1]); }
else return('o');
}
//cap
char cap()
{if(s.top>=0)
 return(s.data[s.top]);
else return('o');
}
//IsDig fun
int IsDig(char c)
{if(c<=57&&c>=48)
return 1;
else return 0;
}
//HasHP
int HasHP(char a, char b)
{if(b=='o') return 1;
else if(a=='/') return 1;
else if(a=='*'&&b!='/') return 1;
else if(a=='-'&&b=='+') return 1;
else return 0;
}
//put
void put()
{pstfx[j]=pop(); j++;
if(!HasHP(infx[i],cap())&&cap()!='(')
put(); 
return;
}

//main
main()
{FILE *f;
s.top=(-1); 
printf("enter infx ");
scanf("%s",infx);
for(i=0;infx[i]!='\0';i++)
{
if(IsDig(infx[i])==1)
{pstfx[j]=infx[i]; j++; }
else if(infx[i]=='(')
push(infx[i]);
else if(cap()=='(')
push(infx[i]);
else if(HasHP(infx[i],cap())==1&&infx[i]!=')')
push(infx[i]);
else if(infx[i]==')')
{while(1)
 {if(cap()=='(') {pop(); break;}
 pstfx[j]=pop(); j++;
 }
}
else if(HasHP(infx[i],cap())==0)
 { put(); push(infx[i]);}
}
while(cap()!='o')
{pstfx[j]=pop(); j++;}
f=fopen("xprsn","w");
fprintf(f,"%s\n",pstfx);
printf("postfix exprn is %s\n",pstfx);
}
