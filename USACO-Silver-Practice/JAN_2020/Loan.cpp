#include <bits/stdc++.h>
using namespace std;
long long N, K, M;
bool check(int x){
    long long given = 0;
    long long days = K;
    while ((days>0)&&(given<N)){
        long long y = (N-given)/x;
        if (y<M){
            return ((N-given+M-1)/M<=days);
        }
        long long increase = (N-x*y-given)/y+1;
        if (increase>days) increase=days;
        given+=y*increase;
        days-=increase;
    }
    return (given>=N);
}
int main(){
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout);
    cin >> N >> K >> M;
    long long a = 1;
    long long b = 1e12;
    while (a!=b){
        long long mid =(a+b+1)/2;
        if (check(mid)){
            a=mid;
        }else{
            b=mid-1;
        }
    }
    cout << a;
}