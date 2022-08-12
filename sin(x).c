#include<stdio.h>
#include<math.h>
int main()
{float x,degree_x,term,mysin;
int n,i;
printf("Enter the value of n : ");
scanf("%d",&n);
printf("Enter degrees : ");
scanf("%f",&degree_x);
x=degree_x*3.14/180;
term=x; mysin=x;
for(i=0;i<(n-1);i++)
{term=-term*x*x/((2*i+2)*(2*i+3));
mysin=mysin+term;
}
printf("The sin value sin(%f) = %f\n",degree_x,mysin);
printf("The sin value using built-in sin(%f) = %f\n",degree_x,sin(x));
return 0;
}
