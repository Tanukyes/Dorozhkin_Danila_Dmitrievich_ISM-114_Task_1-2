#include "Vector.cpp"
#include <locale.h>
#include <random>

int main()
{
    system("chcp 1251");
    system("cls");

    try {
        Vector<int> vec;

        cout << "Демонстрация работы программы для вектора целых чисел." << endl;

        while (true) {
            cout << "\nМеню программы: " << endl;
            cout << "1 - Ввести массив" << endl;
            cout << "2 - Вывести массив" << endl;
            cout << "3 - Отсортировать массив" << endl;
            cout << "4 - Найти по ключу" << endl;
            cout << "5 - Найти минимум, максимум" << endl;
            cout << "6 - Добавить элемент" << endl;
            cout << "7 - Удалить элемент" << endl;
            cout << "0 - Выход" << endl;
            size_t key, n = 0, j;
            int x, min, max;
            cout << "Введите номер команды: ";
            cin >> key;
            if (key == 0)
                break;
            switch (key) {
                case 1:
                    vec = Vector<int>();
                    // Ввод (заполнение)
                    cout << "Введите число элементов вектора: ";
                    cin >> n;
                    for (size_t i = 0; i < n; i++) {
                        cout << "Введите " << i + 1 << "-й элемент: ";
                        cin >> x;
                        vec.push_back(x);
                    }
                case 2:
                    // Вывод на экран
                    cout << endl << "Веткоры целых чисел: " << endl;
                    vec.print();
                    break;
                case 3:
                    // Сортировка вектора методом простого выбора
                    vec.selection_sort();
                    cout << endl << "Отсортированный по возрастанию вектор: " << endl;
                    vec.print();
                    break;
                case 4:
                    // Поиск по ключу
                    cout << "Ведите номер элемента (ключ): ";
                    cin >> j;
                    x = vec.linear_search(j - 1);
                    if (x != INT_MAX)
                        cout << "Элемент с ключом " << j << " в векторе: " << x << endl;
                    else
                        cout << "Элемент с ключом " << j << " не найден в векторе!";
                    break;
                case 5:
                    // Поиск минимального и максимального элемента
                    min = vec.find_min();
                    max = vec.find_max();
                    cout << "Минимальный: " << min << "; максимальный: " << max << endl;
                    break;
                case 6:
                    cout << "Ведите элемент: ";
                    cin >> x;
                    vec.push_back(x);
                    cout << endl << "Вектор после добавления: " << endl;
                    vec.print();
                    break;
                case 7:
                    cout << "Ведите номер элемента: ";
                    cin >> j;
                    vec.remove(j);
                    cout << endl << "Вектор после удаления: " << endl;
                    vec.print();
                    break;
                default:
                    break;
            }
        }

    }
    catch (const std::exception& e) {
        cout << "An " << e.what() << " error has occured.";
    }

    system("pause");

    return 0;
}
