#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int v[N];
    int s[N];
    for (int i=0;i<N;i++){cin >> v[i];s[i]=v[i];}
    sort(s,s+N);
    int st = -1;
    int fi = -1;
    for (int i=0;i<N-1;i++){
        if (v[i+1]<v[i]){
            st=i;
            int temp = i+1;
            while (temp<N-1){
                if (v[temp]>v[temp+1]){
                    temp++;
                }else{
                    break;
                }
            }
            fi=temp;
            break;
        }
    }
    if (st>=0){
        reverse(v+st,v+fi+1);
        bool w = true;
        for (int i=0;i<N;i++){
            if (v[i]!=s[i]){
                w=false;break;
            }
        }
        if (w){
            cout << "yes\n";
            cout << st+1 << " " <<fi+1 << "\n";
        }else{
            cout << "no\n";
        }
    }else{
        cout << "yes\n";
        cout << 1 << " " << 1;
    }
}