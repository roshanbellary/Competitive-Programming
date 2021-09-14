#include <bits/stdc++.h>
using namespace std;
int N, K;
int eval(int a, int b){
    return (-84*a-48*b);
}
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    vector<int> dist(N,1e9);
    dist[0]=0;
    vector<bool> c(N,false);
    while (true){
        int ind = -1; int mini = 1e9;
        for (int i=0;i<N;i++){
            if ((dist[i]<mini)&&(!c[i])){ind=i;mini=dist[i];}
        }
        if (ind<0) break;
        c[ind]=true;
        for (int j=0;j<N;j++){
            if (!c[j]) dist[j]=min(eval(min(ind+1,j+1),max(j+1,ind+1)),dist[j]); 
        }
    }
    sort(dist.begin(),dist.end());
    cout << (long long)(dist[N-K])+2019201997LL << "\n";
}