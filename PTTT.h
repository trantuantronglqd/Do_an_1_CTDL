#include<iostream>
using namespace std;

class PTTT
{
private:
	int unknown;//Soan cua he phuong trinh
	int equation;//So phuong trinh cua he
	double** a;//Ma tan he so
	double* b;//He so tu do
public:
	PTTT();//Tao he phuong trinh
	~PTTT();//Huy he phuong trinh
public:
	void add();//Nhap vao he phuong trinh
	void display();//Xuat ra he phuong trinh
	void solve();//Giai he phuong trinh
};
