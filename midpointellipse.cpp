//similar to midpointcircle algo.
//quadrants are symmetric

//assumes center at origin;then change in the end accordingly
//decision function, F=(b^2 * x^2)+(a^2 * y^2)-(a^2 * b^2)
//point will be on(=0) the boundary,inside(<0) or outside(>0) depending on it

//here at each quadrant,slope varies,so decision parameters have to be changed accordingly(ie, divide a quadrant into 2regions,where at each region x/y having rate of change less as compared to the other will be chosen for the midpoint function and other will be incr. by 1unit)

//starting from (0,b) is R1; same point to (a,0) is R2
//in first quadrant,R1 rate of change of y will be less,=> decision function wrt y and x incr. in 1units.
//similarly in R2, rate of change of x will be less,so we need those minute pixel calc. wrt x, and y will be incr. in units of 1.
//switch b/w R1 and R2 happens at point where rate of change wrt both x and y becomes the same(we move out of region 1 when 2*b^2*x >= 2*a^2*y is violated)


//code gives points different from slides;eqn in slides faulty?
#include<iostream>
#include<vector>
#include<cmath>

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

	int a,b;
	cin>>a>>b;

	int b2=b*b,a2=a*a;

	vector<struct Point> points;

	int x=0,y=b;

	//R1
	float P1=b2-(a2*b)+((1/4)*a2);
	while(b2*x<=a2*y){
		struct Point p;
		p.x=x;p.y=y;
		points.push_back(p);

		if(P1<0){
			P1+=2*b2*(x+1)+b2;
		}
		else{
			y-=1;
			P1+=2*b2*(x+1)+b2-2*a2*(1-y);
		}
		x+=1;
	}

	//R2
	float P2=b2*(pow(x+(1/2),2))+a2*(pow(y-1,2))-(a2*b2);
	while(x<=a && y>=0){
		struct Point p;
		p.x=x;p.y=y;
		points.push_back(p);

		if(P2<0){
			x+=1;
			P2+=2*b2*(x+1)+a2-(2*a2*(y-1));
		}
		else{
			P2+=a2-(2*a2*(y-1));
		}
		y-=1;
	}

	for(int i=0;i<points.size();i++){
		cout<<"("<<points.at(i).x<<", "<<points.at(i).y<<")"<<endl;
	}

	return 0;
}