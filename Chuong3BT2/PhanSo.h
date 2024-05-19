#pragma once
class PhanSo
{
private:
	int tu1, mau1, tu2, mau2;
public:
	void setTu1(int t1);
	int getTu1() const;
	void setTu2(int t2);
	int getTu2() const;
	void setMau1(int m1);
	int getMau1() const;
	void setMau2(int m2);
	int getMau2() const;
	int tu_tong();
	int mau_tong();
	PhanSo();
	PhanSo(int t1, int t2, int m1, int m2);
};

