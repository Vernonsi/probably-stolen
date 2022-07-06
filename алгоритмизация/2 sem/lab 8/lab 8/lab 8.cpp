#include <iostream>
#include <string>
#include<fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class train;
class TIMES {
	double hours;
	double minutes;
public:
	TIMES() {
		hours = 0;
		minutes = 0;
	}
	TIMES(double h, double m) {
		hours = h;
		minutes = m;
		while (minutes > 60) {
			hours++;
			minutes -= 60;
		}
	}
	TIMES(const TIMES& a) {
		hours = a.hours;
		minutes = a.minutes;
	}

	double getHour() {
		return hours;
	}
	double getMinute() {
		return minutes;
	}
	friend ostream& operator<<(ostream& out, TIMES& t) {
		if (t.hours < 10) out << 0;
		out << t.hours << ":";
		if (t.minutes < 10) out << 0;
		out << t.minutes;
		return out;
	}
	friend 	bool operator < (TIMES a, TIMES b)
	{
		if (a.hours == b.hours) return a.minutes < b.minutes;
		return a.hours < b.hours;
	}
	friend 	bool operator > (TIMES a, TIMES b)
	{
		if (a.hours == b.hours) return a.minutes > b.minutes;
		return a.hours > b.hours;
	}

};

class train {
	string number;
	string start_station;
	string end_station;
	TIMES start_time;
	TIMES end_time;
public:
	train(string n, string sst, string est, TIMES st, TIMES et) {
		number = n;
		start_station = sst;
		end_station = est;
		start_time = st;
		end_time = et;
	}
	train(string n, string sst, string est, double sh, double sm, double eh, double em) {
		number = n;
		start_station = sst;
		end_station = est;
		TIMES st(sh, sm);
		TIMES et(eh, em);
		start_time = st;
		end_time = et;
	}
	string getNumber() {
		return number;
	}
	string getStartStation() {
		return start_station;
	}
	string getEndStation() {
		return end_station;
	}
	TIMES getStartTime() {
		return start_time;
	}
	TIMES getEndTime() {
		return end_time;
	}

	friend ostream& operator<<(ostream& out, train& t) {
		out << t.number << " " << t.start_station << " " << t.end_station << " " << t.start_time << " " << t.end_time;
		return out;
	}

	friend 	bool operator < (train a, train b)
	{
		return a.getStartTime().getHour() < b.getStartTime().getHour();
	}
	friend 	bool operator > (train a, train b)
	{
		a.getStartTime().getHour() > b.getStartTime().getHour();
	}

};

vector<train> fvread(ifstream& fin) {
	string number;
	string start_station;
	string end_station;
	double sth, stm;
	double eth, etm;
	vector<train> out;

	while (!fin.eof()) {
		fin >> number >> start_station >> end_station >> sth >> stm >> eth >> etm;
		TIMES s(sth, stm), e(eth, etm);
		train choo(number, start_station, end_station, s, e);
		out.push_back(choo);
	}
	return out;
}

void fvwrite(vector<train> input, ofstream& fout) {
	TIMES start;
	TIMES end;
	for (int i = 0; i < input.size(); i++) {
		start = (input[i].getStartTime());
		end = input[i].getEndTime();
		fout << input[i].getNumber() << " " << input[i].getStartStation() << " " << input[i].getEndStation() << " " << start << " " << end << endl;
	}

}

void output(vector<train> out) {
	vector<train>::iterator iter;
	iter = out.begin();
	while (iter != out.end()) {
		cout << *iter << endl;
		iter++;
	}
}

vector<train> searchStation(vector<train> schedule) {
	string station;
	cout << "end station\n";
	cin >> station;
	vector<train> out;
	for (int i = 0; i < schedule.size(); i++) {
		if (schedule[i].getEndStation() == station) {
			out.push_back(schedule[i]);
		}
	}
	return out;
}

vector<train> sortTime(vector<train> schedule) {
	vector<train> out = schedule;
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out.size(); j++) {
			if (out[i].getStartTime() < out[j].getStartTime())
				swap(out[i], out[j]);
		}
	}
	return out;
}
vector<train> sortsort(vector<train> schedule) {
	vector<double> timed;
	vector<train>::iterator iter;
	iter = schedule.begin();
	for (int i = 0; i < schedule.size(); i++) {
		timed.push_back(schedule[i].getStartTime().getHour());
	}
	sort(timed.begin(), timed.end());
	vector<train> out = schedule;
	iter = out.begin();
	for (int i = 0; i < timed.size();i++) {
		for (int j = 0; j < out.size(); j++) {
			if (timed[i] == out[j].getStartTime().getHour()) swap(out[i], out[j]);
		}
	}
	return out;
}

int main() {
	ifstream fin("trains.txt");
	vector<train> schedule = fvread(fin);
	output(schedule);
	cout << endl << endl;
	//schedule = sortTime(schedule);
	//schedule = sortsort(schedule);
	sort(schedule.begin(), schedule.end());
	output(schedule);
	cout << endl << endl;
	schedule = searchStation(schedule);
	output(schedule);
	ofstream fout("station.txt");
	fvwrite(schedule, fout);

}