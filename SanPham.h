#pragma once
#include <iostream>
#include <string>

class SanPham {
private:
    std::string maSP;
    std::string tenSP;
    double donGia;
public:
    SanPham();
    SanPham(std::string ma, std::string ten, double gia);

    void nhap();
    void xuat(std::ostream& os) const;
    double tinhGia() const;

    bool operator>(const SanPham& other) const;
    bool operator<(const SanPham& other) const;
    bool operator==(const SanPham& other) const;

    std::string getMaSP() const;
    std::string getTenSP() const;
    double getDonGia() const;

    void setDonGia(double gia);
    void setTenSP(const std::string& ten);
};