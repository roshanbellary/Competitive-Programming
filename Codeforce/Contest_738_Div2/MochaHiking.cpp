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
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		int N; cin >> N;
		int a[N];
		for (int i=0;i<N;i++){
			cin >> a[i];
		}
		int pos = -1;
		for (int i=0;i<N-1;i++){
			if ((a[i]==0)&&(a[i+1]==1)){
				pos=i;
			}
		}
		if (pos>=0){
			for (int i=0;i<pos;i++){
				cout << i+1 << " ";
			}
			cout << pos+1 << " " << N+1 << " " << pos+2 << " ";
			for (int i=pos+2;i<N;i++){
				cout << i+1 << " ";
			}
		}else{
			if (a[N-1]==0){
				for (int i=0;i<N;i++){
					cout << i+1 << " ";
				}
				cout << N+1 << " ";
			}else if (a[0]==1){
				cout << N+1 << " ";
				for (int i=0;i<N;i++){
					cout << i+1 << " ";
				}
			}
		}
		cout << "\n";
	}
}
