//makes use of the symmetry of circle(need to calculate only the points of the first octet;rest can be formed by symmetry)
//similar to bresenham algo. in that it also is scan-conversion(ie, determine pixel position closest to the circle path)
//assumes circle is at origin for algo;but in screen center,we make appropriate changes;
//decision circle function, F=(x^2+y^2)-r^2 ; with points being on the boundary of circle(=0),inside(<0) or outside(>0) it;

#include<iostream>
#include<vector>

using namespace std;
struct Point{
	int x;
	int y;
};

int main(){
	
	return 0;
}