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
int N,D;
vector<int> bg;
vector<int> eg;
vector<pair<pair<int,int>,int>> b;
vector<pair<pair<int,int>,int>> e;
bool irb = false;
bool ire = false;
int main(){
	setIO("piepie");
	cin >> N >> D;
	map<pair<int,int>,int> m;
	for (int i=0;i<N;i++) bg.push_back(1e9),eg.push_back(1e9);
	for (int i=0;i<N;i++){
		int bf, ef;
		cin >> bf >> ef;
		b.push_back(make_pair(make_pair(ef,bf),i));
	}
	for (int i=0;i<N;i++){
		int bf,ef;
		cin >> bf >> ef;
		e.push_back(make_pair(make_pair(bf,ef),i));
	}
	sort(b.begin(),b.end());
	sort(e.begin(),e.end());
	queue<pair<pair<int,int>,bool>> q;
	for (int i=0;i<N;i++){
		if (e[i].first.first==0) q.push(make_pair(make_pair(i,1),false)),eg[e[i].second]=1;//starts from a e source
		if (b[i].first.first==0) q.push(make_pair(make_pair(i,1),true)),bg[b[i].second]=1;//starts from a bessie source
	}
	while (!q.empty()){
		int ind = q.front().first.first;
		int d = q.front().first.second;
		bool t = q.front().second;
		q.pop();
		if (t){
			int s = 0;
			int f = N-1;
			while (s!=f){
				int mid = (s+f+1)/2;
				if (e[mid].first.first<=b[ind].first.second){
					s=mid;
				}else{
					f=mid-1;
				}
			}
			int maxi = s;
			s=0;f=N-1;
			while (s!=f){
				int mid =(s+f)/2;
				if (e[mid].first.first>=b[ind].first.second-D){
					f=mid;
				}else{
					s=mid+1;
				}
			}
			int mini = s;
			for (int j=mini;j<=maxi;j++){
				if ((e[j].first.first<=b[ind].first.second)&&(e[j].first.first+D>=b[ind].first.second-D)){
					if (eg[e[j].second]>d+1){
						eg[e[j].second]=d+1;
						q.push(make_pair(make_pair(j,d+1),false));
					}
				}
			}
		}else{
			int s = 0;
			int f = N-1;
			while (s!=f){
				int mid = (s+f+1)/2;
				if (b[mid].first.first<=e[ind].first.second){
					s=mid;
				}else{
					f=mid-1;
				}
			}
			int maxi = s;
			s=0;f=N-1;
			while (s!=f){
				int mid =(s+f)/2;
				if (b[mid].first.first>=e[ind].first.second-D){
					f=mid;
				}else{
					s=mid+1;
				}
			}
			int mini = s;
			for (int j=mini;j<=maxi;j++){
				if ((b[j].first.first<=e[ind].first.second)&&(b[j].first.first>=e[ind].first.second-D)){
					if (bg[b[j].second]>d+1){
						bg[b[j].second]=d+1;
						q.push(make_pair(make_pair(j,d+1),true));
					}
				}
			}
		}
	}
	for (int j:bg){
		if (j!=1e9){
			cout << j << "\n";
		}else cout << "-1\n";
	}
}
