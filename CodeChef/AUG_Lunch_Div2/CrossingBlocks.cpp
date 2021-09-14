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
int T;
class Sorter{
	public:
		int val;
		int pos;
};
bool sorts(Sorter &a, Sorter &b){
	if (a.val==b.val) return (a.pos>b.pos);
	return (a.val<b.val);
}
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		int N; cin >> N;
		vector<int> a(N);
		for (int i=0;i<N;i++) cin >> a[i];
		vector<Sorter> v;
		for (int i=0;i<N;i++){
			Sorter n;
			n.val=a[i];
			n.pos=i;
			v.pb(n);
		}
		sort(v.begin(),v.end(),sorts);
		int pos = -1;
		for (int i=0;i<N;i++){
			if (v[i].pos==0) pos=i;
		}
		if (pos==N-1){
			int currpos = 0;
			int count = 0;
			for (int i=N-1;i>=0;i--){
				int j=i-1;
				while (j>=0){
					if (v[j].val==v[i].val){
						j--;
					}else{
						break;
					}
				}
				j++;
				if (v[j].pos>currpos){currpos=v[j].pos; count++;}
				i=j;
			}
			cout << count << "\n";
		}else{
			cout << "-1\n";
		}
	}
}
