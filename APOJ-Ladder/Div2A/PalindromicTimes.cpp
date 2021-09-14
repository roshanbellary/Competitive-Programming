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
string t;
int main(){
	setIO();
	cin >> t;
	int minu = stoi(t.substr(0,2));
	int sec = stoi(t.substr(3));
	int count = 0;
	string mins,secs;
	while (count<3600){
		sec++;
		if (sec>59){
			sec%=60;
			minu++;
			if (minu>23){
				minu%=24;
			}
		}
		string a=to_string(sec),b=to_string(minu);
		if (sec<10){a="0"+a;}
		if (minu<10){b="0"+b;}
		if ((a[0]==b[1])&&(a[1]==b[0])){
			mins=b;secs=a;
			break;
		}
		count++;
	}
	cout << mins+":"+secs << "\n";
}
