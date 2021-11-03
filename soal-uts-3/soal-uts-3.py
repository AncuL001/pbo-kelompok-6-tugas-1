# Nama File : soal-uts-3.py
# Nama      : Andaru Danurdara Wibisana, Fauzan Azmi Dwicahyo, Irfan Kamal, Muhammad Attila An Naufal
# NPM       : 140810200020, 140810200030, 140810200032, 140810200048
# Kelas     : B
# Tanggal   : 13 Oktober 2021
# Deskripsi : Implementasi Soal UTS ke-3 pada Python

class Jam:
  def __init__(self, j : int, m : int, d: int):
    self.j = j
    self.m = m
    self.d = d

  def __init__(self, string_form: str):
    temp = string_form.split(":", 2)
    self.j = int(temp[0])
    self.m = int(temp[1])
    self.d = int(temp[2])

  def earlier_than(self, rhs: 'Jam') -> bool:
    if self.j > rhs.j: return False
    if self.j < rhs.j: return True

    if self.m > rhs.m: return False
    if self.m < rhs.m: return True
    
    if self.d > rhs.d: return False
    if self.d < rhs.d: return True

    return False

  def later_than(self, rhs: 'Jam') -> bool:
    if self.j > rhs.j: return True
    if self.j < rhs.j: return False

    if self.m > rhs.m: return True
    if self.m < rhs.m: return False
    
    if self.d > rhs.d: return True
    if self.d < rhs.d: return False

    return False

  def __str__(self) -> str:
    return f'{self.j:02}:{self.d:02}:{self.m:02}'

def diff(start: Jam, end: Jam) -> int:
  if end.d < start.d:
    end.d += 60
    end.m -= 1

  if end.m < start.m:
    end.m += 60
    end.j -= 1

  return end.j - start.j

class Pegawai:
  def __init__(self, kode_pegawai: str, nama_pegawai: str, jam_masuk: Jam, jam_pulang : Jam):
    self.__kode_pegawai = kode_pegawai
    self.__nama_pegawai = nama_pegawai
    self.__jam_masuk = jam_masuk
    self.__jam_pulang = jam_pulang

  def set_kode_pegawai(self, kode_pegawai: str) -> None:
    self.__kode_pegawai = kode_pegawai

  def get_kode_pegawai(self) -> str:
    return self.__kode_pegawai

  def set_nama_pegawai(self, nama_pegawai: str) -> None:
    self.__nama_pegawai = nama_pegawai

  def get_nama_pegawai(self) -> str:
    return self.__nama_pegawai

  def set_jam_masuk(self, jam_masuk: Jam) -> None:
    self.__jam_masuk = jam_masuk

  def get_jam_masuk(self) -> Jam:
    return self.__jam_masuk

  def set_jam_pulang(self, jam_pulang: str) -> None:
    self.__jam_pulang = jam_pulang

  def get_jam_pulang(self) -> Jam:
    return self.__jam_pulang

  def get_jam_kerja(self) -> int:
    temp_jam_masuk = Jam(self.__jam_masuk)
    temp_jam_pulang = Jam(self.__jam_pulang)

    if temp_jam_masuk.earlier_than(Jam('08:00:00')):
      temp_jam_masuk = Jam('08:00:00')
    if temp_jam_pulang.later_than(Jam('6:00:00')):
      temp_jam_pulang = Jam('16:00:00')

    return diff(temp_jam_masuk, temp_jam_pulang)

  def get_upah(self) -> int:
    return self.get_jam_kerja() * 50000

def print_information(p: Pegawai):
  print(f'{p.get_kode_pegawai():<8}{p.get_nama_pegawai():<8}{p.get_jam_masuk()}  {p.get_jam_pulang()}  {p.get_jam_kerja()} {p.get_upah()}')

pegawai_list = []

for i in range(4):
  print(f'Kode pegawai {i+1} : ', end='')
  kode_pegawai = input()
  print(f'Nama pegawai {i+1} : ', end='')
  nama_pegawai = input()
  print(f'Jam masuk {i+1} (JJ:MM:DD) : ', end='')
  jam_masuk = input()
  print(f'Jam pulang {i+1} (JJ:MM:DD) : ', end='')
  jam_pulang = input()

  pegawai_list.append(Pegawai(kode_pegawai, nama_pegawai, jam_masuk, jam_pulang))
  print()

for pegawai in pegawai_list:
  print_information(pegawai)
