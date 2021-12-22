/*
Problem: 
Problem Link: 
Notes: 
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
#define f first
#define s second
int mod=1e9+7;
inline void rv(int &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){double p = 0.1;c=getchar();for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}}
    n*=m;
}
inline void rv(string &w){w="";char c=getchar();while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}}
inline void rv(char &c){c=getchar();}
template<typename T, typename ...Types>
void rv(T &n, Types&&... args){rv(n);rv(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
const int MK = 40;
struct Cow{
    double d;
    int b;
};
bool sorts(Cow &a, Cow &b){return (a.d<b.d);}
int N, K, L;
double d[MK];
vector<Cow> lc,rc;
vector<int> csum;
int main(){
	setIO();rv(N, K, L);
    for (int i=0;i<N;i++){
        double d;int b; string t;
        rv(d,b,t);
        if (t=="L") lc.pb({d,b});
        else rc.pb({d,b});
    }
    for (auto &a:rc){d[a.b]+=(L-a.d);}
    sort(rc.begin(),rc.end(),sorts);
    sort(lc.begin(),lc.end(),sorts);
    int ri=0, col = 0;
    for (int i=0;i<lc.size();i++){
        while (ri<rc.size()){
            if (rc[ri].d<=lc[i].d) ri++;
            else break; 
        }
        int cr = ri;
        if (rc[cr].d<=lc[i].d){
            int num = cr+1, cd=lc[i].d;
            int col = lc[i].b;
            int li = i-1;
            while (num--){
                if (li>=0){
                    if (lc[li].d>rc[cr].d){
                        d[col]+=(cd-lc[li].d)/2;
                        cd=(cd+lc[li].d)/2;col+=lc[li].b;col%=K;
                        li--;
                    }else{
                        d[col]+=(cd-rc[cr].d)/2;
                        cd=(cd+rc[cr].d)/2;col+=rc[cr].b;col%=K;
                        cr--;
                    }
                }else{
                    d[col]+=(cd-rc[cr].d)/2;
                    cd=(cd+rc[cr].d)/2;col+=rc[cr].b;col%=K;
                    cr--;
                }
            }
            d[col]+=(cd);
        }else{
            d[lc[i].b]+=lc[i].d;
        }
    }
    for (int i=0;i<K;i++){
        cout << d[i] << "\n";
    }
    
}
