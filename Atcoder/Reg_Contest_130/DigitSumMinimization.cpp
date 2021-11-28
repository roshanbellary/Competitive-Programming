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
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(ll &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
inline void rv(double &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(float &n){
    n=0;int m=1;char c=getchar();
    if (c=='-'){m=-1; c=getchar();}
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    if (c=='.'){
        double p = 0.1;c=getchar();
        for (;c>47 && c<58;c=getchar()){n+=((c-48)*p);p/=10;}
    }
    n*=m;
}
inline void rv(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}
}
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
string a, b;
string ra; string rb;
int da[10], db[10];
int main(){
	setIO();cin >> a >> b;
    for (int i=0;i<a.length();i++) da[a[i]-'0']++;
    for (int i=0;i<b.length();i++) db[b[i]-'0']++;
    bool f = 0;
    for (int i=1;i<10;i++){
        if (da[i]==0) continue;
        for (int j=10-i;j<10;j++){
            if (db[j]>0){
                ra+=(i+'0');
                rb+=(j+'0');
                db[j]--;da[i]--;
                f=1;break;
            }
        }
        if (f) break;
    }
    for (int i=0;i<10;i++){
        if (da[i]==0) continue;
        for (int j=9-i;j<10;j++){
            if (db[j]==0) continue;
            while (db[j]>0 && da[i]>0){
                ra+=(i+'0');rb+=(j+'0');
                db[j]--;da[i]--;
            }
            break;
        }
    }
    for (int i=0;i<10;i++){
        while (da[i]>0){
            ra+=(i+'0');da[i]--;
        }
        while (db[i]>0){
            rb+=(i+'0');db[i]--;
        }
    }
    reverse(ra.begin(),ra.end());
    reverse(rb.begin(),rb.end());
    cout << ra << "\n" << rb << "\n";
}
