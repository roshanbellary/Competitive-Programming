/* 
IOI 2003 D. Guess Which Cow
https://contest.yandex.com/ioi/contest/558/problems/D/
I was able to figure out the optimal way to choose which properties to examine first.
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
int N, P;
string v[50];
bool works[50];
set<char> w[8];
void checkPos(){
	for (int i=0;i<8;i++) w[i].clear();
	for (int j=0;j<P;j++){
		for (int i=0;i<N;i++){
			if (works[i]) w[j].insert(v[i][j]);
		}
	}
}
void takeOff(int p, char C){
	for (int i=0;i<N;i++){
		if (v[i][p]!=C) works[i]=false;
	}
}
int main(){
	setIO(); cin >> N >> P;
	for (int i=0;i<50;i++) works[i]=true;
	for (int i=0;i<N;i++){
		v[i]="";
		for (int j=0;j<P;j++){
			char c; cin >> c;v[i]+=c;
		}
	}
	checkPos();
	for (int i=0;i<P;i++){
		if (w[i].size()==1) continue;
		else if (w[i].size()==2){
			cout << "Q " << i+1 << " " << *w[i].begin() << endl;
			bool ans; cin >> ans;
			set<char>::iterator itr = w[i].begin();itr++;
			if (ans) takeOff(i,*w[i].begin());
			else takeOff(i,*itr);
			checkPos();
		}else{
			bool ans;cout << "Q " << i+1 << " " << *w[i].begin() << endl;cin >> ans;
			set<char>::iterator itr = w[i].begin();itr++;
			if (ans) takeOff(i,*w[i].begin());
			else{
				cout << "Q " << i+1 << " " << *itr << endl;cin >> ans;
				if (ans) takeOff(i,*itr);
				else {itr++;takeOff(i,*itr);}
			}
			checkPos();
		}
	}
	for (int i=0;i<N;i++){
		if (works[i]){
			cout << "C " << i+1 << endl;
		}
	}
}
