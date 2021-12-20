/*
Problem: Nested Ranges Check
Problem Link: https://cses.fi/problemset/task/2168
Notes: 
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
struct Range{
    int s, f, ind;
};
bool sorts(Range &a, Range &b){
    if (a.s==b.s) return (a.f>b.f);
    return (a.s<b.s);
}
const int MN = 2e5;
int N;
vector<Range> st;
indexed_set m;
bool cover[MN],coverer[MN];
void calcContainer(){
    sort(st.begin(),st.end(),sorts);
    multiset<pair<int,int>> m;
    multiset<pair<int,int>> m2;
    for (int i=0;i<st.size();i++){
        auto itr = m.lower_bound({st[i].f,-1});
        auto itr3 = m2.lower_bound({st[i].f,-1});
        if (itr3!=m2.end()) cover[st[i].ind]=1;
        if (itr!=m.end()){
            auto itr2 = itr;
            while (itr!=m.end()){
                coverer[itr->second]=1;
                itr++;
            }
            m.erase(itr2,itr);
        }
        m.insert({st[i].f,st[i].ind});
        m2.insert({st[i].f,st[i].ind});
    }
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++){
        int s,f; rv(s,f);
        st.pb({s,f,i});
    }
    calcContainer();
    for (int i=0;i<N;i++) cout << coverer[i] << " ";
    cout << "\n";
    for (int i=0;i<N;i++) cout << cover[i] << " ";
    cout << "\n";
}
