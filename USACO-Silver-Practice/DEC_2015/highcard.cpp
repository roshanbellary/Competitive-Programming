#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    int N;
    cin >> N;
    vector<bool> c(2*N);
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        c[store-1]=true;
    }
    int games = 0;
    int count = 0;
    for (int i=0;i<2*N;i++){
        if (c[i]){
            count++;
        }else{
            if (count>0){
                games++;
                count--;
            }
        }
    }
    cout << games;
}