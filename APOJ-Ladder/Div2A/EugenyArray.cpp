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
int main(){
	setIO();
	cin >> N >> M;
	int a[N];
	int p[N];
	for (int i=0;i<N;i++){
		cin >> a[i];
	}
	int v[2]; memset(v,0,sizeof(v));
	for (int i=0;i<N;i++){
		a[i]=max(a[i],0);
		v[a[i]]++;
	}
	for (int i=0;i<M;i++){
		int s,f; cin >> s >> f;
		if ((f-s+1)%2==0){
			cout << (min(v[0],v[1])>=(f-s+1)/2) << "\n";
		}else{
			cout << "0\n";
		}
	}
}
