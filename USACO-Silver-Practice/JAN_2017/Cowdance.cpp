#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, T;
vector<int> d;
bool check(int i){
    int index=i;
    priority_queue<int> q;
    for (int j=0;j<i;j++){
        q.push(-d[j]);//negative
    }
    int time=0;
    int start=0;
    while (index<N){
        if (!q.empty()){
            time+=(-q.top()-start);//positive 
            start=-q.top();//positive
            q.pop();
            q.push(-d[index]-start);
        }
        index++;
    }
    while (!q.empty()){
        time+=(-q.top()-start);
        start=-q.top();
        q.pop();
    }
    return (time<=T);
}
int main(){
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    cin >> N >> T;
    for (int i=0;i<N;i++){
        int store;
        cin >> store;
        d.push_back(store);
    }
    int a=1;
    int b=N-1;
    while (a!=b){
        int mid = (a+b)/2;
        if (check(mid)){
            b=mid;
        }else{
            a=mid+1;
        }
    }
    cout << a;
}