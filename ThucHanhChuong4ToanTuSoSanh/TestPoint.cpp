#include <iostream>
#include "Point.h"
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
	vector<Point> lstPoint;
	//Doc file vao danh sach
	ifstream fi("data.txt");
	int n;
	fi >> n; //doc so luong diem
	for (int i = 0; i < n; i++)
	{
		Point p;
		fi >> p; //Da cai dat operator >> trong Point
		lstPoint.push_back(p);
	}
	fi.close();
	//In thu danh sach
	cout << "Danh sach diem: " << n << endl;
	for (int i = 0; i < lstPoint.size(); i++)
		cout << lstPoint[i] << endl; //Da cai dat operator << trong Point
	//Sap xep dung ham sort 
	sort(lstPoint.begin(), lstPoint.end());
	//In lai danh sach
	cout << "Danh sach sau khi sap xep\n";
	for (int i = 0; i < lstPoint.size(); i++)
		cout << lstPoint[i] << endl;
}