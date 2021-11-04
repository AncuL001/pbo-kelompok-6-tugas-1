/*
  Nama File : soal-uts-2.cpp
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 28 Oktober 2021
  Deskripsi : Implementasi Soal UTS ke-2 pada C++
*********************************************/



#include <iostream>

class Matriks {
    private:
     int baris;
     int kolom;
     int** matriks = NULL;
    public:
    Matriks(){ // Matriks tanpa nilai maka secara default 3x3
        baris = 3;
        kolom = 3;
        matriks = new int*[this->baris]; // membuat array sejumlah baris
        for(int i = 0; i < this->baris; i++){ // Membuat array per baris
            this->matriks[i] = new int[this->kolom]; // Membuat array sejumlah kolom 
        }
        for(int i = 0; i < this->baris; i++){
            for(int j = 0; j < this->kolom; j++){
                this->matriks[i][j] = 0; // Memberi nilai awal matriks 0
            }
        }
    }
    Matriks(int inBaris, int inKolom){
        baris = inBaris;
        kolom = inKolom;
        matriks = new int*[this->baris]; // membuat array sejumlah baris
        for(int i = 0; i < this->baris; i++){ // Membuat array per baris
            this->matriks[i] = new int[this->kolom]; // Membuat array sejumlah kolom 
        }
        for(int i = 0; i < this->baris; i++){
            for(int j = 0; j < this->kolom; j++){
                this->matriks[i][j] = 0; // Memberi nilai awal matriks 0
            }
        }
    }

    
    int getBaris(){
        return this->baris;
    }
    int getKolom(){
        return this->kolom;
    }

    // Methods
    void input(){
        for(int i = 0; i < this->baris; i++){
            for(int j = 0; j < this->kolom; j++){
                std::cout << "\t- Matriks [" << i+1 << "][" << j+1 << "] : ";
                std::cin >> this->matriks[i][j];
            }
        }
    }
    void print(){
        for(int i = 0; i < this->baris; i++){
            std::cout<<"|\t";
            for(int j = 0; j < this->kolom; j++){
                std::cout << this->matriks[i][j] << "\t";
            }
        std::cout <<"|\n";
        }
    }
    int * jBaris(){ // Mendapat jumlah dari tiap baris
        static int temp[10]; 
        // 10 sebagai nama default, karna static tidak dapat menyimpan variabel this->kolom, karna kalau bukan static tidak bisa passing array
        int sum = 0;
        for(int i = 0; i < this->baris; i++){
            for(int j = 0; j < this->kolom; j++){
                sum += this->matriks[i][j];
            }
            temp[i] = sum;
            sum = 0;
        }
        return temp;
    }
    int * jKolom(){ // Mendapat jumlah dari tiap kolom
        static int temp[10]; 
        // 10 sebagai nama default, karna static tidak dapat menyimpan variabel this->baris, karna kalau bukan static tidak bisa passing array
        int sum = 0;
        for(int i = 0; i < this->kolom; i++){
            for(int j = 0; j < this->baris; j++){
                sum += this->matriks[j][i];
            }
            temp[i] = sum;
            sum = 0;
        }
        return temp;
    }
};




int main(){
    int baris = 0, kolom = 0;
    std::cout<<"[Program Uts Soal 2]\nBaris : ";
    std::cin>>baris;
    std::cout<<"Kolom : ";
    std::cin>>kolom;
    Matriks matrix(baris,kolom);   // Membuat Objek Matriks 
    matrix.input();  // Input nilai ke Matrix
    std::cout<<"[Isi Matrix]\n";
    matrix.print();
    int *jumlahBaris = matrix.jBaris();
    int *jumlahKolom = matrix.jKolom();
    std::cout<<"\nJumlah Baris Matrix : ";
    for(int i = 0; i < matrix.getBaris(); i++){
        std::cout<<jumlahBaris[i]<<" ";
    }
    std::cout<<"\nJumlah Kolom Matrix : ";
    for(int i = 0; i < matrix.getKolom(); i++){
        std::cout<<jumlahKolom[i]<<" ";
    }
    return 0;
}