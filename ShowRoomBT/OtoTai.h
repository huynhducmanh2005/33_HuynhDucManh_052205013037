#pragma once
#include "Showroom.h"
class OtoTai :public Showroom
{
private:
	float taiTrong;
public:
	OtoTai();
	OtoTai(string, int, double, long long int, float);
	void setTaiTrong(float taiTrong);
	float getTaiTrong() const;
	void toString() const override;
	long long int tinhThue() const override;
	long int thueTruocBa() const override;
	friend ostream& operator<<(ostream& out, const OtoTai& f);
};

