/*
  Nama File : soal-bebas.cpp
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 13 Oktober 2021
  Deskripsi : Implementasi kode Permutasi dan Kombinasi dari pertemuan 4 pada C++
*********************************************/
#include <iostream>

class PersegiPanjang{
    private :
    float panjang, lebar;
    
    public :
    PersegiPanjang(){
        this->panjang = 0;
        this->lebar = 0;
    }
    
    PersegiPanjang(float panjang, float lebar){
        this->panjang = panjang;
        this->lebar = lebar;
    }
    
    void setPanjang(){
        std::cout << "Masukkan panjang persegi panjang  : ";
        std::cin >> this->panjang;
    }
    
    float getPanjang(){
        return this->panjang;
    }
    
    void setLebar(){
        std::cout << "Masukkan lebar persegi panjang    : ";
        std::cin >> this->lebar;
    }
    
    float getLebar(){
        return this->lebar;
    }
    
    float getKeliling(){
        return this->panjang+this->lebar;
    }
    
    float getLuas(){
        return this->panjang*this->lebar;
    }
};


int main(){
    PersegiPanjang persegiPanjang1;
    PersegiPanjang persegiPanjang2(float(6.5), float(3.0));
    persegiPanjang1.setPanjang();
    persegiPanjang1.setLebar();
            
    std::cout << "Panjang Persegi Panjang  1  : " << persegiPanjang1.getPanjang() << "\n";
    std::cout << "Lebar Persegi Panjang 1     : " << persegiPanjang1.getLebar() << "\n";
    std::cout << "Keliling Persegi Panjang 1  : " << persegiPanjang1.getKeliling() << "\n";
    std::cout << "Luas Persegi Panjang 1      : " << persegiPanjang1.getLuas() << "\n\n";

    std::cout << "Panjang Persegi Panjang  2  : " << persegiPanjang2.getPanjang() << "\n";
    std::cout << "Lebar Persegi Panjang 2     : " << persegiPanjang2.getLebar() << "\n";
    std::cout << "Keliling Persegi Panjang 2  : " << persegiPanjang2.getKeliling() << "\n";
    std::cout << "Luas Persegi Panjang 2      : " << persegiPanjang2.getLuas() << "\n\n";

    return 0;
}