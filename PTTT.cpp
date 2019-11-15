#include"PTTT.h"

//Khoi tao he phuong trinh khong đoi so
PTTT::PTTT()
{
	unknown = 100;
	equation = 100;
	a = new double* [unknown];
	for (int i = 0; i < unknown; i++)
		a[i] = new double[unknown];
	b = new double[unknown];
}
//Huy he phuong trinh
PTTT::~PTTT()
{
	for (int i = 0; i < unknown; i++)
		delete a[i];
	delete a;
	delete b;
}
//Nhap vao he phuong trinh co unknown an va equation phuong trinh
void PTTT::add()
{
	cout << "Nhap vao so an cua he phuong trinh:  ";
	cin >> unknown;
	cout << "Nhap vao so phuong trinh cua he:  ";
	cin >> equation;
	for (int i = 0; i < equation; i++)
	{
		cout << "Nhap vao phuong trinh thu " << i + 1 << ": " << endl;
		for (int j = 0; j < unknown; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
		cout << "b[" << i << "] = ";
		cin >> b[i];
	}
	//Neu he co so phuong trinh it hon so nghiem thi tat ca cac phuong trinh bi khuyet deu co he so la 0
	if (equation < unknown)
	{
		for (int i = equation; i < unknown; i++)
		{
			for (int j = 0; j < unknown; j++)
				a[i][j] = 0;
			b[i] = 0;
		}
	}
}
//Xuat ra he phuong trinh co unknown an và equation phuong trinh
void PTTT::display()
{
	for (int i = 0; i < equation; i++)
	{
		for (int j = 0; j < unknown; j++)
		{
			cout << a[i][j] << " \t ";
		}
		cout << b[i];
		cout << endl;
	}
}
//Giai he phuong trinh co unknown an va equation phuong trinh
void PTTT::solve()
{
	int flag = 0;
	int i, j, k, m;
	double tam, x;
	//Tao ma tran lien ket
	for (i = 0; i < unknown; i++)
	{
		a[i][unknown] = b[i];
	}

	//Dung phep bien doi dua ve ma tran cheo
	for (j = 0; j < unknown; j++)
	{
		for (i = unknown - 1; i >= j; i--)
		{
			if (a[i][j] == 0) continue;//Neu phan tu bang 0 thi tang j
			if ((i > j) && (a[i][j] != 0))
			{
				k = i - 1;
				while ((k >= j) && (a[k][j] == 0)) k--;//Xet cac phan tu khac 0 tren cung cot j
				if (k < j)
				{
					//Đoi cho dong thu i va j cho ca ma tran mo rong.
					for (m = 0; m <= unknown; m++)
					{
						tam = a[i][m];
						a[i][m] = a[j][m];
						a[j][m] = tam;
					}
				}
				if ((k >= j) && (k >= 0))
				{
					x = -a[i][j] / a[k][j];
					//Nhan dong thu k voi x roi cong vao dong thu i.
					for (m = 0; m <= unknown; m++)
						a[i][m] += a[k][m] * x;
				}
			}
		}
	}
	for (j = unknown - 1; j >= 0; j--)
	{
		for (i = 0; i <= j; i++)
		{
			if (a[i][j] == 0) continue;
			if ((i < j) && (a[i][j] != 0))
			{
				k = i + 1;
				while ((k <= j) && (a[k][j] == 0)) k++;
				if ((k <= j) && (k <= unknown))
				{
					x = -a[i][j] / a[k][j];
					//Nhan dong thu k voi x roi cong vao dong thu i.
					for (m = 0; m <= unknown; m++)
						a[i][m] += a[k][m] * x;
				}
			}
		}
	}

	// Bat đau tim nghiem
	if (a[unknown - 1][unknown - 1] == 0 && a[unknown - 1][unknown] != 0)
	{
		cout << endl << "HE PHUONG TRINH VO NGHIEM" << endl;
		flag = 1;
		return;
	}
	for (i = 0; i < unknown; i++)
		if (a[i][i] == 0)
		{
			cout << endl << "HE PHUONG TRINH CO VO SO NGHIEM" << endl;
			flag = 1;
			return;
		}
	if (flag == 0)
	{
		cout << endl << "HE PHUONG TRINH CO NGHIEM DUY NHAT:" << endl;
		for (i = 0; i < unknown; i++)
		{
			cout << "x" << i + 1 << " = " << a[i][unknown] / a[i][i] << endl;
		}
	}
}