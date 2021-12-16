/*
Problem: Large Sum
Problem Link: https://projecteuler.net/problem=13
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
const int N = 100;
struct BigNumber{
    string v;
    BigNumber add(BigNumber n){
        string t1 = v;reverse(t1.begin(),t1.end());
        string t2 = n.v; reverse(t2.begin(),t2.end());
        string res = "";
        bool carry = 0;
        for (int i=0;i<min(t2.size(),t1.size());i++){
            int sum = (t1[i]-'0')+(t2[i]-'0');sum+=carry;
            if (sum>=10) carry=1, sum-=10;
            else carry=0;
            res+=to_string(sum);
        }
        if (t2.size()>t1.size()){
            for (int i=t1.size();i<t2.size();i++){
                int sum = t2[i]-'0';sum+=carry;
                if (sum>=10) carry=1, sum-=10;
                else carry=0;
                res+=to_string(sum);
            }
        }else{
            for (int i=t2.size();i<t1.size();i++){
                int sum = t1[i]-'0';sum+=carry;
                if (sum>=10) carry=1, sum-=10;
                else carry=0;
                res+=to_string(sum);
            }
        }
        if (carry) res+="1";
        reverse(res.begin(),res.end());
        BigNumber r; r.v=res;
        return r;
    }
};
int main(){
	setIO();
    BigNumber r = {"0"};
    for (int i=0;i<N;i++){
        BigNumber t; rv(t.v);
        r=r.add(t);
    }
    cout << "\n";
    cout << r.v.substr(0,10) << "\n";
}
