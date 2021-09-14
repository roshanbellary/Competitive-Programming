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
int main(){
	setIO(); cin >> T;
	for (int l=0;l<T;l++){
		int N; cin >> N;
		string r1, r2;
		cin >> r1 >> r2;
		int v[N];
		for (int i=0;i<N;i++){
			if (r1[i]!=r2[i]){
				v[i]=2;
			}else if (r1[i]=='0'){
				v[i]=1;
			}else{
				v[i]=0;
			}
		}
		int sum = 0;
		for (int i=0;i<N;i++){
			if (v[i]==1){
				int j=i+1;
				sum++;
				while (j<N){
					if (v[j]==1){
						j++; sum++;
					}else if (v[j]==0){
						sum++;j++;break;
					}else{
						break;
					}
				}
				i=j-1;
			}else if (v[i]==0){
				int j=i+1;
				while (j<N){
					if (v[j]==0){
						j++;
					}else if (v[j]==1){
						sum+=2;j++;break;
					}else{
						break;
					}
				}
				i=j-1;
			}else{
				sum+=2;
			}
		}
		cout << sum << "\n";
	}
}
