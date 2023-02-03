#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int par[1001];
    int find(int a){
        if(par[a]<0){
            return a;
        }
        return par[a]=find(par[a]);
    }
    void Union(int a,int b){
        par[a]=b;
    }
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++) par[i]=-1;
        vector<pair<int,pair<int,int>>> adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int weight=abs(arr[i][0]-arr[j][0])+abs(arr[i][1]-arr[j][1]);
                adj.push_back({weight,{i,j}});
            }
        }
        sort(adj.begin(),adj.end());
        int sum=0;
        for(int i=0;i<adj.size();i++){
            int a=find(adj[i].second.first);
            int b=find(adj[i].second.second);
            if(a!=b){
                sum+=adj[i].first;
                Union(a,b);
            }
        }
        return sum;
    }
int main()
{
    vector<vector<int>> arr;
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> temp;
        cin>>a;
        temp.push_back(a);
        cin>>b;
        temp.push_back(b);
        arr.push_back(temp);
        
    }
    int res=minCostConnectPoints(arr);
    cout<<res;

    return 0;
}
