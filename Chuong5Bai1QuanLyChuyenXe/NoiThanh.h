#pragma once
#include"ChuyenXe.h"
class NoiThanh :public ChuyenXe
{
private:
	int soTuyen;
	int soKmDiDuoc;
public:
	NoiThanh();
	NoiThanh(string, string, string, int, int, int);
	void setSoTuyen(int soTuyen);
	void setSoKmDiDuoc(int soKmDiDuoc);
	int getSoTuyen() const;
	int getSoKmDiDuoc() const;
	void  thongTinChuyenXe() const override;
	friend ostream& operator<<(ostream& out, const NoiThanh& f);
};

