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
vector<pair<double,double>> c;
bool find(int i, int j, int n){// returns true if value is greater
	double slope;
	if (c[j].first!=c[i].first){
		slope=(c[j].second-c[i].second)/(c[j].first-c[i].first);
		double val = slope*(c[n].first-c[i].first)+c[i].second;
		return (val<=c[n].second);
	}
	return false;
}
int main(){
	setIO("triangles");
	cin >> N;
	for (int i=0;i<N;i++){
		double x, y; cin >> x >> y;
		c.pb({x,y});
	}
	sort(c.begin(),c.end());
	int b[N][N];
	int a[N][N];
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){b[i][j]=0;a[i][j]=0;}
	}
	for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			if (i==j) continue;
			for (int z=i+1;z<j;z++){
				if (find(i,j,z)){
					a[i][j]++;
				}else{
					b[i][j]++;
				}
			}
		}
	}
	vector<int> v(N-2,0);
	for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			for (int z=j+1;z<N;z++){
				if (!find(i,z,j)){
					v[b[i][z]-1-b[i][j]-b[j][z]]++;
				}else{
					v[a[i][z]-1-a[i][j]-a[j][z]]++;
				}
			}
		}
	}
	for (int j:v) cout << j << "\n";
}
