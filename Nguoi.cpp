#include "Nguoi.h"
#include <iostream>
#include <limits>

Nguoi::Nguoi() : ma(""), ten(""), diaChi("") {}

Nguoi::Nguoi(std::string ma, std::string ten, std::string diaChi)
    : ma(ma), ten(ten), diaChi(diaChi) {}

void Nguoi::nhap() {
    std::cout << "Nhap Ma: ";
    std::getline(std::cin, ma);
    std::cout << "Nhap Ten: ";
    std::getline(std::cin, ten);
    std::cout << "Nhap Dia chi: ";
    std::getline(std::cin, diaChi);
}

void Nguoi::xuat(std::ostream& os) const {
    os << "Ma: " << ma << ", Ten: " << ten << ", Dia chi: " << diaChi;
}

std::string Nguoi::getMa() const {
    return ma;
}

std::string Nguoi::getTen() const {
    return ten;
}

std::string Nguoi::getDiaChi() const {
    return diaChi;
}

Nguoi::~Nguoi() {}