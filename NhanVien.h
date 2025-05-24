#pragma once
#include "Nguoi.h"
#include <string>

class NhanVien : public Nguoi {
private:
    std::string chucVu;
public:
    NhanVien();
    NhanVien(std::string ma, std::string ten, std::string diaChi, std::string chucVu);

    void nhap() override;
    void xuat(std::ostream& os) const override;
    void capNhatThongTin();
    void ghiNhanDonHang();

    std::string getChucVu() const;
    void setChucVu(const std::string& cv);
};