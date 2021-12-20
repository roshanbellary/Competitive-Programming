/*
Problem: Nested Ranges Count
Problem Link: https://cses.fi/problemset/task/2169/
Notes: 
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less_equal<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
int cover[MN],coverer[MN];
void calcContained(){
    sort(st.begin(),st.end(),sorts);
    for (int i=0;i<st.size();i++){
        int num = m.order_of_key({st[i].f,-1});
        cover[st[i].ind]=m.size()-num;
        m.insert({st[i].f,st[i].ind});
    }
}
void calcContainer(){
    m.clear();
    for (int i=0;i<st.size();i++){
        int num = m.order_of_key({st[i].f,1e9});
        coverer[st[i].ind]-=num;
        m.insert({st[i].f,st[i].ind});
    }
    for (int i=0;i<st.size();i++){
        coverer[st[i].ind]+=m.order_of_key({st[i].f,1e9})-1;
    }
}
int main(){
	setIO();rv(N);
    for (int i=0;i<N;i++){
        int s,f; rv(s,f);
        st.pb({s,f,i});
    }
    calcContained();calcContainer();
    for (int i=0;i<N;i++) cout << coverer[i] << " ";
    cout << "\n";
    for (int i=0;i<N;i++) cout << cover[i] << " ";
    cout << "\n";
}

