// C program for Binary Search only works on sorted ascending order
//returns index of key or -1 if key not found
#include <stdio.h> 
int binarySearch(int arr[], int size, int key) { 
    int left=0,right,middle;
    right=size-1;
    while(left  <=right){
        middle=(left+right)/2;
        if (arr[middle]<key)
            left=middle+1;
        else if (arr[middle]>key)
            right=middle-1;
        else //key found
            return middle; 
    }
    return -1;
} 

int main(void) {
    int n;
    int arr[]={3,4,23,33,43,56,323,567},x; 
    n=8;
    printf("Enter key to search: ");
    scanf("%d", &x);
    int result = binarySearch(arr, n, x); 
    if (result!=-1) 
        printf("key found at index %d",result);
    else 
        printf("key not found");
} 