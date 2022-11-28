322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>


int coinChange(int* coins, int coinsSize, int amount){
int a[amount+1];
a[0]=0;
    for(int i=1;i<=amount;i++)
    {
        a[i]=amount+1;
    }
    for(int i=1;i<=amount;i++)
    {
        for(int j=0;j<coinsSize;j++)
        {
            if(coins[j]<=i)
            {int x=1+a[i-coins[j]];
             int y=a[i];
            a[i]=x<y?x:y;
            }
        }
    }
    if(a[amount]==amount+1)
     return -1;
    else
     return a[amount];
}
int main()
{int c[10],n,a;
printf("enter n and amount");
scanf("%d%d",&n,&a);
printf("enter coins");
for(int i=0;i<n;i++){
    scanf("%d",&c[i]);
}
  int r=coinChange(c,n,a);
  printf("min coins :%d",r);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
