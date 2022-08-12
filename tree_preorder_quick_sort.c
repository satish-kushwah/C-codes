#include<stdio.h>
#include<stdlib.h>
//tree node
typedef struct node {int data; struct node *left; struct node *right;}node;
node *root; 
//global variables
int dataVal,n,*arr,*tempArr;                
//add node to tree
void addNode(node *treeNode){
  if(treeNode->data==0)
    {treeNode->data=dataVal; return;} //for root node insertion
  else if(dataVal<treeNode->data)
    {if(treeNode->left==NULL)
        {treeNode->left=(node*)malloc(sizeof(node));
        treeNode->left->data=dataVal; treeNode->left->left=treeNode->left->right=NULL; 
        return;
        } 
    else addNode(treeNode->left);
   }
  else if(dataVal>=treeNode->data)
    {if(treeNode->right==NULL)
        {treeNode->right=(node*)malloc(sizeof(node));
        treeNode->right->data=dataVal; treeNode->right->left=treeNode->right->right=NULL; 
        return;
        } 
    else addNode(treeNode->right);
    }
}

void Preorder(int *arr, node *node) 
{   static int i=0;
     if (node == NULL) 
          return; 
     *(arr+i)=node->data;
     i++;
     Preorder(arr,node->left);   
     Preorder(arr,node->right); 
}    
//quick sort
int partition(int *A, int p, int r){
  int i,j,temp;
  i=p-1;
  for (j=p;j<r;j++){
    if (A[j]<A[r]){
      i=i+1;
      temp=A[j];
      A[j]=A[i];
      A[i]=temp;
    }
  }
  i=i+1;
  temp=A[r];
  A[r]=A[i];
  A[i]=temp;
  return(i);
}
void quick_sort(int *A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quick_sort(A,p,q-1);
    quick_sort(A,q+1,r);
  }
}

int main(){   
    root=(node*)malloc(sizeof(node)); 
    root->left=root->right=NULL; root->data=0; //root initialisation
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d",&dataVal);
        addNode(root); //addNodeing node to tree
    }
    arr=(int*)malloc(sizeof(int));
    tempArr=(int*)malloc(sizeof(int));
    Preorder(arr,root); //preorder traversal stored in array arr
    printf("preorder traversal\n");
    for(int i=0; i<n; ++i) {
        printf("%d\n",*(arr+i) );    
    }
    quick_sort(arr,0,n-1); //calling quick_sort to sort array arr
    printf("printing sorted values by merge sort\n");
    for(int i=0; i<n; i++) {
        printf("%d\n",*(arr+i) );    
    }
    return 0;
}
