#include <bits/stdc++.h>
using namespace std;
string Al = "BCDFGHJKLMNOPQRSTVWXZ";
string al = "bcdfghjklmnopqrstvwxz";
string vl = "aeiouy";
string val = "AEIOUY";
string tl = "abcdefghijklmnopqrstuvwxyz";
bool searchAl(char l){
    for (int i=0;i<6;i++){
        if ((vl[i]==l)||(val[i]==l)) return false;
    }
    return true;
}
int main(){
    string store;
    cin >> store;
    string res;
    for (int i=0;i<store.length();i++){
        if (searchAl(store[i])){
            if (Al.find(store[i])!=string::npos){
                res+=("."+al.substr(Al.find(store[i]),1));
            }else{
                res+=("."+store.substr(i,1));
            }
        }
    }
    cout << res << "\n";
}