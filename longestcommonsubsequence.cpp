#include <iostream>
#include<vector>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
        int length1 = text1.size();
        int length2 = text2.size();
        vector<vector<int>> dp(length1+1, vector<int>(length2+1, 0));
        for(int i=1; i <= length1; i++){
            for(int j=1; j <= length2; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[length1][length2];
    }
int main()
{
    string text1,text2;
    getline(cin,text1);
    getline(cin,text2);
    cout<<longestCommonSubsequence(text1,text2);

    return 0;
}
