#include <iostream>

using namespace std;

class MyVector
{
private:
	int size;//So phan tu cua vector
	double* v;//Mang chua cac phan tu
public:
	MyVector();//Tao vector khong doi so
	MyVector(const MyVector& a);//Sao chep vector tu 1 vector khac
	~MyVector();//Huy vector
public:
	void add();//Nhap vao vector
	void display();//Xuat ra vector
	void operator + (MyVector a);//Toan tu cong 2 vector
	MyVector operator * (double a);//Toan tu nhan vector voi so a
};