//Bresenham algorithm
//also a scan conversion algorithm(but only integer calc.)
//moves across the x-axis in unit intervals and chooses b/w y-coordinates(based on mid-point principle)
//does not consider vertical,horizontal and diagonal lines(has to be done explicitly)
//uses H and W in decision function F=2H(x-x1)-2W(y-y1);(=0 -> on line)
//F<0 => midpoint induced lines' slope is more than req. line, so we take (x+1,y)
//F>0 =>(x+1,y+1)


//line in first octet(can be modified for lines in other slopes as well)
#include<iostream>
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

	int H=p2.y-p1.y,W=p2.x-p1.x;
	int H2=2*H,F=H2-W,HW2=2*(H-W);

	vector<struct Point> points;

	int x=p1.x,y=p1.y;

	while(x<=p2.x){
		struct Point p;
		p.x=x;p.y=y;
		points.push_back(p);
		x+=1;

		if(F<0){
			F+=H2;
		}
		else{
			y+=1;
			F+=HW2;
		}
	}

	for(int i=0;i<points.size();i++){
		cout<<"("<<points.at(i).x<<", "<<points.at(i).y<<")"<<endl;
	}


	return 0;
}