#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxprofit(vector<vector<int>>& jobs,vector<int>& dp,int i){
        if(i==jobs.size()){return 0;}
        if(dp[i]!=-1){return dp[i];}
        int l=i+1;
        int r=jobs.size()-1;
        int nextjob=jobs.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            if(jobs[mid][0]>=jobs[i][1]){
                nextjob=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        int pick=jobs[i][2]+maxprofit(jobs,dp,nextjob);
        int notpick=maxprofit(jobs,dp,i+1);
        return dp[i]=max(pick,notpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        for(int i=0;i<startTime.size();i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int>dp(startTime.size(),-1);
        return maxprofit(jobs,dp,0);
        
    }
int main()
{
    vector<int> startime,endtime,profit;
    int n;
    cout<<"enter n";
    cin>>n;
    cout<<"enter startimes";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        startime.push_back(temp);
    }
    cout<<"enter endtimes";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        endtime.push_back(temp);
    }
    cout<<"enter profits";
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        profit.push_back(temp);
    }
    cout<<jobScheduling(startime,endtime,profit);
    return 0;
}


enter n4
enter startimes1
2
3
3
enter endtimes3
4
5
6
enter profits50
10
40
70
120
