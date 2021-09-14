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
class Break{
	public:
		int c,a,l,r;
};
int T;
bool sorts(Break &a, Break &b){
	if (a.c==b.c){return (a.a>=b.a);}
	return (a.c<b.c);
}
int main(){
	setIO();
	cin >> T;
	for (int l=0;l<T;l++){
		vector<Break> c;
		int N; cin >> N;
		for (int i=0;i<N;i++){
			int ai, ci, li, ri;
			cin >> ai >> ci >> li >> ri;
			Break b; b.c=ci;b.a=ai;b.l=li;b.r=ri;
			c.pb(b);
		}
		sort(c.begin(),c.end(),sorts);
		multiset<int> maxs;
		bool w = true;
		for (int i=0;i<N;i++){
			int z=i+1;
			while (z<N){
				if (c[i].c==c[z].c){z++;}
				else break;
			}
			for (int j=i;j<z;j++){
				if (maxs.size()==0){
					continue;
				}else{
					int a = *maxs.rbegin();
					if (a>=c[j].a){
						if (a<c[j].r){
							c[j].a=max(c[j].l,a+1);
						}else{
							w=false;
							break;
						}
					}
				}
			}
			if (!w){break;}
			for (int j=i;j<z;j++){
				maxs.insert(c[j].a);
			}
		}
	}
}
