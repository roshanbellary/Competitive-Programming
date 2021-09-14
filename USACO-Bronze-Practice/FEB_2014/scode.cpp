#include <iostream>
#include <string>
using namespace std;
int recurse(string s){
    if (s.length()<2 || (s.length()%2!=1)){
        return 1;
    }else{
        int tot=1;
        if (s.substr(0,s.length()/2)==s.substr(s.length()/2,s.length()/2)){// Remove first letter add to the back
            tot+=recurse(s.substr(s.length()/2, s.length()/2+1));
        }
        if (s.substr(0,s.length()/2)==s.substr(s.length()/2+1,s.length()/2)){//Remove first letter add front
            tot+=recurse(s.substr(0,(s.length())/2+1));
        }
        if (s.substr(0,s.length()/2)==s.substr(s.length()/2+1,s.length()/2)){//Remove last letter add front
            tot+=recurse(s.substr(s.length()/2,(s.length())/2+1));
        }
        if (s.substr(1,s.length()/2)==s.substr(s.length()/2+1,s.length()/2)){//Remove last letter add back
            tot+=recurse(s.substr(0,s.length()/2+1));
        }
        return tot;
    }
}
int main(){
    freopen("scode.in","r",stdin);
    freopen("scode.out","w",stdout);
    string store;
    cin >> store;
    int n = store.length();
    cout << recurse(store)-1;
}