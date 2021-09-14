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
int main(){
	setIO();
	double r1,r2,c1,c2,d1,d2;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	double a,b,c,d;
	a=(r1+c1-d2)/2;
	b=(r1+c2-d1)/2;
	c=(c1+r2-d1)/2;
	d=(r2+c2-d2)/2;
	bool w1 = ((a+b==r1)&&(c+d==r2)&&(a+c==c1)&&(b+d==c2)&&(a+d==d1)&&(b+c==d2));
	bool w2 = !((a==b)||(a==c)||(a==d)||(b==c)||(b==d)||(c==d));
	bool w3 = !((a!=(int)a)||(b!=(int)b)||(c!=(int)c)||(d!=(int)d));
	bool w4 = !(((a<1)||(a>9))||((b<1)||(b>9))||((c<1)||(c>9))||((d<1)||(d>9)));
	if (w1&&w2&&w3&&w4){
		cout << a << " " << b << "\n";
		cout << c << " " << d << "\n";
	}else cout << "-1\n";
}
