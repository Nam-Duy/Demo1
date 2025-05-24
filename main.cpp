#include <iostream>
#include <limits>
#include <cstdlib>
#include "QuanLy.h"

int main() {
    QuanLy quanLyHeThong;
    int chon;

    do {
        system("cls");
        std::cout << "---------- HE THONG QUAN LY DON HANG ----------\n";
        std::cout << "1. Quan ly San Pham\n";
        std::cout << "2. Quan ly Khach Hang\n";
        std::cout << "3. Quan ly Nhan Vien\n";
        std::cout << "4. Quan ly Don Hang\n";
        std::cout << "5. Quan ly Thanh Toan\n";
        std::cout << "0. Thoat chuong trinh\n";
        std::cout << "------------------------------------------------\n";
        std::cout << "Moi ban chon menu: ";
        if (!(std::cin >> chon)) {
            std::cout << "Lua chon khong hop le.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (chon) {
            case 1: {
                int subChon;
                do {
                    system("cls");
                    std::cout << "--- QUAN LY SAN PHAM ---\n";
                    std::cout << "1. Nhap San Pham moi\n";
                    std::cout << "2. Hien thi danh sach San Pham\n";
                    std::cout << "3. Cap nhat San Pham\n";
                    std::cout << "4. Xoa San Pham\n";
                    std::cout << "0. Tro ve menu chinh\n";
                    std::cout << "Chon: ";
                    if (!(std::cin >> subChon)) {
                        std::cout << "Lua chon khong hop le.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("pause");
                        continue;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (subChon) {
                        case 1: quanLyHeThong.nhapSanPham(); break;
                        case 2: quanLyHeThong.hienThiDanhSachSanPham(); break;
                        case 3: quanLyHeThong.capNhatSanPham(); break;
                        case 4: quanLyHeThong.xoaSanPham(); break;
                        case 0: break;
                        default: std::cout << "Lua chon khong hop le.\n"; system("pause"); break;
                    }
                } while (subChon != 0);
                break;
            }
            case 2: {
                int subChon;
                do {
                    system("cls");
                    std::cout << "--- QUAN LY KHACH HANG ---\n";
                    std::cout << "1. Nhap Khach Hang moi\n";
                    std::cout << "2. Hien thi danh sach Khach Hang\n";
                    std::cout << "3. Cap nhat Khach Hang\n";
                    std::cout << "4. Xoa Khach Hang\n";
                    std::cout << "0. Tro ve menu chinh\n";
                    std::cout << "Chon: ";
                    if (!(std::cin >> subChon)) {
                        std::cout << "Lua chon khong hop le.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("pause");
                        continue;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (subChon) {
                        case 1: quanLyHeThong.nhapKhachHang(); break;
                        case 2: quanLyHeThong.hienThiDanhSachKhachHang(); break;
                        case 3: quanLyHeThong.capNhatKhachHang(); break;
                        case 4: quanLyHeThong.xoaKhachHang(); break;
                        case 0: break;
                        default: std::cout << "Lua chon khong hop le.\n"; system("pause"); break;
                    }
                } while (subChon != 0);
                break;
            }
            case 3: {
                int subChon;
                do {
                    system("cls");
                    std::cout << "--- QUAN LY NHAN VIEN ---\n";
                    std::cout << "1. Nhap Nhan Vien moi\n";
                    std::cout << "2. Hien thi danh sach Nhan Vien\n";
                    std::cout << "3. Cap nhat Nhan Vien\n";
                    std::cout << "4. Xoa Nhan Vien\n";
                    std::cout << "0. Tro ve menu chinh\n";
                    std::cout << "Chon: ";
                    if (!(std::cin >> subChon)) {
                        std::cout << "Lua chon khong hop le.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("pause");
                        continue;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (subChon) {
                        case 1: quanLyHeThong.nhapNhanVien(); break;
                        case 2: quanLyHeThong.hienThiDanhSachNhanVien(); break;
                        case 3: quanLyHeThong.capNhatNhanVien(); break;
                        case 4: quanLyHeThong.xoaNhanVien(); break;
                        case 0: break;
                        default: std::cout << "Lua chon khong hop le.\n"; system("pause"); break;
                    }
                } while (subChon != 0);
                break;
            }
            case 4: {
                int subChon;
                do {
                    system("cls");
                    std::cout << "--- QUAN LY DON HANG ---\n";
                    std::cout << "1. Tao Don Hang moi\n";
                    std::cout << "2. Hien thi danh sach Don Hang\n";
                    std::cout << "3. Sua Don Hang\n";
                    std::cout << "4. Xoa Don Hang\n";
                    std::cout << "0. Tro ve menu chinh\n";
                    std::cout << "Chon: ";
                    if (!(std::cin >> subChon)) {
                        std::cout << "Lua chon khong hop le.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("pause");
                        continue;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (subChon) {
                        case 1: quanLyHeThong.taoDonHang(); break;
                        case 2: quanLyHeThong.hienThiDanhSachDonHang(); break;
                        case 3: quanLyHeThong.suaDonHang(); break;
                        case 4: quanLyHeThong.xoaDonHang(); break;
                        case 0: break;
                        default: std::cout << "Lua chon khong hop le.\n"; system("pause"); break;
                    }
                } while (subChon != 0);
                break;
            }
            case 5: {
                int subChon;
                do {
                    system("cls");
                    std::cout << "--- QUAN LY THANH TOAN ---\n";
                    std::cout << "1. Tao Thanh Toan moi\n";
                    std::cout << "2. Hien thi danh sach Thanh Toan\n";
                    std::cout << "3. Hien thi Don Hang chua thanh toan\n";
                    std::cout << "4. Danh dau Don Hang da thanh toan\n";
                    std::cout << "0. Tro ve menu chinh\n";
                    std::cout << "Chon: ";
                    if (!(std::cin >> subChon)) {
                        std::cout << "Lua chon khong hop le.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("pause");
                        continue;
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    switch (subChon) {
                        case 1: quanLyHeThong.taoThanhToan(); break;
                        case 2: quanLyHeThong.hienThiDanhSachThanhToan(); break;
                        case 3: quanLyHeThong.hienThiDonHangChuaThanhToan(); break;
                        case 4: quanLyHeThong.danhDauDonHangDaThanhToan(); break;
                        case 0: break;
                        default: std::cout << "Lua chon khong hop le.\n"; system("pause"); break;
                    }
                } while (subChon != 0);
                break;
            }
            case 0:
                std::cout << "Tam biet!\n";
                system("pause");
                break;
            default:
                std::cout << "Lua chon khong hop le.\n";
                system("pause");
                break;
        }
    } while (chon != 0);

    return 0;
}