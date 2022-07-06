#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <fstream>
using namespace std;

struct tim {
	int hour;
	int min;
	int sec;
};
bool strm(string str1, string str2) {
    int d = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] == str2[i]) d++;
    }
    if (d == str1.length()) return true;
    return false;
}

tim convert(char* str)
{
	tim result;
	char* context = NULL;
	char* str_number = strtok_s(str, ".", &context);
	result.hour = atoi(str_number);
	str_number = strtok_s(NULL, ".", &context);
	result.min = atoi(str_number);
	str_number = strtok_s(NULL, ".", &context);
	result.sec = atoi(str_number);
	return result;
}

void outerT(tim i) {
    if (i.hour < 10) {
        cout << "0" << i.hour;
    }
    else {
        cout << i.hour;
    }
    cout << ".";
    if (i.min < 10) {
        cout << "0" << i.min;
    }
    else {
        cout << i.min;
    }
    cout << ".";
    if (i.sec < 10) {
        cout << "0" << i.sec;
    }
    else {
        cout << i.sec;
    }
}

class Train {
    string number;
    string station;
    tim start;

public:
    string getNum() {
        return this->number;
    }
    string getStation() {
        return this->station;
    }
    tim getStart() {
        return this->start;
    }
	void setNum(string s) {
		this->number = s;
	}
	void setStation(string s) {
		this->station = s;
	}
	void setTime(tim t) {
		this->start = t;
	}

    void out() {
        cout << "Number: " << this->number << "  Station: " << this->station << "  Time: ";
        outerT(this->start);
        cout << endl;
    }

};

void read(const char* file_name, set<Train*> *array) {

    std::ifstream file(file_name);
    if (file.is_open())
    {
        char tmp_buffer[200];

        while (!file.eof()) {

            Train* item = new Train;

            string s;
            file >> s;
            item->setNum(s);
            file >> s;
            item->setStation(s);
            file >> tmp_buffer;
            item->setTime(convert(tmp_buffer));
            array->insert(item);
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}





#endif // !CLASESS_H
