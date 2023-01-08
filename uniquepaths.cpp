#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int uniquePaths(int m, int n){
int dp[m][n],i,j;
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        if(i==0||j==0){
            dp[i][j]=1;
        }
        else{
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
}
return dp[m-1][n-1];
}
int main()
{
   int m,n;
   cout<<"enter m and n values";
   cin>>m;
   cin>>n;
   cout<<uniquePaths(m,n);
    return 0;
    
}

enter m and n values3
2
3
