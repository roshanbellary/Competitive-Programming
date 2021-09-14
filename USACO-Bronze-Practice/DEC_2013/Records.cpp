#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;
vector<string> names;
vector<int> counts;
int N;
int main(){
    freopen("records.in","r",stdin);
    freopen("records.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        string a,b,c;
        cin >> a >> b >> c;
        string d,e,f,g,h,k;
        d=a+b+c;
        e=a+c+b;
        f=b+a+c;
        g=b+c+a;
        h=c+a+b;
        k=c+b+a;
        int temp = -1;
        for (int j=0;j<names.size();j++){
            if ((names[j]==d)||(names[j]==e)||(names[j]==f)||(names[j]==g)||(names[j]==h)||(names[j]==k)){
                temp=j;
            }
        }
        if (temp>=0){
            counts[temp]++;
        }else{
            names.push_back(d);
            counts.push_back(1);
        }
    }
    int maximum=0;
    for (int i=0;i<counts.size();i++){
        maximum=max(maximum,counts[i]);
    }
    cout << maximum;
}