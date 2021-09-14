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
string s;
int K;
int fact[9]={1,1,2,6,24,120,720,5040,40320};
int main(){
	setIO();
	cin >> s >> K;
	int n = 1;
	sort(s.begin(),s.end());
	if (K==1){
		cout << s << "\n";
	}else{
		n++;
		while (next_permutation(s.begin(),s.end())){
			if (K==n){
				cout << s << "\n";
				break;
			}else{
				n++;
			}
		}
	}
}
