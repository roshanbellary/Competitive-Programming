/*
Problem: 
Problem Link: 
Notes: 
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
#define f first
#define s second
int mod=1e9+7;
inline void rv(int &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(string &w){w="";char c=getchar();while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}}
inline void rv(char &c){c=getchar();}
template<typename T, typename ...Types>
void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
const int MC = 100;
const int MN = 1e5;
struct Note{int c[MC];};
Note n[MC];
int N, S, G, L, seq[MN], previ[MC],r[MC][MC],used[MN], dp[MN];
vector<int> path[MC][MC],res;
void setvect(int i, int j){
    if (r[i][j]==1e9) return;
    if (i==j){path[i][i].pb(i+1); return;}
    int cd = r[i][j], ind = j;
    while (cd>0){
        path[i][j].pb(ind+1);
        for (int k=0;k<N;k++){
            if (r[ind][k]==1 && r[i][k]==cd-1){ind=k;cd--;break;}
        }
    }
    path[i][j].pb(ind+1);
    reverse(path[i][j].begin(),path[i][j].end());
}
void setpaths(){
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) setvect(i,j);
}
int main(){
	setIO();cin >> N >> S >> G;
    for (int i=0;i<N;i++){
        string s; cin >> s;
        for (int j=0;j<S;j++){
            n[i].c[j]=(s[j]-'0');
        }
    }
    cin >> L;for (int i=0;i<L;i++) cin >> seq[i], seq[i]--;
    for (int i=0;i<N;i++){
        for (int j=i;j<N;j++){
            r[i][j]=r[j][i]=1e9;
            int count = 0;
            for (int k=0;k<S;k++){
                count+=(n[i].c[k]!=n[j].c[k]);
            }
            if (count<=G) r[i][j]=r[j][i]=1;
            if (i==j) r[i][i]=0;
        }
    }
    for (int i=0;i<N;i++){
        queue<pair<int,int>> q;
        for (int j=0;j<N;j++){
            if (r[i][j]==1) q.push({j,r[i][j]});
        }
        while (!q.empty()){
            auto a = q.front();q.pop();
            if (r[i][a.f]<a.s) continue;a.s++;
            for (int j=0;j<N;j++){
                if (r[a.f][j]==1 && r[i][j]>a.s){
                    r[i][j]=a.s;q.push({j,a.s});
                }
            }
        }
    }
    setpaths();
    for (int i=0;i<N;i++) previ[i]=-1;
    for (int i=0;i<L;i++) dp[i]=1e9;
    previ[seq[0]]=0;dp[0]=0;used[0]=-1;
    for (int i=1;i<L;i++){
        dp[i]=i;used[i]=-1;
        for (int j=0;j<N;j++){
            if (previ[j]!=-1){
                if (r[j][seq[i]]<=(i-previ[j]) && dp[i]>dp[previ[j]]+(i-previ[j]-1)){
                    dp[i]=dp[previ[j]]+(i-previ[j]-1);
                    used[i]=previ[j];
                }
            }
        }
        previ[seq[i]]=i;
    }
    int minv = 1e9, ind = -1;
    for (int i=0;i<L;i++) {
        if (dp[i]+(L-1-i)<=minv){
            minv=dp[i]+(L-1-i);ind=i;
        }
    }
    cout << minv << "\n";
    for (int i=0;i<(L-1-ind);i++) res.pb(seq[ind]+1);
    int cused = used[ind];
    while (cused!=-1){
        int diff = r[seq[ind]][seq[cused]];if (ind==cused) diff++;
        for (int i=0;i<(ind-cused-diff);i++) res.pb(seq[ind]+1);
        for (int i=0;i<path[seq[ind]][seq[cused]].size()-1;i++) res.pb(path[seq[ind]][seq[cused]][i]);
        ind=cused;cused=used[ind];
    }
    for (int i=0;i<=ind;i++) res.pb(seq[ind]+1);
    reverse(res.begin(),res.end());
    for (int j:res) cout << j << " ";
    cout << "\n";
}
