#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("bgm.in","r",stdin);
    freopen("bgm.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vector<long long> > v(7,vector<long long>(7,0));
    for (int i=0;i<N;i++){
        char c;
        cin >> c;
        int store; cin >>store;
        store%=7;
        if (store<0) store+=7;
        if (c=='B') v[0][store]++;
        if (c=='E') v[1][store]++;
        if (c=='S') v[2][store]++;
        if (c=='I') v[3][store]++;
        if (c=='G') v[4][store]++;
        if (c=='O') v[5][store]++;
        if (c=='M') v[6][store]++;
    }
    long long count = 0;
    for (int b=0;b<7;b++)
        for (int e=0;e<7;e++)
            for (int s=0;s<7;s++)
                for (int i=0;i<7;i++)
                    for (int g=0;g<7;g++)
                        for (int o=0;o<7;o++)
                            for (int m=0;m<7;m++)
                                if ((b+2*e+2*s+i)*(g+o+e+s)*(m+2*o)%7==0) count+=(v[0][b]*v[1][e]*v[2][s]*v[3][i]*v[4][g]*v[5][o]*v[6][m]);

    cout << count << "\n";
}