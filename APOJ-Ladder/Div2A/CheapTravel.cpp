#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    int mini = N*A;
    if ((N/M)*B+(N%M)*A<mini) mini=(N/M)*B+(N%M)*A;
    if ((N/M+1)*B<mini) mini=(N/M+1)*B;
    cout << mini << "\n";
}