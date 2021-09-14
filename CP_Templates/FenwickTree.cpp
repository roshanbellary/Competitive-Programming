#include <bits/stdc++.h>
using namespace std; int N;
vector<int> ft;
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
    for (int i=0;i<N+1;i++) ft.push_back(0);
}