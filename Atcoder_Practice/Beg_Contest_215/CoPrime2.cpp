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
int N, M;
ll a[100001];
int p[100001];
int main(){
	setIO();
	cin >> N >> M;
	for (int i=0;i<N;i++) cin >> a[i];
	for (int i=1;i<=1e5;i++){
		p[i]=i;
	}
	for (int i=4;i<=1e5;i+=2){
		p[i]=2;
	}
	for (int i=3;i*i<=1e5;i++){
		if (p[i]==i){
			for (int j=i*i;j<=1e5;j+=i){
				if (p[j]==j){p[j]=i;}
			}
		}
	}
	set<int> primes;
	for (int i=0;i<N;i++){
		int v = a[i];
		while (v!=1){
			primes.insert(p[v]);
			v/=p[v];
		}
	}
	vector<int> n;
	for (int i=1;i<=M;i++){
		bool w = true;
		for (int j:primes){
			if (i%j==0){
				w=false;break;
			}
		}
		if (w) n.pb(i);
	}
	cout << n.size() << "\n";
	for (int i:n){
		cout << i << "\n";
	}
}
