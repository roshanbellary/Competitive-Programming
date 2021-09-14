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
int N, M;
int a[(int)(2e5+1)];
int t[(int)(2e5+1)];
int main(){
	setIO(); cin >> N >> M;
	int z1 = 0, o1 = 0,z2=0,o2=0;
	for (int i=0;i<N;i++){
		cin >> a[i];
	}
	for (int i=0;i<M;i++){
		cin >> t[i];
	}
	for (int i=0;i<N;i++){
		if (a[i]==0) z1++;
		else o1++;
	}
	for (int i=0;i<M;i++){
		if (t[i]==0) z2++;
		else o2++;
	}
	if (((z1==0)&&(z2>0))||((o1==0)&&(o2>0))){
		cout << "-1\n";
	}else if ((z2>0)&&(o2>0)){
		int pos = -1;
		int i=0; bool w=true;
		while ((i!=0)||w){
			w=false;
			if (a[i]!=a[(i+1)%N]){
				pos=i;
				break;
			}else{
				i++;i%=N;
			}
		}
		int pos2 = -1;
		i=0;w=true;
		while ((i!=0)||w){
			w=false;
			if (a[i]!=a[(i-1+N)%N]){
				pos2=i; break;
			}else{
				i--; i=(i+N)%N;
			}
		}
		if (pos2<pos){
			int ops = 1;
			if (a[(N-pos2)%N]==t[0]){
				ops+=pos2;
			}else ops+=(pos2+1);
			for (int i=1;i<M;i++){
				if (t[i]!=t[i-1]) ops+=2;
				else ops++;
			}
			cout << ops << "\n";
		}else if (pos2==pos){
			int ops = 1;
			if ((a[pos]!=t[0])&&(a[(N-pos2)%N]!=t[0])){
				ops+=(pos+1);
			}else{
				ops+=pos;
			}
			for (int i=1;i<M;i++){
				if (t[i]!=t[i-1]) ops+=2;
				else ops++;
			}
			cout << ops << "\n";
		}else{
			int ops = 1;
			if (a[pos]==t[0]){
				ops+=pos;
			}else ops+=(pos+1);
			for (int i=1;i<M;i++){
				if (t[i]!=t[i-1]) ops+=2;
				else ops++;
			}
			cout << ops << "\n";
		}
	}else if (z2==0){
		int pos = -1;
		for (int i=0;i<N;i++){
			if (a[i]==1){
				pos=i;break;
			}
		}
		int pos2 = -1;
		for (int i=N-1;i>=0;i--){
			if (a[i]==1){
				pos2=N-i;break;
			}
		}
		cout << min(pos,pos2)+M << "\n";
	}else if (o2==0){
		int pos = -1;
		for (int i=0;i<N;i++){
			if (a[i]==0){
				pos=i;break;
			}
		}
		int pos2 = -1;
		for (int i=N-1;i>=0;i--){
			if (a[i]==0){
				pos2=N-i;break;
			}
		}
		cout << min(pos,pos2)+M << "\n";
	}
}
