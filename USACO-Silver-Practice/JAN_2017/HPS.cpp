#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> h;
vector<int> p;
vector<int> s;
void add(char a, int i){
	if (i!=0){
		if (a=='P'){
			p.push_back(p[i-1]+1);
			h.push_back(h[i-1]);
			s.push_back(s[i-1]);
		}
		if (a=='H'){
			h.push_back(h[i-1]+1);
			p.push_back(p[i-1]);
			s.push_back(s[i-1]);
		}
		if (a=='S'){
			s.push_back(s[i-1]+1);
			p.push_back(p[i-1]);
			h.push_back(h[i-1]);
		}
	}else{
		if (a=='P'){
			p.push_back(1);
			h.push_back(0);
			s.push_back(0);
		}
		if (a=='H'){
			h.push_back(1);
			p.push_back(0);
			s.push_back(0);
		}
		if (a=='S'){
			s.push_back(1);
			h.push_back(0);
			p.push_back(0);
		}
	}
}
int main() {
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
	int N;
	cin >> N;
	for (int i=0;i<N;i++){
		char a;
		cin >> a;
		add(a,i);
	}
	int maximum = 0;
	for (int i=0;i<N;i++){
		int store = max(max(s[i],h[i]),p[i])+max(max(s[N-1]-s[i],h[N-1]-h[i]),p[N-1]-p[i]);
		if (maximum<store){
			maximum=store;
		}
	}
	cout << maximum;
	return 0;
}
