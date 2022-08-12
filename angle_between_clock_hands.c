//to cal ang btwn hour nd min hand
#include<stdio.h>
#include<math.h>
main()
{float m,h,ang;
printf("enter time in hh-mm\n");
scanf("%f-%f",&h,&m);
h=.5*(h*60+m); while(h>=360) h=h-360;
m=6*m; while(m>=360) m=m-360;
 ang=m-h; ang=sqrt(ang*ang);
while(ang>180) ang=360-ang;
printf("ang is %f degree\n",ang);
printf("\n");
system("pause");
}
