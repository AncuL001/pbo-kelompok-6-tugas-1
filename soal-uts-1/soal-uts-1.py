class PolaFor:
    def printPattern(self, baris):
        print("Banyak Baris : %d\n" % (baris))
        for i in range(baris, 0, -1):
            print("%d. " % (baris-i+1), end='')
            for j in range(baris, i, -1):
                print("  ", end='')
            for k in range(1, i+1):
                print("* ", end='')
            print("\n", end='')

class PolaWhile:
    def printPattern(self, baris):
        i = baris
        print("Banyak Baris : %d\n" % (baris), end='')
        while i >= 1 :
            j = baris
            k = 1
            print("%d. " % (baris-i+1), end='')
            while j > i:
                print("  ", end='')
                j -= 1
            while k <= i:
                print("* ", end='')
                k += 1
            print("\n", end='')
            i -= 1

if __name__ == "__main__":
    coba = PolaFor()
    coba1 = PolaWhile()

    print("==========Pola For==========")
    coba.printPattern(4)
    
    print("==========Pola While==========")
    coba1.printPattern(4)
