#include <iostream>
#include <string>
#include <cmath>
#define ll long long
ll N;
char letter;
using namespace std;
void getletter(string w, long count){
    if (count < w.length()){
        letter=w[count];
        return;
    }else{
        long len = w.length();
        while (len<=count/2){
            len*=2;
        }
        if (len==count){
            return getletter(w, len-1);
        }else{
            return getletter(w,count-len-1);
        }
    }
}
int main(){
    freopen("cowcode.in","r",stdin);
    freopen("cowcode.out","w",stdout);
    string w;
    cin >> w >> N;
    getletter(w,N-1);
    cout << letter;
}