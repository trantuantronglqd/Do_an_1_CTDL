#include "MyMatrix.h"

//Ham khoi tao ma tran khong doi so
MyMatrix::MyMatrix()
{
	row = col = 100;
	arr = new double* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new double[col];
}
//Ham sao chep ma tran tu mot ma tran khac
MyMatrix::MyMatrix(const MyMatrix& m)
{
	row = m.row;
	col = m.col;
	arr = new double* [row];
	for (int i = 0; i < row; i++)
		arr[i] = new double[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			arr[i][j] = m.arr[i][j];
}
// Ham huy ma tran
MyMatrix::~MyMatrix()
{
	for (int i = 0; i < row; i++)
		delete arr[i];
	delete arr;
}
//Ham nhap vao ma tran co row hang va col cot
void MyMatrix::add()
{
	cout << "Nhap so hang : "; cin >> row;
	cout << "Nhap so cot : "; cin >> col;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> arr[i][j];
		}
}
//Ham xuat ma tran co row hang va col cot
void MyMatrix::display()
{
	cout << "Ma tran ban vua nhap vao: " << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}
///Ham kiem tra co phai ma tran vuong hay khong
bool MyMatrix::SquareMatrix()
{
	return (row == col);
}
//Tinh dinh thuc cua ma tran
double MyMatrix::det()
{
	MyMatrix A(*this);
	int i, j, k;
	double det = 1;
	double temp;
	// Tinh dinh thuc cua A
	for (i = 0; i < A.row - 1; i++)
	{
		if (A.arr[i][i] == 0) // Neu gap phan tu tren đuong cheo chinh bang 0 thi tim hang khac đe đoi
		{
			k = i + 1;
			while (k < A.row && A.arr[k][i] == 0) k++;
			if (k == A.row)
				return 0; // Khong tim thay, tuc det(A) = 0
			for (j = i; j < A.row; j++)// Đoi hang i voi hang k
			{
				temp = A.arr[i][j];
				A.arr[i][j] = A.arr[k][j];
				A.arr[k][j] = temp;
			}
		}
		for (j = i + 1; j < A.row; j++)// Bien đoi đe các phan tu cung cot ở hang duoi bang 0
		{
			temp = -A.arr[j][i] / A.arr[i][i];
			for (k = i + 1; k < A.row; k++)
				A.arr[j][k] += temp * A.arr[i][k]; // Nhan hang i voi (-a[j][i]/a[i][i]) roi cong vao hang j
		}
		det *= A.arr[i][i]; // Tinh dan det(A)
	}
	det *= A.arr[row - 1][row - 1]; // Nhan voi phan tu cuoi cheo chinh 

	return det;
}
//Tim ma tran nghich dao cua ma tran
void MyMatrix::Inverse()
{
	double** a, ratio, temp;
	int i, j, k;
	int n = row;
	// Kiem tra neu khong phai ma tran vuong thi khong co nghich dao
	if (row != col)
	{
		cout << "Ma tran vua nhap vao khong phai ma tran vuong nen khong co ma tran nghich dao." << endl;
		return;
	}
	//Khoi tao mang de luu ma tran don vi
	a = new double* [row + 1];
	for (int i = 0; i <= row; i++)
		a[i] = new double[2 * col];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = arr[i][j];
		}
	}
	//Thiet lap ma tran don vi
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
			{
				a[i][j + n] = 1;
			}
			else
			{
				a[i][j + n] = 0;
			}
		}
	}
	// Đua ma tran ve dang bac thang bang cac bien đoi so cap tren dong (loai bo Gauss)
	for (i = 0; i < n; i++)
	{
		if (a[i][i] == 0)
		{
			cout << "Ma tran vua nhap vao khong co nghich dao" << endl;
			return;
		}
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				ratio = a[j][i] / a[i][i];
				for (k = 0; k < 2 * n; k++)
				{
					a[j][k] = a[j][k] - ratio * a[i][k];
				}
			}
		}
	}
	//Dua ma tran ban dau ve dang don vi, dong thoi dua ma tran don vi về dang nghich dao
	for (i = 0; i < n; i++)
	{
		temp = a[i][i];
		for (j = 0; j < 2 * n; j++)
		{
			a[i][j] = a[i][j] / temp;
		}
	}
	// Xuat ma tran nghich dao
	cout << "Ma tran nghich dao la: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = n; j < 2 * n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
//Tim hang cua ma tran
int MyMatrix::Rank()
{
	int i, j, k, t;
	double temp, luu;
	int rank = row; // Khoi tao hang bang so hang

	i = j = 0;
	// Dung cac phep bien doi de dua ma tran ve dang bac thang
	while (i < row && j < col)
	{
		if (arr[i][j] == 0)
		{
			for (t = i + 1; t < row; t++)
				if (arr[t][j] != 0)
				{
					for (k = i; k < col; k++)
					{
						temp = arr[t][k];
						arr[t][k] = arr[i][k];
						arr[i][k] = temp;
					}
					break;
				}
			if (t == row)j++;
		}
		if (arr[i][j] != 0)
		{
			for (t = i + 1; t < row; t++)
				if (arr[t][j] != 0)
				{
					luu = arr[t][j];
					for (k = j; k < col; k++)
						arr[t][k] = arr[t][k] - arr[i][k] * luu / arr[i][j];
				}
			i++; j++;
		}
	}
	// Tinh rank bang cach lay row tru so hang co tat ca cac phan tu bang 0
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			if (arr[i][j] != 0)break;
		if (j == col)rank--;
	}
	return rank;
}
//Toan tu nhan 2 ma tran
void MyMatrix::operator * (const MyMatrix& a)
{
	//Neu so cot cua ma tran thu nhat khac so hang cua ma tran thu 2 thi khong the tinh tich
	if (col != a.row)
	{
		cout << "Khong the tinh tich 2 ma tran" << endl;
		return;
	}
	// Khoi tao mang ket qua
	double** kq; 
	kq = new double* [row];
	for (int i = 0; i < row; i++)
		kq[i] = new double[a.col];
	int i, j, k;
	// Tinh cac phan tu cua ma tran tich
	for (i = 0; i < row; i++)
		for (j = 0; j < a.col; j++)
		{
			kq[i][j] = 0;
			for (k = 0; k < col; k++)
			{
				kq[i][j] += arr[i][k] * a.arr[k][j];
			}
		}
	//Xuat ket qua
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < a.col; j++)
		{
			cout << kq[i][j] << "\t";
		}
		cout << endl;
	}
}
