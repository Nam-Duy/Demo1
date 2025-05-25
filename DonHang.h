#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "SanPham.h"
#include "KhachHang.h"
#include "NhanVien.h"

class DonHang {
private:
    std::string maDon;
    std::vector<std::pair<SanPham*, int>> danhSachSanPham;
    KhachHang* khachHang;
    NhanVien* nhanVienXuLy;
    double tongTien;

public:
    DonHang();
    DonHang(std::string ma);

    void themSanPham(SanPham* sp, int soLuong);
    void suaSoLuongSanPham(std::string maSP, int soLuongMoi);
    void xoaSanPham(std::string maSP);

    void setKhachHang(KhachHang* kh);
    void setNhanVienXuLy(NhanVien* nv);

    double tinhTongTien();
    void xuatHoaDon(std::ostream& os) const;

    std::string getMaDon() const;
    double getTongTien() const;
    const std::vector<std::pair<SanPham*, int>>& getDanhSachSanPham() const;
    KhachHang* getKhachHang() const;
    NhanVien* getNhanVienXuLy() const;
};
