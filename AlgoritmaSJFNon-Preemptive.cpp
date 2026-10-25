#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Proses {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    bool selesai;
};

void hitungSJFNonPreemptive() {
    // Inisialisasi data berdasarkan NPM: 2517051011
    vector<Proses> p = {
        {1, 2, 1, 0, 0, 0, false},
        {2, 5, 1, 0, 0, 0, false},
        {3, 1, 10, 0, 0, 0, false},
        {4, 7, 5, 0, 0, 0, false},
        {5, 0, 1, 0, 0, 0, false},
        {6, 5, 10, 0, 0, 0, false},
        {7, 1, 5, 0, 0, 0, false},
        {8, 0, 7, 0, 0, 0, false},
        {9, 1, 1, 0, 0, 0, false},
        {10, 1, 2, 0, 0, 0, false}
    };

    int n = p.size();
    int selesaiCount = 0;
    int waktuAktif = 0;
    float totalWt = 0;

    cout << "\n==================================================\n";
    cout << "   SJF NON-PREEMPTIVE (NPM: 2517051011)\n";
    cout << "==================================================\n";
    cout << "ID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "--------------------------------------------------\n";

    while(selesaiCount < n) {
        int idxMin = -1;
        int minBt = 99999;

        for(int i = 0; i < n; i++) {
            if(!p[i].selesai && p[i].at <= waktuAktif) {
                if(p[i].bt < minBt) {
                    minBt = p[i].bt;
                    idxMin = i;
                }
                else if(p[i].bt == minBt) {
                    if(p[i].at < p[idxMin].at || (p[i].at == p[idxMin].at && p[i].id < p[idxMin].id)) {
                        idxMin = i;
                    }
                }
            }
        }

        if(idxMin == -1) {
            waktuAktif++;
        } else {
            waktuAktif += p[idxMin].bt;
            p[idxMin].ct = waktuAktif;
            p[idxMin].tat = p[idxMin].ct - p[idxMin].at;
            p[idxMin].wt = p[idxMin].tat - p[idxMin].bt;
            p[idxMin].selesai = true;
            selesaiCount++;

            totalWt += p[idxMin].wt;

            cout << "P" << p[idxMin].id << "\t" 
                 << p[idxMin].at << "\t" 
                 << p[idxMin].bt << "\t" 
                 << p[idxMin].ct << "\t" 
                 << p[idxMin].tat << "\t" 
                 << p[idxMin].wt << "\n";
        }
    }

    cout << "--------------------------------------------------\n";
    cout << "Total Waiting Time (Total WT) : " << totalWt << "\n";
    cout << "Rata-rata Waiting Time (WT)   : " << fixed << setprecision(2) << (totalWt / n) << "\n";
    cout << "==================================================\n";
}

int main() {
    hitungSJFNonPreemptive();
    return 0;
}