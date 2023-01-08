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
#include <iostream>
#include<vector>
using namespace std;
void merge(vector<int>&nums, int l, int mid, int r){
    int n1 = mid -l+1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i] = nums[l+i];
    }
    for(int j = 0;j<n2;j++){
        b[j] = nums[mid+1+j];
    }
  
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            nums[k] = a[i];
            i++;
            k++;
        }
        else{
            nums[k] = b[j];
            j++;
            k++;
        }
    }
    
    while(i<n1){
        nums[k] = a[i];
        i++;
        k++;
    }
    while(j<n2){
        nums[k] = b[j];
        j++;
        k++;
    }
}
   void mergeSort(vector<int>&nums,int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums, mid+1, r);
        
        merge(nums , l, mid, r);
    }
}
    vector<int> sortArray(vector<int>& nums) {
   int l = 0;
   int r = nums.size() - 1;
    mergeSort( nums, l, r);
    return nums;
}
int main(){
    vector<int> nums;
    int n,a;
    cout<<"enter size";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
      sortArray(nums);
      for(int i=0;i<n;i++){
          printf("%d",nums[i]);
      }
    
}
