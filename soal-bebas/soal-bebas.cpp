/*
  Nama File : soal-bebas.cpp
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 13 Oktober 2021
  Deskripsi : Implementasi kode Permutasi dan Kombinasi dari pertemuan 4 pada C++
*********************************************/
#include <iostream>

int faktorial(int angka){
    int hasil = 1;
    for (int i = angka; i >= 1; i--)
        hasil *= i;
    return hasil;
}

int inputAngka(){
    int angka;
    std::cin >> angka;
    return angka;
}

int permutasi(int n, int r){
    int pembilang = faktorial(n);
    int penyebut = faktorial(n-r);
    return pembilang / float(penyebut);
}

int kombinasi(int n, int r){
    int pembilang = faktorial(n);
    int penyebut = faktorial(n-r) * faktorial(r);
    return pembilang / float(penyebut);
}

void output(int n, int r){
    std::cout << "Permutasi : " << permutasi(n,r) << "\n";
    std::cout << "Kombinasi : " << kombinasi(n,r);
}

int main(){
    int n, r;

    std::cout << "Masukkan n : "; std::cin >> n;
    std::cout << "Masukkan r : "; std::cin >> r;

    std::cout << "\n";
    output(n, r);
    return 0;
}