/* 
IOI 2013 Day 2 Problem 2 Robots
https://oj.uz/problem/view/IOI13_robots
I think I need to get used to using priority queues in order to solve these sorting and 
searching problems, but I was finally able to solve robots as I figure out that I could use 
2 priority queues
*/
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "robots.h"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef long long ll;
#define pb push_back
#define eb emplace_back
#define countbits __builtin_popcount
#define beg0 __builtin_clz
#define terminal0 __builtin_ctz
int mod=1e9+7;
typedef long long ll;
const int MAXN = 50000;
const int MAXT = 1000000;
int a1[MAXN], a2[MAXN];bool del[MAXT];
struct toy {
    int w1, w2;
    int id;
};
int A, B, T;
bool cmp1(toy a, toy b) {
    return a.w1 < b.w1 || (a.w1 == b.w1 && a.w2 < b.w2);
}
bool cmp2(toy a, toy b) {
    return a.w2 < b.w2 || (a.w2 == b.w2 && a.w1 < b.w1);
}
toy t1[MAXT], t2[MAXT];
bool check(int r) {
    int store = t;
    priority_queue<pair<int,int>> pq;
    int ind = 0;
    for (int i = 0; i < A; i++) {
        while (ind != t && (del[t1[ind].id] || t1[ind].w1 < a1[i])) {
            if (!del[t1[ind].id])
                pq.push({ t1[ind].w2, t1[ind].id });
            ind++;
        }
        int tt = r;
        while (!pq.empty() && tt--) {
            int cur = pq.top().second;
            pq.pop();
            store--;
            del[cur] = true;
        }
    }
    pq = priority_queue<pair<int,int>>();
    ind = 0;
    for (int i = 0; i < B; i++) {
        while (ind != t && (del[t2[ind].id] || t2[ind].w2 < a2[i])) {
            if (!del[t2[ind].id])
                pq.push({ t2[ind].w1, t2[ind].id });
            ind++;
        }
        int tt = r;
        while (!pq.empty() && tt--) {
            int cur = pq.top().second;
            pq.pop();
            del[cur] = true;
            store--;
        }
    }
    return store == 0;
}
int putaway(int a, int b, int t, int X[], int Y[], int W[], int S[]){
	A=a;B=b;T=t;
	for (int i=0;i<A;i++){
		a1[i]=X[i];
	}
	for (int i=0;i<B;i++){
		a2[i]=Y[i];
	}
	for (int i=0;i<T;i++){
		t1[i]=t2[i]={W[i],S[i],i};
	}
	sort(t1,t1+T,cmp1);sort(t2,t2+T,cmp2);
	if (A) {
        sort(a1,a1+A);
    }
    if (B) {
        sort(a2,a2+B);
    }
	int l = 0;int h = t;
    while (l!=h) {
        int mid = (l+h+1)/2;
        if (check(mid)) {
            h = mid;
        }else {
            l = mid + 1;
        }
        memset(del, 0, sizeof del);
    }
	if (check(l)){
		return l;
	}else{
		return -1;
	}
}
