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
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T,N,a[(int)2e5];
int main(){
	setIO();cin >> T;
    while (T--){
        cin >> N;
        for (int i=0;i<N;i++){
            cin >> a[i];
        }
        bool w = 1;int ind = -1;
        for (int i=0;i<N;i++){
            if (a[i]==N && i!=0 && i!=N-1){
                w=0;break;
            }else if (a[i]==N){
                ind=i;
            }
        }
        if (!w){cout << "-1\n";continue;}
        if (ind==N-1){
            for (int i=N-2;i>=0;i--){
                cout << a[i] << " ";
            }
            cout << N << "\n";
        }else{
            for (int i=N-1;i>=1;i--){
                cout << a[i] << " ";
            }
            cout << N << "\n";
        }
    }
}
