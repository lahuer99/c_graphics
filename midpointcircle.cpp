//makes use of the symmetry of circle(need to calculate only the points of the first octet;rest can be formed by symmetry)
//similar to bresenham algo. in that it also is scan-conversion(ie, determine pixel position closest to the circle path)
//assumes circle is at origin for algo;but in screen center,we make appropriate changes;
//decision circle function, P=(x^2+y^2)-r^2 ; with points being on the boundary of circle(=0),inside(<0) or outside(>0) it;
//in first octant,inc y by 1, x can be x or (x-1) depending on P[as we check with (x-0.5,y+1)]

//gives points of first octet;(have to complete to get full circle)
#include<iostream>
#include<vector>

using namespace std;
struct Point{
	int x;
	int y;
};

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	struct Point c;
	int r;
	cin>>c.x>>c.y>>r;

	vector<struct Point> points;

	float P=1.25-r;
	int x=r,y=0;
	while(x>=y){
		struct Point p;
		p.x=x;p.y=y;
		points.push_back(p);

		if(P<0){
			P+=2*(y+1)+1;
		}
		else{
			x-=1;
			P+=2*(y+1)-2*(x-1)+1;
		}
		y+=1;

	}

	for(int i=0;i<points.size();i++){
		cout<<"("<<points.at(i).x<<", "<<points.at(i).y<<")"<<endl;
	}
	
	return 0;
}