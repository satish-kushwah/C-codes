                             //tree implementation
#include"stac.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
struct timeval t1r,t2r,t1s,t2s,t1t,t2t;
typedef struct lnode {int data;struct lnode *lch; struct lnode *rch;}node;
node *root,*prnt,*temp; 
int t,n,i,count=0,level=0;                
FILE *fin,*fs;
//add node
void add (node *oprt)
{
if(oprt->data==0) {oprt->data=t; return;} //for root node insertion
else if(t<oprt->data)
 {if(oprt->lch==NULL)
    {oprt->lch=(node*)malloc(sizeof(node));
    oprt->lch->data=t; oprt->lch->lch=oprt->lch->rch=NULL; return;
    } 
add(oprt->lch);
 }
else if(t>=oprt->data)//duplicate entry is allowed, remove = if u dont want
 {if(oprt->rch==NULL)
    {oprt->rch=(node*)malloc(sizeof(node));
    oprt->rch->data=t; oprt->rch->lch=oprt->rch->rch=NULL; return;
    } 
add(oprt->rch);
 }
//else {printf("duplicate entry not allowed\n");count--;}
}

//search
node *search(node *oprt)
{
if(oprt->data==n) { push(oprt->data); return(oprt);} //node found
if(n<oprt->data) 
  {if(oprt->lch==NULL) return NULL;                  //node not found  
   push(oprt->data); prnt=oprt; level++; return(search(oprt->lch));}
if(n>oprt->data) 
  {if(oprt->rch==NULL)  return NULL;                 //node not found
   push(oprt->data); prnt=oprt; level++; return(search(oprt->rch));}
}

//findsmallest
node *smlst(node *oprt)
{if(oprt->data==0) return NULL;      //no data in tree
if(oprt->lch==NULL) return(oprt);    //return smalest
prnt=oprt; return(smlst(oprt->lch));
}                

//lrgest
node *largst(node *oprt)
{if(oprt->data==0) return NULL;      //no data in tree
if(oprt->rch==NULL) return(oprt);    //return largest
prnt=oprt; return(largst(oprt->rch));
}

//delete
void delete(node *oprt)
{if(root->lch==NULL&&root->rch==NULL) {oprt->data=0; count--;return;} //when whole tree deleted
else if(oprt->rch==NULL&&oprt->lch==NULL)                     //node is leaf node
   {if(prnt->lch!=NULL&&prnt->lch->data==oprt->data) //node was left child of parent
    prnt->lch=NULL;  
   else prnt->rch=NULL;                              //node was right child of parent
     free(oprt); count--; return;
   }
else if(oprt->lch!=NULL) 
 {prnt=oprt; temp=largst(oprt->lch); oprt->data=temp->data; delete(temp);}
else if(oprt->rch!=NULL) 
 {prnt=oprt; temp=smlst(oprt->rch);  oprt->data=temp->data; delete(temp);}
}

//inorder
void ino(node *oprt)
{if(oprt!=NULL)
 {ino(oprt->lch);
 fprintf(fs,"%d\n",oprt->data);
 ino(oprt->rch); 
 }
}
                      //main
main()
{ int c;  char f1[20],f2[20];
s.top=-1; //for stac initialisation
root=(node*)malloc(sizeof(node)); root->lch=root->rch=NULL; root->data=0;
do
{printf("\n1 to add node in tree\t2 to search in tree\t3 to find smallest\n4 to find largest\t5 to delete a node: \t6 to sort data in tree\n0 to exit\nchoice: ");    
 scanf("%d",&c);
switch(c)
 {case 0:  break;
  
 case 1: n=0; printf("add whole data from file to tree ? 1 for yes 0 for manual input "); 
         scanf("%d",&n);
        if(n==1) 
           {printf("enter input file name "); scanf("%s",f1); fin=fopen(f1,"r");
           if(fin==NULL) {printf("this file is not there\n"); break;}
                                                           gettimeofday(&t1r, NULL);    
           fscanf(fin,"%d\n",&n); 
           for(i=0;i<n;i++) 
           {fscanf(fin,"%d\n",&t); count++; add(root);}
           printf("total node are %d\n",count);  
                                                           gettimeofday(&t2r,NULL); break;}
                                                           
        else {do {printf("add int to tree 0 to finish: "); scanf("%d",&t); 
                   if(t>0) {count++; add(root);}} 
              while(t!=0); 
              printf("total node are %d\n",count); break;}

 case 2: if(root->data==0) {printf("no data in tree\n"); break;}
          printf("enter int to search "); scanf("%d",&n); while(pop()!=0) 1; level=0;
          if(search(root)!=NULL) 
            {printf("data found \npath is "); 
            while(cap()!=0) printf("%d->",pop());
            printf("\nlevel of this node in tree is %d\n",level);
           }else printf("data not found\n");
          break;

 case 3: if(root->data==0) printf("no data in tree\n"); 
          else printf("smallest in tree is %d\n",smlst(root)->data); break;

 case 4: if(root->data==0) printf("no data in tree\n"); 
          else printf("largest in tree is %d\n",largst(root)->data); break;

 case 5: if(root->data==0) {printf("no data in tree\n"); break;} 
         printf("enter int to delete "); scanf("%d",&n); 
         temp=search(root);
         if(temp!=NULL) {delete(temp); printf("deleted successfully\n");} 
         else printf("data not found to delete\n"); break;

case 6:   if(root->data==0) {printf("no data in tree\n"); break;}
          printf("enter file name to store sorted data "); scanf("%s",f2); fs=fopen(f2,"w");
                                                                   gettimeofday(&t1s, NULL);
          ino(root);
                                                                   gettimeofday(&t2s, NULL);
          printf("data of tree sorted\n"); break;

default : printf("wrong key\n"); break;
 }
} while(c!=0);

printf ("tree creat time = %f seconds\n",
             (double) (t2r.tv_usec - t1r.tv_usec)/1000000+
             (double) (t2r.tv_sec - t1r.tv_sec));
                                         
printf ("sorting time = %f seconds\n",
             (double) (t2s.tv_usec - t1s.tv_usec)/1000000+
             (double) (t2s.tv_sec - t1s.tv_sec));
}
