#include <iostream>
#include <cstring>
#include<vector>
using namespace std;
vector<int> prefixfunction(string s){
    int n=s.size();
    int k;
    vector<int> pr(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(s.substr(0,j)==s.substr(i-j+1,j)){
                pr[i]=j;
            }
        }
    }
    return pr;
}
 
int main()
{
    string s1 = "linux";
    string s2 = "sun and linux";
    vector<int> pr=prefixfunction(s1);
    int pos=-1;
    int i=0,j=0;
    while(i<s2.size()){
        if(s2[i]==s1[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=pr[j-1];
            }
            else{
                i++;
            }
        }
        if(j==s1.size()){
            pos=i-s1.size();
            break;
        }
    }
    cout<<pos;
    return 0;
}
