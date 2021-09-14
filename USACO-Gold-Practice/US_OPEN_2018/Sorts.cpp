#include <bits/stdc++.h>
using namespace std;
vector<int> ft;
int query(int i){
	return (i>0)? ft[i]+query(i-(i&(-i))):0;
}
void update(int i){
	while (i<=ft.size()){
		ft[i]++;
		i+=(i&(-i));
	}
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int N; cin >> N;
	int v[N]; int st[N];
	for (int i=0;i<N;i++){
		cin >> v[i];
		st[i]=v[i];
	}
	sort(st,st+N);
	int count = 1;
	map<int,int> m;
	for (int i=0;i<N;i++){
		int j = i+1;
		while (j<N){
			if (st[j]!=st[i]){
				break;
			}
			j++;
		}
		m[st[i]]=count;
		count++;
		i=j-1;
	}
	for (int i=0;i<count;i++) ft.push_back(0);
	for (int i=0;i<N;i++){
		v[i]=m[v[i]];
	}
	int s[N];
	for (int i=0;i<N;i++) s[i]=v[i];
	sort(s,s+N);
	int totmax = 0;
	for (int i=0;i<N;i++){
		totmax=max(totmax,query(count-1)-query(s[i]-1));
		update(v[i]);
	}
	cout << totmax << "\n";
}
