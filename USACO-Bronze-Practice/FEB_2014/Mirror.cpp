#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M;
bool repeat = false;
int counts=0;
vector<vector<bool> >l;
void simulate(int i, int j, int dir){
    if (i>=N||i<0||j>=M||j<0) return;
    counts++;
    if (dir==0){// +x direction
        if (l[i][j]) simulate(i-1,j,3);// moves up
        else simulate(i+1,j,2); // moves down
    }
    if (dir==1){// -x direction
        if (l[i][j]) simulate(i+1,j,2);//moves down
        else simulate(i-1,j,3);//moves up
    }
    if (dir==2){// +y direction
        if (l[i][j]) simulate(i,j-1,1);
        else simulate(i,j+1,0);
    }
    if (dir==3){// -y direction
        if (l[i][j]) simulate(i,j+1,0);
        else simulate(i,j-1,1);
    }
}
int main(){
    freopen("mirror.in","r",stdin);
    freopen("mirror.out","w",stdout);
    cin >> N >> M;
    for (int i=0;i<N;i++){
        l.push_back(vector<bool>(M));
    }
    for (int i=0;i<N;i++){
        string store;
        cin >> store;
        for (int j=0;j<M;j++){
            if (store.substr(j,1)=="/"){
                l[i][j]=true;
            }
            else {
                l[i][j]=false;
            }
        }
    }
    int maximum=0;
    for (int i=0;i<M;i++){// simulates top row
        counts=0;
        simulate(0,i,2);
        maximum=max(maximum,counts);
    }
    for (int i=0;i<N;i++){//simulates first column
        counts=0;
        simulate(i,0,0);
        maximum=max(maximum,counts);
    }
    for (int i=0;i<N;i++){//simulates last column
        counts=0;
        simulate(i,M-1,1);
        maximum=max(maximum,counts);
    }
    for (int i=0;i<M;i++){//simulates bottom row
        counts=0;
        simulate(N-1,i,3);
        maximum=max(maximum,counts);
    }
    cout << maximum;
}