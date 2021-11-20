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
template <class T> 
void rn(T &n){
    n=0;int m = 1;int c;
    c = getchar();if (c=='-') m=-1;
    for (;c>47 && c<58;c=getchar()){
        n=n*(1<<1)+n*(1<<3)+c-48;
    }
    n*=m;
}
void rw(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){
        w+=c;c=getchar();
    }
}
void rc(char &c){
	c=getchar();
}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int K, N;
pair<int,int> s[(int)1e5];
bool w[(int)1e5];
int main(){
	setIO();cin >> N >> K;
    for (int i=0;i<N;i++){
        for (int j=0;j<3;j++){
            int sc;cin >> sc;s[i].f+=sc;
        }
        s[i].s=i;
    }
    sort(s,s+N);reverse(s,s+N);
    for (int i=0;i<N;i++){
        int st=0,fi=i;
        while (st!=fi){
            int mid = (st+fi+1)/2;
            if (s[mid].f>s[i].f+300) st=mid;
            else fi=mid-1;
        }
        if (s[st].f<=s[i].f+300) st--;
        if (st+2<=K) w[s[i].s]=1;
        else w[s[i].s]=0;
    }
    for (int i=0;i<N;i++){
        if (w[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}
