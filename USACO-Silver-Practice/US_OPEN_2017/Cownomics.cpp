#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int N, M;
vector<string> sp;
vector<string> pl;
bool check(int i,int j, int z){
  bool s[64];
  bool p[64];
  fill(s,s+64,false);
  fill(p,p+64,false);
  for (int a=0;a<N;a++){
    vector<string> spot;
    vector<string> plain;
    spot.push_back(sp[a].substr(i,1));
    spot.push_back(sp[a].substr(j,1));
    spot.push_back(sp[a].substr(z,1));
    plain.push_back(pl[a].substr(i,1));
    plain.push_back(pl[a].substr(j,1));
    plain.push_back(pl[a].substr(z,1));
    int sum1=0;
    int count=1;
    for (int b=0;b<3;b++){
      if (spot[b]=="A"){
        sum1+=count*0;
      }
      if (spot[b]=="T"){
        sum1+=count*1;
      }
      if (spot[b]=="C"){
        sum1+=count*2;
      }
      if (spot[b]=="G"){
        sum1+=count*3;
      }
      count*=4;
    }
    if (p[sum1]){
      return false;
    }else{
      s[sum1]=true;
    }
    int sum2=0;
    count=1;
    for (int b=0;b<3;b++){
        if (plain[b]=="A"){
          sum2+=count*0;
        }
        if (plain[b]=="T"){
          sum2+=count*1;
        }
        if (plain[b]=="C"){
          sum2+=count*2;
        }
        if (plain[b]=="G"){
          sum2+=count*3;
        }
        count*=4;
    }
    if (s[sum2]){
      return false;
    }else{
      p[sum2]=true;
    }
    if (sum1==sum2) return false;
    spot.clear();
    plain.clear();
  }
  return true;
}
int main(){
  freopen("cownomics.in","r",stdin);
  freopen("cownomics.out","w",stdout);
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    string store;
    cin >> store;
    sp.push_back(store);
  }
  for (int i=0; i<N; i++) {
    string store;
    cin >> store;
    pl.push_back(store);
  }
  int answer = 0;
  for (int i=0;i<M;i++){
    for (int j=i+1;j<M;j++){
      for (int z=j+1;z<M;z++){
        if (check(i,j,z)) answer++;
      }
    }
  }
  cout << answer << "\n";
  return 0;
}