#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

struct Jam {
  int j;
  int m;
  int d;

  Jam() {Jam(0,0,0);}

  Jam(int j, int m, int d):
    j{j}, m{m}, d{d} {};

  Jam(const std::string& string_form){
  std::stringstream ss(string_form);
  std::string tmp;

  std::getline(ss, tmp, ':');
  this->j = stoi(tmp);

  std::getline(ss, tmp, ':');
  this->m  = stoi(tmp);

  std::getline(ss, tmp, ':');
  this->d = stoi(tmp);
  }

  bool earlierThan(const Jam& rhs) const {
    if (j > rhs.j) return false;
    if (j < rhs.j) return true;

    if (m > rhs.m) return false;
    if (m < rhs.m) return true;
    
    if (d > rhs.d) return false;
    if (d < rhs.d) return true;

    return true;
  }

  bool laterThan(const Jam& rhs) const {
    if (j > rhs.j) return true;
    if (j < rhs.j) return false;

    if (m > rhs.m) return true;
    if (m < rhs.m) return false;
    
    if (d > rhs.d) return true;
    if (d < rhs.d) return false;

    return true;
  }

  std::string str() const {
    std::stringstream tmp;
    tmp << std::setfill('0') << std::setw(2) << j << ":" 
        << std::setfill('0') << std::setw(2) << m << ":" 
        << std::setfill('0') << std::setw(2) << d;
    return tmp.str();
  }
};

int diff(const Jam& start, Jam end) {
  if (end.d < start.d) {
    end.d += 60;
    end.m--;
  }
  if (end.m < start.m) {
    end.m += 60;
    end.j--;
  }
  return end.j - start.j;
}

class Pegawai {
  private:
  std::string kodePegawai;
  std::string namaPegawai;
  Jam jamMasuk;
  Jam jamPulang;

  public:
  Pegawai(const std::string& kodePegawai,
          const std::string& namaPegawai,
          const Jam& jamMasuk,
          const Jam& jamPulang){
    setNamaPegawai(namaPegawai);
    setKodePegawai(kodePegawai);
    setJamMasuk(jamMasuk);
    setJamPulang(jamPulang);
  }

  std::string getNamaPegawai() const {
    return namaPegawai;
  }
  std::string getKodePegawai() const  {
    return kodePegawai;
  }
  Jam getJamMasuk() const {
    return jamMasuk;
  }
  Jam getJamPulang() const {
    return jamPulang;
  }
  void setNamaPegawai(const std::string& namaPegawai) {
    this->namaPegawai = namaPegawai;
  }
  void setKodePegawai(const std::string& kodePegawai) {
    this->kodePegawai = kodePegawai;
  }
  void setJamMasuk(const Jam& jamMasuk) {
    this->jamMasuk = jamMasuk;
  }
  void setJamPulang(const Jam& jamPulang) {
    this->jamPulang = jamPulang;
  }

  int getJamKerja() const {
    Jam tempJamMasuk = jamMasuk;
    Jam tempJamPulang = jamPulang;

    if (tempJamMasuk.earlierThan(Jam("08:00:00")))
      tempJamMasuk = Jam("08:00:00");
    if (tempJamPulang.laterThan(Jam("16:00:00")))
      tempJamPulang = Jam("16:00:00");
    
    return diff(tempJamMasuk, tempJamPulang);
  }

  int getUpah() const {
    return getJamKerja() * 50000;
  }
};

void printInformation(const Pegawai& p){
  printf("%-8s%-8s%-10s%-10s%d %d\n", 
          p.getKodePegawai().c_str(), 
          p.getNamaPegawai().c_str(), 
          p.getJamMasuk().str().c_str(), 
          p.getJamPulang().str().c_str(), 
          p.getJamKerja(), 
          p.getUpah()
        );
}

int main(){
  std::vector<Pegawai> p;

  for (int i = 0; i < 4; i++){
    std::string kodePegawai, namaPegawai, jamMasuk, jamPulang;

    std::cout << "Kode pegawai " << i+1 << " : ";
    std::cin >> kodePegawai;
    std::cout << "Nama pegawai " << i+1 << " : ";
    std::cin >> namaPegawai;
    std::cout << "Jam masuk " << i+1 << " (JJ:MM:DD) : ";
    std::cin >> jamMasuk;
    std::cout << "Jam keluar " << i+1 << " (JJ:MM:DD) : ";
    std::cin >> jamPulang;

    p.push_back(Pegawai(kodePegawai, namaPegawai, Jam(jamMasuk), Jam(jamPulang)));
    std::cout << "\n";
  }

  for (int i = 0; i < 4; i++){
    printInformation(p[i]);
  }
}