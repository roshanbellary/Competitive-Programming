/*faster implementation of diamonds by far*/
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
int N, K, sizes[(int)5e4],lefts[(int)5e4],rights[(int)5e4];
int main(){
	setIO("diamond");cin >> N >> K;
	for (int i=0;i<N;i++) cin >> sizes[i];sort(sizes,sizes+N);
	queue<int> s;
	for (int i=0;i<N;i++){
		if (s.size()==0) lefts[i]=1,s.push(sizes[i]);
		else{
			while (true){
				if (s.size()==0) break;
				else if (s.front()<sizes[i]-K) s.pop();
				else break;
			}
			lefts[i]=1+s.size();s.push(sizes[i]);
		}
	}
	while (s.size()>0) s.pop();
	for (int i=N-1;i>=0;i--){
		if (s.size()==0) rights[i]=1,s.push(sizes[i]);
		else{
			while (true){
				if (s.size()==0) break;
				else if (s.front()>sizes[i]+K) s.pop();
				else break;
			}
			rights[i]=1+s.size();s.push(sizes[i]);
		}
	}
	int mv = rights[N-1],maxV = lefts[N-1];
	for (int i=N-2;i>=0;i--){
		maxV=max(maxV,lefts[i]+mv);
		mv=max(rights[i],mv);
	}
	cout << maxV << "\n";
}
