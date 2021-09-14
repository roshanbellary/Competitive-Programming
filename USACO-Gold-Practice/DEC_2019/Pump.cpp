//Working Sol created during Contest
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
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
int N, M;
vector<vector<pair<int,pair<int,int>>>> l;
int main(){
	setIO("pump");
	cin >> N >> M;
	for (int i=0;i<N;i++) l.push_back(vector<pair<int,pair<int,int>>>());
	vector<int> flows;
	for (int i=0;i<M;i++){
		int a,b; cin >> a >> b;a--;b--;
		int c,f; cin >> c >> f;
		l[a].push_back(make_pair(b,make_pair(c,f)));
		l[b].push_back(make_pair(a,make_pair(c,f)));
		flows.push_back(f);
	}
	double maxR = 0;
	for (int i=0;i<M;i++){
		int minf = flows[i];
		vector<int> d(N,1e9);
		vector<int> f(N,0);
		vector<bool> v(N,false);
		d[0]=0;
		f[0]=1e9;
		while (true){
			int ind = -1;
			int minC = 1e9;
			for (int i=0;i<N;i++){
				if (!v[i]&&(d[i]<minC)){ind=i;minC=d[i];}
			}
			if (ind<0) break;
			v[ind]=true;
			for (pair<int,pair<int,int>> a:l[ind]){
				if ((a.second.second>=minf)&&(minC+a.second.first<d[a.first])){
					d[a.first]=minC+a.second.first;
					f[a.first]=min(f[ind],a.second.second);
				}
			}
		}
		maxR = max((1e6)*(f[N-1])/((double)d[N-1]),maxR);
	}
	cout << (ll)(maxR) << "\n";
}
