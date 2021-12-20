#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int X,N;
    cin >> X >> N;
    int p[N];
    for (int i=0;i<N;i++)
        cin >> p[i];
    set<pair<int,int> > l;
    set<int> pi;
    for (int i=0;i<N;i++){
        pi.insert(p[i]);
        if (l.size()==0){
            l.insert(pair<int,int>(X-p[i],p[i]));
        }else{
            set<int>::iterator itr = pi.upper_bound(p[i]);
            set<int>::iterator itr2 = pi.lower_bound(p[i]);
            if (itr2==pi.begin()){
                l.insert(pair<int,int>(*itr-p[i],p[i]));
            }else{
                itr2--;
                int postore = *itr2;
                if (itr!=pi.end()){
                    l.insert(pair<int,int>(*itr-p[i],p[i]));
                    l.erase(pair<int,int>(*itr-postore,postore));
                    l.insert(pair<int,int>(p[i]-postore,postore));
                }
                else{
                    l.insert(pair<int,int>(X-p[i],p[i]));
                    l.insert(pair<int,int>(p[i]-postore,postore));
                    l.erase(pair<int,int>(X-postore,postore));
                }
            }
        }
        int maximum = 0;
        set<pair<int,int> >::iterator itr = l.end();
        itr--;
        set<int>::iterator itr2 = pi.begin();
        maximum = max(maximum, itr->first);
        maximum = max(maximum,*itr2);
        cout << maximum << " ";
    }
}