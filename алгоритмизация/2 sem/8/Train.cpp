#include "Train.h"
#include "Source.h"
#include <iterator>
#include <string>



Times::Times()
{
    hour = 0;
    min = 0;
    sec = 0;
}
Times::Times(int h, int m, int s)
{
      hour = h;
      min = m;
      sec = s;
}

int Times::getH()
{
	return this->hour;
}

int Times::getM()
{
	return min;
}

int Times::getS()
{
	return sec;
}

bool Times::timesr(Times t2)
{
    if (this->getH() > t2.getH()) {
        return true;
    }
    if (this->getH() == t2.getH() && this->getM() > t2.getM()) {
        return true;
    }
    if (this->getH() == t2.getH() && this->getM() == t2.getM() && this->getS() > t2.getS()) {
        return true;
    }
    return false;
}

void Times::out()
{
        if (this->hour < 10) {
            cout << "0" << this->hour;
        }
        else {
            cout << this->hour;
        }
        cout << ":";
        if (this->min < 10) {
            cout << "0" << this->min;
        }
        else {
            cout << this->min;
        }
        cout << ":";
        if (this->sec < 10) {
            cout << "0" << this->sec;
        }
        else {
            cout << this->sec;
        }

    
}
Times  Times::timein() {
    while (true) {
        int h = CheckInt("Hour");
        int m = CheckInt("minuts");
        int s = CheckInt("seconds");
        if (h < 24 && m < 60 && s < 60) {
            Times a(h, m, s);
            return a;
        }
        cout << "invalid input" << endl;
    }
}

Train::Train(string num, string dest, Times star, Times en)
{
    number = num;
    destination = dest;
    start = star;
    end = en;
}
Train::Train()
{
    number = "";
    destination = "";
}

string Train::getNumber()
{
    return this->number;
}

string Train::getDest()
{
    return this->destination;
}

Times Train::getSt()
{
    return this->start;
}

Times Train::getEn()
{
    return this->end;
}

void Train::out()
{
    cout << "Number: " << this->number << "  ";
    cout << "Destination: " << this->destination << "  ";
    cout << "Time of start: ";
    this->start.out();
    cout << "  Time of end: ";
    this->end.out();
    cout << endl;
}

void Train::init()
{
        cout << "input number: ";
        cin >> this->number;
        cout << "input destination: ";
        cin >> this->destination;
    while (true) {
        cout << "      input start " << endl;
        this->start = this->start.timein();
        cout << "      input end " << endl;
        this->end = this->end.timein();
        if (timeres(this->start) < timeres(this->end)) {
            break;
        }
        cout << "invalid input of time" << endl;
    }
}

int initsize()
{
    return CheckIntZ("size");
}

int timeres(Times t) {
    int s = t.getH() * 3600 + t.getM() * 60 + t.getS();
    return s;
}

void Sort(vector<Train>* array)
{
    for (vector<Train>::iterator j = array->begin()+1; j != array->end(); j++) {
        for (vector<Train>::iterator i = j; i != array->begin(); i--) {
            if (timeres(i->getSt()) < timeres((i - 1)->getSt())) {
                iter_swap(i, i-1);
            }
        }
    }
}

bool strm(string str1, string str2) {
    int d = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == str2[i]) d++;
    }
    if (d == str1.length()) return true;
    return false;
}

void stationc(vector<Train> array) {
    cout << endl;
    string str;
    cout << "station: ";
    cin >> str;
    cout << endl;
    vector<Train> ar;
    for (vector<Train>::iterator i = array.begin(); i != array.end(); i++) {
        if (strm(str, i->getDest())) {
            ar.push_back(*i);
        }
    }
    while (!ar.empty()) {
        ar.back().out();
        ar.pop_back();
    }
}