/******************************************************************************
 * Họ và tên: [Nguyễn Thành Tâm]
 * MSSV:      [PS48578]
 * Lớp:       [COM108 - CS21302]
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// ====== CHỨC NĂNG 1: KIỂM TRA SỐ NGUYÊN ======
void kiemTraSoNguyen() {
    float n;
    printf("Nhap mot so: ");
    scanf("%f", &n);

    if (n == (int)n)
        printf("Day la so nguyen\n");
    else
        printf("Day khong phai so nguyen\n");
}

// ====== CHỨC NĂNG 2: UCLN & BCNN ======
int UCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void UCLN_BCNN() {
    int a, b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);

    int ucln = UCLN(a, b);
    int bcnn = (a * b) / ucln;

    printf("UCLN = %d\n", ucln);
    printf("BCNN = %d\n", bcnn);
}

// ====== CHỨC NĂNG 3: TÍNH TIỀN KARAOKE ======
void tinhTienKaraoke() {
    int gioVao, gioRa;
    printf("Nhap gio vao: ");
    scanf("%d", &gioVao);
    printf("Nhap gio ra: ");
    scanf("%d", &gioRa);

    int gio = gioRa - gioVao;
    int tien = gio * 30000;

    if (gio > 3)
        tien -= (gio - 3) * 30000 * 0.3;

    printf("Tien karaoke: %d VND\n", tien);
}

// ====== CHỨC NĂNG 4: TÍNH TIỀN ĐIỆN ======
void tinhTienDien() {
    int soDien;
    float tien = 0;
    printf("Nhap so dien tieu thu: ");
    scanf("%d", &soDien);

    if (soDien <= 50)
        tien = soDien * 1678;
    else if (soDien <= 100)
        tien = 50 * 1678 + (soDien - 50) * 1734;
    else
        tien = 50 * 1678 + 50 * 1734 + (soDien - 100) * 2014;

    printf("Tien dien phai tra: %.0f VND\n", tien);
}

// ====== CHỨC NĂNG 5: ĐỔI TIỀN ======
void doiTien() {
    int tien;
    printf("Nhap so tien: ");
    scanf("%d", &tien);

    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    for (int i = 0; i < 9; i++) {
        printf("%d VND: %d to\n", menhGia[i], tien / menhGia[i]);
        tien %= menhGia[i];
    }
}

// ====== CHỨC NĂNG 6: LÃI SUẤT VAY NGÂN HÀNG ======
void laiSuatVay() {
    float tienVay;
    printf("Nhap so tien vay: ");
    scanf("%f", &tienVay);

    float lai = 0.05;
    for (int i = 1; i <= 12; i++) {
        float tienLai = tienVay * lai;
        tienVay -= tienVay / 12;
        printf("Thang %d - Lai: %.2f - Con lai: %.2f\n", i, tienLai, tienVay);
    }
}

// ====== CHỨC NĂNG 7: VAY TIỀN MUA XE ======
void vayMuaXe() {
    float giaXe;
    printf("Nhap gia xe: ");
    scanf("%f", &giaXe);

    float traTruoc = giaXe * 0.3;
    float vay = giaXe - traTruoc;
    float lai = vay * 0.07;

    printf("Tra truoc: %.2f\n", traTruoc);
    printf("Tien vay: %.2f\n", vay);
    printf("Lai suat nam: %.2f\n", lai);
}

// ====== CHỨC NĂNG 8: SẮP XẾP SINH VIÊN ======
void sapXepSinhVien() {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);

    float diem[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap diem SV %d: ", i + 1);
        scanf("%f", &diem[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (diem[i] > diem[j]) {
                float temp = diem[i];
                diem[i] = diem[j];
                diem[j] = temp;
            }
        }
    }

    printf("Danh sach diem tang dan:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", diem[i]);
    printf("\n");
}

// ====== CHỨC NĂNG 9: GAME FPOLY-LOTT ======
void fpolyLott() {
    int so;
    printf("Nhap so du doan (0-15): ");
    scanf("%d", &so);

    int ketQua = rand() % 16;
    printf("So trung thuong: %d\n", ketQua);

    if (so == ketQua)
        printf("CHUC MUNG BAN TRUNG THUONG!\n");
    else
        printf("Chuc ban may man lan sau!\n");
}

// ====== CHỨC NĂNG 10: TÍNH TOÁN PHÂN SỐ ======
void tinhPhanSo() {
    int a, b, c, d;
    printf("Nhap phan so thu nhat (a/b): ");
    scanf("%d/%d", &a, &b);
    printf("Nhap phan so thu hai (c/d): ");
    scanf("%d/%d", &c, &d);

    int tu = a * d + b * c;
    int mau = b * d;

    printf("Tong = %d/%d\n", tu, mau);
}

// ====== MENU CHÍNH ======
int main() {
    int chon;
    do {
        printf("\n===== MENU ASM =====\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. UCLN & BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Lai suat vay ngan hang\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("9. FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: kiemTraSoNguyen(); break;
            case 2: UCLN_BCNN(); break;
            case 3: tinhTienKaraoke(); break;
            case 4: tinhTienDien(); break;
            case 5: doiTien(); break;
            case 6: laiSuatVay(); break;
            case 7: vayMuaXe(); break;
            case 8: sapXepSinhVien(); break;
            case 9: fpolyLott(); break;
            case 10: tinhPhanSo(); break;
            case 0: printf("Thoat chuong trinh\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);

    return 0;
}
