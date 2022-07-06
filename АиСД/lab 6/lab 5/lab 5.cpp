#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

void equal(int* board1, int* board2, int size) {  
	for (int m = 0; m < size; m++) {
			board1[m] = board2[m];
		}
	}


void vibor(int* a,int length) {
	int* array = new int[length];
	equal(array, a,length);

	cout << "\n vibor\n";
	int count = 0;
	long long int sw_count = 0;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (array[i] < array[j]) {
				swap(array[i], array[j]);
				sw_count++;
			}
			count++;
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << endl;
	//for (int i = 0; i < length; i++) {
	//	cout << array[i] << " ";
	//}
	cout << "\n number of operations\n" << count;
	cout << "\n number of swaps\n" << sw_count;
	cout << "\n time\n" << duration;

}

void vstavka(int* a, int length) {
	int* array = new int[length];
	equal(array, a, length);

	cout << "\n vstavka\n";
	int count = 0;
	long long int sw_count = 0;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 1; i < length; i++) {
		count++;
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
			sw_count += 3;
			swap(array[j - 1], array[j]);
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << endl;
	//for (int i = 0; i < length; i++) {
	//	cout << array[i] << " ";
	//}
	cout << "\n number of operations\n" << count;
	cout << "\n number of swaps\n" << sw_count;
	cout << "\n time\n" << duration;
}

void puzirki(int* a, int length) {
	int* array = new int[length];
	equal(array, a, length);

	cout << "\n puzirki\n";
	int count = 0;
	long long int sw_count = 0;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1; j++) { 
			count++;
			if (array[j] > array[j + 1]) {
			sw_count += 3;
				swap(array[j], array[j + 1]);
			}
		}
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << endl;
	//for (int i = 0; i < length; i++) {
	//	cout << array[i] << " ";
	//}
	cout << "\n number of operations\n" << count;
	cout << "\n number of swaps\n" << sw_count;
	cout << "\n time\n" << duration;
}




void iswap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

void piramida(int* a, int length) {
	int* array = new int[length];
	equal(array, a, length);


	cout << "\n piramida\n";

	int count = 0;
	long long int sw_count = 0;
	//int* all_count = new int[2];
	//all_count[0] = count; all_count[1] = sw_count;

	//for (int i = length / 2; i >= 0; i--) downHeap(array, i, length - 1, all_count);
	
	

	//-----------сортировка------------//
	//сортирует по-возрастанию. чтобы настроить по-убыванию,
	//поменяйте знаки сравнения в строчках, помеченных /*(знак)*/
	int sh = 0; //смещение
	bool b = false;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (;;)
	{
		b = false;
		for (int i = 0; i < length; i++)
		{
			if (i * 2 + 2 + sh < length)
			{
			
				if ((array[i + sh] > /*<*/ array[i * 2 + 1 + sh]) || (array[i + sh] > /*<*/ array[i * 2 + 2 + sh]))
				{
					count++;
					if (array[i * 2 + 1 + sh] < /*>*/ array[i * 2 + 2 + sh])
					{
						count++;
						iswap(array[i + sh], array[i * 2 + 1 + sh]);
						sw_count++;
						b = true;
					}
					else if (array[i * 2 + 2 + sh] < /*>*/ array[i * 2 + 1 + sh])
					{
						count++;
						iswap(array[i + sh], array[i * 2 + 2 + sh]);
						sw_count++;
						b = true;
					}
				}
				//дополнительная проверка для последних двух элементов
					   //с помощью этой проверки можно отсортировать пирамиду
					   //состоящую всего лишь из трех элементов
				if (array[i * 2 + 2 + sh] < /*>*/ array[i * 2 + 1 + sh])
				{
					count++;
					iswap(array[i * 2 + 1 + sh], array[i * 2 + 2 + sh]);
					sw_count++;
					b = true;
				}
			}
			else if (i * 2 + 1 + sh < length)
			{
				count++;
				if (array[i + sh] > /*<*/ array[i * 2 + 1 + sh])
				{
					count++;
					iswap(array[i + sh], array[i * 2 + 1 + sh]);
					sw_count++;
					b = true;
				}
			}
		}
		if (!b) { sh++; count++; } //смещение увеличивается, когда на текущем этапе
				  //сортировать больше нечего
		if (sh + 2 == length) break;
	}  //конец сортировки


	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(t2 - t1).count();
	cout << endl;
	//for (int i = 0; i < length; i++) {
	//	cout << array[i] << " ";
	//}
	cout << "\n number of operations\n" << count;
	cout << "\n number of swaps\n" << sw_count;
	cout << "\n time\n" << duration;
}




int main() {
	srand(static_cast<unsigned int>(time(0)));
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		//a[i] = i;//по возрастанию
		//a[i] = n - i-32; // по убыванию 
		a[i] = rand(); // случайно 
		//cout << a[i] << " ";
	}
	cout << endl;
	vibor(a,n);
	vstavka(a, n);
	puzirki(a, n);
	piramida(a, n);
	cout << endl;
	system("pause");
}