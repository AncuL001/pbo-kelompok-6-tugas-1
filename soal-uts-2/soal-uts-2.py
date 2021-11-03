#  Nama File : soal-uts-2.py
#  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
#  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
#  Kelas     : B
#  Tanggal   : 28 Oktober 2021
#  Deskripsi : Implementasi Soal UTS ke-2 pada Python

import time
class Matriks:
    def __init__(self, baris, kolom):
        self.baris = baris
        self.kolom = kolom
        self.matriks = []
        for i in range(baris):
            column = []
            for j in range(kolom):
                column.append(0)
            self.matriks.append(column)
 
    def isi(self):
        for i in range (0, self.baris):
            for j in range (0, self.kolom):
                print("\t- Matriks [", (i+1), "][", (j+1), "] : ",end='')
                self.matriks[i][j]= int(input())
    def cetak(self):
        for i in range(0, self.baris):
            print(self.matriks[i])
 

    def jBaris(self):
        temp = [0 for i in range(self.baris)]
        jumlah = 0
        for i in range(0, self.baris):
            for j in range(0, self.kolom):
                jumlah = jumlah + self.matriks[i][j]
            temp[i] = jumlah
            jumlah = 0
        return temp
    def jKolom(self):
        temp = [0 for i in range(self.kolom)]
        jumlah = 0
        for i in range(0, self.kolom):
            for j in range(0, self.baris):
                jumlah = jumlah + self.matriks[j][i]
            temp[i] = jumlah
            jumlah = 0
        return temp

# Main
print("[Program Uts Soal 2]")
matrix = Matriks(int(input("Baris : ")), int(input("Kolom : ")))
print("[Input Matrix]")
matrix.isi()
print("[Isi Matrix]")
matrix.cetak()
jumBaris = matrix.jBaris()
print("\n[Jumlah Baris Matrix]")
print(jumBaris)
jumKolom = matrix.jKolom()
print("\n[Jumlah Baris Matrix]")
print(jumBaris)
time.sleep(10);