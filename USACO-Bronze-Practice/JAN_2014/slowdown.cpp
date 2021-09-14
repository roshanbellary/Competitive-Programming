#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> d;
vector<int> t;
int main(){
    freopen("slowdown.in","r",stdin);
    freopen("slowdown.out","w",stdout);
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        char a;
        int q;
        cin >> a >> q;
        if (a=='T'){
            t.push_back(q);
        }else{
            d.push_back(q);
        }
    }
    sort(t.begin(),t.end());
    sort(d.begin(),d.end());
    double distance = 0;
    int dindex=0;
    double time = 0;
    int tindex=0;
    double v = 1;
    while ((tindex<t.size())&&(dindex<d.size())){
            if ((double)(t[tindex]-time)>v*(d[dindex]-distance)){
                time+=(d[dindex]-distance)*v;
                distance=d[dindex];
                dindex++;
            }else{
                distance+=(double)(t[tindex]-time)/v;
                time=t[tindex];
                tindex++;
            }
            v++;
    }
    while (tindex<t.size()){
        distance+=(double)(t[tindex]-time)/v;
        time=t[tindex];
        tindex++;
        v++;
    }
    while (dindex<d.size()){
        time+=(d[dindex]-distance)*v;
        distance=d[dindex];
        dindex++;
        v++;
    }
    time+=(1000-distance)*v;
    int ntime = (int)time;
    double fraction = time-ntime;
    if (fraction<0.5){
        cout << ntime;
    }else{
        cout << ntime+1;
    }

}