#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<vector<char> > A;
int maximum = 0;
int checking(char x, int i, int j){
    int count = 0;
    bool a,b,c,d;
    a= (i>1);
    b = (j>1);
    c = (i<N-2);
    d = (j<M-2);
    if (a){
        if ((A[i-1][j]==x)&&(A[i-2][j]==x)){
            count++;
        }
    }
    if (b){
        if ((A[i][j-1]==x)&&(A[i][j-2]==x)){
            count++;
        }
    }
    if (c){
        if ((A[i+1][j]==x)&&(A[i+2][j]==x)){
            count++;
        }
    }
    if (d){
        if ((A[i][j+1]==x)&&(A[i][j+2]==x)){
            count++;
        }
    }
    if (a&&d){
        if ((A[i-1][j+1]==x)&&(A[i-2][j+2]==x)){
            count++;
        }
    }
    if (a&&b){
        if ((A[i-1][j-1]==x)&&(A[i-2][j-2]==x)){
            count++;
        }
    }
    if (c&&b){
        if ((A[i+1][j-1]==x)&&(A[i+2][j-2]==x)){
            count++;
        }
    }
    if (c&&d){
        if ((A[i+1][j+1]==x)&&(A[i+2][j+2]==x)){
            count++;
        }
    }
    return count;
}
void check(char x, char y){
    int total=0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (A[i][j]==x){
                total+=checking(y,i,j);
            }
        }
    }
    if (total>maximum){
        maximum=total;
    }
}
void iterate(){
    char x[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (int i=0;i<26;i++){
        for (int j=0;j<26;j++){
            if ((j!=i)&&(x[i]!='M')&&(x[j]!='O')){
                check(x[i],x[j]);
            }
        }
    }
}
int main(){
    freopen("moocrypt.in","r",stdin);
    freopen("moocrypt.out","w",stdout);
    cin >> N >> M;
    for (int i=0;i<N;i++){
        vector<char> store1;
        for (int j=0;j<M;j++){
            char store;
            cin >> store;
            store1.push_back(store);
        }
        A.push_back(store1);
    }
    iterate();
    cout << maximum;
}
