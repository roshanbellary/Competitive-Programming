#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
vector<vector<int> > a;
int total=0;
int maximum=0;
int main(){
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        a.push_back(vector<int>());
    }
    for (int i=0;i<N-1;i++){
        int i1, i2;
        cin >> i1 >> i2;
        i1--;i2--;
        a[i1].push_back(i2);
        a[i2].push_back(i1);
    }
    for (int i=0;i<N;i++){
        if (a[i].size()+1>maximum){
            maximum=a[i].size()+1;
        }
    }
    cout << maximum;
}