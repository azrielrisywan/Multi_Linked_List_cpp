#ifndef NABIL_LINKEDLIST_H
#define NABIL_LINKEDLIST_H
#include <iostream>
#include <string>
#include "Dospem.h"
#include "Node.h"
#include "Mhs.h"

using namespace std;

class LinkedList {
public:
    Node* head;
    int mhsIterator = 0;
    LinkedList() { head = nullptr; }

    void insertDospem(const Dospem& d) {
        auto* newNode = new Node(d);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayDospem(Node* node) {
        if (node == nullptr) {
            cout << "----------------------------------" << endl;
        } else {
            cout << node->dospem.print();
            displayDospem(node->next);
        }
    }

    void displayDospemTersedia(Node* head) {
        if (head == NULL) {
            cout << "----------------------------------" << endl;
        } else {
            if (head->dospem.getJumlahBimb() >= 10) {
                head = head->next;
            }
            cout << head->dospem.print();
            displayDospemTersedia(head->next);
        }
    }

    void displayMahasiswa(Dospem dospem, Node* node) {
        while (node->dospem.getNamaDos() != dospem.getNamaDos()) {
            node = node->next;
        }
        cout << "Yang dibimbing oleh dospem " + dospem.getNamaDos() + ":\n";
        displayMahasiswaHelper(node->child);
    }

    void displayMahasiswa(const string& topik, Node* node) {
        while (node->dospem.getKepakaran() != topik) {
            node = node->next;
        }
        cout << "Mahasiswa yang mengambil topik TA " + topik + ":\n";
        displayMahasiswaHelper(node->child);
    }

    void displaySemuaMahasiswa (Node* node) {
        while (node != nullptr) {
            displayMahasiswa(node->dospem, head);
            node = node->next;
        }
        cout << "Jumlah Mahasiswa : " << to_string(mhsIterator);
    }

    void displayMahasiswaHelper(Node* node) {
        if (node == nullptr) {
            cout << "-----------------------------------" << endl;
        } else {
            cout << node->mhs.print();
            displayMahasiswaHelper(node->child);
            mhsIterator++;
        }
    }

    void insertMahasiswa(Dospem dospem, Mhs mahasiswa) const {
        Node* tempHead = head;
        auto* newNode = new Node(mahasiswa);

        while (tempHead != nullptr) {
            if (tempHead->dospem.getNamaDos() == dospem.getNamaDos()) {
                tambahJumlahBimbingan(tempHead);
                if (tempHead->child == nullptr) {
                    tempHead->child = newNode;
                    return;
                } else {
                    while (tempHead->child != nullptr) {
                        tempHead = tempHead->child;
                    }
                    tempHead->child = newNode;
                }
            } else {
                tempHead = tempHead->next;
            }
        }
    }

    // no. 4
    static void tambahJumlahBimbingan (Node* node) {
        node->dospem.setJumlahBimb(node->dospem.getJumlahBimb() + 1);
    }
    static void kurangJumlahBimbingan (Node* node) {
        node->dospem.setJumlahBimb(node->dospem.getJumlahBimb() - 1);
    }

    void deleteDospem(string nama) {
        Node* temp = head;
        Node* temp2 = head->next;
        if (nama == temp->dospem.getNamaDos()) {
            head = head->next;
            return;
        }

        while (temp2->dospem.getNamaDos() != nama) {
            temp2 = temp2->next;
        }
        while (temp->next->dospem.getNamaDos() != temp2->dospem.getNamaDos()) {
            temp = temp->next;
        }
        temp->next = temp2->next;
        temp2->next = NULL;
    }

    void deleteMahasiswa(Dospem dospem, Mhs mahasiswa) {
        Node* temp = head;
        while (temp->dospem.getNamaDos() != dospem.getNamaDos()) {
            temp = temp->next;
        }
        kurangJumlahBimbingan(temp);
        deleteMahasiswaHelper(temp->child, std::move(mahasiswa));
    }

    static void deleteMahasiswaHelper(Node* node, Mhs m) {
        Node* temp = node;
        Node* temp2 = node->child;

        while (temp2->mhs.getNama() != m.getNama()) {
            temp2 = temp2->child;
        }
        while (temp->child->mhs.getNama() != temp2->mhs.getNama()) {
            temp = temp->child;
        }
        temp->child = temp2->child;
        temp2->child = nullptr;
    }
};


#endif //NABIL_LINKEDLIST_H
