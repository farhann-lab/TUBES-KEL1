#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fitur.h"

void menuTarikUang(struct Account *acc) {
    int pilihan;
    long jumlah = 0;

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
                scanf("%ld", &jumlah);
            break;
        default:
            printf("Pilihan tidak valid!\n");
            return;
    }

    if (jumlah > acc->saldo) {
        printf("\n=== TRANSAKSI GAGAL ===\n");
        printf("Transaksi tidak dapat diproses.\n");
        printf("Saldo Anda tidak mencukupi untuk melakukan penarikan sebesar %ld\n", jumlah);
        printf("Silakan periksa saldo Anda kembali.\n");
        return;
    }

    acc->saldo -= jumlah;

    simpanAkun(acc); 
    simpanRiwayat("TARIK", jumlah, acc->saldo);

    printf("\n=== STRUK TARIK TUNAI ===\n");
    printf("Jumlah ditarik: %ld\n", jumlah);
    printf("Sisa saldo: %ld\n", acc->saldo);
     printf("\n\nKETIK APA SAJA UNTUK KEMBALI KE MENU\n\n");
    getchar();
    getchar();
    system("cls");
}

void menuSetorUang(struct Account *acc) {
    long jumlah;

    printf("\n=== SETOR TUNAI ===\n");
    printf("Masukkan jumlah setoran: ");
    scanf("%ld", &jumlah);

    if (jumlah <= 0) {
        printf("Jumlah tidak valid!\n");
        return;
    }

    if (jumlah % 50000 != 0 ) {
        printf("ATM hanya menerima pecahan 50.000\n");
        return;
    }

    acc->saldo += jumlah;

    simpanAkun(acc); 
    simpanRiwayat("SETOR", jumlah, acc->saldo);

    printf("\n=== STRUK SETOR TUNAI ===\n");
    printf("Jumlah disetor: %ld\n", jumlah);
    printf("Saldo sekarang: %ld\n", acc->saldo);
    printf("\n\nKETIK APA SAJA UNTUK KEMBALI KE MENU\n\n");
    getchar();
    getchar();
    system("cls");
}

void cekSaldo(const struct Account *acc) {
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
    printf("| Saldo Anda : Rp %ld,-                      |\n", acc->saldo);
    printf("|                                               |\n");
    printf("|   TERIMA KASIH SUDAH MENGGUNAKAN ATM MINI     |\n");
    printf("|                  KELOMPOK 1                   |\n");
    printf("+===============================================+\n");
     printf("\n\nKETIK APA SAJA UNTUK KEMBALI KE MENU\n\n");
    getchar();
    getchar();
    system("cls");

}

// Tampilkan riwayat transaksi dari file riwayat.txt
void riwayatTransaksi(const struct Account *acc) {
    FILE *file = fopen("riwayat.txt", "r");
    int ch;

    if (file == NULL) {
        printf("Tidak ada riwayat transaksi.\n");
        return;
    }

    printf("\n=== RIWAYAT TRANSAKSI ===\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar((char)ch);
    }
    fclose(file);
}

void simpanRiwayat(const char transaksi[], long jumlah, long saldoAkhir) {
    FILE *file = fopen("riwayat.txt", "a");

    if (file == NULL) {
        printf("Gagal menyimpan riwayat!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    

    fprintf(file,
        "+==============================================+\n"
        "|               Riwayat Transaksi              |\n"
        "|                    ATM MINI                  |\n"
        "+==============================================+\n"
        "Tanggal : %02d-%02d-%04d\n"
        "Waktu   : %02d:%02d:%02d\n"
        "[%s] Rp %ld\n"
        "Saldo Setelah Transaksi : Rp %ld\n"
        "+==============================================+\n\n",
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec,               
        transaksi, jumlah, saldoAkhir);
    fclose(file);

}

void menuRiwayat() {
    printf("\n+======================================+\n");
    printf("|    RIWAYAT TRANSAKSI TELAH DICETAK   |\n");
    printf("|     Silahkan cek file riwayat.txt    |\n");
    printf("+======================================+\n");
}

void keluar() {
    printf("\n+===================================+\n");
    printf("|  Terima kasih telah menggunakan   |\n");
    printf("|       ATM MINI KELOMPOK 1         |\n");
    printf("+===================================+\n\n");
    exit(0);
}