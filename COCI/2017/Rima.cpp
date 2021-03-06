/*
Problem: Rima
Problem Link: https://oj.uz/problem/view/COCI17_rima
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
struct Node{
    int end=0;
    char val;
    Node* next[26];
};
const int MN = 5e5;
int N,maxL = 0;
string w[MN];
Node s;
int dfs(Node *curr){
    int mv = curr->end,inc = 0,active = 0;
    for (int i=0;i<26;i++){
        if (curr->next[i]!=nullptr){
            int val = dfs(curr->next[i]);
            inc=max(inc,val);
            if (val>0) active++;
        }
    }
    if (active>0) mv+=(inc+active-1);
    maxL=max(maxL,mv);
    if (curr->end==0) return 0;
    else return mv;
}
void insertNodes(string& wr){
    Node* curr=&s;
    for (int j=wr.size()-1;j>=0;j--){
        if (curr->next[wr[j]-'a']==nullptr){
            Node* v = new Node;v->val=wr[j];
            for (int i=0;i<26;i++) v->next[i]=nullptr;
            curr->next[(int)(wr[j]-'a')]=v;
            curr=curr->next[wr[j]-'a'];
        }else{
            curr=curr->next[(int)(wr[j]-'a')];
        }
    }
    curr->end++;
}
int main(){
	setIO();rv(N);s.val='a';
    for (int i=0;i<26;i++) s.next[i]=nullptr;
    for (int i=0;i<N;i++){cin >> w[i];insertNodes(w[i]);}
    dfs(&s);
    cout << maxL << "\n";
}
