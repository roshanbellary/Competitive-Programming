#include <bits/stdc++.h>
#define ll long long
using namespace std;
int A, B, N;
vector<vector<int>> r;
vector<ll> c;
int main(){
    freopen("cowroute.in","r",stdin);
    freopen("cowroute.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> A >> B >> N;A--;B--;
    set<int> ve;
    for (int i=0;i<N;i++){
        int n;ll C; cin >> C >> n;
        c.push_back(C); r.push_back(vector<int>());
        for (int j=0;j<n;j++){
            int v; cin >> v;
            r[r.size()-1].push_back(--v);
            ve.insert(v);
        }
    }
    map<int,int> no;
    int count = 0;
    for (int j:ve){
        no[j]=count;
        count++;
    }
    priority_queue<pair<ll,pair<int,int>>> pq;
    pq.push(make_pair(0,make_pair(0,A)));
    vector<ll> minC(ve.size(),1e18);
    vector<int> minF(ve.size(),1e9);
    while (!pq.empty()){
        ll cost = -pq.top().first;
        int flights = pq.top().second.first;
        int ind = pq.top().second.second;
        pq.pop();
        if (cost>minC[no[ind]]) continue;
        if (cost==minC[no[ind]]) minF[no[ind]]=min(minF[no[ind]],flights);
        else minC[no[ind]]=cost; minF[no[ind]]=flights;
        for (int i=0;i<N;i++){
            int temp = -1;
            for (int j=0;j<r[i].size();j++){
                if (temp>=0){
                    if (cost+c[r[i][j]]<=minC[r[i][j]]){
                        pq.push(make_pair(-(cost+c[i]),make_pair(flights+(j-temp),r[i][j])));
                    }
                }
                if (r[i][j]==ind){
                    temp=j;
                }
            }
        }
    }
    if (minC[no[B]]==1e18) cout << "-1 -1\n";
    else cout << minC[no[B]] << " " << minF[no[B]] << "\n";
}