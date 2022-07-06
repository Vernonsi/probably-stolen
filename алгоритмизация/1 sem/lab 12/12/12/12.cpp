#include <iostream>
#include <Windows.h>
#include <string.>
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

using namespace std;

void enterNumber(int& n) {
    while (!(cin >> n) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введено некорректное значение! Повторите ввод!!!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Введите количество элементов последовательности символов: ";
    int N = 0;
    enterNumber(N);
    
    double* arr = new double[N];
    cout << "Введите последовательность символов" << endl;

    for (int i = 0; i < N; i++) {
        cout << "Введите символ " << i + 1 << ": ";
        cin >> arr[i];
    }
    //cout << endl;


    ////for (int i = 0; i < N; i++) {
    ////    cout << arr[i] << " ";
    ////}

    cout << endl<<"Stack";

    //Stack realization
    Node_s* top = first_s(arr[0]);
    for (int i = 1; i < N; i++)push_s(&top, arr[i]);
 /*   while (top)
        cout << pop_s(&top) << ' ';*/
    cout  << endl;


    Node_s* comp1 = first_s(arr[0]);
    for (int i = 1; i < N; i++)push_s(&comp1, arr[i]);
    int i = 0;
    int s = 0;
   
    while (comp1) {
        double temp = pop_s(&comp1);
        if (temp != 0) {
            s++;
        }
    }
    double* final_s=new double[s];

    Node_s* comp2 = first_s(arr[0]);
    for (int i = 1; i < N; i++)push_s(&comp2, arr[i]);

    while (comp2) {
        double temp = pop_s(&comp2);
        if (temp != 0) {
            final_s[i] = temp;
             i++;
        }
    }

    for (int i = 0; i < s; i++) {
        cout << final_s[i] << " ";
    }


    cout << endl << "Queue"<< endl;

    //Queue realization
    Node_q* pbeg1 = first_q(arr[N - 1]);
    Node_q* pend1 = pbeg1;
    for (int i = N - 2; i >= 0; i--)add_q(&pend1, arr[i]);
    int j = 0;
    int q = 0;
    while (pbeg1) {
        double temp = del_q(&pbeg1);
        if (temp != 0) {
            q++;
        }
    }
    double* final_q = new double[q];

    Node_q* pbeg2 = first_q(arr[N - 1]);
    Node_q* pend2 = pbeg2;
    for (int i = N - 2; i >= 0; i--)add_q(&pend2, arr[i]);
    while (pbeg2) {
        double temp = del_q(&pbeg2);
        if (temp != 0) {
            final_q[j] = temp;
            j++;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << final_q[i] << " ";
    }


    cout << endl << "Deque"<< endl;
    //Deque realization
    Node_d* pbeg_d1 = first_d(arr[N - 1]);
    Node_d* pend_d1 = pbeg_d1;
    for (int i = N - 2; i >= 0; i--)addLast_d(&pend_d1, arr[i]);

    int k = 0;
    int deq = 0;
    while (pbeg_d1) {
        char temp = delFirst_d(&pbeg_d1);
        if (temp != 0) {
            deq++;
        }
    }
    double* final_d = new double[deq];

    Node_d* pbeg_d2 = first_d(arr[N - 1]);
    Node_d* pend_d2 = pbeg_d2;
    for (int i = N - 2; i >= 0; i--)addLast_d(&pend_d2, arr[i]);
    while (pbeg_d2) {
        char temp = delFirst_d(&pbeg_d2);
        if (temp != 0) {
            final_d[k] = temp;
            k++;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << final_d[i] << " ";
    }
}