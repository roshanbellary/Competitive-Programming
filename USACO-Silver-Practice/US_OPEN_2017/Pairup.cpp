#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Cows{
    public:
     int x,y;
}; 
bool sorts(Cows &a, Cows &b){
    return (a.y<b.y);
}
int main(){
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    int N;
    cin >> N;
    vector<Cows> h;
    for (int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        Cows cow;
        cow.x=a;
        cow.y=b;
        h.push_back(cow);
    }
    sort(h.begin(),h.end(),sorts);
    int l = 0;
    int r = N-1;
    int maximum = 0;
    while (l<=r){
        maximum = max(maximum, h[l].y+h[r].y);
        if (h[l].x>h[r].x){
            h[l].x-=h[r].x;
            r--;
        }else if (h[l].x<h[r].x){
            h[r].x-=h[l].x;
            l++;
        }else{
            r--;
            l++;
        }
    }
    cout << maximum;

}