#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Bales{
public:
	int s;
	int p;
};
vector<Bales> b;
bool sorts(Bales &a, Bales &b){
	return (a.p<b.p);
}
bool check(Bales &a, Bales &b,int diff){
	return (b.p-a.p-diff>a.s)&&(b.p-a.p-diff>b.s);
}
int main() {
	int N;
	freopen("trapped.in","r",stdin);
	freopen("trapped.out","w",stdout);
	cin >> N;
	for (int i=0;i<N;i++){
		Bales store;
		int s,p;
		cin >> s >> p;
		store.s=s;
		store.p=p;
		b.push_back(store);
	}
	sort(b.begin(),b.end(),sorts);
	int area=0;
	for (int i=0;i<N;i++){
		int left = i;
		int right = i+1;
		int temp = b[i+1].p-b[i].p;
		while (left>=0 && right<=N-1){
			bool through = false;
			int dist = b[right].p-b[left].p;
			if (dist > b[left].s){
				left--;
				through=true;
			}
			if (dist > b[right].s){
				right++;
				through=true;
			}
			if (!through){
				break;
			}
		}
		if (left>=0 && right<=N-1){
			area+=temp;
		}
	}
	cout << area;
	return 0;
}
