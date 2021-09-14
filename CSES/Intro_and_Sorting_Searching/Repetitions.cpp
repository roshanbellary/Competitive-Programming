#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string w;
    cin >> w;
    char c = w[0];
    int count = 1;
    int maximum = 0;
    int l = w.length();
    for (int i=1;i<l;i++){
        if (w[i]==c){
            count++;
        }else{
            maximum=max(count,maximum);
            count=1;
            c=w[i];
        }
    }
    maximum=max(count,maximum);
    cout << maximum;
}