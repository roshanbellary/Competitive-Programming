/*
Problem: Shapes
Problem Link: https://atcoder.jp/contests/abc218/tasks/abc218_c
Notes:
The easy part is realizing you just have to rotate the figure then shift it to the upper left corner 
and check if the grids are equal after shifting the second figure to the upper left corner.

The hard part is actually coding the rotations.
I took the middle of the grid as my origin for rotations(Note: the origin has different meanings of even grids and odd grids)
from there I made the rotation transformation on the grid with respect to the origin then converted the resulting coordinates into 
array indices and shifted the resulting figure to the upper left and compared the two figures.
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
template <class T> 
void rn(T &n){
    n=0;int m=1,c=getchar();if (c=='-') m=-1;
    for (;c>47 && c<58;c=getchar()){n=n*(1<<1)+n*(1<<3)+c-48;}
    n*=m;
}
void rw(string &w){
    w="";char c=getchar();
    while (c!=' '&&c!='\n'&&c!=EOF){w+=c;c=getchar();}
}
void rc(char &c){c=getchar();}
template<typename T, typename ...Types>
void rn(T &n, Types&&... args){rn(n);rn(args...);}
template<typename T, typename ...Types>
void rw(T &w,Types&&... args){rw(w);rw(args...);}
template<typename T, typename ...Types>
void rc(T &c,Types&&... args){rc(c);rc(args...);}
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int N;
vector<vector<char>> s1(200,vector<char>(200,'#'));
vector<vector<char>> s2(200,vector<char>(200,'#'));
void printshape(vector<vector<char>> &g){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << g[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
void moveshape(vector<vector<char>> &g){
    int cx = 1e9, cy=1e9;
    vector<vector<char>> temp(N,vector<char>(N,'.'));
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (g[i][j]=='#'){cx=min(cx,i), cy=min(cy,j);}
        }
    }  
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (g[i][j]=='#') temp[i-cx][j-cy]='#';
        }
    }
    g=temp;
}
void rotateshape(vector<vector<char>> &g){
    vector<vector<char>> temp(N,vector<char>(N,'.'));
    if (N%2==0){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (g[i][j]=='#'){
                    int x, y;
                    if (i<N/2) x=(N/2-i);
                    else x=N/2-i-1;
                    if (j<N/2) y=j-N/2;
                    else y=j-N/2+1;
                    int nx = y, ny = -x;x=nx;y=ny;
                    if (x>0) x=N/2-x;
                    else x=N/2-x-1;
                    if (y>0) y=N/2+y-1;
                    else y=y+N/2;
                    temp[x][y]='#';
                }
            }
        }
    }else{
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                if (g[i][j]=='#'){
                    int x = i-N/2,y = j-N/2;
                    int nx = y, ny = -x;
                    x=nx; y=ny;x+=N/2,y+=N/2;
                    temp[x][y]='#';
                }
            }
        }
    }
    g=temp;
}
bool checkSame(vector<vector<char>> &g1,vector<vector<char>> &g2){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (g1[i][j]!=g2[i][j]) return 0;
        }
    }
    return 1;
}
int main(){
	setIO();rn(N);
    for (int i=0;i<N;i++){
        string s;rw(s);
        for (int j=0;j<N;j++){
            s1[i][j]=s[j];
        }
    }
    for (int i=0;i<N;i++){
        string s;rw(s);
        for (int j=0;j<N;j++){
            s2[i][j]=s[j];
        }
    }
    moveshape(s2);
    for (int i=0;i<4;i++){
        rotateshape(s1);moveshape(s1);
        if (checkSame(s1,s2)){
            cout << "Yes\n";return 0;
        }
    }
    cout << "No\n";
}
