#pragma once
#include <iostream>
#include <string>

class Nguoi {
protected:
    std::string ma;
    std::string ten;
    std::string diaChi;
public:
    Nguoi();
    Nguoi(std::string ma, std::string ten, std::string diaChi);
    virtual void nhap();
    virtual void xuat(std::ostream& os) const;
    std::string getMa() const;
    std::string getTen() const;
    std::string getDiaChi() const;
    virtual ~Nguoi();
};