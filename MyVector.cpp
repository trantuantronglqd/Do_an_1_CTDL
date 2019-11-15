#include "MyVector.h"

//Khoi tao mot vector khong doi so
MyVector::MyVector()
{
	size = 100;
	v = new double[size];
}
//Sao chep vector tu mot vector khac
MyVector::MyVector(const MyVector& a)
{
	int i;
	size = a.size;
	v = new double[size];
	for (i = 0; i < size; i++)
		v[i] = a.v[i];
}
//Huy vector
MyVector::~MyVector()
{
	delete[]v;
}
//Nhap vao vector co size phan tu
void MyVector::add()
{
	cout << "Nhap vao so phan tu cua vector: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "v[" << i << "]= ";
		cin >> v[i];
	}
}
//Xuat ra vector co size phan tu
void MyVector::display()
{
	for (int i = 0; i < size; i++)
		cout << v[i] << "    ";
	cout << endl;
}
//Toan tu cong 2 vector
void MyVector::operator + (MyVector a)
{
	//Neu 2 vector cung so phan tu thuc hien cong 2 phan tu o tung vi tri voi nhau
	if (size == a.size)
	{
		for (int i = 0; i < size; i++)
			this->v[i] = v[i] + a.v[i];
		cout << "Tong cua hai vector la: ";
		this->display();
	}
	else //Neu 2 vector khong cung so phan tu thi khong thuc hien đuoc phep cong
	{
		cout << "Hai vector khong cung so phan tu nen khong thuc hien duoc phep cong." << endl;
		return;
	}
}
//Nhan vector voi mot so a
MyVector MyVector::operator * (double a)
{
	//Nhan tung phan tu cua vector voi so a
	for (int i = 0; i < size; i++)
		this->v[i] = v[i] * a;
	return *this;
}