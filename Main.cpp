#include"Menu.h"

int main()
{
	char chose;
	cout << endl << "---*---*---*---*---*---*---*---*---CHAO MUNG BAN DEN VOI CHUONG TRINH CUA CHUNG TOI---*---*---*---*---*---*---*---*---" << endl << endl;
	cout << "_______________________________________________________START___________________________________________________________" << endl << endl;
	cout << "                                         CHON DOI TUONG BAN MUON LAM VIEC:" << endl
		<< "                                                    1/ HAM BOOLE." << endl
		<< "                                                    2/ VECTOR." << endl
		<< "                                                    3/ MA TRAN." << endl
		<< "                                                    4/ THOAT." << endl;
	cout << "Nhap lua chon cua ban: ";
	cin >> chose;
	cout << endl;
	while (chose != '1' && chose != '2' && chose != '3' && chose != '4')
	{
		cout << "Lua chon khong hop le! Vui long nhap lai: ";
		cin >> chose;
		cout << endl;
	}
	if (chose == '4')
	{
		cout << "_____________________________________________________THANK YOU__________________________________________________________" << endl << endl;
		return 0;
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
	cout << "_____________________________________________________THANK YOU__________________________________________________________" << endl << endl;
	return 0;
}
