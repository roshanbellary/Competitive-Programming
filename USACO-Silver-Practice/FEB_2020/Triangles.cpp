#include <bits/stdc++.h>
using namespace std;
class Point{
    public:
        long long x,y;
        int ix, iy;
};
int N;
vector<Point> gx;
vector<Point*> gy;
bool sortx(Point &a, Point &b){
    if (a.x==b.x){
        return (a.y<b.y);
    }
    return (a.x<b.x);
}
bool sorty(Point* a, Point* b){
    if (a->y==b->y){
        return (a->x<b->x);
    }
    return ((a->y)<(b->y));
}
int main(){
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        Point store;
        long a,b;
        cin >> a >> b;
        store.x=a;store.y=b;
        gx.push_back(store);
    }
    for (int i=0;i<N;i++){
        gy.push_back(&gx[i]);
    }
    sort(gx.begin(),gx.end(),sortx);
    sort(gy.begin(),gy.end(),sorty);
    for (int i=0;i<N;i++){
        gx[i].ix=i;
        gy[i]->iy=i;
    }
    vector<long long > bx(N);
    for (int i=0;i<N;i++){
        int j = i+1;
        long long sums = 0;
        while (j<N){
            if (gx[j].x!=gx[i].x){
                break;
            }
            j++;
        }
        for (int a=i;a<j;a++){
            sums+=(gx[a].y);
        }
        long long before = 0;
        for (int a=i;a<j;a++){
            bx[a]=(gx[a].y)*(a-i)-before+sums-before-(j-a)*(gx[a].y);
            before=before+(gx[a].y);
        }
        i=j-1;
    }
    vector<long long> by(N);
    for (int i=0;i<N;i++){
        int j = i+1;
        long long sums=0;
        while (j<N){
            if (gy[j]->y!=gy[i]->y){
                break;
            }
            j++;
        }
        for (int a=i;a<j;a++){
            sums+=((gy[a]->x));
        }
        long long before = 0;
        for (int a=i;a<j;a++){
            by[a]=(gy[a]->x)*(a-i)-before+sums-before-(j-a)*(gy[a]->x);
            before=before+(gy[a]->x);
        }
        i=j-1;
    }
    long long area = 0;
    for (int i=0;i<N;i++){
        area+=(bx[i]%1000000007)*(by[gx[i].iy]%1000000007);
    }
    cout << area%1000000007;
}