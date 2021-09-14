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
int main(){
	setIO("cardgame");
	cin >> N;
	vector<bool> t(2*N,false);
	vector<int> e;
	vector<int> b;
	set<int> bc1;
	set<int> bc2;
	set<int> ec;
	for (int i=0;i<N;i++){
		int v; cin >> v;v--;
		t[v]=true;
		e.push_back(v);
	}
	for (int i=0;i<2*N;i++){
		if (!t[i]) b.push_back(i);
	}
	for (int i:b){bc1.insert(i); bc2.insert(i);}
	int h[N];int i = 0;
	for (int j:e){
		auto itr = bc1.lower_bound(j);
		if (itr==bc1.end()){
			h[i] = (i!=0)?h[i]=h[i-1]:0;
		}else{
			bc1.erase(*itr);
			if (i!=0) h[i]=h[i-1]+1;
			else h[i]=1;
		}
		i++;
	}
	int l[N];
	i=N-1;
	for (int j=N-1;i>=0;j--){
		auto i2 = bc2.lower_bound(e[j]);
		if (i2!=bc2.begin()){
			i2--;
			bc2.erase(*i2);
			if (i!=N-1) l[i]=l[i+1]+1;
			else l[i]=1;
		}else{
			if (i!=N-1) l[i]=l[i+1];
			else l[i]=0;
		}
		i--;
	}
	int mv = 0;
	for (int i=0;i<N-1;i++){
		mv=max(h[i]+l[i+1],mv);
	}
	mv=max(mv,max(l[0],h[N-1]));
	cout << mv << "\n";
}
