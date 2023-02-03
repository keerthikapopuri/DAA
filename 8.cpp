#include <iostream>
#include<stack>
using namespace std;
string reverseWords(string s) {
        stack<char> stac;
        string ans="";
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            bool flag=false;
            if(s[i]==' '){
                while(stac.size()){
                    char temp=stac.top();
                    stac.pop();
                    ans+=temp;
                    flag=true;
                }
                if(flag==true){ans+=' ';}
                continue;
            }
            stac.push(s[i]);
        }
        while(stac.size()){
            char temp=stac.top();
            ans+=temp;
            stac.pop();
        }
        if(ans[ans.size()-1]==' '){
            ans.pop_back();
        }
        return ans;
    }
int main()
{
    string str;
    getline (cin, str);
    cout<<reverseWords(str);

    return 0;
}
