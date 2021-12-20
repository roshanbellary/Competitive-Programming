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
int T;
string a, b, s;
ll res;
bool solve(){
    int ind = a.size()-1;b="";
    for (int i=s.size()-1;i>=0;i--){
        if (ind<0 || i<0) return 0;
        if ((s[i]-'0')>=(a[ind]-'0')){
            if (ind<0 || i<0) return 0;
            b=to_string((s[i]-'0')-(a[ind]-'0'))+b;ind--;
        }else{
            if (i>0){
                if (ind<0 || i<0 || i-1<0) return 0;
                int r = 10*(s[i-1]-'0')+(s[i]-'0')-(a[ind]-'0');
                if (r>=10 || r<0) return 0;
                b=to_string(r)+b;
                i--;ind--;
            }else return 0;
        }
    }
    if (ind>=0) return 0;
    return 1;
}
bool iterate(){
    cin >> a >> s;b="";
    for (int i=a.size();i<=s.size();i++){
        bool r = solve();
        if (r) return 1;
        else a="0"+a;
    }
    return 0;
}
void convert(){
    int ind = -1;
    for (int i=0;i<b.size()-1;i++){
        if (b[i]=='0') ind=i+1;
        else break;
    }
    if (ind<0) return;
    else{
        b=b.substr(ind,b.size()-ind);
    }
}
int main(){
	setIO();cin >> T;
    while (T--){
        bool r = iterate();
        if (r){
            convert();
            cout << b << "\n";
        }
        else  cout << "-1\n";
    }
}
