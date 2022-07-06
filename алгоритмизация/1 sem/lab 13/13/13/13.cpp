#include <iostream>
#include "BinaryTree.h"

using namespace std;


int main() {
	setlocale(0, "Russian");
	cout << "Введите количество элементов бинарного дерева: ";
	int n = 0;
	enterNumberI(n);
	long double* b = new long double[n];
	cout << "Введите элементы бинарного дерева: \n";
	for (int i = 0; i < n; i++) {
		cout << "Введите " << i + 1 << " элемент: ";
		enterNumberIR(b[i]);
	}
	TREE* top;
	first(top, b[0]);
	for (int i = 1; i < n; i++)
		add(top, b[i]);
	cout << endl;
	print_tree_level(top, 0);


	cout << "Введите элемент, который уже находится в дереве\n";
	long double z;
	cin >> z;
	bool q=false;
	for (int i = 0; i < n; i++) {
		if (z == b[i]) q = true;
	}
	if (q == true) {
		int v = a_search_s(top, z); // Находим кол-во шагов от вершины до элемента
		cout << "Элементы, которые находятся на одном уровне с "<< z <<endl;
		for (int i = 0; i < n; i++) {
			int i_v= a_search_s(top, b[i]);
			if (v == i_v) {
				TREE* gg= search_s(top, b[i]);
				cout << gg->d << " ";
			}
		}

	}
	else cout << "Такого элемента нет в дереве";





	//long double z;
	//int level;
	//cin >> z;
	//for (int i = 0; i < n; i++) {
	//	if (z == b[i]) {
	//		level = i;
	//		cout << endl;
	//		///*print_tree_level(top, n1);*/
	//		//	cout << top->d << endl;
	//		print_1_level(top, level);
	//		cout << endl;
	//	}
	//}
	
}