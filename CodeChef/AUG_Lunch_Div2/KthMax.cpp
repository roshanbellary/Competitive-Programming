#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T, K, N;
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		cin >> N >> K;
		int a[N];
		for (int i=0;i<N;i++) cin >> a[i];
		int maxv = -1;
		for (int i=0;i<N;i++) maxv=max(maxv,a[i]);
		vector<int> p;
		for (int i=0;i<N;i++){
			if (a[i]==maxv) p.pb(i);
		}
		ll count = 0;
		for (int j:p){
			if (j-(K-1)>=0){
				count+=(N-j);
			}
		}
		cout << count << "\n";
	}
}
