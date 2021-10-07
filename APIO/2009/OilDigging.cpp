//had to use editorial to solve problem
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
using namespace std;
int M, N, K,dp[1500][1500][2],pp[1500][1500][4],pq[1500][1500],ar[1500][1500];
int main(){
	ios_base::sync_with_stdio(0);
	cin >> M >> N >> K;
	for(int i = 0; i < M; i++) for(int j = 0; j < N; j++) cin >> ar[i][j];
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			pq[i][j] = ar[i][j];
			if(i) pq[i][j] += pq[i-1][j];
			if(j) pq[i][j] += pq[i][j-1];
			if(i && j) pq[i][j] -= pq[i-1][j-1];
		}
	}
	for(int i = K-1; i < M; i++) for(int j = K-1; j < N; j++){
		pp[i][j][0] = pq[i][j];
		if(i > K-1) pp[i][j][0] -= pq[i-K][j];
		if(j > K-1) pp[i][j][0] -= pq[i][j-K];
		if(i > K-1 && j > K-1) pp[i][j][0] += pq[i-K][j-K];
	}
	for(int i = M-1; i >= 0; i--){
		for(int j = 0; j < N; j++){
			pq[i][j] = ar[i][j];
			if(i<M-1) pq[i][j] += pq[i+1][j];
			if(j) pq[i][j] += pq[i][j-1];
			if(i<M-1 && j) pq[i][j] -= pq[i+1][j-1];
		}
	}
	for(int i = M-K; i >= 0; i--) for(int j = K-1; j < N; j++){
		pp[i][j][1] = pq[i][j];
		if(i < M-K) pp[i][j][1] -= pq[i+K][j];
		if(j > K-1) pp[i][j][1] -= pq[i][j-K];
		if(i < M-K && j > K-1) pp[i][j][1] += pq[i+K][j-K];
	}
	for(int i = 0; i < M; i++){
		for(int j = N-1; j >= 0; j--){
			pq[i][j] = ar[i][j];
			if(i) pq[i][j] += pq[i-1][j];
			if(j<N-1) pq[i][j] += pq[i][j+1];
			if(i && j<N-1) pq[i][j] -= pq[i-1][j+1];
		}
	}
	for(int i = K-1; i < M; i++) for(int j = N-K; j >= 0; j--){
		pp[i][j][2] = pq[i][j];
		if(i > K-1) pp[i][j][2] -= pq[i-K][j];
		if(j < N-K) pp[i][j][2] -= pq[i][j+K];
		if(i > K-1 && j < N-K) pp[i][j][2] += pq[i-K][j+K];
	}
	for(int i = M-1; i >= 0; i--){
		for(int j = N-1; j >= 0; j--){
			pq[i][j] = ar[i][j];
			if(i<M-1) pq[i][j] += pq[i+1][j];
			if(j<N-1) pq[i][j] += pq[i][j+1];
			if(i<M-1 && j<N-1) pq[i][j] -= pq[i+1][j+1];
		}
	}
	for(int i = M-K; i >= 0; i--) for(int j = N-K; j >= 0; j--){
		pp[i][j][3] = pq[i][j];
		if(i < M-K) pp[i][j][3] -= pq[i+K][j];
		if(j < N-K) pp[i][j][3] -= pq[i][j+K];
		if(i < M-K && j < N-K) pp[i][j][3] += pq[i+K][j+K];
	}
	for(int i = K-1; i < M; i++){
		int Mx = 0;
		for(int j = 0; j < N; j++){
			Mx = max(Mx, pp[i][j][0]);
		}
		dp[i-K+1][i][0] = Mx;
	}
	for(int l = K; l < M; l++){
		for(int i = 0; i < M-l; i++){
			dp[i][i+l][0] = max(max(dp[i+1][i+l][0],dp[i][i+K-1][0]), max(dp[i][i+l-1][0],dp[i+l-K+1][i+l][0]));
		}
	}
	for(int i = K-1; i < N; i++){
		int Mx = 0;
		for(int j = 0; j < M; j++){
			Mx = max(Mx, pp[j][i][0]);
		}
		dp[i-K+1][i][1] = Mx;
	}
	for(int l = K; l < N; l++){
		for(int i = 0; i < N-l; i++){
			dp[i][i+l][1] = max(max(dp[i+1][i+l][1],dp[i][i+K-1][1]), max(dp[i][i+l-1][1],dp[i+l-K+1][i+l][1]));
		}
	}
	for(int i = 0; i < M; i++) for(int j = 0; j < N; j++){
		if(i) pp[i][j][0] = max(pp[i][j][0], pp[i-1][j][0]);
		if(j) pp[i][j][0] = max(pp[i][j][0], pp[i][j-1][0]);
	}
	for(int i = M-1; i >= 0; i--) for(int j = 0; j < N; j++){
		if(i < M-1) pp[i][j][1] = max(pp[i][j][1], pp[i+1][j][1]);
		if(j) pp[i][j][1] = max(pp[i][j][1], pp[i][j-1][1]);
	}
	for(int i = 0; i < M; i++) for(int j = N-1; j >= 0; j--){
		if(i) pp[i][j][2] = max(pp[i][j][2], pp[i-1][j][2]);
		if(j < N-1) pp[i][j][2] = max(pp[i][j][2], pp[i][j+1][2]);
	}
	for(int i = M-1; i >= 0; i--) for(int j = N-1; j >= 0; j--){
		if(i < M-1) pp[i][j][3] = max(pp[i][j][3], pp[i+1][j][3]);
		if(j < N-1) pp[i][j][3] = max(pp[i][j][3], pp[i][j+1][3]);
	}
	int ans = 0;
	for(int i = K; i < M-K; i++){
		for(int j = K; j < N-K; j++){
			ans = max(ans, pp[i-1][N-1][0]+pp[i][j-1][1]+pp[i][j][3]);
			ans = max(ans, pp[i-1][j-1][0]+pp[i-1][j][2]+pp[i][N-1][1]);
			ans = max(ans, pp[i-1][j-1][0]+pp[i][j-1][1]+pp[M-1][j][2]);
			ans = max(ans, pp[M-1][j-1][0]+pp[i-1][j][2]+pp[i][j][3]);
		}
	}
	for(int i = 1; i < M; i++) for(int j = i+K; j < M; j++){
		ans = max(ans, pp[i-1][N-1][0]+dp[i][j-1][0]+pp[j][N-1][1]);
	}
	for(int i = 1; i < N; i++) for(int j = i+K; j < N; j++){
		ans = max(ans, pp[M-1][i-1][0]+dp[i][j-1][1]+pp[M-1][j][2]);
	}
	cout << ans << endl;
}
