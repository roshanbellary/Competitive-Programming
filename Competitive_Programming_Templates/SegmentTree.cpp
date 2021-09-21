//This particular implementation is a range sum query with value modification
//This code is only for reference purposes. For a faster implementation of a range sum query with value modifications use Fenwick Trees.
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int st[4*MAXN];
int v[MAXN];
void build(int index, int L, int R){
    if (L==R){
        st[index]=v[L];//sets value of segment tree if at an index
    }else{
        build(index*2,L,(L+R)/2);//splits up range
        build(index*2+1,(L+R)/2+1,R);//splits up range
        st[index]=st[2*index]+st[2*index+1];//calculates sum of both ranges
    }
}
void build(){
    build(1,1,MAXN);
}
void update(int index, int L, int R, int item, int val){
   if ((item<L)||(item>R)) return;// checks to see if the changed index is within range if not then return
   else if (L==R){
       st[index]=val;//if we are at index update its value
   }else{
       update(2*index,L,(L+R)/2,item,val);//splits up range
       update(2*index+1,(L+R)/2+1,R,item,val);//splits up range
       st[index]=st[2*index]+st[2*index+1];
   }
}
void update(int item, int val){
    update(1,1,MAXN,item,val);
}
int query(int index, int L, int R, int ql, int qr){
    if ((R<ql)||(L>qr)) return 0;//checks to see if the query is partially contained within range if not then return
    if ((R<=qr)&&(L>=ql)) return st[index];// checks to see if range is fully part of query then returns value of index if true
    return (query(2*index,L,(L+R)/2,ql,qr)+query(2*index+1,(L+R)/2+1,R,ql,qr)); //splits up range into halves and calls query unction on both
}
int query(int ql, int qr){
    return query(1,1,MAXN,ql,qr);
}
int main(){
    for (int i=0;i<MAXN;i++){
        cin >> v[i];
    }
    build();
}
