912. Sort an Array
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
int nums[100];
void merge(int* nums,int l,int mid,int h){
    int b[h-l+1];
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=h){
        b[k++]=nums[i]<nums[j]?nums[i++]:nums[j++];
        
    }
    while(i<=mid){b[k++]=nums[i++];}
    while(j<=h){b[k++]=nums[j++];}
    k=0;
    for(int i=l;i<=h;i++){
        nums[i]=b[k++];
    }
}

void mergesort(int* nums,int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,h);
        merge(nums,l,mid,h);
    }
}
void sortarray(int* nums,int n,int* returnsize)
{
    *returnsize=n;
    
    mergesort(nums,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d",*(nums+i));
    }
}
int main()
{
    int n,returnsize;
    printf("enter size");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    sortarray(nums,n,&returnsize);

    return 0;
}
