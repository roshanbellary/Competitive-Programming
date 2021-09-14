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
int mod = 1e9+7;
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
		for (int i=0;i<N;i++) cin >> a[i];
		queue<int> qp1;
		queue<int> qn1;
		queue<int> qp2;
		queue<int> qn2;
		for (int i=0;i<N;i++){
			if (a[i]%2==0){qp1.push(i);qp2.push(i);}
			else{qn1.push(i);qn2.push(i);}
		}
		if ((N%2==0)&&(qp1.size()!=N/2)) cout << "-1\n";
		else if ((N%2==1)&&((qp1.size()<N/2)||(qn1.size()<N/2))) cout << "-1\n";
		else{
			ll sum1 = 0;
			if ((N%2==1)&&(qp2.size()<(N+1)/2)){
				sum1+=1e18;
			}else{
				for (int i=0;i<N;i++){
					if (i%2==0){
						sum1+=abs(qp1.front()-i);
						qp1.pop();
					}else{
						sum1+=abs(qn1.front()-i);
						qn1.pop();
					}
				}
			}
			ll sum2 = 0;
			if ((N%2==1)&&(qn2.size()<(N+1)/2)){
				sum2+=1e18;
			}else{
				for (int i=0;i<N;i++){
					if (i%2==0){
						sum2+=abs(i-qn2.front());
						qn2.pop();
					}else{
						sum2+=abs(i-qp2.front());
						qp2.pop();
					}
				}
			}
			cout << min(sum1/2,sum2/2) << "\n";
		}
	
	}
}
