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
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, M, S;
double A[(int)1e6];
double p[(int)1e6+1];
double sum=0;
int main(){
	setIO(); cin >> N >> M >> S;
	for (int i=0;i<N;i++){
		cin >> A[i];sum+=A[i];
	}
	p[0]=0;
	for (int i=0;i<N;i++){
		p[i+1]=p[i]+A[i];
	}
	double res = 0;
	for (int i=0;i<=N;i++){
		for (int j=0;j<=N-i;j++){
			int d = N-i-j;
			if (d*M>S) continue;
			int diff = S-d*M;
			if ((j==0 && diff!=0)||(j*M<diff)) continue;
			double add = diff/((double)j);
			res=max(res,(p[i+j]-p[i])*add+(p[N]-p[i+j])*M);
		}
	}
	cout << fixed << setprecision(10) << res << "\n";
}
