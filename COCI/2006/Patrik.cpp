/*
Problem: COI '06 #1 Patrik
Problem Link: https://dmoj.ca/problem/coi06p1
Notes: I made a pretty dumb mistake on this one and wasn't able to catch it initally by making 
test cases.
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
ll N,a[(int)5e5],prevs[(int)5e5];
int main(){
	setIO(); cin >> N;
	for (int i=0;i<N;i++) cin >> a[i];
	stack<pair<int,int>> h; ll col = 0;
	for (int i=0;i<N;i++){
		if (h.size()==0){
			prevs[i]=0; h.push({a[i],1});
		}else{
			ll c = 0;
			while (true){
				if (h.size()==0) break;
				if (h.top().first<a[i]){
					c+=h.top().second;
					h.pop();
				}else if (h.top().first==a[i]){
					c+=h.top().second;if (h.size()>1) c++;break;
				}else{
					c++;
					break;
				}
			}
			prevs[i]=c;
			if (h.size()>0){
				if (h.top().first==a[i]) h.top().second++;
				else h.push({a[i],1});
			}else{
				h.push({a[i],1});
			}
		}
	}
	for (int i=0;i<N;i++) col+=prevs[i];
	cout << col << "\n";
}
