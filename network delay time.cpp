#include <iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(105);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(105,INT_MAX);
        dist[k]=0;
        pq.push({dist[k],k});
        while(!pq.empty()){
            int prev_dist=pq.top().first;
            int prev_pos=pq.top().second;
            pq.pop();
            for(auto x:adj[prev_pos]){
                int next_pos=x.first;
                int next_dist=x.second;
                if(dist[next_pos]>dist[prev_pos]+next_dist){
                    dist[next_pos]=dist[prev_pos]+next_dist;
                    pq.push({dist[next_pos],next_pos});
                }
            }
        }
        int mini=INT_MIN;
        for(int i=1;i<=n;i++){
            if(i!=k && dist[i]==INT_MAX){return -1;}
            mini=max(mini,dist[i]);
        }
        return mini;
    }
int main()
{
    vector<vector<int>> arr;
    int n,a,b,ne,k,c;
    cin>>ne;
    for(int i=0;i<ne;i++){
        vector<int> temp;
        cin>>a;
        temp.push_back(a);
        cin>>b;
        temp.push_back(b);
        cin>>c;
        temp.push_back(c);
        arr.push_back(temp);
        
    }
    cin>>n;
    cin>>k;
    int res=networkDelayTime(arr,n,k);
    cout<<res;

    return 0;
}
