#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    vector<int> a(N);
    int maxa = -1, minb=1e9, mina=1e9;
    for (int i=0;i<N;i++) cin >> a[i],maxa=max(maxa,a[i]),mina=min(mina,a[i]);
    vector<int> b(M);
    for (int i=0;i<M;i++) cin >> b[i],minb=min(minb,b[i]);
    int s = maxa, f=minb-1;
    while (s<f){
        int mid = (s+f)/2;
        if (mid>=2*mina){
            f=mid;
        }else{
            s=mid+1;
        }
    }
    if ((s>=2*mina)&&(s>=maxa)&&(s<minb)) cout << s << "\n";
    else cout << "-1\n";

}