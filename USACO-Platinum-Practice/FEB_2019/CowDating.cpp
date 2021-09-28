/*
USACO 2019 February Contest, Platinum Problem 1. Cow Dating
http://www.usaco.org/index.php?page=viewproblem2&cpid=924
Cool two pointer method problem. It took me a lot of time figuring out the end condition to 
stop adding on a new probability.
*/
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
int N;
double prod = 1; 
int main(){
	setIO("cowdate");
	cin >> N;
	double p[N];
	for (int i=0;i<N;i++){
		cin >> p[i];
		p[i]/=1e6;
	}
	double maxp = 0;
	int l = 0;
	int r = 0;
	double sum = 0;
	double prod = 1;
	while (l<N){
		while (r<N){
			if (sum>=1){
				break;
			}else{
				prod*=(1-p[r]);
				sum+=(p[r]/(1-p[r]));
				r++;
			}
		}
		maxp=max(prod*sum,maxp);
		sum-=p[l]/(1-p[l]);
		prod/=(1-p[l]);
		l++;
	}
	cout << (int)(1e6*maxp) << "\n";
}
