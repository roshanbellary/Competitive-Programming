#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Cow{ll p, v;
};
const ll MM = 2e5;
ll K, M, N;
double p[MM];
Cow f[MM];
bool sorts(Cow &a, Cow &b){return (a.p<b.p);}
priority_queue<ll> pq;
int main(){
    cin >> K >> M >> N;
    for (ll i=0;i<K;i++) cin >> f[i].p >> f[i].v;
    for (ll i=0;i<M;i++) cin >> p[i];
    sort(p,p+M);sort(f,f+K, sorts);
    ll col = 0, ind = 0;
    while (ind<K){
        if (f[ind].p<=p[0]) col+=f[ind].v, ind++;
        else break;
    }
    pq.push(col);
    for (ll i=0;i<M-1;i++){
        ll tcol = 0;vector<ll> inds;
        while (ind<K){
            if (f[ind].p<=p[i+1]){inds.push_back(ind);tcol+=f[ind].v;ind++;}
            else break;
        }
        ll rind = 0, lind=0;
        ll col=0, mcol = 0;
        while (rind<inds.size()){
            if (rind) col-=f[inds[rind-1]].v;
            while (lind<inds.size()){
                if (f[inds[lind]].p-f[inds[rind]].p<p[i+1]-f[inds[lind]].p){
                    col+=f[inds[lind]].v;lind++;
                }else break;
            }
            mcol=max(mcol,col);rind++;
        }
        pq.push(mcol);pq.push(tcol-mcol);
    }
    col = 0;
    while (ind<K){col+=f[ind].v;ind++;}
    pq.push(col);ll res = 0;
    while (N--) if (!pq.empty()){res+=pq.top();pq.pop();}
    cout << res << "\n";
}