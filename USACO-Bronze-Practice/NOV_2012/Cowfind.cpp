#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    freopen("cowfind.in","r",stdin);
    freopen("cowfind.out","w",stdout);
    string s;
    cin >> s;
    vector<int> dp(s.length());
    dp[0]=0;
    for (int i=0;i<s.length()-1;i++){
        if (s.substr(i,2)=="(("){
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=dp[i-1];
        }
    }
    dp[s.length()-1]=dp[s.length()-2];
    int count=0;
    for (int i=0;i<s.length()-1;i++){
        if (s.substr(i,2)=="))"){
            count+=dp[i];
        }
    }
    cout << count;
}