#include "PhanSo.h"

void PhanSo::setTu1(int t1)
{
	tu1 = t1;
}

int PhanSo::getTu1() const
{
	return tu1;
}

void PhanSo::setTu2(int t2)
{
	tu2 = t2;
}

int PhanSo::getTu2() const
{
	return tu2;
}

void PhanSo::setMau1(int m1)
{
	mau1 = m1;
}

int PhanSo::getMau1() const
{
	return mau1;
}

void PhanSo::setMau2(int m2)
{
	mau2 = m2;
}

int PhanSo::getMau2() const
{
	return mau2;
}

int PhanSo::tu_tong()
{
	return tu1 * mau2 + tu2 * mau1;
}

int PhanSo::mau_tong()
{
	return mau1 * mau2;
}

PhanSo::PhanSo()
{
	setTu1(3);
	setTu2(5);
	setMau1(2);
	setMau2(4);
}

PhanSo::PhanSo(int t1, int t2, int m1, int m2)
{
	setTu1(t1);
	setTu2(t2);
	setMau1(m1);
	setMau2(m2);
}
