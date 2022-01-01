//
// Created by Legion Y530 on 12/31/2021.
//

#ifndef NABIL_DOSPEM_H
#define NABIL_DOSPEM_H

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Dospem {
private:
    string namaDos;
    string kepakaran;
    int jumlahBimb{};

public:
    // Constructor
    Dospem() {}
    Dospem(string nama, string kepakaran, int jumlahBimb) {
        this->namaDos = std::move(nama);
        this->kepakaran = std::move(kepakaran);
        this->jumlahBimb = jumlahBimb;
    }

    // Destructor
    ~Dospem();

    // Setter
    void setNamaDos(string n) {
        namaDos = std::move(n);
    }
    void setKepakaran(string k) {
        kepakaran = std::move(k);
    }
    void setJumlahBimb(int j) {
        jumlahBimb = j;
    }

    // Getter
    basic_string<char> getNamaDos() {
        return namaDos;
    }
    basic_string<char> getKepakaran() {
        return kepakaran;
    }
    int getJumlahBimb() const {
        return jumlahBimb;
    }

    string print() {
        return
        "Nama            : " + getNamaDos() + "\n" +
        "Kepakaran       : " + getKepakaran() + "\n" +
        "Jumlah Bimbingan: " + to_string(getJumlahBimb()) + "\n\n";
    }

};

Dospem::~Dospem(){}

#endif //NABIL_DOSPEM_H
