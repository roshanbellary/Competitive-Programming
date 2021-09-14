#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	freopen("cow.in","r",stdin);
	freopen("cow.out","w",stdout);
	int N;
	cin >> N;
	string store;
	cin >> store;
	long long c[N];
	long long w[N];
	long long result = 0;
	for (int i=0;i<N;i++){
		if (i>0){
			if (store.substr(i,1)=="C"){
				c[i]=c[i-1]+1;
				w[i]=w[i-1];
			} else if (store.substr(i,1)=="W"){
				w[i]=w[i-1]+1;
				c[i]=c[i-1];
			}else{
				w[i]=w[i-1];
				c[i]=c[i-1];
			}
		}else{
			if (store.substr(0,1)=="C"){
				c[0]=1;
				w[0]=0;
			} else if (store.substr(0,1)=="W"){
				w[0]=1;
				c[0]=0;
			}else{
				w[0]=0;
				c[0]=0;
			}
		}
	}
	for (int i=0;i<N;i++){
		if (store.substr(i,1)=="O"){
			result+=c[i]*(w[N-1]-w[i]);
		}
	}
	cout << result;
	return 0;
}
