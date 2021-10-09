/*
USACO 2012 December Contest, Gold Problem 1. Gangs of Instanbull/Cowstantinople
http://usaco.org/index.php?page=viewproblem2&cpid=211
Interesting recursion problem it took me some time to figure out how to reach O(N^3) while 
printing out the lexographic order. The lexographic order part took me the most time to 
figure out.
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
void update_state(int& gang, int& cur, int cgang) {
  if(cur == 0) {
    gang = cgang;
  }
  if(gang == cgang) {
    cur++;
  } else {
    cur--;
  }
}
int max_cows(int gang, int cur, vector<int> G) {
  sort(G.begin()+1,G.end());
  while(G.back() > 0) {
    for(int i = G.size() - 1; i > 0; i--) {
      update_state(gang, cur, i);
      G[i]--;
      if(G[i - 1] <= G[i]) {
        break;
      }
    }
  }
  for(int i = 0; i < G[0]; i++) {
    update_state(gang, cur, 0);
  }
  return gang == 0 ? cur : 0;
}
vector<int> G(100);
int main() {
  setIO("gangs");
  int N, M; cin >> N >> M;
  for(int i=0;i<N;i++) {
    cin >> G[i];
  }
  int gang = 0;
  int cows = 0;
  int res = max_cows(gang, cows, G);
  if(res > 0) {
    cout << "YES\n" << res << "\n";
    for(int i = 0; i < N; i++) {
      int pgang = gang;int pcows = cows;
      for(int j = 0; ; j++) {
        if(G[j] == 0) {continue;}
        G[j]--;update_state(gang, cows, j);
        if(max_cows(gang, cows, G) == res) {
          cout << j+1 << '\n';
          break;
        }
        G[j]++;
        gang = pgang;
        cows = pcows;
      }
    }
  } else {
    cout << "NO" << endl;
  }
}
