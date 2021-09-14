#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int g[1000001];
class Patch{
	public:
		int x;
		int g;
};
bool sorts(Patch &a, Patch &b){
	return (a.x<b.x);
}
int main() {
	freopen("lazy.in","r",stdin);
	freopen("lazy.out","w",stdout);
	int N,K;
	cin >> N >> K;
	Patch l[N];
	for (int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		Patch p;
		p.g=a;
		p.x=b;
		l[i]=p;
	}
	sort(l,l+N,sorts);
	int index = 0;
	if (l[0].x==0){
		g[0]=l[0].g;
		index=1;
	}else{
		g[0]=0;
		index=0;
	}
	for (int i=0;i<1000001;i++){
		if (index < N){
			if (l[index].x==i){
				g[i]=l[index].g+g[i-1];
				index++;
			}else{
				g[i]=g[i-1];
			}
		}else{
			g[i]=g[i-1];
		}
	}
	int maximum=0;
	for (int i=0;i<1000001;i++){
		int low = max(i-K,0);
		int high = min(i+K,1000000);
		if (low!=0){
			maximum=max(g[high]-g[low-1],maximum);
		}else{
			maximum=max(g[high],maximum);
		}
	}
	cout << maximum;
	return 0;
}
