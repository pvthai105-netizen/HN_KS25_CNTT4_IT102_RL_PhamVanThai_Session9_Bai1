#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main(void) {
    struct VeMayBay ve[50];
    int n;
    int i;
    int found = 0;
    char pnrCanTim[10];

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");

    /* Nhap so luong ve */
    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);

        if (n < 1 || n > 50) {
            printf("So luong ve khong hop le! Vui long nhap lai.\n");
        }
    } while (n < 1 || n > 50);

    /* Nhap danh sach ve */
    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Nhap ma PNR: ");
        scanf("%9s", ve[i].maPNR);

        while (getchar() != '\n');

        printf("Nhap ho ten hanh khach: ");
        fgets(ve[i].tenHanhKhach, sizeof(ve[i].tenHanhKhach), stdin);
        ve[i].tenHanhKhach[strcspn(ve[i].tenHanhKhach, "\n")] = '\0';

        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(ve[i].hangVe, sizeof(ve[i].hangVe), stdin);
        ve[i].hangVe[strcspn(ve[i].hangVe, "\n")] = '\0';

        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &ve[i].trongLuongHanhLy);

        /* Tinh phi phu thu */
        if (ve[i].trongLuongHanhLy > 7.0f) {
            ve[i].phiPhuThu =
                (long)((ve[i].trongLuongHanhLy - 7.0f) * 50000);
        } else {
            ve[i].phiPhuThu = 0;
        }
    }

    /* Xuat danh sach */
    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-25s %-12s %-15s %-15s\n",
           "STT", "MA PNR", "HO TEN HANH KHACH",
           "HANG VE", "HANH LY(KG)", "PHI PHU THU");
    printf("----------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-15.1f %-15ld\n",
               i + 1,
               ve[i].maPNR,
               ve[i].tenHanhKhach,
               ve[i].hangVe,
               ve[i].trongLuongHanhLy,
               ve[i].phiPhuThu);
    }

    printf("----------------------------------------------------------------------------------------------------\n");

    /* Tim kiem va cap nhat */
    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");
    scanf("%9s", pnrCanTim);

    for (i = 0; i < n; i++) {
        if (strcmp(ve[i].maPNR, pnrCanTim) == 0) {
            found = 1;

            printf("Tim thay ve cua hanh khach: %s\n",
                   ve[i].tenHanhKhach);

            printf("Nhap trong luong hanh ly moi (kg): ");
            scanf("%f", &ve[i].trongLuongHanhLy);

            if (ve[i].trongLuongHanhLy > 7.0f) {
                ve[i].phiPhuThu =
                    (long)((ve[i].trongLuongHanhLy - 7.0f) * 50000);
            } else {
                ve[i].phiPhuThu = 0;
            }

            printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n",
                   ve[i].phiPhuThu);

            break;
        }
    }

    if (found == 0) {
        printf("Khong tim thay ma PNR hop le!\n");
    } else {
        /* In lai danh sach sau cap nhat */
        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("----------------------------------------------------------------------------------------------------\n");
        printf("%-5s %-10s %-25s %-12s %-15s %-15s\n",
               "STT", "MA PNR", "HO TEN HANH KHACH",
               "HANG VE", "HANH LY(KG)", "PHI PHU THU");
        printf("----------------------------------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-15.1f %-15ld\n",
                   i + 1,
                   ve[i].maPNR,
                   ve[i].tenHanhKhach,
                   ve[i].hangVe,
                   ve[i].trongLuongHanhLy,
                   ve[i].phiPhuThu);
        }

        printf("----------------------------------------------------------------------------------------------------\n");
    }

    return 0;
}