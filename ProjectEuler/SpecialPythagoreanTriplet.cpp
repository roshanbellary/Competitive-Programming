/*
Problem: Special Pythagorean triplet
Problem Link: https://projecteuler.net/problem=9
Notes: 
No need to program this problem
One cool thing about pythagorean triplets is that they can be expressed
as a=m^2-n^2, b=2mn, c=m^2+n^2
Thus we just have to find m, n st. m>n and m<m+n and 2m^2+2mn=1000
2m^2+2mn=1000 => 2m(m+n)=1000 => m(m+n)=500
the above equation gives us that m=20, n=5
thus m^2-n^2=375,2mn=200, and m^2+n^2=425
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << 200*375*425 << "\n";
}
