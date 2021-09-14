#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, s; cin >> m >> s;
    if (s>9*m){
        cout << "-1 -1\n";
    }else if (!((s==0)&&(m>=0))){
        int fill = s/9;
        string maxi ="";
        for (int i=0;i<fill;i++){
            maxi+="9";
        }
        if ((maxi.length()<m)){
            maxi+=to_string(s%9);
            for (int i=maxi.length();i<m;i++){
                maxi+="0";
            }
        }
        string mini = "";
        for (int i=0;i<m;i++){
            mini+="0";
        }
        int p = s;
        mini[0]++; p--;
        if (p>0){
            int add = p/9;
            int left = p%9;
            for (int i=m-1;i>=m-add;i--){
                mini[i]='9';
            }
            if (left>0) mini[m-add-1]+=left;
        }
        cout << mini << " " << maxi << "\n";
    }else if ((m==1)&&(s==0)){
        cout << "0 0\n";
    }else{
        cout << "-1 -1\n";
    }
}