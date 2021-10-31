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
int N, Q,dpl[(int)1e5],dpr[(int)1e5],c[(int)1e5];
string s;
int main(){
	setIO();cin >> N >> Q >> s;
	for (int i=0;i<N;i++) c[i]=(s[i]-'A');
	stack<int> col;
	for (int i=0;i<N;i++){
		if (col.size()==0){
			dpl[i]=1;col.push(c[i]);
		}else{
			if (c[i]>col.top()){
				dpl[i]=dpl[i-1]+1;
				col.push(c[i]);
			}else{
				bool found = false;
				while (col.size()>0){
					if (col.top()==c[i]){dpl[i]=dpl[i-1]; break;}
					else if (col.top()>c[i])col.pop();
					else{
						dpl[i]=dpl[i-1]+1;
						col.push(c[i]);
						break;
					}
				}
				if (col.size()==0){col.push(c[i]);dpl[i]=dpl[i-1]+1;}
			}
		}
	}
	while (col.size()>0) col.pop();
	for (int i=N-1;i>=0;i--){
		if (col.size()==0){
			dpr[i]=1;col.push(c[i]);
		}else{
			if (c[i]>col.top()){
				dpr[i]=dpr[i+1]+1;
				col.push(c[i]);
			}else{
				bool found = false;
				while (col.size()>0){
					if (col.top()==c[i]){dpr[i]=dpr[i+1]; break;}
					else if (col.top()>c[i])col.pop();
					else{
						dpr[i]=dpr[i+1]+1;
						col.push(c[i]);
						break;
					}
				}
				if (col.size()==0){col.push(c[i]);dpr[i]=dpr[i+1]+1;}
			}
		}
	}
	for (int i=0;i<Q;i++){
		int s, f; cin >> s >> f;s--;f--;
		int brush = 0;
		if (s) brush+=dpl[s-1];
		if (f<N-1) brush+=dpr[f+1];
		cout << brush << "\n";
	}
}
