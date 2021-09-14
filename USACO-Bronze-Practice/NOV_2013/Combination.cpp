#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
int parse (int, int);
int main(){
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);
    cin >> N;
    int a,b,c;
    cin >> a >> b >> c;
    int x,y,z;
    cin >> x >> y >> z;
    if (N<5){
        cout << N*N*N;
    }else{
        cout << 2*5*5*5-parse(a,x)*parse(b,y)*parse(c,z);
    }
}
int parse(int i, int j){
    int p1[5];
    int p2[5];
    for (int a=i-2;a<=i+2;a++){
        if (a>N){
            p1[a-i+2]=a-N;
        }else if (a<1){
            p1[a-i+2]=N+a;
        }else{
            p1[a-i+2]=a;
        }
    }
    for (int a=j-2;a<=j+2;a++){
        if (a>N){
            p2[a-j+2]=a-N;
        }else if (a<1){
            p2[a-j+2]=N+a;
        }else{
            p2[a-j+2]=a;
        }
    }
    int count = 0;
    for (int c=0;c<5;c++){
        for (int d=0;d<5;d++){
            if (p1[c]==p2[d]){
                count++;
            }
        }
    }
    return count;
}