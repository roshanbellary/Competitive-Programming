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
int A, B, N, M;
int main(){
	setIO("fencedin");
	cin >> A >> B >> N >> M;
	ll pa[N]; ll prevb[M];
	for (int i=0;i<N;i++){
		cin >> pa[i];
	}
	for (int i=0;i<M;i++){
		cin >> prevb[i];
	}
	sort(pa,pa+N);
	sort(prevb,prevb+M);
	vector<ll> a(N+1); vector<ll> b(M+1);
	for (int i=0;i<=N;i++){
		if (i==0) a[i]=pa[i];
		else if (i==N) a[i]=(A-pa[i-1]);
		else a[i]=pa[i]-pa[i-1];
	}
	for (int i=0;i<=M;i++){
		if (i==0) b[i]=prevb[i];
		else if (i==M) b[i]=(B-prevb[i-1]);
		else b[i]=prevb[i]-prevb[i-1];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll sum = 0;
	sum+=a[0]*M;
	sum+=b[0]*N;
	int i=1; int j=1;
	while ((i<N+1)&&(j<M+1)){
		if (a[i]<b[j]){
			sum+=a[i]*(M+1-j);
			i++;
		}else{
			sum+=b[j]*(N+1-i);
			j++;
		}
	}	
	cout << sum << "\n";
}
