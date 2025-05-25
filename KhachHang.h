#pragma once
#include "Nguoi.h"
#include <string>

class KhachHang : public Nguoi {
private:
    std::string loaiKhachHang;
public:
    KhachHang();
    KhachHang(std::string ma, std::string ten, std::string diaChi, std::string loai);

    void nhap() override;
    void xuat(std::ostream& os) const override;
    void capNhatThongTin();

    std::string getLoaiKhachHang() const;
};
