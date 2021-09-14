#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
class Cow{
    public:
        int x,y;
        int ix;
        int iy;
        void changex(int ax){
            ix=ax;
        }
        void changey(int ay){
            iy=ay;
        }
};
vector<Cow> x;
bool sortx(Cow &a, Cow &b){
    return (a.x<b.x);
}
bool sorty(Cow &a, Cow &b){
    return (a.y<b.y);
}
int findI(int iy){
    for (int i=0;i<N;i++){
        if (x[i].iy==iy){
            return i;
        }
    }
    return -1;
}
int main(){
    freopen("reduce.in","r",stdin);
    freopen("reduce.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        Cow store;
        store.x=a;
        store.y=b;
        x.push_back(store);
    }
    sort(x.begin(),x.end(),sortx);
    for (int i=0;i<N;i++){
        x[i].ix=i;
    }
    sort(x.begin(),x.end(),sorty);
    for (int i=0;i<N;i++){
        x[i].iy=i;
    }
    sort(x.begin(),x.end(),sortx);
    int area = 2000000000;
    for (int i=0;i<4;i++){
        for (int j=N-1;j>N-5;j--){
            for (int a=0;a<4;a++){
                for (int b=N-1;b>N-5;b--){
                    int c,d;
                    c = findI(a);
                    d = findI(b);
                    if (a>=b){
                        continue;
                    }
                    if (i>=j){
                        continue;
                    }
                    if ((c<i)||(c>j)){
                        continue;
                    }
                    if ((d<i)||(d>j)){
                        continue;
                    }
                    if ((x[i].iy<a)||(x[i].iy>b)){
                        continue;
                    }
                    if ((x[j].iy<a)||(x[j].iy>b)){
                        continue;
                    }
                    int total = i+N-1-j+a+N-1-b;
                    for (int z=0;z<a;z++){
                        int e = findI(z);
                        if ((e<i)||(e>j)){
                            total--;
                        }
                    }
                    for (int z=N-1;z>b;z--){
                        int e = findI(z);
                        if ((e<i)||(e>j)){
                            total--;
                        }
                    }
                    if (total==3){
                        area=min(area,abs((x[j].x-x[i].x)*(x[d].y-x[c].y)));
                    }
                }
            }
        }
    }
    cout << area;
}