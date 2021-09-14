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
		int N, M; cin >> N >> M;
		int a[N];
		for (int i=0;i<N;i++){cin >> a[i];a[i]%=M;}
		int dp[N];
		for (int i=0;i<N;i++){
			if (i==0) dp[i]=a[i];
			else{
				dp[i]=(a[i]+dp[i-1])%M;
				dp[i]%=M;
			}
		}
		int minn = 1e9;
		for (int i=0;i<N;i++){
			for (int j=i;j<N;j++){
				if (i!=0){
					if ((dp[j]-dp[i-1]==0)&&(((N-1-j)&i)==i)){
						minn=min(minn,__builtin_popcount(i|(N-1-j)));
					}
				}else{
					if ((dp[j]==0)&&(((N-1-j)&i)==i)){
						minn=min(minn,__builtin_popcount(i|(N-1-j)));
					}
				}
			}
		}
		if (minn!=1e9) cout << minn << "\n";
		else cout << "-1\n";
	}
}
