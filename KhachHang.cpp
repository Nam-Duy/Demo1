#include "KhachHang.h"
#include <iostream>
#include <limits>
#include <cstdlib>

KhachHang::KhachHang() : Nguoi(), loaiKhachHang("Thuong") {}

KhachHang::KhachHang(std::string ma, std::string ten, std::string diaChi, std::string loai)
    : Nguoi(ma, ten, diaChi), loaiKhachHang(loai) {}

void KhachHang::nhap() {
    Nguoi::nhap();
    std::cout << "Nhap Loai Khach Hang (VIP/Thuong): ";
    std::getline(std::cin, loaiKhachHang);
}

void KhachHang::xuat(std::ostream& os) const {
    Nguoi::xuat(os);
    os << ", Loai KH: " << loaiKhachHang;
}

void KhachHang::capNhatThongTin() {
    system("cls");
    int chon;
    do {
        std::cout << "Cap nhat thong tin Khach Hang:\n";
        std::cout << "1. Cap nhat Ten\n";
        std::cout << "2. Cap nhat Dia chi\n";
        std::cout << "3. Cap nhat Loai Khach Hang\n";
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
                std::string loaiMoi;
                std::cout << "Nhap Loai Khach Hang moi (VIP/Thuong): ";
                std::getline(std::cin, loaiMoi);
                if (!loaiMoi.empty()) {
                    loaiKhachHang = loaiMoi;
                    std::cout << "Da cap nhat Loai Khach Hang.\n";
                } else {
                    std::cout << "Loai Khach Hang khong hop le.\n";
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

std::string KhachHang::getLoaiKhachHang() const {
    return loaiKhachHang;
}
