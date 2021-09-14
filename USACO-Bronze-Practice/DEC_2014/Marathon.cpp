#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Checkpoint{
    public:
        int x,y;
};
int distance(Checkpoint &a, Checkpoint &b){
        return (abs(b.x-a.x)+abs(b.y-a.y));
}
int main(){
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    int N;
    cin >> N;
    vector<Checkpoint> l;
    for (int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        Checkpoint store;
        store.x=x;
        store.y=y;
        l.push_back(store);
    }
    int sum = 0;
    for (int i=0;i<N-1;i++){
        sum+=distance(l[i+1],l[i]);
    }
    int m = sum;
    for (int i=1;i<N-1;i++){
        int result = sum - distance(l[i],l[i-1])-distance(l[i+1],l[i])+distance(l[i+1],l[i-1]);
        if (result<m){
            m=result;
        }
    }
    cout << m;
}