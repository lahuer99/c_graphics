//DDA - Digital Differential Analyzer
//its a scan-conversion line algorithm(take next nearest pixel to line)

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
struct Point{
	int x;
	int y;
};

int main(){
	#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
	
	struct Point p1,p2;
	cin>>p1.x>>p1.y>>p2.x>>p2.y;

	int dx=p2.x-p1.x,dy=p2.y-p1.y;
	int steps=max(abs(dx),abs(dy));

	float x=p1.x,y=p1.y;

	float xinc=(float)dx/steps,yinc=(float)dy/steps;

	vector<struct Point> points;
	points.push_back(p1);

	for(int i=0;i<steps;i++){
		x+=xinc;y+=yinc;
		struct Point p;
		p.x=round(x);p.y=round(y);
		points.push_back(p);
	}

	for(int i=0;i<points.size();i++){
		cout<<"("<<points.at(i).x<<", "<<points.at(i).y<<")"<<endl;
	}

	return 0;
}