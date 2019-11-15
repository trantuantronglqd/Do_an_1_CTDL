#include"Menu.h"

//Lam viec voi ham boole
void BooleFunction()
{
	char next;
	Boole();
	cout << endl << "------------------------------------------------------* * * *----------------------------------------------------------" << endl << endl;
	cout << "Ban co muon tiep tuc lam viec khong? (Nhap vao N neu muon ket thuc, nhap vao Y de tiep tuc): " << endl;
	cout << "Nhap lua chon cua ban: ";
	cin >> next;
	while (next != 'N' && next != 'Y')
	{
		cout << "Lua chon khong hop le! Vui long nhap lai: ";
		cin >> next;
	}
	if (next == 'N') return;
	else
	{
		cout << "_______________________________________________________NEXT_____________________________________________________________" << endl << endl;
		char chose;
		cout << "                                        CHON DOI TUONG BAN MUON LAM VIEC:" << endl
			<< "                                                    1/ HAM BOOLE." << endl
			<< "                                                    2/ VECTOR." << endl
			<< "                                                    3/ MA TRAN." << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> chose;
		cout << endl;
		while (chose != '1' && chose != '2' && chose != '3')
		{
			cout << "Lua chon khong hop le! Vui long nhap lai: ";
			cin >> chose;
		}
		if (chose == '1')
		{
			BooleFunction();
		}
		if (chose == '2')
		{
			Vector();
		}
		if (chose == '3')
		{
			Matrix();
		}
	}
}

//Lam viec voi vector
void Vector()
{
	char chose2, next;
	cout << "BAN MUON THUC HIEN THAO TAC NAO VOI VECTOR?" << endl
		<< "1/ Cong hai vecto." << endl
		<< "2/ Nhan vecto voi mot so anphal." << endl;
	cout << endl << "Nhap lua chon cua ban: ";
	cin >> chose2;
	while (chose2 != '1' && chose2 != '2')
	{
		cout << "Lua chon khong hop le! Vui long nhap lai: ";
		cin >> chose2;
	}
	cout << endl;
	//Neu lua chon 1 thi tinh tong 2 vector
	if (chose2 == '1')
	{
		MyVector V1, V2;
		cout << "Nhap vao vector thu nhat: " << endl;
		V1.add(); 
		cout << "Vector ban vua nhap vao la: ";
		V1.display();
		cout << "Nhap vao vector thu hai: " << endl;
		V2.add(); 
		cout << "Vector ban vua nhap vao la: ";
		V2.display();
		V1 + V2;
		cout << endl << "------------------------------------------------------* * * *----------------------------------------------------------" << endl << endl;
	}
	//Neu lưa chon 2 thi tinh tich vector voi so a
	if (chose2 == '2')
	{
		MyVector V;
		double a;
		cout << "Nhap vao vector: " << endl;
		V.add(); 
		cout << "Vector ban vua nhap vao la: ";
		V.display();
		cout << "Nhap vao so anphal: a =  ";
		cin >> a;
		cout << "Tich cua vector va so anphal ban vua nhap vao la: ";
		(V * a).display();
		cout << endl << "------------------------------------------------------* * * *---------------------------------------------------------" << endl << endl;
	}
	cout << "Ban co muon tiep tuc lam viec khong? (Nhap vao N neu muon ket thuc, nhap vao Y de tiep tuc): " << endl;
	cout << "Nhap lua chon cua ban: ";
	cin >> next;
	while (next != 'N' && next != 'Y')
	{
		cout << "Lua chon khong hop le! Vui long nhap lai: ";
		cin >> next;
	}
	if (next == 'N') return;
	else
	{
		cout << "_______________________________________________________NEXT_____________________________________________________________" << endl << endl;
		char chose;
		cout << "                                        CHON DOI TUONG BAN MUON LAM VIEC:" << endl
			<< "                                                    1/ HAM BOOLE." << endl
			<< "                                                    2/ VECTOR." << endl
			<< "                                                    3/ MA TRAN." << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> chose;
		cout << endl;
		while (chose != '1' && chose != '2' && chose != '3')
		{
			cout << "Lua chon khong hop le! Vui long nhap lai: ";
			cin >> chose;
		}
		if (chose == '1')
		{
			BooleFunction();
		}
		if (chose == '2')
		{
			Vector();
		}
		if (chose == '3')
		{
			Matrix();
		}
	}
}
//Lam viec voi ma tran
void Matrix()
{
	char chose3, next;
	cout << "BAN MUON THUC HIEN THAO TAC NAO VOI MA TRAN?" << endl
		<< "1/ Tinh dinh thuc cua ma tran." << endl
		<< "2/ Nghich dao ma tran." << endl
		<< "3/ Tim hang cua ma tran." << endl
		<< "4/ Tich hai ma tran." << endl
		<< "5/ Giai he phuong trinh tuyen tinh." << endl;
	cout << endl << "Nhap lua chon cua ban: ";
	cin >> chose3;
	while (chose3 != '1' && chose3 != '2' && chose3 != '3' && chose3 != '4' && chose3 != '5')
	{
		cout << "Lua chon khong hop le! Vui long nhap lai: ";
		cin >> chose3;
	}
	cout << endl;
	//Neu lua chon 1 thi tinh dinh thuc ma tran
	if (chose3 == '1')
	{
		MyMatrix M;
		cout << "Nhap vao ma tran can tinh dinh thuc: " << endl;
		M.add();
		M.display();
		if (M.SquareMatrix())
			cout << "Dinh thuc cua ma tran vua nhap vao la: " << M.det() << endl;
		else cout << "Ma tran vua nhap khong phai ma tran vuong nen khong co dinh thuc." << endl;
		cout << endl << "------------------------------------------------------* * * *---------------------------------------------------------" << endl << endl;
	}
	//Neu lua chon 2 thi tim nghich dao ma tran
	if (chose3 == '2')
	{
		MyMatrix M;
		cout << "Nhap vao ma tran can tim nghich dao: " << endl;
		M.add();
		M.display();
		M.Inverse();
		cout << endl << "------------------------------------------------------* * * *---------------------------------------------------------" << endl << endl;
	}
	//Neu lua chon 3 thi tim hang cua ma tran
	if (chose3 == '3')
	{
		MyMatrix M;
		cout << "Nhap vao ma tran can tim hang: " << endl;
		M.add();
		M.display();
		cout << "Hang cua ma tran vua nhap vao la: " << M.Rank();
		cout << endl << "------------------------------------------------------* * * *---------------------------------------------------------" << endl << endl;
	}
	//Neu lua chon 4 thi tinh tich cua 2 ma tran
	if (chose3 == '4')
	{
		MyMatrix M1, M2;
		cout << "Nhap vao ma tran thu nhat: " << endl;
		M1.add();
		M1.display();
		cout << "Nhap vao ma tran thu hai: " << endl;
		M2.add();
		M2.display();
		cout << "Tich cua 2 ma tran la: " << endl;
		M1* M2;
		cout << endl << "------------------------------------------------------* * * *---------------------------------------------------------" << endl << endl;
	}
	//Neu lua chon 5 thi giai he phuong trinh tuyen tinh
	if (chose3 == '5')
	{
		PTTT P;
		P.add();
		P.display();
		P.solve();
		cout << "------------------------------------------------------* * * *---------------------------------------------------------" << endl << endl;
	}
	cout << "Ban co muon tiep tuc lam viec khong? (Nhap vao N neu muon ket thuc, nhap vao Y de tiep tuc): " << endl;
	cout << "Nhap lua chon cua ban: ";
	cin >> next;
	while (next != 'N' && next != 'Y')
	{
		cout << "Lua chon khong hop le! Vui long nhap lai: ";
		cin >> next;
	}
	if (next == 'N') return;
	else
	{
		cout << "________________________________________________________NEXT____________________________________________________________" << endl << endl;
		char chose;
		cout << "                                         CHON DOI TUONG BAN MUON LAM VIEC:" << endl
			<< "                                                    1/ HAM BOOLE." << endl
			<< "                                                    2/ VECTOR." << endl
			<< "                                                    3/ MA TRAN." << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> chose;
		cout << endl;
		while (chose != '1' && chose != '2' && chose != '3')
		{
			cout << "Lua chon khong hop le! Vui long nhap lai: ";
			cin >> chose;
		}
		if (chose == '1')
		{
			BooleFunction();
		}
		if (chose == '2')
		{
			Vector();
		}
		if (chose == '3')
		{
			Matrix();
		}
	}
}