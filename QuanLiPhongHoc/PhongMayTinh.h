#pragma once
#include "PhongHoc.h"
class PhongMayTinh : public PhongHoc
{
private:
	int mayTinh;
public:
	PhongMayTinh();
	PhongMayTinh(string, string, float, int, int);
	void setMayTinh(int mayTinh);
	int getMayTinh() const;
	void danhSach() const override;
	bool datChuan() const override;
	friend ostream& operator<<(ostream& out, const PhongMayTinh& f);

};



