#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
class Range{
    public:
        int s,f;
};
vector<Range> px;
bool sortsx(Range a, Range b){
    return (a.s)<(b.s);
}
int main(){
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        Range pe;
        pe.s=x-y;
        pe.f=x+y;
        px.push_back(pe);
    }
    sort(px.begin(),px.end(),sortsx);
    int temp = 0;
    int i = 1;
    int number = 1;
    while (i<N){
        if (px[i].f<=px[temp].f){
            i++;
        }else{
            number++;
            temp=i;
            i++;
        }
    }
    cout << number;
}