/*
  Nama File : soal-uts-1.cpp
  Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
  NPM       : 140810200020, 140810200030, 140810200032, 140810200048
  Kelas     : B
  Tanggal   : 13 Oktober 2021
  Deskripsi : Implementasi kode pola dengan while loop dan for loop
*********************************************/
#include <stdio.h>

class PolaFor{
    public:
        void printPattern(int baris){
            printf("Banyak Baris : %d\n", baris);
            for(int i= baris; i >= 1; i--){
                printf("%d. ", baris-i+1);
                for(int j=baris; j > i;j--){
                    printf("  ");
                }  
                for(int k=1;k<=i;k++){
                    printf("* ");
                }  
                printf("\n");
            }
        }
};

class PolaWhile{
public:
    void printPattern(int baris){
        int i = baris;
        int j, k;
        printf("Banyak Baris : %d\n", baris);
        while(i >= 1) {
            j = baris;
            k = 1;
            printf("%d. ", baris-i+1);
            while(j > i) {
                printf("  ");
                j--;
            }
            while(k <= i) {
                printf("* ");
                k++;
            }
            printf("\n");
            i--;
        }
    }
};

int main(int argc, char const *argv[])
{
    PolaFor coba = PolaFor();
    PolaWhile coba1 = PolaWhile();

    printf("==========Pola For==========\n");
    coba.printPattern(4);

    printf("==========Pola While==========\n");
    coba1.printPattern(4);
    return 0;
}

