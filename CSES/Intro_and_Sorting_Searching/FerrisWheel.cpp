#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N,W;
    cin >> N >> W;
    int w[N];
    for (int i=0;i<N;i++)
        cin >> w[i];
    sort(w,w+N);
    int maxi = N-1;
    int count = 0;
    int index = N;
    for (int i=0;i<N;i++){
        int a = i;
        int b = maxi;
        if (b<=a) {index=i;break;}
        while (a!=b){
            int mid =(a+b+1)/2;
            if (w[i]+w[mid]<=W){
                a=mid;
            }else{
                b=mid-1;
            }
        }
        if (a==i){ index=i;break;}
        count++;
        maxi=a-1;
    }
    count=(N-count);
    cout << count << endl;
}