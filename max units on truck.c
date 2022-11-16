1710. Maximum Units on a Truck
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

 

Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91
 

Constraints:

1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
int maximise(int a[][2],int j,int trucksize){
    int i=0,total=0,count=0;
    while(i<j && count<trucksize){
        if(count+a[i][0]<=trucksize){
            count+=a[i][0];
            total+=a[i][0]*a[i][1];
        }
        else{
            total+=(trucksize-count)*a[i][1];
            count=trucksize;
        }
        i++;
    }
    return total;
}
int main()
{
    int a[10][2]={{2,2},{1,3},{3,1}},i,j=3;
    for(i=0;i<3;i++)
    {
        for(j=i+1;j<3;j++){
            if(a[i][1]<a[j][1]){
                int temp=a[i][1];
                int val=a[i][0];
                a[i][0]=a[j][0];
                a[i][1]=a[j][1];
                a[j][1]=temp;
                a[j][0]=val;
               
            }
        }
    }
    int trucksize;
    printf("enter truck size");
    scanf("%d",&trucksize);
    int res=maximise(a,j,trucksize);
     printf("%d",res);
    return 0;
}
