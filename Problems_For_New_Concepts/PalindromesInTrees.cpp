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
const int L=200005,N=(1<<20);
vector<int> parts[L],ad[L]; bool vis[L];
int sizes[L],par[L],part[L],H[L],cpart;
ll res[L],dp[L];
string s;
int dfssizes(int u,int p=-1){
  sizes[u]=1;
  for(int v:ad[u])
    if(!vis[v] && v!=p)
      sizes[u]+=dfssizes(v,u);
  return sizes[u];
}
int dfsFC(int u,int r,int p=-1){
  for(int v:ad[u])
    if(!vis[v] && v!=p)
      {
  if(sizes[v]>sizes[r]/2)
    return dfsFC(v,r,u);
      }
  return u;
}
int cnt[N],val[L],tmp[N];
void dfs1(int u,int r,int p=-1){
  dp[u]=0;
  if(p==r){
	part[u]=++cpart;
	parts[cpart].clear();
  }  
  else if(p!=-1) part[u]=part[p];
  if(p!=-1) parts[cpart].pb(u);
  for(int v1:ad[u])
    if(!vis[v1]&&v1!=p){
		H[v1]=H[u]+1;
		val[v1]=(val[u]^(1<<(s[v1-1]-'a')));
		dfs1(v1,r,u);
    }
}
void dfs2(int u,int r,int par=-1){
  dp[u]=cnt[val[u]];
  for (int i=0;i<20;i++)
    dp[u]+=cnt[val[u]^(1<<i)];
  for(int v1:ad[u])
    {
      if(vis[v1] || v1==par) continue;
      dfs2(v1,r,u);
      dp[u]+=dp[v1];
    }
  res[u]+=dp[u];
}
void solve(int r,int sizesr){
  H[r]=cpart=0;
  val[r]=(1<<(s[r-1]-'a'));
  dfs1(r,r);
  for (int i=1;i<=cpart;i++)
    for(int v1:parts[i])
      cnt[val[v1]]++;
  cnt[val[r]]++;
  for (int i=1;i<=cpart;i++){
		for(int v1:parts[i]){
			cnt[val[v1]]--;
			val[v1]^=(1<<(s[r-1]-'a'));
			tmp[val[v1]]++;
		}
		for(int v1:parts[i]){
			if(tmp[val[v1]]){
				dp[r]+=(ll)tmp[val[v1]]*cnt[val[v1]];
				for (int j=0;j<20;j++) dp[r]+=(ll)tmp[val[v1]]*cnt[val[v1]^(1<<j)];
				tmp[val[v1]]=0;
			}
		}
		dfs2(parts[i][0],r,r);
		for(int v1:parts[i]){
			val[v1]^=(1<<(s[r-1]-'a'));
			cnt[val[v1]]++;
		}
    }
  cnt[val[r]]--;
  dp[r]+=cnt[0];
  for (int i=0;i<20;i++)
    dp[r]+=cnt[(1<<i)];
  res[r]+=dp[r]/2;
  for (int i=1;i<=cpart;i++)
    for(int v1:parts[i]) cnt[val[v1]]--;
}
void dfsMCT(int u,int p=-1){
  dfssizes(u);
  int r=dfsFC(u,u);
  par[r]=p; solve(r,sizes[u]); vis[r]=true;
  for(int v:ad[r])
    if(!vis[v]) dfsMCT(v,r);
}
int main(){
  setIO();
  int n,x,y;cin>>n;
  for (int i=1;i<n;i++){
	cin>>x>>y;
	ad[x].pb(y); ad[y].pb(x);
  }
  cin>>s;dfsMCT(1);
  for (int i=1;i<n;i++) cout<<res[i]+1<<" ";
  cout<<"\n";
}
