#include "train.h"
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

times convert(char* str) // конвертируем char 10.02.19 в times 10 часов, 02 минуты и 19 секунд
{
    times result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.min = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.sec = atoi(str_number);
    return result;
}

int str(const char* name) { // размер?
    char* str = new char[1024];
    int i = 0;
    ifstream base(name);
    while (!base.eof())
    {
        base.getline(str, 1024, '\n');
        i++;
    }
    base.close();
    return i;
}
void read(const char* file_name, route* array[], int& size) { // запиываем массив route'ов

    std::ifstream file(file_name);
    if (file.is_open())
    {
        char tmp_buffer[MAX_STRING_SIZE];

        int i = 0;
        while(!file.eof()) {

            route* item = new route;

            
            file >> item->number;
            file >> item->destination;
            file >> tmp_buffer;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->end = convert(tmp_buffer);

            array[i] = item;
            i++;
        }
        size = i;
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}

long int timeres(times t) {// время в секундах
    long int s = t.hour * 3600 + t.min * 60 + t.sec;
    return s;
}

void Sort(route* array[], int size)// сортируем по отправлению
{
    route* temp = new route;
    for (int j = 0; j < size - 1; j++) {
        for (int i = 0; i < size - 1 - j; i++) {
            if (timeres(array[i]->start) > timeres(array[i + 1]->start)) {
                 temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
            }
        }
    }
}


void outtime(times t) { // пишем 0 перед временем, если оно меньше 10 (эстэтишна)
    if (t.hour < 10) {
        cout << "0" << t.hour;
    }
    else {
        cout << t.hour;
    }
    cout << ".";
    if (t.min < 10) {
        cout << "0" << t.min;
    }
    else {
        cout << t.min;
    }
    cout << ".";
    if (t.sec < 10) {
        cout << "0" << t.sec;
    }
    else {
        cout << t.sec;
    }

}

bool strm(string str1, string str2) { // сравниваем размер
    int d = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == str2[i]) d++;
    }
    if (d == str1.length()) return true;
    return false;
}


ostream& operator<<(ostream& viv, route* i) { // пишем 0 перед временем, если оно меньше 10 (эстэтишна) в прибытии
    viv << i->number << " " << i->destination << " ";
    if (i->start.hour < 10) {
        viv << "0" << i->start.hour;
    }
    else {
        viv << i->start.hour;
    }
    viv << ".";
    if (i->start.min < 10) {
        viv << "0" << i->start.min;
    }
    else {
        viv << i->start.min;
    }
    viv << ".";
    if (i->start.sec < 10) {
        viv << "0" << i->start.sec;
    }
    else {
        viv << i->start.sec;
    }
    viv << " ";
    if (i->end.hour < 10) {
        viv << "0" << i->start.hour;
    }
    else {
        viv << i->end.hour;
    }
    viv << ".";
    if (i->end.min < 10) {
        viv << "0" << i->end.min;
    }
    else {
        viv << i->end.min;
    }
    viv << ".";
    if (i->end.sec < 10) {
        viv << "0" << i->end.sec;
    }
    else {
        viv << i->end.sec;
    }

    return viv;
}


ostream& operator<<(ostream& viv, route i) {// пишем 0 перед временем, если оно меньше 10 (эстэтишна) при отправлении
    viv << i.number << " " << i.destination << " ";
    if (i.start.hour < 10) {
        viv << "0" << i.start.hour;
    }
    else {
        viv << i.start.hour;
    }
    viv << ".";
    if (i.start.min < 10) {
        viv << "0" << i.start.min;
    }
    else {
        viv << i.start.min;
    }
    viv << ".";
    if (i.start.sec < 10) {
        viv << "0" << i.start.sec;
    }
    else {
        viv << i.start.sec;
    }
    viv << " ";
    if (i.end.hour < 10) {
        viv << "0" << i.start.hour;
    }
    else {
        viv << i.end.hour;
    }
    viv << ".";
    if (i.end.min < 10) {
        viv << "0" << i.end.min;
    }
    else {
        viv << i.end.min;
    }
    viv << ".";
    if (i.end.sec < 10) {
        viv << "0" << i.end.sec;
    }
    else {
        viv << i.end.sec;
    }

    return viv;
}

void fout(const char* file_name, route item) {// вывод рас
    std::ofstream file(file_name, ios::app);
    file << item << endl;
}

void fout2(const char* file_name, route* item) {// вывод два
    std::ofstream file(file_name, ios::app);
    file << item << endl;
}

void stationc(const char* str, route* array[], int size) {
    cout << endl;
    cout << "station: \"" << str <<"\"" << endl;
    for (int i = 0; i < size; i++) {
        if (strcmp(str, array[i]->destination)) {
            Out(array[i]);
        }
    }
}

void stationf(const char* file_name, string str, route* array[], int size) {
    ofstream file(file_name, ios::app);
    file << "station: " << "\"" << str << "\"" << endl;
    for (int i = 0; i < size; i++) {
        if (strm(str, array[i]->destination)) {
            fout2(file_name, array[i]);
        }
    }
}

void Out(route* C) { // вывод одного поезда
    cout << "Number: " << C->number << "| Destination: " << C->destination << "| start: ";
    outtime(C->start);
    cout << "| end: ";
    outtime(C->end);
    cout << endl;
}
void Output(route* array[], int size) {// вывод всего
    for (int i = 0; i < size; i++) {
        Out(array[i]);
    }
}




void fileout(const char* file_name, route* array[], int size) {//вывод в файл
    std::ofstream file(file_name);
    file.clear();
    for (int i = 0; i < size; i++) {
       fout2(file_name, array[i]);
    }
}



