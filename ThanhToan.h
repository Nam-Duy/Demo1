#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DonHang.h"
#include "KhachHang.h"
#include "NhanVien.h"

class ThanhToan {
private:
    std::string phuongThuc;
    std::string ngayThanhToan;
    double soTien;
    std::string trangThai;
    DonHang* donHangLienQuan;
    KhachHang* khachHangTT;
    NhanVien* nhanVienTT;

public:
    ThanhToan();
    ThanhToan(std::string pt, std::string ngay, double tien, std::string tt);

    void nhap(const std::vector<DonHang*>& allDonHangs, KhachHang* khachHangDefault = nullptr, NhanVien* nhanVienDefault = nullptr);
    void xuat(std::ostream& os) const;
    void danhDauThanhToan(std::string trangThaiMoi);
    double tinhToanSoTienThanhToan();

    ThanhToan operator+(const ThanhToan& other) const;

    std::string getMaDonHangLienQuan() const;
    std::string getTrangThai() const;
    double getSoTien() const;
    std::string getNgayThanhToan() const;
    std::string getPhuongThuc() const;

    void setDonHangLienQuan(DonHang* dh);
    void setKhachHangTT(KhachHang* kh);
    void setNhanVienTT(NhanVien* nv);
    void setSoTien(double tien);
};