#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menuTarikUang();
void menuSetorUang();
void cekSaldo();
void simpanSaldo();
void simpanRiwayat(char transaksi[], double jumlah, double saldoAkhir);

double saldo = 500000;

int main () {
    system("cls");
    int pilihan;

    while (1) {
        printf("\n==== TRANSAKSI ATM ====\n");
        printf("1. Tarik Tunai\n");
        printf("2. Setor Tunai\n");
        printf("3. Cek Saldo\n");
        printf("4. Keluar\n");
        printf("pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                menuTarikUang();
                break;
            case 2:
                menuSetorUang();
                break;
            case 3:
                cekSaldo();
                break;
            case 4:
                printf("Terima kasih telah menggunakan ATM KEL 1.\n");
                return 0;
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

void menuTarikUang() {
    int pilihan;
    double jumlah = 0;

    printf("\n=== TARIK TUNAI ===\n");
    printf("1. 50.000\n");
    printf("2. 100.000\n");
    printf("3. 200.000\n");
    printf("4. 300.000\n");
    printf("5. 500.000\n");
    printf("6. 1.000.000\n");
    printf("7. Jumlah lain\n");
    printf("Pilih nominal: ");
    scanf("%d", &pilihan);

    switch(pilihan) {
        case 1: jumlah = 50000; break;
        case 2: jumlah = 100000; break;
        case 3: jumlah = 200000; break;
        case 4: jumlah = 300000; break;
        case 5: jumlah = 500000; break;
        case 6: jumlah = 1000000; break;
        case 7:
           printf("Masukkan Jumlah penarikan : ");
            scanf("%lf", &jumlah);
            break;
        default:
            printf("Pilihan tidak valid!\n");
            return;
    }

    if (jumlah > saldo) {
        printf("\n=== TRANSAKSI GAGAL ===\n");
        printf("Transaksi tidak dapat diproses.\n");
        printf("Saldo Anda tidak mencukupi untuk melakukan penarikan sebesar %.0f\n", jumlah);
        printf("Silakan periksa saldo Anda kembali.\n");
        return;
    }

    saldo -= jumlah;

    simpanSaldo();
    simpanRiwayat("TARIK", jumlah, saldo);

    printf("\n=== STRUK TARIK TUNAI ===\n");
    printf("Jumlah ditarik: %.0f\n", jumlah);
    printf("Sisa saldo: %.0f\n", saldo);
    printf("\nTERIMA KASIH SUDAH MENGGUNAKAN ATM MINI KEL 1.\n");
}

void menuSetorUang() {
    double jumlah;

    printf("\n=== SETOR TUNAI ===\n");
    printf("Masukkan jumlah setoran: ");
    scanf("%lf", &jumlah);

    if (jumlah <= 0) {
        printf("Jumlah tidak valid!\n");
        return;
    }

    if ((int)jumlah % 50000 != 0 ) {
        printf("ATM hanya menerima pecahan 50.000\n");
        return;
    }

    saldo += jumlah;

    simpanSaldo();
    simpanRiwayat("SETOR", jumlah, saldo);

    printf("\n=== STRUK SETOR TUNAI ===\n");
    printf("Jumlah disetor: %.0f\n", jumlah);
    printf("Saldo sekarang: %.0f\n", saldo);
    printf("\n\nTERIMA KASIH SUDAH MENGGUNAKAN ATM MINI KEL 1.");
}

void cekSaldo() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    printf("\n+===============================================+\n");
    printf("|                 RIWAYAT TRANSAKSI             |\n");
    printf("|                   CEK SALDO                   |\n");
    printf("+===============================================+\n");

    printf("| Tanggal : %02d-%02d-%04d                          |\n",
            t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);  
    printf("| Waktu   : %02d:%02d:%02d                            |\n",
            t->tm_hour, t->tm_min, t->tm_sec);
    printf("| Saldo Anda : Rp %.0f,-                      |\n", saldo);
    printf("|                                               |\n");
    printf("|   TERIMA KASIH SUDAH MENGGUNAKAN ATM MINI     |\n");
    printf("|                  KELOMPOK 1                   |\n");
    printf("+===============================================+\n");

}

void simpanSaldo() { 
    FILE *file = fopen("saldo.txt", "w");

    if (file == NULL) {
        printf("Gagal menyimpan saldo!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(file,
        "+===============================================+\n"
        "|                   SALDO ATM                   |\n"
        "+===============================================+\n"
        "| Saldo Terakhir : Rp %-26.0f|\n"
        "+===============================================+\n",
         saldo);
    fclose(file);
}

void simpanRiwayat(char transaksi[], double jumlah, double saldoAkhir) {
    FILE *file = fopen("riwayat.txt", "a");

    if (file == NULL) {
        printf("Gagal menyimpan riwayat!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    

    fprintf(file,
        "+==============================================+\n"
        "|                Riwayat Transaksi             |\n"
        "|                    ATM MINI                  |\n"
        "+==============================================+\n"
        "Tanggal : %02d-%02d-%04d\n"
        "Waktu   : %02d:%02d:%02d\n"
        "[%s] Rp %.0f\n"
        "Saldo Setelah Transaksi : Rp %.0f\n"
        "+==============================================+\n\n",
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec,               
        transaksi, jumlah, saldoAkhir);
    fclose(file);

}



