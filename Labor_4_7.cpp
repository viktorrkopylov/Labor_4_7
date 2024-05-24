#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <stack>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    vector<int> vec;
    list<int> list;

    stack<int> deq;

    for (int i = 0; i < 200000; ++i) {
        vec.push_back(i);
        list.push_back(i);
    }
    cout << sizeof(deq) << "\n";
    cout << "size of vector: " << sizeof(vec) << "\nVec size: " << vec.size() << "\nSize of int: " << sizeof(int) << endl << endl;

    cout << "Размер вектора: " << sizeof(vec) + (vec.size() * sizeof(int)) << " байт\n";
    cout << "Размер списка: " << sizeof(list) + (list.size() * sizeof(int)) << " байт\n";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto start_vec = chrono::high_resolution_clock::now();                  // расчет времени, за которое происходит вставка элемента в vector 
    vec.insert(vec.begin(), 8);
    auto end_vec = chrono::high_resolution_clock::now();

    

    auto start_list = chrono::high_resolution_clock::now();
    list.insert(list.begin(), 8);
    auto end_list = chrono::high_resolution_clock::now();

    auto duration_vector = chrono::duration_cast<chrono::microseconds>(end_vec - start_vec).count();              // метод count() возвращает значение продолжительности в микросекундах в виде целого числа
    auto duration_list = chrono::duration_cast<chrono::microseconds>(end_list - start_list).count();              //duration_cast преобразует время 

    cout << "Время вставки в вектор: " << duration_vector << " мкс\n";
    cout << "Время вставки в список: " << duration_list << " мкс\n";
}
