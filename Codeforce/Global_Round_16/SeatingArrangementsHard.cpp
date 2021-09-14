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
#define mod 1e9+7
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int T;
vector<vector<int>> ft(300,vector<int>(301,0));
void update(int r, int i){
	while (i<=300){
		ft[r][i]++;
		i+=(i&(-i));
	}
}
int query(int r, int i){
	return ((i==0)?0:ft[r][i]+query(r,i-(i&(-i))));
}
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		int N, M; cin >> N >> M;
		int v[N*M];
		for (int i=0;i<N*M;i++){
			cin >> v[i];
		}
		vector<pair<int,int>> s;
		for (int i=0;i<N*M;i++){
			s.pb({v[i],-i});
		}
		sort(s.begin(),s.end());
		map<pair<int,int>,int> m;
		int count = 0;
		for (int i=0;i<N*M;i++){
			int j=i+1;
			while (j<N*M){
				if (s[j].first==s[i].first){
					j++;
				}else{
					break;
				}
			}
			for (int z=i;z<j;z++){
				m[s[z]]=count;
				count++;
			}
			i=j-1;
		}
		int sum = 0;
		for (int i=0;i<N*M;i++){
			int pos = m[{v[i],-i}];
			int row = (pos)/M;
			int col = (pos)%M+1;
			sum+=query(row,col-1);
			cout << row << " " << col << " " << query(row,col-1) << " " << v[i] << " " << ft[row][col-1] << "\n";
			update(row,col);
		}
		cout << sum << "\n";
		for (int i=0;i<300;i++){
			fill(ft[i].begin(),ft[i].end(),0);
		}
	}
}
