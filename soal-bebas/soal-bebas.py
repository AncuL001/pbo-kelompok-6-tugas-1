# Nama File : soal-bebas.py
# Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
# NPM       : 140810200020, 140810200030, 140810200032, 140810200048
# Kelas     : B
# Tanggal   : 13 Oktober 2021
# Deskripsi : Implementasi kode Permutasi dan Kombinasi dari pertemuan 4 pada C++

import math

# @staticmethod
def faktorial(angka):
    hasil = 1
    for i in range(angka, 1, -1):
        hasil *= i
    return hasil

# @staticmethod
def inputAngka():
    angka = input()
    return angka

# @staticmethod
def permutasi(n, r):
    pembilang = faktorial(n)
    penyebut = faktorial(n-r)
    return math.trunc(pembilang / float(penyebut))

# @staticmethod
def kombinasi(n, r):
    pembilang = faktorial(n)
    penyebut = faktorial(n-r) * faktorial(r)
    return math.trunc(pembilang / float(penyebut))

# @staticmethod
def output(n, r):
    print("Permutasi : ", permutasi(n,r))
    print("Kombinasi : ", kombinasi(n,r))

n = None
r = None

print("Masukkan n : ", end = '')
n = inputAngka()
print("Masukkan r : ", end = '')
r = inputAngka()

n = int(n)
r = int(r)

print("")
output(n, r)