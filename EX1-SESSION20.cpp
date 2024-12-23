#include <stdio.h>
#include <string.h>

// Khai b�o c?u tr�c cho d?i tu?ng s�ch
struct Book {
    char maSach[20];
    char tenSach[100];
    char tacGia[100];
    float giaTien;
    char theLoai[50];
};

// Khai b�o m?ng s�ch
struct Book sach[100];
int soLuong = 0;

// H�m hi?n th? menu
void hienThiMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so luong va thong tin sach\n");
    printf("2. Hien thi thong tin sach\n");
    printf("3. Them sach vao vi tri\n");
    printf("4. Xoa sach theo ma sach\n");
    printf("5. Cap nhat thong tin sach theo ma sach\n");
    printf("6. Sap xep sach theo gia (tang/giam)\n");
    printf("7. Tim kiem sach theo ten sach\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban: ");
}

// H�m nh?p th�ng tin s�ch
void nhapThongTinSach() {
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuong);
    for (int i = 0; i < soLuong; i++) {
        printf("Nhap thong tin sach thu %d\n", i + 1);
        printf("Ma sach: ");
        scanf("%s", sach[i].maSach);
        printf("Ten sach: ");
        getchar(); // �? lo?i b? k� t? newline trong b? d?m
        fgets(sach[i].tenSach, sizeof(sach[i].tenSach), stdin);
        sach[i].tenSach[strcspn(sach[i].tenSach, "\n")] = '\0'; // Lo?i b? k� t? newline
        printf("Tac gia: ");
        fgets(sach[i].tacGia, sizeof(sach[i].tacGia), stdin);
        sach[i].tacGia[strcspn(sach[i].tacGia, "\n")] = '\0';
        printf("Gia tien: ");
        scanf("%f", &sach[i].giaTien);
        printf("The loai: ");
        getchar(); // �? lo?i b? k� t? newline trong b? d?m
        fgets(sach[i].theLoai, sizeof(sach[i].theLoai), stdin);
        sach[i].theLoai[strcspn(sach[i].theLoai, "\n")] = '\0';
    }
}

// H�m hi?n th? th�ng tin s�ch
void hienThiThongTinSach() {
    for (int i = 0; i < soLuong; i++) {
        printf("Ma sach: %s\n", sach[i].maSach);
        printf("Ten sach: %s\n", sach[i].tenSach);
        printf("Tac gia: %s\n", sach[i].tacGia);
        printf("Gia tien: %.2f\n", sach[i].giaTien);
        printf("The loai: %s\n", sach[i].theLoai);
        printf("\n");
    }
}

// H�m th�m s�ch v�o v? tr�
void themSach() {
    if (soLuong >= 100) {
        printf("Khong the them sach, vuot qua gioi han\n");
        return;
    }
    int viTri;
    printf("Nhap vi tri can them (0 - %d): ", soLuong);
    scanf("%d", &viTri);
    if (viTri < 0 || viTri > soLuong) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = soLuong; i > viTri; i--) {
        sach[i] = sach[i - 1];
    }
    printf("Nhap thong tin sach moi\n");
    printf("Ma sach: ");
    scanf("%s", sach[viTri].maSach);
    printf("Ten sach: ");
    getchar();
    fgets(sach[viTri].tenSach, sizeof(sach[viTri].tenSach), stdin);
    sach[viTri].tenSach[strcspn(sach[viTri].tenSach, "\n")] = '\0';
    printf("Tac gia: ");
    fgets(sach[viTri].tacGia, sizeof(sach[viTri].tacGia), stdin);
    sach[viTri].tacGia[strcspn(sach[viTri].tacGia, "\n")] = '\0';
    printf("Gia tien: ");
    scanf("%f", &sach[viTri].giaTien);
    printf("The loai: ");
    getchar();
    fgets(sach[viTri].theLoai, sizeof(sach[viTri].theLoai), stdin);
    sach[viTri].theLoai[strcspn(sach[viTri].theLoai, "\n")] = '\0';
    soLuong++;
}

// H�m x�a s�ch theo m� s�ch
void xoaSachTheoMa() {
    char maSach[20];
    printf("Nhap ma sach can xoa: ");
    scanf("%s", maSach);
    int viTri = -1;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(sach[i].maSach, maSach) == 0) {
            viTri = i;
            break;
        }
    }
    if (viTri == -1) {
        printf("Khong tim thay ma sach!\n");
        return;
    }
    for (int i = viTri; i < soLuong - 1; i++) {
        sach[i] = sach[i + 1];
    }
    soLuong--;
}

// H�m c?p nh?t th�ng tin s�ch theo m� s�ch
void capNhatThongTin() {
    char maSach[20];
    printf("Nhap ma sach can cap nhat: ");
    scanf("%s", maSach);
    int viTri = -1;
    for (int i = 0; i < soLuong; i++) {
        if (strcmp(sach[i].maSach, maSach) == 0) {
            viTri = i;
            break;
        }
    }
    if (viTri == -1) {
        printf("Khong tim thay ma sach!\n");
        return;
    }
    printf("Nhap thong tin moi cho sach\n");
    printf("Ma sach: ");
    scanf("%s", sach[viTri].maSach);
    printf("Ten sach: ");
    getchar();
    fgets(sach[viTri].tenSach, sizeof(sach[viTri].tenSach), stdin);
    sach[viTri].tenSach[strcspn(sach[viTri].tenSach, "\n")] = '\0';
    printf("Tac gia: ");
    fgets(sach[viTri].tacGia, sizeof(sach[viTri].tacGia), stdin);
    sach[viTri].tacGia[strcspn(sach[viTri].tacGia, "\n")] = '\0';
    printf("Gia tien: ");
    scanf("%f", &sach[viTri].giaTien);
    printf("The loai: ");
    getchar();
    fgets(sach[viTri].theLoai, sizeof(sach[viTri].theLoai), stdin);
    sach[viTri].theLoai[strcspn(sach[viTri].theLoai, "\n")] = '\0';
}

// H�m s?p x?p s�ch theo gi�
void sapXepSach() {
    int luaChon;
    printf("Chon kieu sap xep (1: Tang dan, 2: Giam dan): ");
    scanf("%d", &luaChon);
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if ((luaChon == 1 && sach[i].giaTien > sach[j].giaTien) || (luaChon == 2 && sach[i].giaTien < sach[j].giaTien)) {
                struct Book temp = sach[i];
                sach[i] = sach[j];
                sach[j] = temp;
            }
        }
    }
}

// H�m t�m ki?m s�ch theo t�n
void timKiemSach() {
    char tenSach[100];
    printf("Nhap ten sach can tim: ");
    getchar();
    fgets(tenSach, sizeof(tenSach), stdin);
    tenSach[strcspn(tenSach, "\n")] = '\0';
    for (int i = 0; i < soLuong; i++) {
        if (strstr(sach[i].tenSach, tenSach) != NULL) {
            printf("Ma sach: %s\n", sach[i].maSach);
            printf("Ten sach: %s\n", sach[i].tenSach);
            printf("Tac gia: %s\n", sach[i].tacGia);
            printf("Gia tien: %.2f\n", sach[i].giaTien);
            printf("The loai: %s\n", sach[i].theLoai);
            printf("\n");
        }
    }
}

int main() {
    int luaChon;
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        switch(luaChon) {
            case 1:
                nhapThongTinSach();
                break;
            case 2:
                hienThiThongTinSach();
                break;
            case 3:
                themSach();
                break;
            case 4
