#include "QuanLy.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

// Helper function implementations
bool QuanLy::isValidString(const std::string& str) const {
    return !str.empty() && str.find_first_not_of(" \t\n") != std::string::npos;
}

bool QuanLy::isValidNumber(double num, double min) const {
    return num >= min;
}

// Template function for generic types with getMa()
template <typename U>
U* QuanLy::timTheoMa(const std::vector<U*>& danhSach, const std::string& ma) {
    for (U* item : danhSach) {
        if (item->getMa() == ma) {
            return item;
        }
    }
    return nullptr;
}

// Specialization for SanPham (uses getMaSP)
template <>
SanPham* QuanLy::timTheoMa<SanPham>(const std::vector<SanPham*>& danhSach, const std::string& ma) {
    for (SanPham* item : danhSach) {
        if (item->getMaSP() == ma) {
            return item;
        }
    }
    return nullptr;
}

// Specialization for DonHang (uses getMaDon)
template <>
DonHang* QuanLy::timTheoMa<DonHang>(const std::vector<DonHang*>& danhSach, const std::string& ma) {
    for (DonHang* item : danhSach) {
        if (item->getMaDon() == ma) {
            return item;
        }
    }
    return nullptr;
}

QuanLy::QuanLy() {}

QuanLy::~QuanLy() {
    for (auto* sp : dsSanPham) delete sp;
    dsSanPham.clear();
    for (auto* kh : dsKhachHang) delete kh;
    dsKhachHang.clear();
    for (auto* nv : dsNhanVien) delete nv;
    dsNhanVien.clear();
    for (auto* dh : dsDonHang) delete dh;
    dsDonHang.clear();
    for (auto* tt : dsThanhToan) delete tt;
    dsThanhToan.clear();
}

// --- Quản lý Sản Phẩm ---
void QuanLy::nhapSanPham() {
    system("cls");
    std::cout << "--- Nhap San Pham Moi ---\n";
    SanPham* sp = new SanPham();
    sp->nhap();
    if (!isValidString(sp->getMaSP()) || !isValidString(sp->getTenSP()) || !isValidNumber(sp->getDonGia())) {
        std::cout << "Du lieu san pham khong hop le.\n";
        delete sp;
    } else if (timTheoMa(dsSanPham, sp->getMaSP()) != nullptr) {
        std::cout << "Ma San Pham da ton tai. Vui long nhap lai.\n";
        delete sp;
    } else {
        dsSanPham.push_back(sp);
        std::cout << "Da them san pham moi.\n";
    }
    system("pause");
}

void QuanLy::hienThiDanhSachSanPham() const {
    system("cls");
    std::cout << "--- Danh Sach San Pham ---\n";
    if (dsSanPham.empty()) {
        std::cout << "Chua co san pham nao.\n";
    } else {
        for (const auto* sp : dsSanPham) {
            sp->xuat(std::cout);
            std::cout << "\n";
        }
    }
    system("pause");
}

void QuanLy::capNhatSanPham() {
    system("cls");
    std::cout << "--- Cap Nhat San Pham ---\n";
    std::string maSPCanCapNhat;
    std::cout << "Nhap Ma San Pham can cap nhat: ";
    std::getline(std::cin, maSPCanCapNhat);

    if (!isValidString(maSPCanCapNhat)) {
        std::cout << "Ma San Pham khong hop le.\n";
        system("pause");
        return;
    }

    SanPham* spCanCapNhat = timTheoMa(dsSanPham, maSPCanCapNhat);
    if (spCanCapNhat) {
        int chon;
        do {
            system("cls");
            std::cout << "Cap nhat thong tin San Pham " << spCanCapNhat->getMaSP() << ":\n";
            std::cout << "1. Cap nhat Ten San Pham\n";
            std::cout << "2. Cap nhat Don Gia\n";
            std::cout << "0. Quay lai\n";
            std::cout << "Chon: ";
            std::cin >> chon;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (chon) {
                case 1: {
                    std::string tenMoi;
                    std::cout << "Nhap Ten San Pham moi: ";
                    std::getline(std::cin, tenMoi);
                    if (isValidString(tenMoi)) {
                        spCanCapNhat->setTenSP(tenMoi);
                        std::cout << "Cap nhat Ten San Pham thanh cong!\n";
                    } else {
                        std::cout << "Ten San Pham khong hop le.\n";
                    }
                    break;
                }
                case 2: {
                    double giaMoi;
                    std::cout << "Nhap Don Gia moi: ";
                    if (std::cin >> giaMoi && isValidNumber(giaMoi)) {
                        spCanCapNhat->setDonGia(giaMoi);
                        std::cout << "Cap nhat Don Gia thanh cong!\n";
                    } else {
                        std::cout << "Don Gia khong hop le.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 0:
                    break;
                default:
                    std::cout << "Lua chon khong hop le.\n";
                    break;
            }
            system("pause");
        } while (chon != 0);
    } else {
        std::cout << "Khong tim thay San Pham voi ma " << maSPCanCapNhat << ".\n";
        system("pause");
    }
}

void QuanLy::xoaSanPham() {
    system("cls");
    std::cout << "--- Xoa San Pham ---\n";
    std::string maSPCanXoa;
    std::cout << "Nhap Ma San Pham can xoa: ";
    std::getline(std::cin, maSPCanXoa);

    if (!isValidString(maSPCanXoa)) {
        std::cout << "Ma San Pham khong hop le.\n";
        system("pause");
        return;
    }

    auto it = dsSanPham.begin();
    bool found = false;
    while (it != dsSanPham.end()) {
        if ((*it)->getMaSP() == maSPCanXoa) {
            delete *it;
            it = dsSanPham.erase(it);
            std::cout << "Da xoa san pham " << maSPCanXoa << ".\n";
            found = true;
            break;
        } else {
            ++it;
        }
    }

    if (!found) {
        std::cout << "Khong tim thay San Pham voi ma " << maSPCanXoa << ".\n";
    }
    system("pause");
}

// --- Quản lý Khách Hàng ---
void QuanLy::nhapKhachHang() {
    system("cls");
    std::cout << "--- Nhap Khach Hang Moi ---\n";
    KhachHang* kh = new KhachHang();
    kh->nhap();
    if (!isValidString(kh->getMa())) {
        std::cout << "Ma Khach Hang khong hop le.\n";
        delete kh;
    } else if (timTheoMa(dsKhachHang, kh->getMa()) != nullptr) {
        std::cout << "Ma Khach Hang da ton tai. Vui long nhap lai.\n";
        delete kh;
    } else {
        dsKhachHang.push_back(kh);
        std::cout << "Da them khach hang moi.\n";
    }
    system("pause");
}

void QuanLy::hienThiDanhSachKhachHang() const {
    system("cls");
    std::cout << "--- Danh Sach Khach Hang ---\n";
    if (dsKhachHang.empty()) {
        std::cout << "Chua co khach hang nao.\n";
    } else {
        for (const auto* kh : dsKhachHang) {
            kh->xuat(std::cout);
            std::cout << "\n";
        }
    }
    system("pause");
}

void QuanLy::capNhatKhachHang() {
    system("cls");
    std::cout << "--- Cap Nhat Khach Hang ---\n";
    std::string maKHCanCapNhat;
    std::cout << "Nhap Ma Khach Hang can cap nhat: ";
    std::getline(std::cin, maKHCanCapNhat);

    if (!isValidString(maKHCanCapNhat)) {
        std::cout << "Ma Khach Hang khong hop le.\n";
        system("pause");
        return;
    }

    KhachHang* khTimDuoc = timTheoMa(dsKhachHang, maKHCanCapNhat);
    if (khTimDuoc) {
        khTimDuoc->capNhatThongTin();
        std::cout << "Cap nhat thong tin Khach Hang thanh cong.\n";
    } else {
        std::cout << "Khong tim thay Khach Hang voi ma " << maKHCanCapNhat << ".\n";
    }
    system("pause");
}

void QuanLy::xoaKhachHang() {
    system("cls");
    std::cout << "--- Xoa Khach Hang ---\n";
    std::string maKHCanXoa;
    std::cout << "Nhap Ma Khach Hang can xoa: ";
    std::getline(std::cin, maKHCanXoa);

    if (!isValidString(maKHCanXoa)) {
        std::cout << "Ma Khach Hang khong hop le.\n";
        system("pause");
        return;
    }

    auto it = dsKhachHang.begin();
    bool found = false;
    while (it != dsKhachHang.end()) {
        if ((*it)->getMa() == maKHCanXoa) {
            delete *it;
            it = dsKhachHang.erase(it);
            std::cout << "Da xoa khach hang " << maKHCanXoa << ".\n";
            found = true;
            break;
        } else {
            ++it;
        }
    }

    if (!found) {
        std::cout << "Khong tim thay Khach Hang voi ma " << maKHCanXoa << ".\n";
    }
    system("pause");
}

// --- Quản lý Nhân Viên ---
void QuanLy::nhapNhanVien() {
    system("cls");
    std::cout << "--- Nhap Nhan Vien Moi ---\n";
    NhanVien* nv = new NhanVien();
    nv->nhap();
    if (!isValidString(nv->getMa())) {
        std::cout << "Ma Nhan Vien khong hop le.\n";
        delete nv;
    } else if (timTheoMa(dsNhanVien, nv->getMa()) != nullptr) {
        std::cout << "Ma Nhan Vien da ton tai. Vui long nhap lai.\n";
        delete nv;
    } else {
        dsNhanVien.push_back(nv);
        std::cout << "Da them nhan vien moi.\n";
    }
    system("pause");
}

void QuanLy::hienThiDanhSachNhanVien() const {
    system("cls");
    std::cout << "--- Danh Sach Nhan Vien ---\n";
    if (dsNhanVien.empty()) {
        std::cout << "Chua co nhan vien nao.\n";
    } else {
        for (const auto* nv : dsNhanVien) {
            nv->xuat(std::cout);
            std::cout << "\n";
        }
    }
    system("pause");
}

void QuanLy::capNhatNhanVien() {
    system("cls");
    std::cout << "--- Cap Nhat Nhan Vien ---\n";
    std::string maNVCanCapNhat;
    std::cout << "Nhap Ma Nhan Vien can cap nhat: ";
    std::getline(std::cin, maNVCanCapNhat);

    if (!isValidString(maNVCanCapNhat)) {
        std::cout << "Ma Nhan Vien khong hop le.\n";
        system("pause");
        return;
    }

    NhanVien* nvTimDuoc = timTheoMa(dsNhanVien, maNVCanCapNhat);
    if (nvTimDuoc) {
        nvTimDuoc->capNhatThongTin();
        std::cout << "Cap nhat thong tin Nhan Vien thanh cong.\n";
    } else {
        std::cout << "Khong tim thay Nhan Vien voi ma " << maNVCanCapNhat << ".\n";
    }
    system("pause");
}

void QuanLy::xoaNhanVien() {
    system("cls");
    std::cout << "--- Xoa Nhan Vien ---\n";
    std::string maNVCanXoa;
    std::cout << "Nhap Ma Nhan Vien can xoa: ";
    std::getline(std::cin, maNVCanXoa);

    if (!isValidString(maNVCanXoa)) {
        std::cout << "Ma Nhan Vien khong hop le.\n";
        system("pause");
        return;
    }

    auto it = dsNhanVien.begin();
    bool found = false;
    while (it != dsNhanVien.end()) {
        if ((*it)->getMa() == maNVCanXoa) {
            delete *it;
            it = dsNhanVien.erase(it);
            std::cout << "Da xoa nhan vien " << maNVCanXoa << ".\n";
            found = true;
            break;
        } else {
            ++it;
        }
    }

    if (!found) {
        std::cout << "Khong tim thay Nhan Vien voi ma " << maNVCanXoa << ".\n";
    }
    system("pause");
}

// --- Quản lý Đơn Hàng ---
void QuanLy::taoDonHang() {
    system("cls");
    std::cout << "--- Tao Don Hang Moi ---\n";

    if (dsKhachHang.empty()) {
        std::cout << "Chua co khach hang nao. Vui long nhap khach hang truoc.\n";
        system("pause");
        return;
    }
    if (dsNhanVien.empty()) {
        std::cout << "Chua co nhan vien nao. Vui long nhap nhan vien truoc.\n";
        system("pause");
        return;
    }
    if (dsSanPham.empty()) {
        std::cout << "Chua co san pham nao. Vui long nhap san pham truoc.\n";
        system("pause");
        return;
    }

    std::string maDonHang;
    std::cout << "Nhap Ma Don Hang: ";
    std::getline(std::cin, maDonHang);

    if (!isValidString(maDonHang)) {
        std::cout << "Ma Don Hang khong hop le.\n";
        system("pause");
        return;
    }

    if (timTheoMa(dsDonHang, maDonHang) != nullptr) {
        std::cout << "Ma Don Hang da ton tai. Vui long nhap lai.\n";
        system("pause");
        return;
    }

    DonHang* newDH = new DonHang(maDonHang);

    // Chọn Khách hàng
    std::string maKH;
    KhachHang* khTimDuoc = nullptr;
    do {
        std::cout << "Nhap Ma Khach Hang (0 de huy): ";
        std::getline(std::cin, maKH);
        if (maKH == "0") {
            delete newDH;
            std::cout << "Da huy tao don hang.\n";
            system("pause");
            return;
        }
        if (!isValidString(maKH)) {
            std::cout << "Ma Khach Hang khong hop le.\n";
            hienThiDanhSachKhachHang();
            continue;
        }
        khTimDuoc = timTheoMa(dsKhachHang, maKH);
        if (!khTimDuoc) {
            std::cout << "Khong tim thay Khach Hang voi ma " << maKH << ". Vui long nhap lai.\n";
            hienThiDanhSachKhachHang();
        }
    } while (!khTimDuoc);
    newDH->setKhachHang(khTimDuoc);

    // Chọn Nhân viên
    std::string maNV;
    NhanVien* nvTimDuoc = nullptr;
    do {
        std::cout << "Nhap Ma Nhan Vien xu ly (0 de huy): ";
        std::getline(std::cin, maNV);
        if (maNV == "0") {
            delete newDH;
            std::cout << "Da huy tao don hang.\n";
            system("pause");
            return;
        }
        if (!isValidString(maNV)) {
            std::cout << "Ma Nhan Vien khong hop le.\n";
            hienThiDanhSachNhanVien();
            continue;
        }
        nvTimDuoc = timTheoMa(dsNhanVien, maNV);
        if (!nvTimDuoc) {
            std::cout << "Khong tim thay Nhan Vien voi ma " << maNV << ". Vui long nhap lai.\n";
            hienThiDanhSachNhanVien();
        }
    } while (!nvTimDuoc);
    newDH->setNhanVienXuLy(nvTimDuoc);
    nvTimDuoc->ghiNhanDonHang();

    // Thêm sản phẩm vào đơn hàng
    char themTiep;
    do {
        std::cout << "Them san pham vao don hang:\n";
        hienThiDanhSachSanPham();
        std::string maSPCanThem;
        int soLuong;
        std::cout << "Nhap Ma San Pham can them (0 de ket thuc): ";
        std::getline(std::cin, maSPCanThem);

        if (maSPCanThem == "0") break;

        if (!isValidString(maSPCanThem)) {
            std::cout << "Ma San Pham khong hop le.\n";
            continue;
        }

        SanPham* spTimDuoc = timTheoMa(dsSanPham, maSPCanThem);
        if (spTimDuoc) {
            std::cout << "Nhap so luong cho SP " << spTimDuoc->getTenSP() << ": ";
            if (std::cin >> soLuong && isValidNumber(soLuong, 1)) {
                newDH->themSanPham(spTimDuoc, soLuong);
            } else {
                std::cout << "So luong khong hop le.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } else {
            std::cout << "Khong tim thay san pham voi ma " << maSPCanThem << ".\n";
        }

        std::cout << "Ban co muon them san pham khac? (y/n): ";
        std::cin >> themTiep;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (themTiep == 'y' || themTiep == 'Y');

    // Calculate and display total with debug info
    double total = newDH->tinhTongTien();
    dsDonHang.push_back(newDH);
    std::cout << "Da tao don hang moi voi tong tien: " << std::fixed << std::setprecision(0) << total << ".\n";
    system("pause");
}
void QuanLy::hienThiDanhSachDonHang() const {
    system("cls");
    std::cout << "--- Danh Sach Don Hang ---\n";
    if (dsDonHang.empty()) {
        std::cout << "Chua co don hang nao.\n";
    } else {
        for (const auto* dh : dsDonHang) {
            dh->xuatHoaDon(std::cout);
            std::cout << "\n--------------------\n";
        }
    }
    system("pause");
}

void QuanLy::suaDonHang() {
    system("cls");
    std::cout << "--- Sua Don Hang ---\n";
    std::string maDonCanSua;
    std::cout << "Nhap Ma Don Hang can sua: ";
    std::getline(std::cin, maDonCanSua);

    if (!isValidString(maDonCanSua)) {
        std::cout << "Ma Don Hang khong hop le.\n";
        system("pause");
        return;
    }

    DonHang* dhTimDuoc = timTheoMa(dsDonHang, maDonCanSua);
    if (dhTimDuoc) {
        int chon;
        do {
            system("cls");
            std::cout << "Sua Don Hang " << dhTimDuoc->getMaDon() << ":\n";
            dhTimDuoc->xuatHoaDon(std::cout);
            std::cout << "1. Them san pham\n";
            std::cout << "2. Sua so luong san pham\n";
            std::cout << "3. Xoa san pham\n";
            std::cout << "4. Doi Khach Hang\n";
            std::cout << "5. Doi Nhan Vien xu ly\n";
            std::cout << "0. Quay lai\n";
            std::cout << "Chon: ";
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
                    hienThiDanhSachSanPham();
                    std::string maSP;
                    int soLuong;
                    std::cout << "Nhap Ma San Pham can them: ";
                    std::getline(std::cin, maSP);
                    if (!isValidString(maSP)) {
                        std::cout << "Ma San Pham khong hop le.\n";
                        break;
                    }
                    SanPham* sp = timTheoMa(dsSanPham, maSP);
                    if (sp) {
                        std::cout << "Nhap so luong: ";
                        if (std::cin >> soLuong && isValidNumber(soLuong, 1)) {
                            dhTimDuoc->themSanPham(sp, soLuong);
                            dhTimDuoc->tinhTongTien();
                            std::cout << "Da them san pham. Tong tien moi: " << std::fixed << std::setprecision(0) << dhTimDuoc->getTongTien() << "\n";
                        } else {
                            std::cout << "So luong khong hop le.\n";
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    } else {
                        std::cout << "Khong tim thay San Pham voi ma " << maSP << ".\n";
                    }
                    break;
                }
                case 2: {
                    std::string maSP;
                    int soLuongMoi;
                    std::cout << "Nhap Ma San Pham can sua so luong: ";
                    std::getline(std::cin, maSP);
                    if (!isValidString(maSP)) {
                        std::cout << "Ma San Pham khong hop le.\n";
                        break;
                    }
                    std::cout << "Nhap so luong moi: ";
                    if (std::cin >> soLuongMoi && isValidNumber(soLuongMoi, 0)) {
                        dhTimDuoc->suaSoLuongSanPham(maSP, soLuongMoi);
                        dhTimDuoc->tinhTongTien();
                        std::cout << "Da cap nhat so luong. Tong tien moi: " << std::fixed << std::setprecision(0) << dhTimDuoc->getTongTien() << "\n";
                    } else {
                        std::cout << "So luong khong hop le.\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    break;
                }
                case 3: {
                    std::string maSP;
                    std::cout << "Nhap Ma San Pham can xoa: ";
                    std::getline(std::cin, maSP);
                    if (!isValidString(maSP)) {
                        std::cout << "Ma San Pham khong hop le.\n";
                        break;
                    }
                    dhTimDuoc->xoaSanPham(maSP);
                    dhTimDuoc->tinhTongTien();
                    std::cout << "Da xoa san pham. Tong tien moi: " << std::fixed << std::setprecision(0) << dhTimDuoc->getTongTien() << "\n";
                    break;
                }
                case 4: {
                    hienThiDanhSachKhachHang();
                    std::string maKH;
                    std::cout << "Nhap Ma Khach Hang moi: ";
                    std::getline(std::cin, maKH);
                    if (!isValidString(maKH)) {
                        std::cout << "Ma Khach Hang khong hop le.\n";
                        break;
                    }
                    KhachHang* khMoi = timTheoMa(dsKhachHang, maKH);
                    if (khMoi) {
                        dhTimDuoc->setKhachHang(khMoi);
                        std::cout << "Da cap nhat Khach Hang cho don hang.\n";
                    } else {
                        std::cout << "Khong tim thay Khach Hang voi ma " << maKH << ".\n";
                    }
                    break;
                }
                case 5: {
                    hienThiDanhSachNhanVien();
                    std::string maNV;
                    std::cout << "Nhap Ma Nhan Vien xu ly moi: ";
                    std::getline(std::cin, maNV);
                    if (!isValidString(maNV)) {
                        std::cout << "Ma Nhan Vien khong hop le.\n";
                        break;
                    }
                    NhanVien* nvMoi = timTheoMa(dsNhanVien, maNV);
                    if (nvMoi) {
                        dhTimDuoc->setNhanVienXuLy(nvMoi);
                        nvMoi->ghiNhanDonHang();
                        std::cout << "Da cap nhat Nhan Vien xu ly cho don hang.\n";
                    } else {
                        std::cout << "Khong tim thay Nhan Vien voi ma " << maNV << ".\n";
                    }
                    break;
                }
                case 0:
                    break;
                default:
                    std::cout << "Lua chon khong hop le.\n";
                    break;
            }
            system("pause");
        } while (chon != 0);
    } else {
        std::cout << "Khong tim thay Don Hang voi ma " << maDonCanSua << ".\n";
        system("pause");
    }
}

void QuanLy::xoaDonHang() {
    system("cls");
    std::cout << "--- Xoa Don Hang ---\n";
    std::string maDonCanXoa;
    std::cout << "Nhap Ma Don Hang can xoa: ";
    std::getline(std::cin, maDonCanXoa);

    if (!isValidString(maDonCanXoa)) {
        std::cout << "Ma Don Hang khong hop le.\n";
        system("pause");
        return;
    }

    auto it_dh = dsDonHang.begin();
    bool found = false;
    while (it_dh != dsDonHang.end()) {
        if ((*it_dh)->getMaDon() == maDonCanXoa) {
            // Xóa các thanh toán liên quan trước
            auto it_tt = dsThanhToan.begin();
            while (it_tt != dsThanhToan.end()) {
                if ((*it_tt)->getMaDonHangLienQuan() == maDonCanXoa) {
                    delete *it_tt;
                    it_tt = dsThanhToan.erase(it_tt);
                } else {
                    ++it_tt;
                }
            }
            delete *it_dh;
            it_dh = dsDonHang.erase(it_dh);
            std::cout << "Da xoa don hang " << maDonCanXoa << " va cac thanh toan lien quan.\n";
            found = true;
            break;
        } else {
            ++it_dh;
        }
    }

    if (!found) {
        std::cout << "Khong tim thay Don Hang voi ma " << maDonCanXoa << ".\n";
    }
    system("pause");
}

// --- Quản lý Thanh Toán ---
void QuanLy::taoThanhToan() {
    system("cls");
    std::cout << "--- Tao Thanh Toan Moi ---\n";

    if (dsDonHang.empty()) {
        std::cout << "Chua co don hang nao de tao thanh toan.\n";
        system("pause");
        return;
    }

    std::string maDonCanTT;
    DonHang* foundDH = nullptr;
    do {
        std::cout << "Nhap Ma Don Hang can thanh toan (0 de huy): ";
        std::getline(std::cin, maDonCanTT);
        if (maDonCanTT == "0") {
            std::cout << "Da huy tao thanh toan.\n";
            system("pause");
            return;
        }
        if (!isValidString(maDonCanTT)) {
            std::cout << "Ma Don Hang khong hop le.\n";
            hienThiDanhSachDonHang();
            continue;
        }
        foundDH = timTheoMa(dsDonHang, maDonCanTT);
        if (!foundDH) {
            std::cout << "Khong tim thay Don Hang voi ma " << maDonCanTT << ". Vui long nhap lai.\n";
            hienThiDanhSachDonHang();
        } else {
            bool alreadyPaid = false;
            for (const auto* tt : dsThanhToan) {
                if (tt->getMaDonHangLienQuan() == foundDH->getMaDon() && tt->getTrangThai() == "Da thanh toan") {
                    alreadyPaid = true;
                    break;
                }
            }
            if (alreadyPaid) {
                std::cout << "Don hang nay da duoc danh dau 'Da thanh toan' roi.\n";
                foundDH = nullptr;
                system("pause");
            }
        }
    } while (!foundDH);

    ThanhToan* newTT = new ThanhToan();
    newTT->setDonHangLienQuan(foundDH);
    newTT->setKhachHangTT(foundDH->getKhachHang());
    newTT->setNhanVienTT(foundDH->getNhanVienXuLy());
    newTT->nhap(dsDonHang, foundDH->getKhachHang(), foundDH->getNhanVienXuLy());
    newTT->tinhToanSoTienThanhToan();
    dsThanhToan.push_back(newTT);
    std::cout << "Da tao thanh toan moi cho don hang " << foundDH->getMaDon() << ".\n";
    system("pause");
}

void QuanLy::hienThiDanhSachThanhToan() const {
    system("cls");
    std::cout << "--- Danh Sach Thanh Toan ---\n";
    if (dsThanhToan.empty()) {
        std::cout << "Chua co thanh toan nao.\n";
    } else {
        for (const auto* tt : dsThanhToan) {
            tt->xuat(std::cout);
            std::cout << "\n";
        }
    }
    system("pause");
}

void QuanLy::hienThiDonHangChuaThanhToan() const {
    system("cls");
    std::cout << "--- Danh Sach Don Hang Chua Thanh Toan ---\n";
    bool foundUnpaid = false;
    for (const auto* dh : dsDonHang) {
        bool isPaid = false;
        for (const auto* tt : dsThanhToan) {
            if (tt->getMaDonHangLienQuan() == dh->getMaDon() && tt->getTrangThai() == "Da thanh toan") {
                isPaid = true;
                break;
            }
        }
        if (!isPaid) {
            dh->xuatHoaDon(std::cout);
            std::cout << "\n--------------------\n";
            foundUnpaid = true;
        }
    }
    if (!foundUnpaid) {
        std::cout << "Tat ca don hang da duoc thanh toan hoac chua co don hang nao.\n";
    }
    system("pause");
}

void QuanLy::danhDauDonHangDaThanhToan() {
    system("cls");
    std::cout << "--- Danh Dau Don Hang Da Thanh Toan ---\n";
    std::string maDonCanDanhDau;
    std::cout << "Nhap Ma Don Hang can danh dau da thanh toan: ";
    std::getline(std::cin, maDonCanDanhDau);

    if (!isValidString(maDonCanDanhDau)) {
        std::cout << "Ma Don Hang khong hop le.\n";
        system("pause");
        return;
    }

    DonHang* foundDH = timTheoMa(dsDonHang, maDonCanDanhDau);
    if (foundDH) {
        ThanhToan* relatedTT = nullptr;
        for (auto* tt : dsThanhToan) {
            if (tt->getMaDonHangLienQuan() == foundDH->getMaDon()) {
                relatedTT = tt;
                break;
            }
        }

        if (relatedTT) {
            if (relatedTT->getTrangThai() == "Da thanh toan") {
                std::cout << "Don hang " << foundDH->getMaDon() << " da duoc danh dau 'Da thanh toan' truoc do.\n";
            } else {
                relatedTT->danhDauThanhToan("Da thanh toan");
                std::cout << "Da danh dau don hang " << foundDH->getMaDon() << " la 'Da thanh toan'.\n";
            }
        } else {
            std::cout << "Chua co thong tin thanh toan cho don hang nay. Dang tao thanh toan moi...\n";
            ThanhToan* newTT = new ThanhToan();
            newTT->setDonHangLienQuan(foundDH);
            newTT->setKhachHangTT(foundDH->getKhachHang());
            newTT->setNhanVienTT(foundDH->getNhanVienXuLy());
            newTT->nhap({}, foundDH->getKhachHang(), foundDH->getNhanVienXuLy());
            newTT->tinhToanSoTienThanhToan();
            newTT->danhDauThanhToan("Da thanh toan");
            dsThanhToan.push_back(newTT);
            std::cout << "Da tao va danh dau thanh toan cho don hang " << foundDH->getMaDon() << ".\n";
        }
    } else {
        std::cout << "Khong tim thay Don Hang voi ma " << maDonCanDanhDau << ".\n";
    }
    system("pause");
}