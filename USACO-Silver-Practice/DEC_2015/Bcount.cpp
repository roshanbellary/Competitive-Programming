#include <iostream>
#include <vector>
using namespace std;
int main() {
	freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);
	int N,Q;
	cin >> N >> Q;
	int s[3][N];
	int a,b;
	cin >> a;
	s[a-1][0]=1;
	s[(a%3)][0]=0;
	s[(a+1)%3][0]=0;
	for (int i=1;i<N;i++){
		cin >> a;
		s[a-1][i]=s[a-1][i-1]+1;
		s[(a%3)][i]=s[(a%3)][i-1];
		s[(a+1)%3][i]=s[(a+1)%3][i-1];
	}
	for (int i=0;i<Q;i++){
		cin >> a >> b;
		if (a>1){
			cout << s[0][b-1]-s[0][a-2] << " " << s[1][b-1]-s[1][a-2] << " "<< s[2][b-1]-s[2][a-2]<<endl;
		}else{
			cout << s[0][b-1] << " " << s[1][b-1] << " "<< s[2][b-1]<<endl;
		}
	}
	return 0;
}
