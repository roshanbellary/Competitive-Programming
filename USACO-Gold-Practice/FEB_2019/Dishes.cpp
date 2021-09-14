#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("dishes.in","r",stdin);
    freopen("dishes.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int v[N];
    for (int i=0;i<N;i++){
        cin >> v[i];
    }
    int max = v[0];
    int count = -1;
    vector<int> maxs;
    vector<stack<int>> mins;
    int totmax = -1;
    for (int i=0;i<N;i++){
        if (maxs.size()==0){
            maxs.push_back(v[i]);
            mins.push_back(stack<int>());
            mins[0].push(v[i]);
        }else{
            if (v[i]<totmax){
                count=i;
                break;
            }
            int a = 0;
            int b = maxs.size()-1;
            while (a!=b){
                int mid = (a+b)/2;
                if (maxs[mid]>=v[i]){
                    b=mid;
                }else{
                    a=mid+1;
                }
            }
            if ((maxs[b]>v[i])&&(v[i]<mins[b].top())){
                mins[b].push(v[i]);
            }else if ((maxs[b]>v[i])&&(v[i]>mins[b].top())){
                bool w = true;
                while (true){
                    if (mins[b].top()<v[i]){
                        if (totmax>mins[b].top()){
                            w=false;
                            break;
                        }else{
                            totmax=mins[b].top();
                        }
                        mins[b].pop();
                    }else{
                        mins[b].push(v[i]);
                        break;
                    }
                }
                if (!w){
                    count = i;
                    break;
                }
            }else{
                maxs.push_back(v[i]);
                mins.push_back(stack<int>());
                mins[mins.size()-1].push(v[i]);
            }
        }
    }
    if (count<0) cout << N << "\n";
    else cout << count << "\n";
}