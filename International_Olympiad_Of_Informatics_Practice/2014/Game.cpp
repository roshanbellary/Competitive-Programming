//used IOI editorial to solve problem
/*
IOI 2014 C. Game
https://contest.yandex.ru/ioi/contest/579/problems/C/?success=11544284#7/2014_07_23/stWJB8fh2J
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "grader.h"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
#define mod 1e9+7
void setIO(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void setIO(string f){
	freopen((f+".in").c_str(),"r",stdin);
	freopen((f+".out").c_str(),"w",stdout);
	setIO();
}
int n[1500];
void initialize(int n){

}
int hasEdge(int u, int v){
	return ++n[((u>v)?u:v)] == (u>v?u:v);
}
int main(){
	setIO();
}
