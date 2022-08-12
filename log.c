//log for any base
#include<stdio.h>
#include<math.h>
main()
{float n,p=0.0,i=0.0001,b; int c; 
printf("enter base of log: 1 for 10, 2 for e, any key for other ");
scanf("%d",&c);
if(c!=2&&c!=1)
{printf("enter base of log: ");
scanf("%f",&b);}
else {if(c==1) b=10.0;
      else b=2.71828;
     }
if(b<=1)
{printf("this base not allowewd \n"); return;}
printf("enter nu to get log on %g base ",b);
scanf("%f",&n);
if(n<1)
{printf("this number not allowewd\n"); return;}
while(pow(b,p)<n)
{p++;
 if(pow(b,p)>n)
   {p=p-1; break;}
 else if(pow(b,p)==n)
   {p=p;break;}
}
while(1)
 {p=p+i;
  if(pow(b,p)>n)
   {p=p-i; break;}
  else if(pow(b,p)==n)
   {p=p; break;	}
 }
printf("log%g,%g=%g\n",b,n,p);
}
