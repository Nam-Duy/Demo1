#include "DonHang.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

DonHang::DonHang() : maDon(""), khachHang(nullptr), nhanVienXuLy(nullptr), tongTien(0.0) {}

DonHang::DonHang(std::string ma) : maDon(ma), khachHang(nullptr), nhanVienXuLy(nullptr), tongTien(0.0) {}

void DonHang::themSanPham(SanPham* sp, int soLuong) {
    if (sp == nullptr || soLuong <= 0) {
        std::cout << "San pham khong hop le hoac so luong <= 0.\n";
        return;
    }
    for (auto& item : danhSachSanPham) {
        if (*item.first == *sp) {
            item.second += soLuong;
            std::cout << "Cap nhat so luong san pham " << sp->getTenSP() << " thanh " << item.second << "\n";
            return; // Defer tinhTongTien to taoDonHang
        }
    }
    danhSachSanPham.push_back({sp, soLuong});
    std::cout << "Da them san pham " << sp->getTenSP() << " voi so luong " << soLuong << "\n";
}

void DonHang::suaSoLuongSanPham(std::string maSP, int soLuongMoi) {
    if (soLuongMoi < 0) {
        std::cout << "So luong moi khong the la so am.\n";
        return;
    }
    bool found = false;
    for (auto& item : danhSachSanPham) {
        if (item.first->getMaSP() == maSP) {
            if (soLuongMoi == 0) {
                xoaSanPham(maSP);
                std::cout << "Da xoa san pham " << item.first->getTenSP() << " vi so luong la 0.\n";
            } else {
                item.second = soLuongMoi;
                std::cout << "Da cap nhat so luong san pham " << item.first->getTenSP() << " thanh " << soLuongMoi << ".\n";
            }
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Khong tim thay san pham voi ma " << maSP << " trong don hang.\n";
    }
}

void DonHang::xoaSanPham(std::string maSP) {
    auto it = std::remove_if(danhSachSanPham.begin(), danhSachSanPham.end(),
                             [&maSP](const std::pair<SanPham*, int>& item) {
                                 return item.first->getMaSP() == maSP;
                             });
    if (it != danhSachSanPham.end()) {
        danhSachSanPham.erase(it, danhSachSanPham.end());
        std::cout << "Da xoa san pham voi ma " << maSP << " khoi don hang.\n";
    } else {
        std::cout << "Khong tim thay san pham voi ma " << maSP << " trong don hang.\n";
    }
}

void DonHang::setKhachHang(KhachHang* kh) {
    this->khachHang = kh;
}

void DonHang::setNhanVienXuLy(NhanVien* nv) {
    this->nhanVienXuLy = nv;
}

double DonHang::tinhTongTien() {
    tongTien = 0.0;
    for (const auto& item : danhSachSanPham) {
        double gia = item.first->tinhGia();
        int sl = item.second;
        double thanhTien = gia * sl;
        tongTien += thanhTien;
        std::cout << "Debug: SP " << item.first->getTenSP() << ", Don Gia: " << gia 
                  << ", So Luong: " << sl << ", Thanh Tien: " << thanhTien << "\n";
    }
    std::cout << "Debug: Tong Tien = " << tongTien << "\n";
    return tongTien;
}

void DonHang::xuatHoaDon(std::ostream& os) const {
    os << "-------------------- HOA DON --------------------\n";
    os << "Ma Don Hang: " << maDon << "\n";
    if (khachHang) {
        os << "Khach Hang: " << khachHang->getTen() << " (Ma: " << khachHang->getMa() << ")\n";
    } else {
        os << "Khach Hang: Khong co thong tin\n";
    }
    if (nhanVienXuLy) {
        os << "Nhan Vien Xu Ly: " << nhanVienXuLy->getTen() << " (Ma: " << nhanVienXuLy->getMa() << ")\n";
    } else {
        os << "Nhan Vien Xu Ly: Khong co thong tin\n";
    }
    os << "-------------------------------------------------\n";
    os << std::left << std::setw(20) << "Ten San Pham"
       << std::right << std::setw(10) << "So Luong"
       << std::right << std::setw(15) << "Don Gia"
       << std::right << std::setw(15) << "Thanh Tien" << "\n";
    os << "-------------------------------------------------\n";
    for (const auto& item : danhSachSanPham) {
        os << std::left << std::setw(20) << item.first->getTenSP()
           << std::right << std::setw(10) << item.second
           << std::right << std::setw(15) << std::fixed << std::setprecision(0) << item.first->getDonGia()
           << std::right << std::setw(15) << std::fixed << std::setprecision(0) << (item.first->getDonGia() * item.second) << "\n";
    }
    os << "-------------------------------------------------\n";
    os << std::right << std::setw(45) << "TONG TIEN: "
       << std::right << std::setw(15) << std::fixed << std::setprecision(0) << tongTien << "\n";
    os << "-------------------------------------------------\n";
}

std::string DonHang::getMaDon() const {
    return maDon;
}

double DonHang::getTongTien() const {
    return tongTien;
}

const std::vector<std::pair<SanPham*, int>>& DonHang::getDanhSachSanPham() const {
    return danhSachSanPham;
}

KhachHang* DonHang::getKhachHang() const {
    return khachHang;
}

NhanVien* DonHang::getNhanVienXuLy() const {
    return nhanVienXuLy;
}