#pragma once
#include"ChuyenXe.h"
class NgoaiThanh :public ChuyenXe
{
private:
	string noiDen;
	int soNgayDi;
public:
	NgoaiThanh();
	NgoaiThanh(string, string, string, int, string, int);
	void setNoiDen(string noiDen);
	void setSoNgayDi(int soNgayDi);
	string getNoiDen() const;
	int getSoNgayDi() const;
	void  thongTinChuyenXe() const override;

	friend ostream& operator<<(ostream& out, const NgoaiThanh& f);
};

