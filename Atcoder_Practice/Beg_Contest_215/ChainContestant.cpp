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
int N;
string s;
int main(){
	setIO();
	cin >> N >> s;
	ll dp[N][10][10]; // i is the position, t is the type that we're ending on, number of blocks
	ll p[10][N];
	p[s[0]-'a'][0]=1;
	for (int i=1;i<10;i++){
		p[(s[0]-'a'+i)%10][0]=0;
	}
	for (int i=1;i<N;i++){
		p[s[i]-'a'][i]=1+p[s[i]-'a'][i];
		for (int j=1;j<10;j++){
			p[(s[i]-'a'+i)%10][i]=p[(s[i]-'a'+i)%10][i-1];
		}
	}
	for (int i=0;i<N;i++){
		for (int j=0;j<10;j++){
			for (int k=1;k<10;k++){
				for (int z=0;z<i;z++){
					dp[i][j][k]+=dp[z][j][k-1];
				}
			}
		}
	}
}
