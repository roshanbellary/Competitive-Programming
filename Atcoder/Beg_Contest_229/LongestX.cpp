/*
Problem: Longest X
Problem Link: https://atcoder.jp/contests/abc229/tasks/abc229_d
Notes: Finding next range then figuring out how long you can extend current range after joining to latest possible range
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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
string S;
int K,pref[(int)2e5];
vector<pair<int,int>> v;
int main(){
	setIO();cin >> S >> K;
    pair<int,int> p;
    for (int i=0;i<S.length();i++){
        if (S[i]=='X'){
            p.f=i;
            while (i<S.length()){if (S[i]!='X') break;i++;}
            p.s=--i;v.pb(p);
        }
    }
    for (int i=0;i<S.length();i++){
        if (S[i]=='X') pref[i]=1;
        else pref[i]=0;
        if (i) pref[i]+=pref[i-1];
    }
    int ml = 0;
    for (int i=0;i<v.size();i++){
        int s = i, f=v.size()-1;
        while (s!=f){
            int mid = (s+f+1)/2;
            if (v[mid].s-v[i].f-pref[v[mid].s]+pref[v[i].f]<=K) s=mid;
            else f=mid-1;
        }
        int space = v[s].s-v[i].f+1;
        int filled = pref[v[s].f-1]-pref[v[i].s]+(v[s].s-v[s].f+1)+(v[i].s-v[i].f+1);
        int left = K-(space-filled);
        ml=max(min(v[s].s-v[i].f+1+left,(int)S.length()), ml);
    }
    ml=max(ml,min((int)S.length(),K));
    cout << ml << "\n";
}