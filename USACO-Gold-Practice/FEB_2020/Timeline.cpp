#include <bits/stdc++.h>
using namespace std;
int N, M, C;
vector<int> d;
vector<vector<pair<int,int>>> l;
int main(){
    freopen("timeline.in","r",stdin);
    freopen("timeline.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> C;
    for (int i=0;i<N;i++){int da; cin >> da; d.push_back(da);}
    for (int i=0;i<N;i++) l.push_back(vector<pair<int,int>>());
    for (int i=0;i<C;i++){
        int a,b,x; cin >> a >> b >> x; a--;b--;
        l[a].push_back(make_pair(b,x));
        l[b].push_back(make_pair(a,-x));
    }
    vector<bool> v(N,false);
    vector<int> minD(N,-1e9);
    for (int i=0;i<N;i++){
        if (!v[i]){
            priority_queue<pair<int,int>> pq;
            pq.push(make_pair(d[i],i));
            vector<int> ind;
            while (!pq.empty()){
                int time = pq.top().first;
                int j = pq.top().second;
                pq.pop();
                if (time<minD[j]) continue;
                if (minD[j]==-1e9) ind.push_back(j);
                v[j]=true;
                minD[j]=time;
                if (l[j].size()>0){
                    for (pair<int,int> k:l[j]){
                        if (k.second>0){if (minD[k.first]<time+k.second) pq.push(make_pair(time+k.second,k.first));}
                        else{
                            if ((time+k.second>d[k.first])&&(d[k.first]>minD[k.first])) pq.push(make_pair(d[k.first],k.first));
                        }
                    }
                }
            }
            int mind = 1e9;
            if (ind.size()>0){
                for (int j:ind){
                    mind=min(minD[j]-d[j],mind);
                }
                if (mind<0){
                    for (int j:ind){
                        minD[j]+=mind;
                    }
                }
            }
        }
    }
    for (int d:minD){
        cout << d << "\n";
    }
}