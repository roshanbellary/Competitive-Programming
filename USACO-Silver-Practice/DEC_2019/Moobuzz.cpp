#include <iostream>
using namespace std;
int x[8] = {1,2,4,7,8,11,13,14};
int main(){
    freopen("moobuzz.in","r",stdin);
    freopen("moobuzz.out","w",stdout);
    int N;
    cin >> N;
    int times;
    N--;
    times=N/8;
    N-=8*times;
    cout << x[N]+15*times;
}