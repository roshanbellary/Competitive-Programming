#include <iostream>
#include <vector>
#include <set>
using namespace std;
long B[2];
long E[2];
long S[2];
long I[2];
long G[2];
long O[2];
long M[2];
int main(){
    freopen("geteven.in","r",stdin);
    freopen("geteven.out","w",stdout);
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        char store;
        int val;
        cin >> store;
        cin >> val;
        val=abs(val);
        if (store=='B'){
            B[val%2]++;
        }
        if (store=='E'){
            E[val%2]++;
        }
        if (store=='S'){
            S[val%2]++;
        }
        if (store=='I'){
            I[val%2]++;
        }
        if (store=='G'){
            G[val%2]++;
        }
        if (store=='O'){
            O[val%2]++;
        }
        if (store=='M'){
            M[val%2]++;
        }
    }
    long count=0;
    for (int b=0;b<2;b++){
        for (int e=0;e<2;e++){
            for (int s=0;s<2;s++){
                for (int i=0;i<2;i++){
                    for (int g=0;g<2;g++){
                        for (int o=0;o<2;o++){
                            for (int m=0;m<2;m++){
                                if (((b+2*e+2*s+i)*(g+o+e+s)*(m+2*o))%2==0){
                                    count+=B[b]*E[e]*S[s]*I[i]*G[g]*O[o]*M[m];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << count;
}