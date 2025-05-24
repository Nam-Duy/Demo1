#include "ThanhToan.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <ctime>

ThanhToan::ThanhToan() : phuongThuc(""), ngayThanhToan(""), soTien(0.0), trangThai("Chua thanh toan"), donHangLienQuan(nullptr), khachHangTT(nullptr), nhanVienTT(nullptr) {}

ThanhToan::ThanhToan(std::string pt, std::string ngay, double tien, std::string tt)
    : phuongThuc(pt), ngayThanhToan(ngay), soTien(tien), trangThai(tt), donHangLienQuan(nullptr), khachHangTT(nullptr), nhanVienTT(nullptr) {}

void ThanhToan::nhap(const std::vector<DonHang*>& allDonHangs, KhachHang* khachHangDefault, NhanVien* nhanVienDefault) {
    system("cls");
    std::cout << "--- Nhap Thong Tin Thanh Toan ---\n";

    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    ngayThanhToan = buffer;
    std::cout << "Ngay Thanh Toan (tu dong): " << ngayThanhToan << "\n";

    if (khachHangDefault) {
        khachHangTT = khachHangDefault;
        std::cout << "Khach hang mac dinh: ";
        khachHangDefault->xuat(std::cout);
        std::cout << "\n";
    }

    if (nhanVienDefault) {
        nhanVienTT = nhanVienDefault;
        std::cout << "Nhan vien mac dinh: ";
        nhanVienDefault->xuat(std::cout);
        std::cout << "\n";
    }

    if (donHangLienQuan) {
        soTien = donHangLienQuan->tinhTongTien();
        std::cout << "So tien thanh toan (theo don hang): " << std::fixed << std::setprecision(0) << soTien << "\n";
    } else {
        std::cout << "Nhap so tien thanh toan: ";
        if (!(std::cin >> soTien) || soTien < 0) {
            std::cout << "So tien khong hop le.\n";
            soTien = 0.0;
            std::cin.clear();
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Nhap Phuong Thuc Thanh Toan (Tien mat/Chuyen khoan/The): ";
    std::getline(std::cin, phuongThuc);
    if (phuongThuc.empty()) phuongThuc = "Tien mat";

    std::cout << "Nhap Trang Thai Thanh Toan (Chua thanh toan/Da thanh toan/Huy): ";
    std::getline(std::cin, trangThai);
    if (trangThai.empty()) trangThai = "Chua thanh toan";
}

void ThanhToan::xuat(std::ostream& os) const {
    os << "Ngay: " << ngayThanhToan
       << ", PT: " << phuongThuc
       << ", So Tien: " << std::fixed << std::setprecision(0) << soTien
       << ", Trang thai: " << trangThai;
    if (donHangLienQuan) {
        os << ", DH Lien Quan: " << donHangLienQuan->getMaDon();
    }
    if (khachHangTT) {
        os << ", KH: " << khachHangTT->getTen();
    }
    if (nhanVienTT) {
        os << ", NV: " << nhanVienTT->getTen();
    }
}

void ThanhToan::danhDauThanhToan(std::string trangThaiMoi) {
    trangThai = trangThaiMoi;
    std::cout << "Da cap nhat trang thai thanh toan: " << trangThaiMoi << "\n";
}

double ThanhToan::tinhToanSoTienThanhToan() {
    if (donHangLienQuan) {
        soTien = donHangLienQuan->tinhTongTien();
    }
    return soTien;
}

ThanhToan ThanhToan::operator+(const ThanhToan& other) const {
    ThanhToan result = *this;
    result.soTien += other.soTien;
    return result;
}

std::string ThanhToan::getMaDonHangLienQuan() const {
    return donHangLienQuan ? donHangLienQuan->getMaDon() : "";
}

std::string ThanhToan::getTrangThai() const {
    return trangThai;
}

double ThanhToan::getSoTien() const {
    return soTien;
}

std::string ThanhToan::getNgayThanhToan() const {
    return ngayThanhToan;
}

std::string ThanhToan::getPhuongThuc() const {
    return phuongThuc;
}

void ThanhToan::setDonHangLienQuan(DonHang* dh) {
    donHangLienQuan = dh;
}

void ThanhToan::setKhachHangTT(KhachHang* kh) {
    khachHangTT = kh;
}

void ThanhToan::setNhanVienTT(NhanVien* nv) {
    nhanVienTT = nv;
}

void ThanhToan::setSoTien(double tien) {
    soTien = tien;
}