#include<stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=0,j=0,k=0;
   int arr[m+n];
    while(i<m && j<n){
if(nums1[i]<nums2[j]){arr[k++]=nums1[i++];}
else{arr[k++]=nums2[j++];}
    }
 for(;i<m;i++){
        arr[k++]=nums1[i];
    }
     for(;j<n;j++){
        arr[k++]=nums2[j];
    }
     for(i=0;i<m+n;i++){
        nums1[i]=arr[i];
    }
}
 int nums1[100],nums2[100];
void main()
{
   int num1size,num2size,m,n;
    printf("enter the size of 1st array");
    scanf("%d",&num1size);
    printf("enter size of 2nd array");
    scanf("%d",&num2size);
    printf("enter number of elements to be merged");
    scanf("%d",&m);
    n=num2size;
    for(int i=0;i<num1size;i++)
    {
        scanf("%d",&nums1[i]);
    }
    for(int i=0;i<num2size;i++)
    {
        scanf("%d",&nums2[i]);
    }
    merge(nums1,num1size,m,nums2,num2size,n);
    for(int i=0;i<num1size;i++)
    {
        printf("%d",nums1[i]);
    }

    
    
}
