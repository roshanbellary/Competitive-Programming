//had to use editorial to solve problem
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
#define f first
#define s second
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
const int MX=1e9;
int countseq(int mnval, int K, int len){
  int succ = MX - mnval;
  int DP[len + 2];
  int pows[K + 1];
  int powslow[K + 1];
  pows[0] = 1;
  powslow[0] = 1;
  for (int i = 1; i <= K; i++){
    pows[i] = (pows[i-1]*(succ+1))%mod;
    powslow[i] = (pows[i-1]*succ)%mod;
  }
  DP[0] = 1;
  DP[1] = 1;
  for (int i = 2; i <= min(K, len); i++){
    DP[i] = pows[i - 1];
  }
  if (len < K){
    return pows[len];
  }
  for (int i = K; i <= len; i++){
      DP[i + 1] = DP[i];
      DP[i + 1]=(DP[i+1]-(DP[i - K]*powslow[K - 1]))%mod;
      DP[i + 1]=(DP[i+1]*succ)%mod;
      DP[i + 1]+=(DP[i])%mod;
	  DP[i]%=mod;
  }
  return DP[len + 1];
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, K; cin >> N >> K;
    vector<int> in(N - K + 1);
    for (int i = 0; i < N - K + 1; i++){
      cin >> in[i];
    }
    vector<pair<int,int>> comp;
    int cur = -1;
    int cnt = 0;
    for (int i = 0; i < N - K + 1; i++){
      if (cur == in[i]){
        ++cnt;
      }
      else{
        if (cnt) comp.pb({cur, cnt});
        cur = in[i];
        cnt = 1;
      }
    }
    comp.pb({cur, cnt});
    if (comp.size() == 1){
      cout << countseq(comp[0].f, K, N) << endl;
    }
    else{
        int res = 1;
        for (int i = 0; i < comp.size(); i++){
          int a = comp[i].f;
          int len;
          if (i == 0){
            if (comp[1].f > comp[0].f){
              len = comp[0].s - 1;
            }
            else{
              len = comp[0].s + K - 1;
            }
          }
          else if (i == comp.size() - 1){
            if (comp[i - 1].f > comp[i].f){
              len = comp[i].s - 1;
            }
            else{
              len = comp[i].s + K - 1;
            }
          }
          else{
            if (comp[i - 1].f > comp[i].f){
              if (comp[i + 1].f > comp[i].f){
                len = max(0, comp[i].s - K - 1);
              }
              else{
                len = comp[i].s - 1;
              }
            }
            else{
              if (comp[i + 1].f > comp[i].f){
                len = comp[i].s - 1;
              }
              else{
                len = comp[i].s + K - 1;
              }
            }
          }
          res=(res*countseq(a, K, len))%mod;
        }
        cout << res << endl;
    }
}