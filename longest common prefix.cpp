#include <iostream>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string ref=strs[0];
    string res="";
    if(strs.size()==1){
        return strs[0];
    }
    for(int i=0;i<strs[1].size();i++){
        int cnt=0;
        for(int j=1;j<strs.size();j++){
            if(ref[i]==strs[j][i])
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
        if(cnt==strs.size()-1)
        {
                res+=ref[i];
        }
        else
        {
            break;
        }
    }
    return res;
    }

int main()
{
    vector<string>s;
    string temp;
    int n;
    cout<<"enter number of strings";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        s.push_back(temp);
    }
    
    cout<<longestCommonPrefix(s);
    return 0;
}


enter number of strings3
flower
flow
flight
fl
