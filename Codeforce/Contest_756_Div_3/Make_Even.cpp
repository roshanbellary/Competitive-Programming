/*
Problem: Make Even
Problem Link: https://codeforces.com/contest/1611/problem/A
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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T,N;
int main(){
	setIO();cin >> T;
    while (T--){
        cin >> N;string s = to_string(N);
        int minv = 1e9;
        for (int i=0;i<s.size();i++){
            if ((s[i]-'0')%2==0){
                if (i==s.size()-1) minv=min(minv,0);
                if (i==0) minv=min(minv,1);
                minv=min(minv,2);
            }
        }
        cout << ((minv==1e9)?(-1):minv) << "\n";
    }
}
