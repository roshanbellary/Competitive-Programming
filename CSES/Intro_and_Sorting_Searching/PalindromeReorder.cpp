#include <bits/stdc++.h>
#define long long ll;
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string w;
    cin >> w;
    int c[26];
    fill(c,c+26,0);
    for (int i=0;i<w.length();i++){
        int x = w[i]-'A';
        c[x]++;
    }
    char words[w.length()];
    int start = 0;
    bool works = true;
    int count = 0;
    int index = -1;
    for (int i=0;i<26;i++){
        if ((c[i]%2==1)&&(count>=1)){
            works=false;
            break;
        }else if (c[i]%2==1){
            count++;
            index = i;
        }
    }
    if (works){
        if (index>=0){
            int start = 0;
            for (int i=0;i<26;i++){
                if (i==index)continue;
                for (int j=0;j<c[i]/2;j++){
                    words[start+j]='A'+i;
                    words[w.length()-start-j-1]='A'+i;
                }
                start+=c[i]/2;
            }
            for (int j=0;j<c[index];j++){
                words[start+j]='A'+index;
                words[w.length()-start-j-1]='A'+index;
            }
            start+=c[index];
        }else{
            int start = 0;
            for (int i=0;i<26;i++){
                for (int j=0;j<c[i]/2;j++){
                    words[start+j]='A'+i;
                    words[w.length()-start-j-1]='A'+i;
                }
                start+=c[i]/2;
            }
        }
        for (int i=0;i<w.length();i++){
            cout << words[i];
        }
    }else{
        cout << "NO SOLUTION";
    }
}