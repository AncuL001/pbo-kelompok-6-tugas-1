# Nama File : soal-bebas.py
# Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
# NPM       : 140810200020, 140810200030, 140810200032, 140810200048
# Kelas     : B
# Tanggal   : 13 Oktober 2021
# Deskripsi : Implementasi kode Permutasi dan Kombinasi dari pertemuan 4 pada C++

import math

class PersegiPanjang:
    def __init__(self, *args):
        if len(args) == 2:
            self.__panjang = float(args[0])
            self.__lebar = float(args[1])
        elif len(args) == 0:
            self.__panjang = float(0)
            self.__lebar = float(0)
    
    def setPanjang(self, panjang):
        self.__panjang = float(panjang)
    
    def getPanjang(self):
        return self.__panjang
    
    def setLebar(self, lebar):
        self.__lebar = float(lebar)
    
    def getLebar(self):
        return self.__lebar
    
    def getKeliling(self):
        return 2 * (self.__panjang + self.__lebar)
    
    def getLuas(self):
        return self.__panjang * self.__lebar

persegiPanjang1 = PersegiPanjang()
persegiPanjang2 = PersegiPanjang(float(6.5), float(3.0))

print("Masukkan panjang persegi panjang  : ", end='')
persegiPanjang1.setPanjang(input())
print("Masukkan lebar persegi panjang    : ", end='')
persegiPanjang1.setLebar(input())
        
print("Panjang Persegi Panjang  1  : ", persegiPanjang1.getPanjang())
print("Lebar Persegi Panjang 1     : ", persegiPanjang1.getLebar())
print("Keliling Persegi Panjang 1  : ", persegiPanjang1.getKeliling())
print("Luas Persegi Panjang 1      : ", persegiPanjang1.getLuas(), "\n")

print("Panjang Persegi Panjang  2  : ", persegiPanjang2.getPanjang())
print("Lebar Persegi Panjang 2     : ", persegiPanjang2.getLebar())
print("Keliling Persegi Panjang 2  : ", persegiPanjang2.getKeliling())
print("Luas Persegi Panjang 2      : ", persegiPanjang2.getLuas())
