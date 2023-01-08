#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
static bool compare(vector<int>& a,vector<int>& b){
        if(a[1]<b[1]){return true;}
        if(a[1]==b[1]){return a[0]<b[0];}
        return false;
    }
int maxEvents(vector<vector<int>>& events){
        sort(events.begin(),events.end(),compare);
        set<int>days;
        int total=events[events.size()-1][1];
        for(int i=1;i<=total;i++){
            days.insert(i);
        }
        int ans=0;
        for(int i=0;i<events.size();i++){
            int s=events[i][0];
            int e=events[i][1];
            auto d =days.lower_bound(s);
            if(d==days.end()||*d>e) continue;
            else{
                ans++;
                days.erase(d);
            }
        }
        return ans;
    }   
int main()
{
   int n,a,b,trucksize;
   cout<<"enter size";
   cin>>n;
   vector<vector<int>> events;
   for(int i=0;i<n;i++){
       vector<int> temp;
       cout<<"enter 2 element";
       cin>>a;
       temp.push_back(a);
       cin>>b;
       temp.push_back(b);
       events.push_back(temp);
   }
   int res=maxEvents(events);
   printf("%d",res);
    return 0;
    
}
