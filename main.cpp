#include "Dospem.h"
#include "LinkedList.h"
#include "Mhs.h"

using namespace std;

int main() {

    // objects from Dospem Class
    Dospem anton("Anton", "Computer Vision", 0);
    Dospem anisa("Anisa", "Kriptografi", 0);
    Dospem joko("Joko", "IoT", 0);
    Dospem ani("Ani", "NLP", 0);

    // objects from Mhs Class
    Mhs budi("Budi", "123456", "Computer Vision", 125);
    Mhs andi("Andi", "123488", "Computer Vision", 133);
    Mhs tono("Tono", "123457", "Kriptografi", 130);
    Mhs toni("Toni", "123458", "NLP", 121);
    Mhs tuti("Tuti", "123499", "NLP", 130);
    Mhs adi("Adi", "123477", "NLP", 128);

    LinkedList list;

    // 1. Menambah dan menghapus dosen
    // menambah
    list.insertDospem(anton);
    list.insertDospem(anisa);
    list.insertDospem(joko);
    list.insertDospem(ani);
    // menghapus
//    list.deleteDospem("Ani");

    // 2. menambah dan menghapus mahasiswa
    // menambah
    list.insertMahasiswa(anton, budi);
    list.insertMahasiswa(anton, andi);
    list.insertMahasiswa(anisa, tono);
    list.insertMahasiswa(ani, toni);
    list.insertMahasiswa(ani, tuti);
    list.insertMahasiswa(ani, adi);
    // menghapus
//    list.deleteMahasiswa(ani, tuti);

    // no. 4 ada di LinkedList.h line ke-107

    // no. 5
//    list.displayDospem(list.head);
    // no. 6
//    list.displayMahasiswa(ani,list.head);
    // no. 7
//    list.displayMahasiswa("Kriptografi", list.head);
    // no. 8
//    list.displayMahasiswa(anton, list.head);
//    list.displayMahasiswa(anisa, list.head);
//    list.displayMahasiswa(ani, list.head);
    // no. 9
//    list.displayDospemTersedia(list.head);
    // no. 10
//    list.displaySemuaMahasiswa(list.head);
    return 0;
}
