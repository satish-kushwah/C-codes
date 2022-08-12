#include<time.h>
#include<stdlib.h>
#include<stdio.h>
main(register int ac, char *av[])
{struct timeval t1r,t2r,t1s,t2s,t1t,t2t;
                                        gettimeofday(&t1t, NULL);
FILE *fin,*fout;
register int t,i,j,larg; long *x,n;                                        
                                        gettimeofday(&t1r, NULL); //reading 
fin=fopen(av[1],"r");
if(fin==NULL) {printf("error-file do not exist"); return 0;}                          
fscanf(fin,"%ld\n",&n);
x=(long*)malloc(n*sizeof(long));
for(i=0;i<n;i++)
fscanf(fin,"%ld\n",(x+i));
                                        gettimeofday(&t2r, NULL);                           
                                        gettimeofday(&t1s, NULL); 
for(i=0;i<(n-1);i++)
{ larg=0;
 for(j=1;j<(n-i);j++)
  { if(*(x+j)>*(x+larg)) larg=j; }
 t=*(x+n-1-i); *(x+n-1-i)=*(x+larg); *(x+larg)=t;
}
                                        gettimeofday(&t2s, NULL);
fout=fopen(av[2],"w");
for(i=0;i<n;i++)
fprintf(fout,"%ld\n",*(x+i));                                           
printf ("read file time = %f seconds\n",
             (double) (t2r.tv_usec - t1r.tv_usec)/1000000+
             (double) (t2r.tv_sec - t1r.tv_sec));
                                         
printf ("sorting time = %f seconds\n",
             (double) (t2s.tv_usec - t1s.tv_usec)/1000000+
             (double) (t2s.tv_sec - t1s.tv_sec));
                                        gettimeofday(&t2t, NULL);
printf ("Total time = %f seconds\n",
             (double) (t2t.tv_usec - t1t.tv_usec)/1000000+
             (double) (t2t.tv_sec - t1t.tv_sec));
}
