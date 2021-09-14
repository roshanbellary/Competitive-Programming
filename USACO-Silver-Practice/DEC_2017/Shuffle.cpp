#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N;
map<int, int> a;
bool works=false;
vector<bool> visited;
void dfs(int i, int init){
    visited[i]=true;
    if (i==init){
        works=true;
    }else if (!visited[a[i]]){
        dfs(a[i],init);
    }else{
        return;
    }
}
int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++)
        visited.push_back(false);
    for (int i=0;i<N;i++){
        int index;
        cin >> index;
        a[i]=index-1;
    }
    int counts=0;
    vector<int> il(N);
    for (int i=0;i<N;i++){
        works=false;
        fill(visited.begin(),visited.end(),false);
        dfs(a[i],i);
        if (works) counts++;
    }
    cout << (counts);
}