//Made by Roshan Bellary
#include <bits/stdc++.h>
using namespace std; 
const int MAXN=1e5;
int N;
int parent[MAXN];
int sizes[MAXN];
int findRoot(int i){// finds the root of the inputted node
    if (i==parent[i]) return i;
    else{
        parent[i]=findRoot(parent[i]);// this line compresses the tree ensuring that the alg runs in O(log(N))
        return parent[i];//returns root
    }
}
void unions(int a, int b){//alg for combining two sets together
    a=findRoot(a);//sets vertex to root to make combining easier
    b=findRoot(b);
    if (a==b) return;//returns if roots are already equal
    if (sizes[b]>sizes[a]) swap(a,b);//compares sizes of trees to make sure we're adding to larger tree to be more efficient
    parent[b]=a;//sets parent of one node to be the other
    sizes[a]+=sizes[b];//adds size of one tree to the other
}
int main(){
    cin >> N;
    memset(sizes,sizeof(sizes),1);
    for (int i=0;i<N;i++){
        parent[i]=i;sizes[i]=1;
    }

}
