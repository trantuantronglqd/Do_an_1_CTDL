#include<iostream>

using namespace std;

//Xây dựng lớp ma trận
class MyMatrix
{
private:
	int col;//So cot cua ma tran
	int row;//So dong cua ma tran
	double** arr;//Mang 2 chieu chua ca phan tu cua ma tran
public:
	MyMatrix();//tao ma tran khong doi so
	MyMatrix(const MyMatrix& m);//Sao chep ma tran tu mot ma tran khac
	~MyMatrix();//Huy ma tran
public:
	void add();//Nhap vao ma tran
	void display();//Xuat ra ma tran
	bool SquareMatrix();//Kiem tra co phai ma tran vuong khong?
	double det();//Tinh đinh thuc ma tran
	void Inverse();//Tim ma tran nghich đao
	void operator * (const MyMatrix& a);//Toan tu nhan ma tran
	int Rank();//Tim hang cua ma tran
};
