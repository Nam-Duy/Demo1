#pragma once
#include <vector>
#include <string>
#include <algorithm> // For std::remove_if
#include "SanPham.h"
#include "KhachHang.h"
#include "NhanVien.h"
#include "DonHang.h"
#include "ThanhToan.h"

class QuanLy {
private:
    std::vector<SanPham*> dsSanPham;
    std::vector<KhachHang*> dsKhachHang;
    std::vector<NhanVien*> dsNhanVien;
    std::vector<DonHang*> dsDonHang;
    std::vector<ThanhToan*> dsThanhToan;

    // Hàm template để tìm kiếm đối tượng theo mã
    template <typename U>
    U* timTheoMa(const std::vector<U*>& danhSach, const std::string& ma);

public:
    QuanLy();
    ~QuanLy(); // Destructor để giải phóng bộ nhớ

    // Quản lý Sản Phẩm
    void nhapSanPham();
    void hienThiDanhSachSanPham() const;
    void capNhatSanPham();
    void xoaSanPham();

    // Quản lý Khách Hàng
    void nhapKhachHang();
    void hienThiDanhSachKhachHang() const;
    void capNhatKhachHang();
    void xoaKhachHang();

    // Quản lý Nhân Viên
    void nhapNhanVien();
    void hienThiDanhSachNhanVien() const;
    void capNhatNhanVien();
    void xoaNhanVien();

    // Quản lý Đơn Hàng
    void taoDonHang();
    void hienThiDanhSachDonHang() const;
    void suaDonHang();
    void xoaDonHang();

    // Quản lý Thanh Toán
    void taoThanhToan();
    void hienThiDanhSachThanhToan() const;
    void hienThiDonHangChuaThanhToan() const;
    void danhDauDonHangDaThanhToan();

private:
    // Helper function for input validation
    bool isValidString(const std::string& str) const;
    bool isValidNumber(double num, double min = 0.0) const;
};