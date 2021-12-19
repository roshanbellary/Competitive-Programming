#include <bits/stdc++.h>
using namespace std;
struct BigInteger{
    string n;
    BigInteger operator+(BigInteger p){
        string t1=n;string t2=p.n;
        reverse(begin(t1),end(t1));
        reverse(begin(t2),end(t2));
        string res = "";
        bool carry = 0;
        for (int i=0;i<max(t1.size(),t2.size());i++){
            int sum=carry;
            if (i<t1.size()) sum+=t1[i];
            if (i<t2.size()) sum+=t2[i];
            if (sum>=10) carry=1, sum-=10;
            else carry = 0;
            res+=to_string(sum);
        }
        reverse(begin(res),end(res));
        BigInteger ni;ni.n=res;
    }
    BigInteger operator-(BigInteger p){

    }
    
};
int main(){

}