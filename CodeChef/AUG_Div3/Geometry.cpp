#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void setIO(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}
void setIO(string f){
	string in = f+".in";
	string out = f+".out";
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	setIO();
}
double v,t;
class Point{
	public:	
		double x; double y;
		double dist(Point &n){
			return (sqrt(pow(n.x-x,2)+pow(n.y-y,2)));
		}
};
class Segment{
	public:	
		Point p1,p2;
		double slope(){
			if (p2.x!=p1.x){return ((p2.y-p1.y)/(p2.x-p1.x));}
			else{return -1e9;}
		}
		double perpendicular(Point &n){
			double sl1 = slope();
			if (sl1==0){
				double r = v*t/(abs(p1.y-n.y));
				return abs(p1.y-n.y);
			}else if (sl1==-1e9){
				double r = v*t/(abs(p1.x-n.x));
				return abs(p1.x-n.x);
			}else{
				double sl2 = -1/sl1;
				double dy = n.y-p1.y;
				double x = (dy-sl2*n.x+sl1*p1.x)/(sl1-sl2);
				double y = sl1*(x-p1.x)+p1.y;
				Point n2; n2.x=x; n2.y=y;
				return sqrt(pow(x-n.x,2)+pow(y-n.y,2));
			}
		}
		double length(){
			return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
		}
		double angle(Segment n){
			pair<double, double> disp1 = make_pair(p1.x-p2.x,p1.y-p2.y);
			pair<double, double> disp2 = make_pair(n.p2.x-n.p1.x,n.p2.y-n.p1.y);
			double dotprod = disp1.first*disp2.first+disp1.second*disp2.second;
			double cangle = dotprod/(length()*n.length());
			return acos(cangle);
		}
};
int T;
int N, Q;
int main(){
	setIO();
	cin >> T;
	cout << fixed << setprecision(10);
	for (int l=0;l<T;l++){
		cin >> N >> Q;
		vector<Point> p;
		for (int i=0;i<N;i++){
			double x, y; cin >> x >> y;
			Point n; n.x=x; n.y=y;
			p.push_back(n);
		}
		double area = 0;
		Point center;
		double sumx = 0;
		double sumy = 0;
		for (int i=0;i<N;i++){
			sumx+=p[i].x;
			sumy+=p[i].y;
			int next = (i+1)%N;
			area+=(p[next].y*p[i].x-p[i].y*p[next].x);
		}
		area=abs(area)/2;
		center.x=(sumx)/N;
		center.y=(sumy)/N;
		vector<Segment> s;
		double sums = 0;
		double quant = 0;
		for (int i=0;i<N;i++){
			Segment n;
			int next = (i+1)%N;
			n.p1=p[i];n.p2=p[next];
			s.push_back(n);
			sums+=abs(n.length());
		}
		for (int i=0;i<N;i++){
			int next = (i+1)%N;
			double a = s[i].angle(s[next]);
			quant+=(abs(tan(M_PI/2-a/2)));
		}
		for (int i=0;i<Q;i++){
			cin >> v >> t;
			double d = v*t;
			cout << area+d*sums+pow(d,2)*quant << "\n";
		}
	}
}
