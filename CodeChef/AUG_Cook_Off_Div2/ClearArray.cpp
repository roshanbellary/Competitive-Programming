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
		int N,K;
		ll X; cin >> N >> K >> X;
		ll a[N];
		for (int i=0;i<N;i++){
			cin >> a[i];
		}
		ll p[N];
		for (int i=0;i<N;i++){
			if (i==0) p[i]=a[i];
			else p[i]=p[i-1]+a[i];
		}
		ll left[N][K+1];
		ll right[N][K+1];
		left[0][1]=p[0]-X;
		for (int i=0;i<N;i++){
			left[i][0]=0;
		}
		for (int i=2;i<=K;i++){
			left[0][i]=0;
		}
		for (int k=1;k<=K;k++){
			for (int i=1;i<N;i++){
				ll mini = 0;
				for (int j=0;j<i;j++){
					mini=min(left[j][k-1]+X-a[j+1],mini);
				}
				left[i][k]=mini;
			}
		}
		right[N-1][1]=p[N-1]-p[N-2]-X;
		for (int i=0;i<N;i++){
			right[i][0]=0;
		}
		for (int i=2;i<=K;i++){
			right[0][i]=0;
		}
		for (int k=1;k<=K;k++){
			for (int i=N-2;i>=0;i--){
				ll mini = 0;
				for (int j=i+1;j<N;j++){
					mini=min(right[j][k-1]+X-a[j-1],mini);
				}
				right[i][k]=mini;
			}
		}
		ll mini = p[N-1];
		for (int i=1;i<N-1;i++){
			int count = min(min(i,N-i),K);
			for (int k=0;k<=count;k++){
				mini=min(mini,left[i-1][k]+p[i-1]+right[i+1][k]+p[N-1]-p[i]-X*k+a[i]);
			}
		}
		cout << mini << "\n";
	}
}
