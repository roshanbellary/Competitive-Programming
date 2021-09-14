#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
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
int H,W, N;
int main(){
	setIO();
	cin >> H >> W >> N;
	vector<pair<int,int>> x;
	vector<pair<int,int>> y;
	for (int i=0;i<N;i++){
		int a,b; cin >> a >> b;
		x.push_back(make_pair(a,i));
		y.push_back(make_pair(b,i));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	int xs[N];
	int ys[N];
	map<int,int> mx;
	map<int,int> my;
	int count = 1;
	for (int i=0;i<N;i++){
		mx[x[i].first]=count;
		int j=i+1;
		while (j<N){
			if (x[j].first!=x[i].first) break;
			else j++;
		}
		i=j-1;count++;
	}
	count = 1;
	for (int i=0;i<N;i++){
		my[y[i].first]=count;
		int j=i+1;
		while (j<N){
			if (y[j].first!=y[i].first) break;
			else j++;
		}
		i=j-1;count++;
	}
	for (int i=0;i<N;i++){
		xs[x[i].second]=mx[x[i].first];
		ys[y[i].second]=my[y[i].first];
	}
	for (int i=0;i<N;i++){
		cout << xs[i] << " " << ys[i] << "\n";
	}
}
