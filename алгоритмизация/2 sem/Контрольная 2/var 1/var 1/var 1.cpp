#include <iostream>
#include <vector>
#include <string>

using namespace std;

class University  {
protected:	string faculty;
	int course;
	int group;	
	string ID;
public:
	University(string Faculty, int Course, int Group,string id) {
		faculty = Faculty;
		course = Course;
		group = Group;
		ID = id;
	}
	University() {
		faculty = "";
		course = 0;
		group = 0;
		ID = "";
	}
	string getFaculty() {
		return faculty;
	}
	int getCourse() {
		return course;
	}
	int getGroup() {
		return group;
	}
	string getID() {
		return ID;
	}
	
};

class Student :public University {
	string Surname;
	string Name;
	string Patronymic;
	int Date;
	string Adress;
	string Number;

public:
	Student(string surname, string name, string patronymic, int date,string adress, string number, string Faculty, int Course, int Group, string id): University(Faculty,Course, Group,id) {
		Surname = surname;
		Name = name;
		Patronymic = patronymic;
		Adress = adress;
		Date = date;
		Number = number;
		faculty = Faculty;
		course = Course;
		group = Group;
		ID = id;
	}
	Student() : University() {
		Surname ="";
		Name = "";
		Patronymic = "";
		Adress = "";
		Date = 0;
		Number = "";
		faculty = "";
		course = 0;
		group = 0;
		ID = "";
	}
	string getSurname() {
		return Surname;
	}
	string getName() {
		return Name;
	}
	string getPatronymic() {
		return Patronymic;
	}
	int getDate() {
		return Date;
	}
	string getAdress() {
		return Adress;
	}
	string getNumber() {
		return Number;
	}
	
};

ostream& operator<<(ostream& out, Student a) {
	out << "Name: " << a.getSurname() << " " << a.getName() << " " << a.getPatronymic() << endl;
	out << "Date of birth: " << a.getDate() << endl;
	out << "Adress: " << a.getAdress() << endl;
	out << "Phone number: " << a.getNumber() << endl;
	out << "Faculty: " << a.getFaculty() << endl;
	out << "Course: " << a.getCourse() << endl;
	out << "Group: " << a.getGroup() << endl << endl;
	return out;
}



int main() {
	int n;
	cout << "Number of students:";
	cin >> n;
	string ID, Surname, Name, Patronymic, Number,Adress, faculty;
	int course, group, Date;
	vector<Student> students(n);
	for (int i = 1; i <= n; i++) {
		cout << "Student " << i << "\nSurname: ";
		cin >> Surname;
		cout << "Name ";
		cin >> Name;
		cout << "Patronomic ";
		cin >> Patronymic;
		cout << "Year of birth ";
		cin >> Date;
		cout << "Adress ";
		cin >> Adress;
		cout << "Phone number ";
		cin >> Number;
		cout << "Faculty ";
		cin >>faculty;
		cout << "Course ";
		cin >> course;
		cout << "Group ";
		cin >> group;
		cout << "ID ";
		cin >> ID;
		students[i - 1] = Student(Surname, Name, Patronymic, Date, Adress, Number, faculty, course, group, ID);
	}
	cout << "\nType faculty name\n";
	string checkfac;
	cin >> checkfac;
	for (int i = 0; i < n; i++) {
		if (students[i].getFaculty() == checkfac){
			cout << students[i];
		}
	}
	cout << endl << endl;
	cout << "\nType year\n";
	cin >> Date;
	for (int i = 0; i < n; i++) {
		if (students[i].getDate() > Date) {
			cout << students[i];
		}
	}
	cout << endl << endl << endl;
	bool g = true;
	cout << "Groups\n";
	cout << students[0].getGroup() << endl;
	for (int i = 1; i < n; i++) {
		g = true;
		for (int m = 0; m < i; m++) {
			if (students[i].getGroup() == students[m].getGroup()) g = false;
		}
		if (g) cout << students[i].getGroup() << endl;
	}
	cout << endl << endl ;

	int fcounter = 1;
	for (int i = 1; i < n; i++) {
		g = true;
		for (int m = 0; m < i; m++) {
			if (students[i].getFaculty() == students[m].getFaculty()) g = false;
		}
		if (g) fcounter++;
	}

	int gcounter = 1;
	for (int i = 1; i < n; i++) {
		g = true;
		for (int m = 0; m < i; m++) {
			if (students[i].getGroup() == students[m].getGroup()) g = false;
		}
		if (g) gcounter++;
	}

	int ccounter = 1;
	for (int i = 1; i < n; i++) {
		g = true;
		for (int m = 0; m < i; m++) {
			if (students[i].getCourse() == students[m].getCourse()) g = false;
		}
		if (g) ccounter++;
	}

	cout << "Number of facultys - " << fcounter << endl;
	cout << "Number of groups - " << gcounter << endl;
	cout << "Number of courses - " << ccounter << endl;
}