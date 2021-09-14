#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ll long long
#define int long long
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
int32_t main(){
	setIO();
	cin >> s;
	int N = s.length();
	int pos = -1;
	for (int i=0;i<N;i++){
		if (s[i]=='^'){pos=i;break;}
	}
	int rsum = 0;
	int lsum = 0;
	string n = "123456789";
	for (int i=0;i<pos;i++){
		if (n.find(s[i])!=string::npos){
			lsum+=((pos-i)*(s[i]-'0'));
		}
	}
	for (int i=pos+1;i<N;i++){
		if (n.find(s[i])!=string::npos){
			rsum+=((i-pos)*(s[i]-'0'));
		}
	}
	if (rsum>lsum) cout << "right\n";
	else if (rsum==lsum) cout << "balance\n";
	else cout << "left\n";
}
