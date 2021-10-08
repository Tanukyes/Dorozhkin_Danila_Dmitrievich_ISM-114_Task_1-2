#include "Vector.h"
#include <locale.h>
#include <random>

int main()
{
	system("chcp 1251");
	system("cls");
	
	Vector<int> vec;
	
	cout << "������������ ������ ��������� ��� ������� ����� �����." << endl;
	
	while (true)
	{
		cout << "\n���� ���������: " << endl;
		cout << "1 - ������ ������" << endl;
		cout << "2 - ������� ������" << endl;
		cout << "3 - ������������� ������" << endl;
		cout << "4 - ����� �� �����" << endl;
		cout << "5 - ����� �������, ��������" << endl;
		cout << "6 - �������� �������" << endl;
		cout << "7 - ������� �������" << endl;
		cout << "0 - �����" << endl;
		int key, n = 0, j, x, min, max;
		cout << "������� ����� ������� ����: ";
		cin >> key;
		if (key == 0)
			break;
		switch (key)
		{
		case 1:
			vec = Vector<int>();
			// ���� (����������)
			cout << "������� ����� ��������� �������: ";
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "������� " << i + 1 << "-� �������: ";
				cin >> x;
				vec.push_back(x);
			}
		case 2:
			// ����� �� �����
			cout << endl << "������ ����� �����: " << endl;
			vec.print();
			break;
		case 3:
			// ���������� ������� ������� �������� ������
			vec.selection_sort();
			cout << endl << "��������������� �� ����������� ������: " << endl;
			vec.print();
			break;
		case 4:
			// ����� �� �����
			cout << "������� ����� �������� (����): ";
			cin >> j;
			x = vec.linear_search(j - 1);
			if (x != INT_MAX)
				cout << "������� � ������ " << j << " � �������: " << x << endl;
			else
				cout << "������� � ������ " << j << " �� ������ � �������!";
			break;
		case 5:
			// ����� ������������ � ������������� ��������
			min = vec.find_min();
			max = vec.find_max();
			cout << "�����������: " << min << "; ������������: " << max << endl;
			break;
		case 6:
			cout << "������� �������: ";
			cin >> x;
			vec.push_back(x);
			cout << endl << "������ ����� ����������: " << endl;
			vec.print();
			break;
		case 7:
			cout << "������� ����� ��������: ";
			cin >> j;
			vec.remove(j);
			cout << endl << "������ ����� ��������: " << endl;
			vec.print();
			break;
		default:
			break;
		}
	}

	system("pause");

	return 0;
}