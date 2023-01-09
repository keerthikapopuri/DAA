#include <iostream>

using namespace std;
int lengthOfLongestSubstring(string s) {
        int i,j,k,length=1,len;
        if(s.size()==0){
            return 0;
        }
        for(i=0;i<s.size();i++){
            for(j=i+1;j<s.size();j++){
            len=1;
            for(k=i;k<j;k++){
                if(s[j]!=s[k]){
                    len++;
                }
                else{
                    break;
                }
            }
            if(len>length && k==j){
                    length=len;
            }
            else if (k!=j){
                break;
            }
            }
        }
        return length;
        
    }
int main()
{
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s);

    return 0;
}


abcabcbb
3
