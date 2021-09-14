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
int N;
ll s[200001];
ll t[200001];
ll d[200001];
int main(){
	setIO();
	cin >> N;
	for (int i=0;i<N;i++) cin >> s[i];
	for (int i=0;i<N;i++) cin >> t[i];
	for (int i=0;i<N;i++) d[i]=t[i];
	int start = 0; ll miniv = t[0]+s[0];
	for (int i=1;i<=2*N;i++){
		int ind = (start+i)%N;
		d[ind]=min(miniv,d[ind]);
		miniv=min(miniv+s[ind],t[ind]+s[ind]);
	}
	for (int i=0;i<N;i++){
		cout << d[i] << "\n";
	}
}
