#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("trapped.in","r",stdin);
    freopen("trapped.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, B;
    cin >> N >> B;
    vector<pair<int,int> > v;
    for (int i=0;i<N;i++){
        int s,p;
        cin >> s >> p;
        v.push_back(pair<int,int>(p,s));
    }
    sort(v.begin(),v.end());
    int s = 0;
    int f = N-1;
    while (s!=f){
        int mid = (s+f+1)/2;
        if (v[mid].first<=B){
            s=mid;
        }else{
            f=mid-1;
        }
    }
    if (f<N-1) f++;
    if (s==N-1){
        cout << -1 << endl;
    }else if ((s==0)&&(v[s].first>B)){
        cout << -1 << endl;
    }else{
        bool bs = true;
        int mini = 1e9+1;
        int temp1 = s;
        int temp2 = f;
        while ((s>=0)&&(f<=N-1)){
            bool did = false;
            bool s1 =  (v[f].first-v[s].first>v[s].second);
            bool s2 = (v[f].first-v[s].first>v[f].second);
            if (s1&&s2){
                s--;
            }else if (s1){
                mini=min(v[f].first-v[s].first-v[s].second,mini);
                s--;
            }else if (s2){
                mini=min(v[f].first-v[s].first-v[f].second,mini);
                f++;
            }else{
                bs=false;
            }
        }
        if (s==-1){
            s=temp1;
            f=temp2;
            while ((s>=0)&&(f<=N-1)){
                bool did = false;
                bool s1 =  (v[f].first-v[s].first>v[s].second);
                bool s2 = (v[f].first-v[s].first>v[f].second);
                if (s1&&s2){
                    f++;
                }else if (s1){
                    mini=min(v[f].first-v[s].first-v[s].second,mini);
                    s--;
                }else if (s2){
                    mini=min(v[f].first-v[s].first-v[f].second,mini);
                    f++;
                }else{
                    bs=false;
                }
            }
            if (f==-1) cout << -1 << endl;
            else{
                cout << mini << endl;
            }
        }else{
            if (!bs) cout << 0 << endl;
            else{
                cout << mini << endl;
            }
        }
    }
}