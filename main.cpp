#include "Vector.cpp"
#include <locale.h>
#include <random>

int main()
{
	system("chcp 1251");
	system("cls");
	
	Vector<int> vec;
	
	cout << "Демонстрация работы программы для вектора целых чисел." << endl;
	
	while (true)
	{
		cout << "\nМеню программы: " << endl;
		cout << "1 - ввести массив" << endl;
		cout << "2 - вывести массив" << endl;
		cout << "3 - отсортировать массив" << endl;
		cout << "4 - найти по ключу" << endl;
		cout << "5 - найти минимум, максимум" << endl;
		cout << "6 - добавить элемент" << endl;
		cout << "7 - удалить элемент" << endl;
		cout << "0 - выход" << endl;
		size_t key, n = 0, j;
		int x, min, max;
		cout << "Введите номер команды меню: ";
		cin >> key;
		if (key == 0)
			break;
		switch (key)
		{
		case 1:
			vec = Vector<int>();
			// ввод (заполнение)
			cout << "Введите число элементов вектора: ";
			cin >> n;
			for (size_t i = 0; i < n; i++)
			{
				cout << "Введите " << i + 1 << "-й элемент: ";
				cin >> x;
				vec.push_back(x);
			}
		case 2:
			// вывод на экран
			cout << endl << "Вектор целых чисел: " << endl;
			vec.print();
			break;
		case 3:
			// сортировка вектора методом простого выбора
			vec.selection_sort();
			cout << endl << "Отсортированный по возрастанию вектор: " << endl;
			vec.print();
			break;
		case 4:
			// поиск по ключу
			cout << "Введите номер элемента (ключ): ";
			cin >> j;
			x = vec.linear_search(j - 1);
			if (x != INT_MAX)
				cout << "Элемент с ключом " << j << " в векторе: " << x << endl;
			else
				cout << "Элемент с ключом " << j << " не найден в векторе!";
			break;
		case 5:
			// поиск минимального и максимального элемента
			min = vec.find_min();
			max = vec.find_max();
			cout << "Минимальный: " << min << "; максимальный: " << max << endl;
			break;
		case 6:
			cout << "Введите элемент: ";
			cin >> x;
			vec.push_back(x);
			cout << endl << "Вектор после добавления: " << endl;
			vec.print();
			break;
		case 7:
			cout << "Введите номер элемента: ";
			cin >> j;
			vec.remove(j);
			cout << endl << "Вектор после удаления: " << endl;
			vec.print();
			break;
		default:
			break;
		}
	}

	system("pause");

	return 0;
}
