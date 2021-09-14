#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
int c[(int)(1e5+1)];
int ft[(int)(1e5+1)];
int query(int i){
	return ((i==0)? ft[0]:ft[i]+query(i-(i&(-i))));
}
void update(int i){
	while (i<=N){
		ft[i]++;
		i+=(i&(-i));
	}
}
bool check(int p){
	vector<int> count(N,0);
	for (int i=0;i<p;i++){
		count[N-c[i]-1]++;
	}
	int counter = 0;
	for (int i=0;i<N;i++){
		counter+=count[i];
		if (counter>=i+1){
			return true;
		}
	}
	return false;
}
int main(){
	setIO("greedy"); cin >> N;
	for (int i=0;i<N;i++) cin >> c[i];
	for (int i=0;i<=N;i++) ft[i]=0;
	int s = 0;
	int f = N-1;
	while (s!=f){
		int mid = (s+f)/2;
		if (check(mid)){
			f=mid;
		}else{
			s=mid+1;
		}
	}
	if (!check(N-1)){
		cout << 0 << "\n";
	}else{
		cout << N-s << "\n";
	}
}
