#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
int N, M;
int main(){
	setIO();
	cin >> N >> M;
	if ((M>2*(N+1))||(M<N-1)){
		cout << "-1\n";
	}else{
		string s = "";
		int left = M-(N-1);
		if (left>=(N-1)){
			int temp = left-N+1;
			if (temp>0) left-=temp;
			if (temp>0){
				for (int i=0;i<min(temp,2);i++){
					s+="1"; temp--;
				}
			}
			for (int i=0;i<left;i++){
				s+="011";
			}
			for (int i=left;i<N-1;i++){
				s+="01";
			}
			s+="0";
			for (int j=0;j<min(temp,2);j++){
				s+="1";
			}
		}else{
			for (int i=0;i<left;i++){
				s+="011";
			}
			for (int i=left;i<N-1;i++){
				s+="01";
			}
			s+="0";
		}
		cout << s << "\n";
	}
}
