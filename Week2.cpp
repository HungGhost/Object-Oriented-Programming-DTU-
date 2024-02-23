#include <bits/stdc++.h>
#include <cstring>
using namespace std;

class SinhVien
{
private:
    string ten;
    int maSv;
    float diemCgpa;

public:
    void nhapThongTin()
    {
        cout << "--> Nhap Ten Sinh Vien : ";
        cin.ignore();
        getline(cin, ten);
        cout << "--> Nhap Ma Sinh Vien : ";
        cin >> maSv;
        cout << "--> Nhap Diem CGPA : ";
        cin >> diemCgpa;
    }

    void hienThiThongTin() const
    {
        cout << "\n\t+---------------------------------------------------+";
        cout << "\n\t| " << std::left << std::setw(20) << "Ten "
             << "|";
        cout << std::left << std::setw(14) << " Ma Sinh Vien "
             << "|";
        cout << std::left << std::setw(11) << " Diem CGPA "
             << "|";
        cout << "\n\t+---------------------------------------------------+";
        cout << "\n\t| " << std::left << std::setw(20) << layTen() << "|";
        cout << std::left << std::setw(14) << layMaSv() << "|";
        cout << std::left << std::setw(11) << layDiemCgpa() << "|";
        cout << "\n\t+---------------------------------------------------+";
    }

    void suaThongTin()
    {
        cout << "Chinh Sua Thong Tin Sinh Vien:\n";
        nhapThongTin();
    }

    int layMaSv() const
    {
        return maSv;
    }

    float layDiemCgpa() const
    {
        return diemCgpa;
    }

    string layTen() const
    {
        return ten;
    }
};

void nhapDanhSachSinhVien(SinhVien *danhSach, int soLuong)
{
    system("cls");
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t | Add Student Details |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < soLuong; i++)
    {
        cout << "Nhap thong tin cho Sinh Vien " << i + 1 << ":\n";
        danhSach[i].nhapThongTin();
    }
}

void hienThiDanhSachSinhVien(const SinhVien *danhSach, int soLuong)
{
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t | Student Result Table |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\nHien Thi Thong Tin Sinh Vien theo Thu Tu Nhap:\n";
    for (int i = 0; i < soLuong; i++)
    {
        danhSach[i].hienThiThongTin();
    }
    cout << endl;
}

void sapXepDanhSachTheoMaSv(SinhVien *danhSach, int soLuong)
{
    for (int i = 0; i < soLuong - 1; i++)
    {
        for (int j = 0; j < soLuong - i - 1; j++)
        {
            if (danhSach[j].layMaSv() > danhSach[j + 1].layMaSv())
            {
                swap(danhSach[j], danhSach[j + 1]);
            }
        }
    }
}
int timKiemSinhVienTheoMaSv(const SinhVien *danhSach, int soLuong, int maSv)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSach[i].layMaSv() == maSv)
        {
            return i;
        }
    }
    return -1;
}
void menu()
{
    int choice;
    const int soLuongSinhVien = 4;
    SinhVien *danhSachSinhVien = new SinhVien[soLuongSinhVien];
    do
    {
        cout << "\n\n\t\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t\t |    STUDENT MANAGEMENT SYSTEM    | " << endl;
        cout << "\t\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t\t 1. Nhap danh sach sinh vien. " << endl;
        cout << "\t\t\t\t 2. Hien thi danh sach sinh vien. " << endl;
        cout << "\t\t\t\t 3. Sap xep danh sach theo Ma Sinh Vien. " << endl;
        cout << "\t\t\t\t 4. Tim kiem sinh vien theo Ma Sinh Vien. " << endl;
        cout << "\t\t\t\t 5. Thoat. " << endl;
        cout << "\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t  Choose Option : [ 1 / 2 / 3 / 4 / 5 ]" << endl;
        cout << "\t\t\t\t-----------------------------------------" << endl;
        cout << " --> Please Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            nhapDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
            cout << endl;
            cout << "\t\t\t\t --> Nhap Danh Sach Sinh Vien Thanh Cong <--";
            break;

        case 2:
            hienThiDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
            char choice;
            do
            {
                cout << "\n\nBan Co Muon Quay Lai Truong Trinh k? (Y/N): ";
                cin >> choice;

                if (choice == 'Y' || choice == 'y')
                {
                    cout << "\t\t\t Chuc Mung Da Tro Lai Do` Ngoc 😣";
                    menu();
                    break; //Yamate Kudasai
                }
                else if (choice == 'N' || choice == 'n')
                {
                    return;
                }
                else
                {
                    cout << "Nhap Sai Moi Nhap Lai Y or N: ";
                }
            } while (true);
            break;

        case 3:
            sapXepDanhSachTheoMaSv(danhSachSinhVien, soLuongSinhVien);
            cout << "\nHien Thi Danh Sach Sau Khi Sap Xep Theo Ma Sinh Vien:\n";
            hienThiDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
            break;

        case 4:
            int Timsv;
            cout << "\nNhap Ma Sinh Vien Can Tim: ";
            cin >> Timsv;
            int viTri;
            viTri = timKiemSinhVienTheoMaSv(danhSachSinhVien, soLuongSinhVien, Timsv);
            if (viTri != -1)
            {
                cout << "\nThong Tin Sinh Vien Co Ma " << Timsv << ":\n";
                danhSachSinhVien[viTri].hienThiThongTin();
            }
            else
            {
                cout << "\nKhong Tim Thay Sinh Vien voi Ma " << Timsv << ".\n";
            }
            break;
        case 5:
            cout << "Thoat chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (choice != 5);
}
int main()
{
    menu();
    return 0;
}
