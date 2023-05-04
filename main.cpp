//Ilnaz Magizov DSAI-02
//i.magizov@innopolis.university

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define GNUPLOT_NAME "C:\\gnuplot\\bin\\gnuplot -persist"


using namespace std;

int main() {
    cout << fixed << setprecision(2);
    double  v0, k0, a1, a2, b1, b2, t, n, j;
    v0 = 220; k0 = 170; a1 = 0.29; b1 = 0.0008; a2 = 0.11; b2 = 0.0006; t = 150; n = 3000;
    vector <double> vt(n + 1), kt(n + 1);
    cout << "t:\n";
    for(int i = 0; i <= n; ++i){
        j = (t / n) * ((double) i);
        cout << j << ' ';
    }
    cout << "\nv:\n";
    for(int i = 0; i <= n; ++i){
        j = (t / n) * ((double) i);
        vt[i] = a2 / b2 + (v0 - a2/ b2) * cos(sqrt(a1 * a2) * j) - (k0 - a1 / b1) * ((sqrt(a2) * b1) / (b2 * sqrt(a1))) * sin(sqrt(a1 * a2) * j);
        cout << vt[i] << ' ';
    }
    cout << "\nk:\n";
    for(int i = 0; i <= n; ++i){
        j = (t / n) * ((double) i);
        kt[i] = a1 / b1 + (k0 - a1 / b1) * cos(sqrt(a1 * a2) * j) + (v0 - a2 / b2) * ((sqrt(a1) * b2) / (b1 * sqrt(a2))) * sin(sqrt(a1 * a2) * j);
        cout << kt[i] << ' ';
    }
    ofstream ofs("data.log");
    for (int i = 0; i <= n; ++i){
        j = (t / n) * ((double) i);
        ofs << j << ' ' << vt[i] << ' ' << kt[i] << endl;
    }
    ofs.close();
    FILE* pipe1 = _popen(GNUPLOT_NAME, "w");
    fprintf(pipe1, "plot [100 : 600] [0 : 400] 'data.log' u 3:2 with lines\n");
    fflush(pipe1);
    _pclose(pipe1);
    FILE* pipe = _popen(GNUPLOT_NAME, "w");
    fprintf(pipe, "plot [0 : 150] [0 : 650] 'data.log' u 1:2 with lines, 'data.log' u 1:3 with lines\n");
    fflush(pipe);
    _pclose(pipe);
    return 0;
}