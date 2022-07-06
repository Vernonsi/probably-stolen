#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

void generate() {
    srand(static_cast<unsigned int>(time(0)));
    string file_name;
    //cin >> file_name;
    file_name = "Source.txt";

    ofstream fout(file_name);

    //int i = rand();
    if (fout.is_open()) {
        for (int count = 0; count < 50000; ++count) {
            fout << rand() << ' '; //случайно  
            //fout << count + i << ' '; //по возрастанию
            //fout <<  -count + i << ' '; //по убыванию

            if ((count + 1) % 5 == 0)
                fout << endl;
        }
        fout.close();
        cout << "Done" << file_name << endl;
    }
}

//определение конца блока
bool End_Range(FILE* f) {
    int tmp;
    tmp = fgetc(f);
    tmp = fgetc(f);
    if (tmp != '\'') fseek(f, -2, 1);
    else fseek(f, 1, 1);
    return tmp == '\'' ? true : false;
}

int main() {
    generate();
    int count = 0, sw_count = 0, f_count=0;
    int s1, s2, a1, a2, mark;
    FILE* f, * f1, * f2;
    s1 = s2 = 1;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    while (s1 > 0 && s2 > 0) {
        mark = 1;
        s1 = 0;
        s2 = 0;
     fopen_s(&f, "Source.txt", "r");
     f_count++;
     fopen_s(&f1, "nmsort_1", "w");
     f_count++;
     fopen_s(&f2, "nmsort_2", "w");
     f_count++;
        fscanf_s(f, "%d", &a1);
        f_count++;
        if (!feof(f)) {
            fprintf(f1, "%d ", a1);
            f_count += 2;
        }
        if (!feof(f)) { fscanf_s(f, "%d", &a2); f_count += 2;}
        while (!feof(f)) {
            count++;
            f_count++;
            if (a2 < a1) {
                switch (mark) {
                case 1: {fprintf(f1, "' "); f_count++; mark = 2; s1++; break; }
                case 2: {fprintf(f2, "' "); f_count++; mark = 1; s2++; break; }
                }
            }
            if (mark == 1) { fprintf(f1, "%d ", a2); f_count++; s1++; }
            else { fprintf(f2, "%d ", a2); f_count++; s2++; }
            a1 = a2;
            fscanf_s(f, "%d", &a2);
            f_count++;
        }
        if (s2 > 0 && mark == 2) { fprintf(f2, "'"); f_count++;}
        if (s1 > 0 && mark == 1) { fprintf(f1, "'"); f_count++;}
        fclose(f2); f_count++; 
        fclose(f1); f_count++;
        fclose(f);  f_count++;




        fopen_s(&f, "Source.txt", "w"); f_count++;
        fopen_s(&f1, "nmsort_1", "r");  f_count++;
        fopen_s(&f2, "nmsort_2", "r");  f_count++;
        if (!feof(f1)) { fscanf_s(f1, "%d", &a1); f_count+=2;}
        if (!feof(f2)) { fscanf_s(f2, "%d", &a2); f_count += 2;}
        bool file1, file2;
        while (!feof(f1) && !feof(f2)) {
            f_count += 2;
            file1 = file2 = false;
            while (!file1 && !file2) {
                if (a1 <= a2) {
                    count++;
                    fprintf(f, "%d ", a1);
                    f_count++;
                    file1 = End_Range(f1);
                    f_count += 3;

                    fscanf_s(f1, "%d", &a1);
                    f_count ++;
                }
                else {
                    sw_count++;
                    fprintf(f, "%d ", a2);
                    f_count++;
                    file2 = End_Range(f2);
                    f_count += 3;
                    fscanf_s(f2, "%d", &a2);
                    f_count++;
                }
            }
            while (!file1) {
                fprintf(f, "%d ", a1);
                f_count++;
                file1 = End_Range(f1);
                f_count += 3;
                fscanf_s(f1, "%d", &a1);
                f_count++;
            }
            while (!file2) {
                fprintf(f, "%d ", a2);
                f_count++;
                file2 = End_Range(f2);
                f_count += 3;
                fscanf_s(f2, "%d", &a2);
                f_count++;
            }
        }
        file1 = file2 = false;
        while (!file1 && !feof(f1)) {
            f_count++;
            fprintf(f, "%d ", a1);
            f_count++;
            file1 = End_Range(f1);
            f_count += 3;
            fscanf_s(f1, "%d", &a1);
            f_count++;
        }
        while (!file2 && !feof(f2)) {
            f_count++;
            fprintf(f, "%d ", a2);
            f_count++;
            file2 = End_Range(f2);
            f_count += 3;
            fscanf_s(f2, "%d", &a2);
            f_count++;
        }
        fclose(f2);
        fclose(f1);
        fclose(f);
        f_count += 3;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(t2 - t1).count();
    remove("nmsort_1");
    remove("nmsort_2");
    cout << "\n number of operations\n" << count;
    cout << "\n number of swaps\n" << sw_count;
    cout << "\n number of file operations\n" << f_count;
    cout << "\n time\n" << duration;
}


