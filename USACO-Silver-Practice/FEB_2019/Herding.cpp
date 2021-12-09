/*
Problem:Sleepy Cow Herding
Problem Link:  http://usaco.org/index.php?page=viewproblem2&cpid=918
Notes: 
Not my best solution for a problem as I just made a bunch of edge cases
and constructed my solution from there.

For the minimum amount of moves, it's obviously optimal to start the range of N cows from a certain cow
as starting at a different range would cost a move. Thus if you were to start at 
Cow i with position p[i] then the other cows would have to fill the range p[i]+1 to p[i]+N-1.
So the minimum number of moves to fill that range is N-number of cows contained in the range.
We can then take the minimum across all of the possible ranges starting from Cow 1 to N. However,
we have one caveat. If you contain the last cow in your range but not at the end 
then that means that you cannot place any cow after the last cow making it impossible to fill the range.
Additionally, if contain every cow except the last cow in the range and the last position of the range
is open there is no way to fill it making the range impossible to fill

The maximum amount of moves is a lot easier to calculate. Main thing to realize is that
you can kinda roll up a range by moving consecutive cows over each other like a crawling centipede.
The main thing to realize however is that you lose some of the distance between the endpoint cow and 
the cow next to it, so you have to take maximum of the distances to find the answer.

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
const int MN = 1e5;
int N, p[MN];
int main() {
    setIO("herding");rv(N);
    for (int i=0;i<N;i++) rv(p[i]);
    sort(p,p+N);
    if (p[N-1]-p[0]==N-1){
        cout << "0\n0\n";return 0;
    }
    int minM = 1e9,maxM = 0;
    for (int i=0;i<N;i++){
        int s = i, f=N-1;
        while (s!=f){
            int mid = (s+f+1)/2;
            if (p[mid]<=p[i]+N-1) s=mid;
            else f=mid-1;
        }
        if (s==N-1 && p[N-1]<p[i]+N-1) continue;
        if (s-i+1==N-1 && p[s]<p[i]+N-1) continue;
        minM = min((N-(s-i+1)),minM);
    }
    maxM = max(1+p[N-1]-p[1]+1-N,1+p[N-2]-p[0]+1-N);
    cout << minM << "\n" << maxM << "\n";
}

