#include <iostream>
#include <vector>
#include <iomanip> // Untuk std::setprecision
#include <string>

struct Mahasiswa {
    std::string NIM;
    
    std::string Nama;
    float NilaiAbsen;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir;
    char Grade;
};

void tambahMahasiswa(std::vector<Mahasiswa>& daftar);
void hitungNilaiAkhir(Mahasiswa& mhs);
void tentukanGrade(Mahasiswa& mhs);
void tampilkanMahasiswa(const std::vector<Mahasiswa>& daftar);
void cariMahasiswa(const std::vector<Mahasiswa>& daftar, const std::string& nim);

int main() {
    std::vector<Mahasiswa> daftarMahasiswa;
    int pilihan;

    do {
        std::cout << "\n=== Sistem Pengelolaan Nilai UAS Mahasiswa ===\n";
        std::cout << "1. Tambah Mahasiswa\n";
        std::cout << "2. Tampilkan Semua Mahasiswa\n";
        std::cout << "3. Cari Mahasiswa Berdasarkan NIM\n";
        std::cout << "4. Keluar\n";
        std::cout << "Pilih opsi: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa(daftarMahasiswa);
                break;
            case 2:
                tampilkanMahasiswa(daftarMahasiswa);
                break;
            case 3: {
                std::string nim;
                std::cout << "Masukkan NIM yang dicari: ";
                std::cin >> nim;
                cariMahasiswa(daftarMahasiswa, nim);
                break;
            }
            case 4:
                std::cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                std::cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}

void tambahMahasiswa(std::vector<Mahasiswa>& daftar) {
    Mahasiswa mhs;

    std::cout << "Masukkan NIM: ";
    std::cin >> mhs.NIM;
    std::cout << "Masukkan Nama: ";
    std::cin.ignore(); // Mengabaikan newline dari input sebelumnya
    std::getline(std::cin, mhs.Nama);
    
    std::cout << "Masukkan Nilai Absen: ";
    std::cin >> mhs.NilaiAbsen;
    
    std::cout << "Masukkan Nilai Tugas: ";
    std::cin >> mhs.NilaiTugas;

    std::cout << "Masukkan Nilai UTS: ";
    std::cin >> mhs.NilaiUTS;

    std::cout << "Masukkan Nilai UAS: ";
    std::cin >> mhs.NilaiUAS;

    hitungNilaiAkhir(mhs);
    tentukanGrade(mhs);

    daftar.push_back(mhs);
    
    std::cout << "Data Mahasiswa Berhasil Ditambahkan!\n";
}

void hitungNilaiAkhir(Mahasiswa& mhs) {
    // Menghitung nilai akhir dengan bobot
    mhs.NilaiAkhir = (0.1 * mhs.NilaiAbsen) + (0.2 * mhs.NilaiTugas) + (0.3 * mhs.NilaiUTS) + (0.4 * mhs.NilaiUAS);
}

void tentukanGrade(Mahasiswa& mhs) {
    if (mhs.NilaiAkhir >= 85) {
        mhs.Grade = 'A';
    } else if (mhs.NilaiAkhir >= 70) {
        mhs.Grade = 'B';
    } else if (mhs.NilaiAkhir >= 55) {
        mhs.Grade = 'C';
    } else if (mhs.NilaiAkhir >= 40) {
        mhs.Grade = 'D';
    } else {
        mhs.Grade = 'E';
    }
}

void tampilkanMahasiswa(const std::vector<Mahasiswa>& daftar) {
    if (daftar.empty()) {
        std::cout << "Tidak ada data mahasiswa.\n";
        return;
    }

    std::cout << "\nDaftar Mahasiswa:\n";
    for (const auto& mhs : daftar) {
        std::cout << "NIM: " << mhs.NIM 
                  << ", Nama: " << mhs.Nama 
                  << ", Nilai Akhir: " << std::fixed << std::setprecision(2) 
                  << mhs.NilaiAkhir 
                  << ", Grade: " << mhs.Grade 
                  << "\n";
    }
}

void cariMahasiswa(const std::vector<Mahasiswa>& daftar, const std::string& nim) {
    for (const auto& mhs : daftar) {
        if (mhs.NIM == nim) {
            std::cout << "\nData Mahasiswa Ditemukan:\n"
                      << "NIM: " << mhs.NIM 
                      << ", Nama: " << mhs.Nama 
                      << ", Nilai Akhir: " << std::fixed << std::setprecision(2)
                      << mhs.NilaiAkhir 
                      << ", Grade: " << mhs.Grade 
                      << "\n";
            return;
        }
    }
    
    std::cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}
