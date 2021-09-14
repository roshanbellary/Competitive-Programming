#include <bits/stdc++.h>
using namespace std;
int B,E;
vector<int> b;
vector<int> e;
int main(){
    freopen("greetings.in","r",stdin);
    freopen("greetings.out","w",stdout);
    cin >> B >> E;
    for (int i=0;i<B;i++){
        int d;
        char dir;
        cin >> d >> dir;
        if (dir=='R') b.push_back(d);
        else b.push_back(-d);
    }
    for (int i=0;i<E;i++){
        int d;
        char dir;
        cin >> d >> dir;
        if (dir=='R') e.push_back(d);
        else e.push_back(-d);
    }
    int ei = 0;
    int bi = 0;
    int bp = 0;
    int ep = 0;
    int storeb = b[bi];
    int storee = e[ei];
    int moos = 0;
    bool before = true;
    while ((ei<E)&&(bi<B)){
        if (bp==ep){
            if (!before) moos++;
            before=true; 
        }else{
            before=false;
        }
        if (storeb==0){
            bi++;
            if (bi<B){
                storeb+=b[bi];
            }
            else{
                break;
            }
        }
        if (storee==0){
            ei++;
            if (ei<E) storee+=e[ei];
            else break;
        }
        if (storeb<0){
            storeb++;
            bp--;
        }else{
            storeb--;
            bp++;
        }
        if (storee<0){
            storee++;
            ep--;
        }else{
            storee--;
            ep++;
        }
    }
    before = (bp==ep);
    while (bi<B){
        if (bp==ep){
            if (!before) moos++; 
            before=true;
        }else{
            before=false;
        }
        if (storeb==0){
            bi++;
            if (bi<B) storeb+=b[bi];
            else break;
        }
        if (storeb<0){
            storeb++;
            bp--;
        }else if (storeb>0){
            storeb--;
            bp++;
        }
    }
    while (ei<E){
        if (bp==ep){
            if (!before) moos++; 
            before=true;
        }else{
            before=false;
        }
        if (storee==0){
            ei++;
            if (ei<E) storee+=e[ei];
            else break;
        }
        if (storee<0){
            storee++;
            ep--;
        }else{
            storee--;
            ep++;
        }
    }
    cout << moos;
}