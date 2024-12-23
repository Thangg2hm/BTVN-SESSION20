#include <stdio.h>
#include <string.h>

// Khai báo c?u trúc cho d?i tu?ng s?n ph?m
struct SanPham {
    char maSanPham[20];
    char tenSanPham[100];
    float giaNhap;
    float giaBan;
    int soLuong;
};

// Khai báo m?ng s?n ph?m và bi?n d? luu doanh thu
struct SanPham sanPham[100];
int soLuongSanPham = 0;
float doanhThu = 0;

// Hàm hi?n th? menu
void hienThiMenu() {
    printf("\nMENU\n");
    printf("1. Nhap so luong va thong tin san pham\n");
    printf("2. Hien thi danh sach san pham\n");
    printf("3. Nhap san pham\n");
    printf("4. Cap nhat thong tin san pham\n");
    printf("5. Sap xep san pham theo gia (tang/giam)\n");
    printf("6. Tim kiem san pham\n");
    printf("7. Ban san pham (co the nhap so luong can ban)\n");
    printf("8. Doanh thu hien tai\n");
    printf("9. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Hàm nh?p thông tin s?n ph?m
void nhapThongTinSanPham() {
    printf("Nhap so luong san pham: ");
    scanf("%d", &soLuongSanPham);
    for (int i = 0; i < soLuongSanPham; i++) {
        printf("Nhap thong tin san pham thu %d\n", i + 1);
        printf("Ma san pham: ");
        scanf("%s", sanPham[i].maSanPham);
        printf("Ten san pham: ");
        getchar(); // Ð? lo?i b? ký t? newline trong b? d?m
        fgets(sanPham[i].tenSanPham, sizeof(sanPham[i].tenSanPham), stdin);
        sanPham[i].tenSanPham[strcspn(sanPham[i].tenSanPham, "\n")] = '\0'; // Lo?i b? ký t? newline
        printf("Gia nhap: ");
        scanf("%f", &sanPham[i].giaNhap);
        printf("Gia ban: ");
        scanf("%f", &sanPham[i].giaBan);
        printf("So luong: ");
        scanf("%d", &sanPham[i].soLuong);
        doanhThu -= sanPham[i].soLuong * sanPham[i].giaNhap;
    }
}

// Hàm hi?n th? danh sách s?n ph?m
void hienThiDanhSachSanPham() {
    for (int i = 0; i < soLuongSanPham; i++) {
        printf("Ma san pham: %s\n", sanPham[i].maSanPham);
        printf("Ten san pham: %s\n", sanPham[i].tenSanPham);
        printf("Gia nhap: %.2f\n", sanPham[i].giaNhap);
        printf("Gia ban: %.2f\n", sanPham[i].giaBan);
        printf("So luong: %d\n", sanPham[i].soLuong);
        printf("\n");
    }
}

// Hàm nh?p s?n ph?m vào m?ng
void nhapSanPham() {
    char maSanPham[20];
    printf("Nhap ma san pham can them: ");
    scanf("%s", maSanPham);
    
    // Ki?m tra xem s?n ph?m dã t?n t?i chua
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(sanPham[i].maSanPham, maSanPham) == 0) {
            int soLuong;
            printf("Nhap so luong can them: ");
            scanf("%d", &soLuong);
            sanPham[i].soLuong += soLuong;
            doanhThu -= soLuong * sanPham[i].giaNhap;
            return;
        }
    }
    
    // N?u s?n ph?m chua t?n t?i, thêm s?n ph?m m?i
    printf("Nhap thong tin san pham moi\n");
    strcpy(sanPham[soLuongSanPham].maSanPham, maSanPham);
    printf("Ten san pham: ");
    getchar();
    fgets(sanPham[soLuongSanPham].tenSanPham, sizeof(sanPham[soLuongSanPham].tenSanPham), stdin);
    sanPham[soLuongSanPham].tenSanPham[strcspn(sanPham[soLuongSanPham].tenSanPham, "\n")] = '\0';
    printf("Gia nhap: ");
    scanf("%f", &sanPham[soLuongSanPham].giaNhap);
    printf("Gia ban: ");
    scanf("%f", &sanPham[soLuongSanPham].giaBan);
    printf("So luong: ");
    scanf("%d", &sanPham[soLuongSanPham].soLuong);
    doanhThu -= sanPham[soLuongSanPham].soLuong * sanPham[soLuongSanPham].giaNhap;
    soLuongSanPham++;
}

// Hàm c?p nh?t thông tin s?n ph?m
void capNhatThongTin() {
    char maSanPham[20];
    printf("Nhap ma san pham can cap nhat: ");
    scanf("%s", maSanPham);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(sanPham[i].maSanPham, maSanPham) == 0) {
            printf("Nhap thong tin moi cho san pham\n");
            printf("Ten san pham: ");
            getchar();
            fgets(sanPham[i].tenSanPham, sizeof(sanPham[i].tenSanPham), stdin);
            sanPham[i].tenSanPham[strcspn(sanPham[i].tenSanPham, "\n")] = '\0';
            printf("Gia nhap: ");
            scanf("%f", &sanPham[i].giaNhap);
            printf("Gia ban: ");
            scanf("%f", &sanPham[i].giaBan);
            printf("So luong: ");
            scanf("%d", &sanPham[i].soLuong);
            return;
        }
    }
    printf("Khong tim thay ma san pham!\n");
}

// Hàm s?p x?p s?n ph?m theo giá
void sapXepSanPham() {
    int luaChon;
    printf("Chon kieu sap xep (1: Tang dan, 2: Giam dan): ");
    scanf("%d", &luaChon);
    for (int i = 0; i < soLuongSanPham - 1; i++) {
        for (int j = i + 1; j < soLuongSanPham; j++) {
            if ((luaChon == 1 && sanPham[i].giaBan > sanPham[j].giaBan) || (luaChon == 2 && sanPham[i].giaBan < sanPham[j].giaBan)) {
                struct SanPham temp = sanPham[i];
                sanPham[i] = sanPham[j];
                sanPham[j] = temp;
            }
        }
    }
}

// Hàm tìm ki?m s?n ph?m theo tên
void timKiemSanPham() {
    char tenSanPham[100];
    printf("Nhap ten san pham can tim: ");
    getchar();
    fgets(tenSanPham, sizeof(tenSanPham), stdin);
    tenSanPham[strcspn(tenSanPham, "\n")] = '\0';
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strstr(sanPham[i].tenSanPham, tenSanPham) != NULL) {
            printf("Ma san pham: %s\n", sanPham[i].maSanPham);
            printf("Ten san pham: %s\n", sanPham[i].tenSanPham);
            printf("Gia nhap: %.2f\n", sanPham[i].giaNhap);
            printf("Gia ban: %.2f\n", sanPham[i].giaBan);
            printf("So luong: %d\n", sanPham[i].soLuong);
            printf("\n");
        }
    }
}

// Hàm bán s?n ph?m
void banSanPham() {
    char maSanPham[20];
    printf("Nhap ma san pham can ban: ");
    scanf("%s", maSanPham);
    for (int i = 0; i < soLuongSanPham; i++) {
        if (strcmp(sanPham[i].maSanPham, maSanPham) == 0) {
            int soLuongBan;
            printf("Nhap so luong can ban: ");
            scanf("%d", &soLuongBan);
            if (sanPham[i].soLuong == 0) {
                printf("Het hang!\n");
                return;
            }
            if (soLuongBan > sanPham[i].soLuong) {
                printf("Khong con du hang!\n");
                return;
            }
            sanPham[i].soLuong -= soLuongBan;
            doanhThu += soLuongBan * sanPham[i].giaBan;
            return;
        }
    }
    printf("Khong tim thay ma san pham!\n");
}


void hienThiDoanhThu() {
    printf("Doanh thu hien tai: %.2f\n", doanhThu);
}

int main() {
    int luaChon;
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        switch(luaChon) {
            case 1:
                nhapThongTinSanPham();

