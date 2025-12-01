#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cekSaldo() {
    int saldo = 1500000;
    return saldo;
}

void simpanHistory(char penerima[], int jumlah) {
    FILE *f;
    f = fopen("history.txt", "a");
    if (f == NULL) {
        printf("Gagal membuka file history...\n");
        return;
    }
    fprintf(f, "TRANSFER KE %s : %d\n", penerima, jumlah);
    fclose(f);
}

void transfer() {
    char namaUser[20] = "Tiara";
    char namaTujuan[100];
    char line[200];
    int nominal;
    int saldo = cekSaldo();

    printf("=== MENU TRANSFER UANG ===\n\n");

    // baca nama penerima (boleh ada spasi)
    printf("Masukkan nama penerima : ");
    if (fgets(namaTujuan, sizeof(namaTujuan), stdin) == NULL) {
        printf("Input gagal.\n");
        return;
    }
    // hapus newline jika ada
    size_t L = strlen(namaTujuan);
    if (L > 0 && (namaTujuan[L-1] == '\n' || namaTujuan[L-1] == '\r')) {
        namaTujuan[L-1] = '\0';
        L--;
        // handle CRLF (Windows)
        if (L > 0 && namaTujuan[L-1] == '\r') namaTujuan[L-1] = '\0';
    }

    // baca nominal dengan validasi
    while (1) {
        printf("Masukkan nominal transfer : ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Input gagal.\n");
            return;
        }
        // hapus newline
        size_t ln = strlen(line);
        if (ln > 0 && (line[ln-1] == '\n' || line[ln-1] == '\r')) {
            line[ln-1] = '\0';
            ln--;
            if (ln > 0 && line[ln-1] == '\r') line[ln-1] = '\0';
        }

        // konversi dan cek
        char *endptr;
        long val = strtol(line, &endptr, 10);
        if (endptr == line || *endptr != '\0') {
            printf("Input nominal tidak valid. Masukkan angka saja.\n");
            continue;
        }
        if (val <= 0) {
            printf("Nominal harus lebih besar dari 0.\n");
            continue;
        }
        nominal = (int) val;
        break;
    }

    if (nominal > saldo) {
        printf("\nMaaf saldo Anda tidak cukup!\n");
        return;
    }

    saldo = saldo - nominal;

    printf("\nTransfer berhasil!\n");
    printf("Pengirim    : %s\n", namaUser);
    printf("Penerima    : %s\n", namaTujuan);
    printf("Jumlah      : %d\n", nominal);
    printf("Sisa Saldo  : %d\n", saldo);

    simpanHistory(namaTujuan, nominal);
    printf("\n(Riwayat tersimpan di history.txt)\n");
}

int main() {
    // PENTING: kalau program lain sebelumnya pakai scanf(), kadang ada newline tersisa.
    // Karena kita cuma pakai fgets() di sini, main langsung panggil fungsi transfer.
    transfer();
    return 0;
}
