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
int N, M;
string r[100];
struct Player{
	int points;
	int ind;
};
bool cmp(Player &a, Player &b){
	if (a.points==b.points) return (a.ind<b.ind);
	return (a.points>b.points);
}
bool check(int i1, int i2, int t){
	if (r[i1][t]=='G' && r[i2][t]=='C') return true;
	if (r[i1][t]=='C' && r[i2][t]=='P') return true;
	if (r[i1][t]=='P' && r[i2][t]=='G') return true;
	return false;
}
int main(){
	setIO();cin >> N >> M;
	for (int i=0;i<2*N;i++){
		cin >> r[i];
	}
	vector<Player> ppl;
	for (int i=0;i<2*N;i++){
		ppl.pb({0,i});
	}
	for (int i=0;i<M;i++){
		for (int j=0;j<2*N;j+=2){
			int ind1 = ppl[j].ind;
			int ind2 = ppl[j+1].ind;
			if (check(ind1,ind2,i)) ppl[j].points++;
			if (check(ind2,ind1,i)) ppl[j+1].points++;
		}
		sort(ppl.begin(),ppl.end(),cmp);
	}
	for (int i=0;i<2*N;i++){
		cout << ppl[i].ind+1 << "\n";
	}
}
