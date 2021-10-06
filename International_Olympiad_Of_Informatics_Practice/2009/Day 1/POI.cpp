/*
International Olympiad In Informatics 2009 Contest Day 1 - POI
https://contest.yandex.ru/ioi/contest/568/download/C/
I was able to understand how to solve this problem quickly via sorting.
*/
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
int mod=1e9+7;
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N, T, P;
int t[2000];
vector<int> n[2000];
int nt[2000];
class Person{
	public:
		int points;
		int tasks;
		int id;
};
bool sorts(Person &a, Person &b){
	if (b.points>a.points) return false;
	if (b.points<a.points) return true;
	if (b.tasks>a.tasks) return false;
	if (b.tasks<a.tasks) return true;
	return (b.id>a.id);
}
int main(){
	setIO();
	cin >> N >> T >> P;
	for (int i=0;i<N;i++){
		int v;
		for (int j=0;j<T;j++){
			cin >> v;
			if (!v) t[j]++,nt[i]++;
			else n[i].pb(j);
		}
	}
	vector<Person> pe;
	for (int i=0;i<N;i++){
		Person p; int points = 0;
		for (int j:n[i]){
			points+=nt[j];
		}
		p.id=i;
		p.points=points;
		p.tasks=n[i].size();
		pe.pb(p);
	}
	sort(pe.begin(),pe.end(),sorts);--P;
	for (int i=0;i<N;i++){
		if (pe[i].id==P){
			cout << pe[i].points << " " << pe[i].id+1 << "\n";
			return 0;
		}
	}

}
