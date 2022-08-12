#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//stac struct
struct stack{int size;
             int top;
             int *data;}; 
struct stack s;
//push
void push(struct stack *s, int t)
{
 if((1+s->top)<(s->size))
  {s->top++;
   
  s->data[s->top]=t; 
  }
 else {s->size=s->size*2; s->data=(int*)realloc(s->data,s->size*sizeof(int));
      s->top++;
      s->data[s->top]=t;  
      }
}
//pop
int pop(struct stack *s)
{if(s->top>=0)
 {s->top--; return(s->data[s->top+1]); }
}
//IsDig fun
int IsDig(char c)
{if(c<=57&&c>=48)
return 1;
else return 0;
}
//main
main()
{FILE *f;
char pfx[20]; int a,b,r,i,l;
s.top=(-1); s.size=10;
s.data=(int*)malloc(s.size*sizeof(int));
f=fopen("xprsn","r");
fscanf(f,"%s\n",pfx);
//printf("enter xprsn ");
//gets(pfx); 
l=strlen(pfx);
for(i=0;i<l;i++)
{if(IsDig(pfx[i]))
 {a=pfx[i]-'0';
 push(&s,a);}
 else {
      switch(pfx[i]) 
       {case '+': a=pop(&s); 
                   b=pop(&s);  r=a+b; 
                   break;
       case '-': b=pop(&s); 
                 a=pop(&s);  r=a-b; 
                 break;
       case '*': a=pop(&s);  
                 b=pop(&s);  r=a*b; 
                 break;
       case '/': b=pop(&s); 
                  a=pop(&s);  r=a/b; 
                break;
       }
      push(&s,r);       
     }
}
r=pop(&s); 
printf("result = %d\n",r);
} 
