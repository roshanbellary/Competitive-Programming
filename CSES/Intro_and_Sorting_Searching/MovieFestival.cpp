#include <bits/stdc++.h>
using namespace std;
class Movie{
    public:
        int s,f;
};
bool sorts(Movie &a, Movie &b){
    return (a.f<b.f);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    vector<Movie> th;
    for (int i=0;i<N;i++){
        Movie store;
        int s,f;
        cin >> s >> f;
        store.s=s;store.f=f;
        th.push_back(store);
    }
    sort(th.begin(),th.end(),sorts);
    int count = 1;
    int temp = 0;
    for (int i=0;i<N;i++){
        if (th[i].s>=th[temp].f){
            count++;
            temp=i;
        }
    }
    cout << count;
}