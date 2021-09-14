#include <bits/stdc++.h>
using namespace std;
int N;
vector<string > bad;
vector<string> bads;
vector<string > good;
vector<string> goods;
int main(){
    freopen("scramble.in","r",stdin);
    freopen("scramble.out","w",stdout);
    cin >> N;
    for (int i=0;i<N;i++){
        string store;
        cin >> store;
        char store2[store.length()];
        char store3[store.length()];
        for (int j=0;j<store.length();j++){
            store2[j]=store[j];
            store3[j]=store[j];
        }
        sort(store2,store2+store.length());
        sort(store3,store3+store.length(),greater<char>());
        string less;
        string more;
        for (int j=0;j<store.length();j++){
            less+=store2[j];
            more+=store3[j];
        }
        bad.push_back(more);
        bads.push_back(more);
        good.push_back(less);
        goods.push_back(less);
    }
    sort(bad.begin(),bad.end());
    sort(good.begin(),good.end());
    for (int i=0;i<N;i++){
        int index1 = -1;
        int index2 = -1;
        int a = 0;
        int b = N-1;
        while (a!=b){
            int mid = (a+b+1)/2;
            if (bads[i].compare(good[mid])>=0){
                a=mid;
            }else{
                b=mid-1;
            }
        }
        index1=a+1;
        int c = 0;
        int d = N-1;
        while (c!=d){
            int mid = (c+d)/2;
            if (goods[i].compare(bad[mid])<=0){
                d=mid;
            }else{
                c=mid+1;
            }
        }
        index2=c+1;
        cout << index2 << " " << index1 << endl;
    }
}