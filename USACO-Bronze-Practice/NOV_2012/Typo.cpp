#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
vector<int> f;
vector<int> b;
int main() {
	freopen("typo.in","r",stdin);
	freopen("typo.out","w",stdout);
	string store;
	getline(cin, store);
	int N = store.length();
	if (store.substr(0,1)=="("){
		f.push_back(1);
		b.push_back(0);
	}else{
		f.push_back(0);
		b.push_back(1);
	}
	for (int i=1;i<N;i++){
		if (store.substr(i,1)=="("){
			f.push_back(f[i-1]+1);
			b.push_back(b[i-1]);
		}else{
			b.push_back(b[i-1]+1);
			f.push_back(f[i-1]);
		}
	}
	bool nbal = false;
	bool bturn = false;
	bool fturn = false;
	int pos = 0;
	if (f[N-1]==b[N-1]+2){
		bturn=true;
	}
	if (b[N-1]==f[N-1]+2){
		fturn=true;
	}
	if (!((abs(f[N-1]-b[N-1])==2))){
		nbal=true;
	}
	if (fturn){
		bool change = false;
		for (int i=0;i<N;i++){
			if ((f[i]>=b[i]-2)&&(f[i]<b[i])&&(!change)){
				change = true;
				pos+=b[i];
				break;
			}else if (f[i]<b[i]-2){
				nbal=true;
				break;
			}
		}
		if (!change){
			nbal=true;
		}
	}
	if (bturn){
		bool change = false;
		int total = 0;
		int temp;
		for (int i=0;i<N;i++){
			if ((f[i]==b[i])||(f[i]==b[i]+1)){
				temp=i;
			}
		}
		int max = 0;
		for (int i=0;i<N;i++){
			if (((f[i]>b[i]+1))&&(i>temp)){
				max=i;
				change = true;
			}
		}
		if (!change){
			nbal=true;
		}else{
			pos+=(f[max]-f[temp]);
		}
	}
	if (nbal){
		cout << 0;
	}else{
		cout << pos;
	}
	return 0;
}
