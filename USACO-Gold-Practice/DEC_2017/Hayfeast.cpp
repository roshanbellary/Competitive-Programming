//DEC 2017 Gold Prob 3
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    long long M;
    cin >> N >> M;
    vector<pair<int,int> > v(N);
    for (int i=0;i<N;i++){
        int f,s; 
        cin >> f >> s;
        v[i]=pair<int,int>(f,s);
    }
    int l=0,r=0;
    long long sum = 0;
    multiset<int> m;
    int mini = 1e9+1;
    while (r<=N){
        if ((sum<M)&&(r==N)) break;
        if (sum<M){
            sum+=v[r].first;
            m.insert(v[r].second);
            r++;
        }else{
            sum-=v[l].first;
            auto itr = m.end();
            itr--;
            mini=min(mini,*itr);
            m.erase(m.find(v[l].second));
            l++;
        }
    }
    cout << mini << "\n";
}