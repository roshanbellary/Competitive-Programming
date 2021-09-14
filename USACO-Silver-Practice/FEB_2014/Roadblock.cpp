#include <bits/stdc++.h>
#define int long long
using namespace std;
int N, M;
vector<vector<pair<int,int>>> l;
vector<bool> v;
vector<int> d;
int32_t main(){
    freopen("rblock.in","r",stdin);
    freopen("rblock.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i=0;i<N;i++){l.push_back(vector<pair<int,int>>()); v.push_back(false); d.push_back(1e18);}
    for (int i=0;i<M;i++){
        int a,b,j;
        cin >> a >> b >> j;
        a--; b--;
        l[a].push_back(pair<int,int>(b,j));
        l[b].push_back(pair<int,int>(a,j));
    }
    d[0]=0;
    int s = 0;
    while (true){
        int j = -1;
        for (int i=0;i<N;i++){
            if (!v[i]){
                if (j<0) j=i;
                else if (d[j]>d[i]) j=i;
            }
        }
        if (j<0) break;
        v[j]=true;
        for (pair<int,int> a:l[j]){
            if (d[a.first]>d[j]+a.second){
                d[a.first]=d[j]+a.second;
            }
        }
    }
    int length = d[N-1];
    int init = d[N-1];
    vector<int> path;
    int a = N-1;
    while (true){
        path.push_back(a);
        if (a==0) break;
        for (pair<int,int> b:l[a]){
            if (d[b.first]+b.second==d[a]){
                a=b.first;
                break;
            }
        }
    }
    for (int i=0;i<path.size()-1;i++){
        int temp = -1;
        for (int j=0;j<l[path[i]].size();j++){
            if (l[path[i]][j].first==path[i+1]){
                temp = j;
                break;
            }
        }
        int store = -1;
        for (int j=0;j<l[path[i+1]].size();j++){
            if (l[path[i+1]][j].first==path[i]){
                store=j;
                break;
            }
        }
        l[path[i]][temp].second*=2;
        l[path[i+1]][store].second*=2;
        fill(d.begin(),d.end(),1e18);
        fill(v.begin(),v.end(),false);
        d[0]=0;
        int s = 0;
        while (true){
            int j = -1;
            for (int i=0;i<N;i++){
                if (!v[i]){
                    if (j<0) j=i;
                    else if (d[j]>d[i]) j=i;
                }
            }
            if (j<0) break;
            v[j]=true;
            for (pair<int,int> a:l[j]){
                if (d[a.first]>d[j]+a.second){
                    d[a.first]=d[j]+a.second;
                }
            }
        }
        if (d[N-1]>length) length=d[N-1];
        l[path[i]][temp].second/=2;
        l[path[i+1]][store].second/=2;
    }
    cout << length-init << "\n";
}