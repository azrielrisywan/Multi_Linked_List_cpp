//
// Created by Legion Y530 on 12/31/2021.
//

#ifndef NABIL_MHS_H
#define NABIL_MHS_H
#include <iostream>
#include <string>

using namespace std;

class Mhs {
private:
    string nama;
    string nim;
    string topikTA;
    int sksLulus;

public:
    // Constructor
    Mhs() {}
    Mhs(string nama, string nim, string topikTA, int sksLulus) {
        this->nama = nama;
        this->nim = nim;
        this->topikTA = topikTA;
        this->sksLulus = sksLulus;
    }
    // Setter
    void setNama(string n) {
        nama = std::move(n);
    }
    void setNim(string n) {
        nim = std::move(n);
    }
    void setTopikTA(string t) {
        topikTA = std::move(t);
    }
    void setSksLulus(int s) {
        sksLulus = s;
    }

    // Getter
    basic_string<char> getNama() {
        return nama;
    }
    basic_string<char> getNim() {
        return nim;
    }
    basic_string<char> getTopikTA() {
        return topikTA;
    }
    int getSksLulus() const {
        return sksLulus;
    }

    string print() {
        return
                "Nama            : " + getNama() + "\n" +
                "NIM             : " + getNim() + "\n" +
                "Topik TA        : " + getTopikTA() + "\n" +
                "Jumlah Bimbingan: " + to_string(getSksLulus()) + "\n\n";
    }
};


#endif //NABIL_MHS_H
