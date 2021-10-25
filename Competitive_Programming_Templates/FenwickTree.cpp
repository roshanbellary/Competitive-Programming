//Made by Roshan Bellary
#include <bits/stdc++.h>
using namespace std; 
const int MAXN=1e5;
int N;int ft[MAXN];
void update(int i){
    while (i<=N){
        ft[i]++;i+=(i&(-i));//updates the necessary parts of the fenwick tree
    }
}
int query(int i){
    return (i>0) ? ft[i]+query(i-(i&(-i))):0;//adds up the necessary parts of the fenwick tree
}
int main(){
    cin >> N;
}