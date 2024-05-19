#include "Fraction.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>
using namespace std;

int main()
{
	int n; 
	cout << "Nhap n: ";
	cin >> n;
	vector<Fraction> fraction;
	vector<Fraction> fractionUnique;

	for (int i = 0; i < 100; i++)
	{
		Fraction f(n);
		fraction.push_back(f);
	}
	if (n < 1 ) { cout << "Khong hop le "; }
	else
	{
		cout << "Phan so khong vuot qua 1/2: ";
		for (const Fraction& f : fraction)
		{
			if (f <= Fraction(1, 2))
			{
				cout << f << " ";
			}
		}
		cout << endl;
		if (n < 3) { cout << "Cac phan so bang nhau "; }
		else {

			sort(fraction.begin(), fraction.end());
			fractionUnique.push_back(fraction[0]);
			for (int i = 1; i < n; i++)
			{
				if (fraction[i] != fraction[i - 1] && fraction[i] != fraction[i + 1])
				{
					fractionUnique.push_back(fraction[i]);
				}
			}
			cout << "Phan so khong trung nhau: ";
			for (const Fraction& f : fractionUnique)
			{
				cout << f << " ";
			}
		}
	}
	return 0;
}