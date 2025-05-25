#include "NhanVien.h"
#include <iostream>
#include <limits>
#include <cstdlib>

NhanVien::NhanVien() : Nguoi(), chucVu("") {}

NhanVien::NhanVien(std::string ma, std::string ten, std::string diaChi, std::string chucVu)
    : Nguoi(ma, ten, diaChi), chucVu(chucVu) {}

void NhanVien::nhap() {
    Nguoi::nhap();
    std::cout << "Nhap Chuc Vu: ";
    std::getline(std::cin, chucVu);
}

void NhanVien::xuat(std::ostream& os) const {
    Nguoi::xuat(os);
    os << ", Chuc Vu: " << chucVu;
}

void NhanVien::capNhatThongTin() {
    system("cls");
    int chon;
    do {
        std::cout << "Cap nhat thong tin Nhan Vien:\n";
        std::cout << "1. Cap nhat Ten\n";
        std::cout << "2. Cap nhat Dia chi\n";
        std::cout << "3. Cap nhat Chuc vu\n";
        std::cout << "0. Quay lai\n";
        std::cout << "Chon: ";
        if (!(std::cin >> chon)) {
            std::cout << "Lua chon khong hop le.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            system("cls");
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (chon) {
            case 1: {
                std::string tenMoi;
                std::cout << "Nhap Ten moi: ";
                std::getline(std::cin, tenMoi);
                if (!tenMoi.empty()) {
                    ten = tenMoi;
                    std::cout << "Da cap nhat Ten.\n";
                } else {
                    std::cout << "Ten khong hop le.\n";
                }
                break;
            }
            case 2: {
                std::string diaChiMoi;
                std::cout << "Nhap Dia chi moi: ";
                std::getline(std::cin, diaChiMoi);
                if (!diaChiMoi.empty()) {
                    diaChi = diaChiMoi;
                    std::cout << "Da cap nhat Dia chi.\n";
                } else {
                    std::cout << "Dia chi khong hop le.\n";
                }
                break;
            }
            case 3: {
                std::string chucVuMoi;
                std::cout << "Nhap Chuc vu moi: ";
                std::getline(std::cin, chucVuMoi);
                if (!chucVuMoi.empty()) {
                    chucVu = chucVuMoi;
                    std::cout << "Da cap nhat Chuc vu.\n";
                } else {
                    std::cout << "Chuc vu khong hop le.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                std::cout << "Lua chon khong hop le.\n";
                break;
        }
        if (chon != 0) {
            system("pause");
            system("cls");
        }
    } while (chon != 0);
}

void NhanVien::ghiNhanDonHang() {
    std::cout << "Nhan vien " << ten << " da ghi nhan mot don hang.\n";
}

std::string NhanVien::getChucVu() const {
    return chucVu;
}

void NhanVien::setChucVu(const std::string& cv) {
    chucVu = cv;
}
