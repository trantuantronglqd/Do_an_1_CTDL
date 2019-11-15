#include"Boole.h"

// Ham chuyen bieu thuc nhap vao tu chuoi sang so
//input: inputChar: bieu thuc nhap vao; n: so tu toi tieu
//output: Mang 2 chieu sau khi chuyen
int** TransInput(string inputChar, const int n)
{
	int** Num01;
	vector < vector <char> > Save(n);
	Num01 = new int* [n]; // Mang Num01 luu gia tri cua bieu thuc sau khi chuyen
	for (int j = 0; j < n; j++) // Khoi tao mang 2 chieu co kich thuoc n * 4 phan tu, voi n la so tu toi tieu, 4 la so bien, gia tri ban dau -1
	{
		Num01[j] = new int[4];
		for (int k = 0; k < 4; k++)
			Num01[j][k] = -1;
	}

	int dem = 0;
	// Duyet chuoi inputChar, nhap lan luot cac ky tu cua chuoi vao vector con cua vector Save, gap khoang trang thi chuyen sang vector con tiep theo cua Save
	for (int i = 0; i < inputChar.size(); i++)
	{
		if (inputChar[i] == ' ')
			dem++;
		else Save.at(dem).push_back(inputChar[i]);
	}

	// Duyet vector Save, neu la bien khang dinh thi chuyen thanh 1, neu la bien phu dinh thi chuyen thanh 0, khong co bien thi giu nguyen -1
	for (int m = 0; m < n; m++)
	{
		Save.at(m).push_back(' '); // them vao ki tu khoang trang de khi kiem tra co phai la bien phu dinh khong thi khong bi tran 
		for (int k = 0; k < Save.at(m).size() - 1; k++)
		{
			if (Save.at(m).at(k) == 'x')
				Num01[m][0] = 1;
			if (Save.at(m).at(k) == 'x' && Save.at(m).at(k + 1) == '-')
				Num01[m][0] = 0;
			if (Save.at(m).at(k) == 'y')
				Num01[m][1] = 1;
			if (Save.at(m).at(k) == 'y' && Save.at(m).at(k + 1) == '-')
				Num01[m][1] = 0;
			if (Save.at(m).at(k) == 'z')
				Num01[m][2] = 1;
			if (Save.at(m).at(k) == 'z' && Save.at(m).at(k + 1) == '-')
				Num01[m][2] = 0;
			if (Save.at(m).at(k) == 't')
				Num01[m][3] = 1;
			if (Save.at(m).at(k) == 't' && Save.at(m).at(k + 1) == '-')
				Num01[m][3] = 0;
		}
	}
	return Num01;
}

// Ham chuyen ket qua tu so thanh chu
// input: vector output: luu ket qua dang so; vector Ans : luu cac te bao khong duoc chon ngay lan dau; min: do dai ngan nhat cua day cac te bao khong duoc chon ngay luc dau
// output: in ket qua ra man hinh 
void TransOutput(vector < vector <int> > output, vector < vector <int> > Ans, int min)
{
	if (Ans.size() != 0)
	{
		for (int i = 0; i < Ans.size(); i++)
		{
			if (Ans.at(i).size() == min)
			{
				for (int j = 0; j < Ans.at(i).size(); j++)
				{
					if (output.at(Ans.at(i).at(j) - 1).at(0) == 0)
						cout << "x-";
					if (output.at(Ans.at(i).at(j) - 1).at(0) == 1)
						cout << "x";
					if (output.at(Ans.at(i).at(j) - 1).at(1) == 0)
						cout << "y-";
					if (output.at(Ans.at(i).at(j) - 1).at(1) == 1)
						cout << "y";
					if (output.at(Ans.at(i).at(j) - 1).at(2) == 0)
						cout << "z-";
					if (output.at(Ans.at(i).at(j) - 1).at(2) == 1)
						cout << "z";
					if (output.at(Ans.at(i).at(j) - 1).at(3) == 0)
						cout << "t-";
					if (output.at(Ans.at(i).at(j) - 1).at(3) == 1)
						cout << "t";
					cout << " ";
				}
				for (int k = 0; k < output.size(); k++) // in cac te bao giong nhau giua cac ket qua
				{
					if (output.at(k).size() != 4)
						if (output.at(k).back() == 1)
						{
							if (output.at(k).at(0) == 0)
								cout << "x-";
							if (output.at(k).at(0) == 1)
								cout << "x";
							if (output.at(k).at(1) == 0)
								cout << "y-";
							if (output.at(k).at(1) == 1)
								cout << "y";
							if (output.at(k).at(2) == 0)
								cout << "z-";
							if (output.at(k).at(2) == 1)
								cout << "z";
							if (output.at(k).at(3) == 0)
								cout << "t-";
							if (output.at(k).at(3) == 1)
								cout << "t";
							cout << " ";
						}
				}
				cout << endl;
			}
		}
	}
	if (Ans.size() == 0)
	{
		for (int i = 0; i < output.size(); i++)
		{
			if (output.at(i).size() != 4)
				if (output.at(i).back() == 1)
				{
					if (output.at(i).at(0) == 0)
						cout << "x-";
					if (output.at(i).at(0) == 1)
						cout << "x";
					if (output.at(i).at(1) == 0)
						cout << "y-";
					if (output.at(i).at(1) == 1)
						cout << "y";
					if (output.at(i).at(2) == 0)
						cout << "z-";
					if (output.at(i).at(2) == 1)
						cout << "z";
					if (output.at(i).at(3) == 0)
						cout << "t-";
					if (output.at(i).at(3) == 1)
						cout << "t";
					cout << " ";
				}
		}
	}
}

//Ham tao bieu do Kanaurgh la 1 mang 3 chieu, tai moi o luu 1 mang 1 chieu tu 0 -> 3 la cac gia tri truyen vao, vi tri thu 4 la co flag de danh dau
void Kanaurghfunc(int***& Kanaurgh)
{
	// Tao x
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			Kanaurgh[i][j][0] = 1;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j < 4; j++)
		{
			Kanaurgh[i][j][0] = 0;
		}
	}

	//Tao y
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			Kanaurgh[i][j][1] = 1;
		}
	}
	for (int j = 0; j < 4; j++)
	{
		Kanaurgh[j][0][1] = 0;
		Kanaurgh[j][3][1] = 0;
	}

	//Tao z
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Kanaurgh[i][j][2] = 1;
		}
	}
	for (int i = 2; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Kanaurgh[i][j][2] = 0;
		}
	}

	//Tao t
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Kanaurgh[i][j][3] = 1;
		}
	}
	for (int j = 0; j < 4; j++)
	{
		Kanaurgh[0][j][3] = 0;
		Kanaurgh[3][j][3] = 0;
	}

	// Tao flag
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			Kanaurgh[i][j][4] = 0;
		}
}

//Ham tim so nguyen X trong vector A
// input: vector A, X can tim
//output: 1 neu tim thay, 0 neu khong tim thay
int findXinVector(vector <int>A, int X)
{
	for (int i = 0; i < A.size(); i++)
		if (X == A.at(i))
			return 1;
	return 0;
}

//Ham kiem tra te bao lon tim duoc co nam trong te bao nao truoc do hay khong
//input: mang temp luu cac vi tri cua cac o thuoc te bao vua tim duoc; vector TickBigCells chua thong tin cac o nam duoc danh dau la te bao lon; type N: N = 4 khi can kiem tra loai te bao co 4 o, N = 2 khi kiem tra loai te bao co 2 o
//output: tra ve 1 neu te bao nam trong te bao truoc do, nguoc lai tra ve 0
int CheckTypeN(int temp[], vector < vector <int> >TickBigCells, int N)
{
	if (N == 4)
	{
		// Kiem tra neu co 1 o bat ky chua danh dau thi tra ve 0
		for (int i = 0; i < 4; i++)
		{
			if (TickBigCells.at(temp[i]).size() == 0) return 0;
		}
		//Kiem tra neu co gia tri nao trung nhau o ca 4 vector thi tra ve 1	
		for (int i = 0; i < TickBigCells.at(temp[0]).size(); i++)
			if (findXinVector(TickBigCells.at(temp[1]), TickBigCells.at(temp[0]).at(i)) == 1 && findXinVector(TickBigCells.at(temp[2]), TickBigCells.at(temp[0]).at(i)) == 1 && findXinVector(TickBigCells.at(temp[3]), TickBigCells.at(temp[0]).at(i)) == 1)
				return 1;
	}

	if (N == 2)
	{
		// Kiem tra neu co 1 o bat ky chua danh dau thi tra ve 0
		for (int i = 0; i < 2; i++)
		{
			if (TickBigCells.at(temp[i]).size() == 0) return 0;
		}
		//Kiem tra neu co gia tri nao trung nhau o ca 4 vector thi tra ve 1	
		for (int i = 0; i < TickBigCells.at(temp[0]).size(); i++)
			if (findXinVector(TickBigCells.at(temp[1]), TickBigCells.at(temp[0]).at(i)) == 1)
				return 1;
	}
	return 0;
}

//Ham danh dau cac o trong bieu do Kanaurgh 
//input: Mang 3 chieu la bieu do Kanaurgh da duoc tao; mang 2 chieu temp chua du lieu nhap vao duoi dang so; n la so tu toi tieu
//output: danh dau cac o theo du lieu duoc nhap vao bang cach bat co flag
void Tick(int***& Kanaurgh, int** temp, int n)
{
	int live = 0, death = 0;
	for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int m = 0; m < 4; m++)
				{
					if (temp[i][m] != -1) // neu gia tri truyen vao la bien thi tang bien live len 1
					{
						if (temp[i][m] == Kanaurgh[j][k][m])
							live++;
					}
					else if (temp[i][m] == -1) death++; // gia tri truyen vao khong la bien thi bien death tang len 1
					if (live + death == 4) // kiem tra neu live + death = so luong bien la 4 thi bat co flag len 1
						Kanaurgh[j][k][4] = 1;
				}
				live = 0; death = 0;
			}
		}
}

//Ham tim te bao lon va phu lai de tim ra cong thuc cuoi cung
//input: Mang 3 chieu la bieu do Kanaurgh da duoc danh dau
//output: in ra ket qua
void findBigCells(int***& Kanaurgh)
{
	int dem1 = 0, dem0 = 0, demCells = 1; // demCells: bien dem so te bao lon
	vector < vector <int> >TickBigCells(34); // vector luu gia tri cac te bao lon tim duoc tai vi tri (10 * i + j) neu trong bieu do o do co vi tri (i,j)
	vector < vector <int> >BigCells; // vector luu gia tri cua cac te bao lon da tim duoc

	//Tim cac te bao lon co 8 o

	//Duyet mang Karnaugh voi cac o duoc danh dau, neu gia tri flag = 1 thi bien dem1 tang 1, neu gia tri flag = 0 thi bien dem0 tang 1
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (Kanaurgh[j][k][4] == 1)
				{
					if (Kanaurgh[j][k][i] == 1) dem1++;
					if (Kanaurgh[j][k][i] == 0) dem0++;
				}
			}
		}
		if (dem1 == 8) // sau khi duyet dem1 = 8 thi them gia tri te bao thu demCells vao cac o trong TickBigCells co vi tri tuong ung voi cac o nam trong te bao demCells
		{
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
				{
					if (Kanaurgh[j][k][4] == 1)
					{
						if (Kanaurgh[j][k][i] == 1)
						{
							TickBigCells.at(10 * j + k).push_back(demCells);
						}
					}
				}
			BigCells.resize(demCells); // Reset so luong te bao lon
			BigCells.at(demCells - 1).resize(4, -1); // khoi tao gia tri ban dau cho te bao lon
			BigCells.at(demCells - 1).at(i) = 1; // nhap gia tri cua te bao lon
			demCells++;
		}
		else if (dem0 == 8) // sau khi duyet dem0 = 8 thi them gia tri te bao thu demCells vao cac o trong TickBigCells co vi tri tuong ung voi cac o nam trong te bao demCells
		{
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
				{
					if (Kanaurgh[j][k][4] == 1)
					{
						if (Kanaurgh[j][k][i] == 0)
						{
							TickBigCells.at(10 * j + k).push_back(demCells);
						}
					}
				}
			BigCells.resize(demCells);
			BigCells.at(demCells - 1).resize(4, -1);
			BigCells.at(demCells - 1).at(i) = 0;
			demCells++;
		}
		dem1 = 0; dem0 = 0; // reset bien dem
	}

	//tim cac te bao lon co 4 o
	int dem4cells = 1, temp[4]; // bien dem4cells dung de dem cac o co cung gia tri bien; mang temp dung de luu vi tri cac o co cung gia tri bien voi vi tri o trong Karnaugh la (i, j) thi se duoc luu tuong ung voi vi tri 10*i+j
	for (int m1 = 0; m1 < 4; m1++) // (m1, n1) la vi tri cua o duoc dem di so sanh
		for (int n1 = 0; n1 < 4; n1++)
			for (int first = 0; first < 3; first++) // first, second la vi tri cua cac bien can so sanh 
				for (int second = first + 1; second < 4; second++)
				{
					for (int m2 = 0; m2 < 4; m2++) //(m2, n2) la vi tri cua o duoc so sanh
					{
						for (int n2 = 0; n2 < 4; n2++)
						{
							if (Kanaurgh[m1][n1][4] == 1 && Kanaurgh[m2][n2][4] == 1) // kiem tra xem 2 o co duoc danh dau hay khong
								if (Kanaurgh[m1][n1] != Kanaurgh[m2][n2]) // 2 o khong duoc trung nhau
								{
									if (Kanaurgh[m1][n1][first] == Kanaurgh[m2][n2][first] && Kanaurgh[m1][n1][second] == Kanaurgh[m2][n2][second]) // kiem tra gia tri cac bien co bang nhau khong
									{
										temp[dem4cells] = 10 * m2 + n2;
										dem4cells++;
									}
									if (dem4cells == 4) // kiem tra du so luong cua te bao 4 o
									{
										temp[0] = 10 * m1 + n1;
										if (CheckTypeN(temp, TickBigCells, 4) == 0) // kiem tra cac o co thuoc te bao nao truoc do hay khong
										{
											for (int h = 0; h < 4; h++) // them te bao thu demCells vao vi tri o tuong ung trong TickBigCells, vi tri duoc lay trong mang temp
											{
												TickBigCells.at(temp[h]).push_back(demCells);
											}
											BigCells.resize(demCells); // reset so luong te bao lon
											BigCells.at(demCells - 1).resize(4, -1); // khoi tao gia tri ban dau cho te bao lon
											// nhap gia tri cua te bao lon
											BigCells.at(demCells - 1).at(first) = Kanaurgh[m1][n1][first];
											BigCells.at(demCells - 1).at(second) = Kanaurgh[m1][n1][second];
											demCells++;
										}
										dem4cells = 1; // reset lai bien dem
									}
								}
						}
					}
					dem4cells = 1;
				}

	//tim cac te bao lon co 2 o
	int dem2cells = 1;
	for (int m1 = 0; m1 < 4; m1++) // (m1, n1) la vi tri cua o duoc dem di so sanh
		for (int n1 = 0; n1 < 4; n1++)
			for (int first = 0; first < 2; first++) // first, second, third la vi tri cua cac bien can so sanh
				for (int second = first + 1; second < 3; second++)
					for (int third = second + 1; third < 4; third++)
					{
						for (int m2 = 0; m2 < 4; m2++) // (m2, n2) la vi tri cua o duoc so sanh
							for (int n2 = 0; n2 < 4; n2++)
							{
								if (Kanaurgh[m1][n1][4] == 1 && Kanaurgh[m2][n2][4] == 1)// kiem tra xem 2 o co duoc danh dau hay khong
									if (Kanaurgh[m1][n1] != Kanaurgh[m2][n2])// 2 o khong duoc trung nhau
									{
										if (Kanaurgh[m1][n1][first] == Kanaurgh[m2][n2][first] && Kanaurgh[m1][n1][second] == Kanaurgh[m2][n2][second] && Kanaurgh[m1][n1][third] == Kanaurgh[m2][n2][third]) // kiem tra gia tri cac bien co bang nhau khong
										{
											temp[dem4cells] = 10 * m2 + n2;
											dem2cells++;
										}
										if (dem2cells == 2) // kiem tra du so luong cua te bao 2 o
										{
											temp[0] = 10 * m1 + n1;
											if (CheckTypeN(temp, TickBigCells, 2) == 0) // kiem tra cac o co thuoc te bao nao truoc do hay khong
											{
												for (int h = 0; h < 2; h++)
												{
													TickBigCells.at(temp[h]).push_back(demCells); // them te bao thu demCells vao vi tri o tuong ung trong TickBigCells, vi tri duoc lay trong mang temp
												}
												BigCells.resize(demCells); // reset so luong te bao lon
												BigCells.at(demCells - 1).resize(4, -1); // khoi tao gia tri ban dau cho te bao lon
												//nhap gia tri cua te bao lon
												BigCells.at(demCells - 1).at(first) = Kanaurgh[m1][n1][first];
												BigCells.at(demCells - 1).at(second) = Kanaurgh[m1][n1][second];
												BigCells.at(demCells - 1).at(third) = Kanaurgh[m1][n1][third];
												demCells++;
											}
											dem2cells = 1; // reset bien dem
										}
									}
							}
						dem2cells = 1;
					}
	// tim te bao lon chi co 1 o
	for (int j = 0; j < 4; j++)
		for (int k = 0; k < 4; k++)
		{
			if (Kanaurgh[j][k][4] == 1 && TickBigCells[10 * j + k].size() == 0) // kiem tra cac o co danh dau va vi tri cua o do tuong ung trong TickBigCells chua co phan tu nao
			{
				TickBigCells[10 * j + k].push_back(demCells); // them te bao thu demCells vao vi tri o tuong ung trong TickBigCells
				BigCells.resize(demCells); //reset so luong te bao lon
				BigCells.at(demCells - 1).resize(4, -1); // khoi tao gia tri ban dau cho te bao lon
				// nhap gia tri cua te bao lon
				BigCells.at(demCells - 1).at(0) = Kanaurgh[j][k][0];
				BigCells.at(demCells - 1).at(1) = Kanaurgh[j][k][1];
				BigCells.at(demCells - 1).at(2) = Kanaurgh[j][k][2];
				BigCells.at(demCells - 1).at(3) = Kanaurgh[j][k][3];
				demCells++;
			}
		}

	// phu nguoc 

	// Tim nhung o chi co 1 te bao, va thay co flag cua cac o cua te bao do bang so 2
	for (int i = 0; i < TickBigCells.size(); i++)
		if (TickBigCells.at(i).size() == 1) // tim cac vi tri co 1 te bao
		{
			Kanaurgh[i / 10][i % 10][4] = 2; // thay co flag = 2, co nghia la da phu. Vi tri trong TickBigCells duoc tra lai tuong ung trong Karnaugh
			BigCells.at(TickBigCells.at(i).at(0) - 1).push_back(1); // danh dau te bao do trong vector BigCells (vector luu gia tri cac te bao lon) la duoc chon
			for (int j = 0; j < TickBigCells.size(); j++)
			{
				if (findXinVector(TickBigCells.at(j), TickBigCells.at(i).at(0)) == 1) // tim cac o nam chung te bao lon, thay co flag = 2
					Kanaurgh[j / 10][j % 10][4] = 2;
			}
		}

	// xu li nhung o co nhieu hon 1 te bao va chua duoc phu
	vector < vector <int> > Ans; // luu day cac te bao khong duoc chon ngay luc dau
	int start = 0, size; // start dung de ngat khi da nhap cac te bao cua o dau tien duoc tim thay vao trong Ans
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (start == 0) // khoi tao cac gia tri te bao ban dau
			{
				if (Kanaurgh[i][j][4] == 1)
				{
					for (int k = 0; k < TickBigCells[10 * i + j].size(); k++)
					{
						Ans.resize(k + 1);
						Ans.at(k).push_back(TickBigCells[10 * i + j][k]);
					}
					start = 1; size = Ans.size();
				}
			}
			else // cac gia tri luc sau
			{
				if (Kanaurgh[i][j][4] == 1)
				{
					for (int u = 0; u < size; u++)
					{
						for (int v = 0; v < Ans.at(u).size(); v++)
						{
							if (findXinVector(TickBigCells[10 * i + j], Ans.at(u).at(v)) == 0) // kiem tra trong o (i,j) co te bao Ans.at(u).at(v))hay khong, co thi bo qua
							{
								Ans.resize(Ans.size() + TickBigCells[10 * i + j].size() - 1);  // dat lai kich thuoc vector
								for (int o = Ans.size() - TickBigCells[10 * i + j].size() + 1; o < Ans.size(); o++) // sao chep qua cac vector con moi tao
								{
									for (int y = 0; y < Ans.at(u).size(); y++)
									{
										Ans.at(o).push_back(Ans.at(u).at(y));
									}
								}
								// them cac gia tri vao cac vector
								Ans.at(u).push_back(TickBigCells[10 * i + j][0]);
								int p = 1;
								for (int o = Ans.size() - TickBigCells[10 * i + j].size() + 1; o < Ans.size(); o++)
								{
									Ans.at(o).push_back(TickBigCells[10 * i + j][p]);
									p++;
								}
							}
						}
					}
				}
			}
		}
	}

	// tim chieu dai ngan nhat cua cac day te bao
	int min = 0;
	if (Ans.size() != 0)
	{
		min = Ans.at(0).size();
		for (int i = 1; i < Ans.size(); i++)
		{
			if (Ans.at(i).size() < min)
			{
				min = Ans.at(i).size();
			}
		}
	}

	//tim te bao ngan nhat trong cac te bao trong o chua duoc phu
	int dem = 0, Min1 = 100;
	for (int i = 0; i < Ans.size(); i++)
		for (int j = 0; j < Ans.at(i).size(); j++)
			if (Ans.at(i).size() == min)
			{
				for (int m = 0; m < 4; m++)
				{
					if (BigCells.at(Ans.at(i).at(j) - 1).at(m) != -1) // dem so luong vi tri co bien
						dem++;
				}
				if (dem < Min1)
					Min1 = dem;
				dem = 0;
			}

	// day te bao nao co te bao ngan nhat thi giu nguyen kich thuoc, khong thi them phan tu 0 vao cuoi day de loai tru
	dem = 0;
	for (int i = 0; i < Ans.size(); i++)
		for (int j = 0; j < Ans.at(i).size(); j++)
			if (Ans.at(i).size() == min)
			{
				for (int m = 0; m < 4; m++)
				{
					if (BigCells.at(Ans.at(i).at(j) - 1).at(m) != -1) // dem so luong vi tri co bien
						dem++;
				}
				if (dem != Min1)
					Ans.at(i).push_back(0);
				dem = 0;
			}

	//xuat ket qua
	TransOutput(BigCells, Ans, min);
}

void Boole()
{
	int*** Kanaurgh;
	Kanaurgh = new int** [4];
	for (int i = 0; i < 4; i++)
	{
		Kanaurgh[i] = new int* [4];
		{
			for (int j = 0; j < 4; j++)
			{
				Kanaurgh[i][j] = new int[5];
			}
		}
	}
	Kanaurghfunc(Kanaurgh);
	int n;
	cout << "Nhap so luong tu toi tieu: ";
	cin >> n;
	string input, temp = "        ";
	cin.ignore();
	cout << "\nNhap vao bieu thuc: ";
	getline(cin, input);
	int dem = 0, dembien = 0, dembien1 = 0;

	//kiem tra so luong bien co hop le hay khong
Kiemtrabien: for (int i = 0; i < input.size(); i++)
{
	if (input[i] != ' ') // truyen bien vao temp
	{
		temp[dembien] = input[i];
		dembien++;
	}
	if (input[i] == ' ' || i == input.size() - 1) // kiem tra so luong bien
	{
		for (int j = 0; j < dembien; j++)
		{
			if (temp[j] != '-' && temp[j] != ' ')
			{
				dembien1++;
			}
		}
		if (dembien1 > 4)
		{
			cout << "\nBan da nhap sai so luong bien, vui long nhap lai voi so luong bien nho hon hoac bang 4. \nVui long nhan Enter de tiep tuc\n";
			cin.ignore();
			cout << "Nhap lai bieu thuc: ";
			getline(cin, input);
			i = -1;
			dembien = 0;
			dembien1 = 0;
			temp = "        ";
			goto Kiemtrabien;
		}
		dembien = 0;
		dembien1 = 0;
		temp = "        ";
	}
}

			 for (int i = 0; i < input.size(); i++)
			 {
				 if (input[i] == ' ')
					 dem++;
			 }

			 // Kiem tra so luong tu toi tieu co hop le hay khong
			 while (dem != n - 1)
			 {
				 cout << "\nBan da nhap sai so luong tu toi tieu, vui long nhan Enter de tiep tuc.\n";
				 cin.ignore();
				 cout << "Nhap lai bieu thuc: ";
				 getline(cin, input);
				 dem = 0;
				 for (int i = 0; i < input.size(); i++)
				 {
					 if (input[i] == ' ')
						 dem++;
				 }
			 }
			 Tick(Kanaurgh, TransInput(input, n), n);
			 cout << "Tat ca cac da thuc toi tieu: " << endl;
			 findBigCells(Kanaurgh);
			 cout << endl << "------------------------------------------------------* * * *---------------------------------------------------------" << endl << endl;
}