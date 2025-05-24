#include "SanPham.h"
#include <iostream>
#include <limits>
#include <iomanip> // Added for std::setprecision

SanPham::SanPham() : maSP(""), tenSP(""), donGia(0.0) {}

SanPham::SanPham(std::string ma, std::string ten, double gia)
    : maSP(ma), tenSP(ten), donGia(gia) {}

void SanPham::nhap() {
    std::cout << "Nhap Ma San Pham: ";
    std::getline(std::cin, maSP);
    std::cout << "Nhap Ten San Pham: ";
    std::getline(std::cin, tenSP);
    std::cout << "Nhap Don Gia: ";
    std::cin >> donGia;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void SanPham::xuat(std::ostream& os) const {
    os << "Ma SP: " << maSP << ", Ten SP: " << tenSP << ", Don Gia: " << std::fixed << std::setprecision(0) << donGia;
}

double SanPham::tinhGia() const {
    return donGia;
}

bool SanPham::operator>(const SanPham& other) const {
    return donGia > other.donGia;
}

bool SanPham::operator<(const SanPham& other) const {
    return donGia < other.donGia;
}

bool SanPham::operator==(const SanPham& other) const {
    return maSP == other.maSP;
}

std::string SanPham::getMaSP() const {
    return maSP;
}

std::string SanPham::getTenSP() const {
    return tenSP;
}

double SanPham::getDonGia() const {
    return donGia;
}

void SanPham::setDonGia(double gia) {
    donGia = gia;
}

void SanPham::setTenSP(const std::string& ten) {
    tenSP = ten;
}