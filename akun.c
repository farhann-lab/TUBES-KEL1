#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fitur.h"

// cek apakah file akun ada
int akunAda(void) {
    FILE *file = fopen("akun.txt", "r");
    if (file == NULL) {
        printf("Anda belum memiliki akun.\n");
        return 0;
    }
    fclose(file);
    return 1;
}

// simpan data ke file
void simpanAkun(const struct Account *acc) {
    FILE *file = fopen("akun.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    fprintf(file, "%s %s %ld", acc->nama, acc->pin, acc->saldo);
    fclose(file);
}

// buat akun baru
void buatAkun(struct Account *acc) {
    printf("== BUAT AKUN BARU ==\n");

    printf("Masukkan Nama (1 kata): ");
    scanf("%s", acc->nama);

    printf("Buat PIN: ");
    scanf("%s", acc->pin);

    printf("Masukkan Saldo Awal: ");
    scanf("%ld", &acc->saldo);

    simpanAkun(acc);

    printf("Akun berhasil dibuat!\n");
}

// ambil data dari file
void ambilAkun(struct Account *acc) {
    FILE *fp = fopen("akun.txt", "r");
    if (fp == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    fscanf(fp, "%49s %9s %ld", acc->nama, acc->pin, &acc->saldo);
    fclose(fp);
}

// login
void login(const struct Account *acc) {
    char pinInput[10];
    int percobaan = 0;

    while (1) {
        printf("Silahkan Masukkan PIN: ");
        scanf("%s", pinInput);

        if (strcmp(pinInput, acc->pin) == 0) {
            system("cls");
            printf("Login berhasil!\n");
            printf("Selamat datang, %s!\n", acc->nama);
            return;
        } else {
            printf("PIN salah!\n");
            printf("Sisa percobaan: %d\n", 2 - percobaan);
            percobaan++;
        }

        if (percobaan == 3) {
            printf("Terlalu banyak percobaan. Program berhenti.\n");
            exit(0);
        }
    }
}

// ubah PIN
void ubahPin(struct Account *acc) {
    char pinLama[10], pinBaru[10];

    while (1) {
    printf("Masukkan PIN lama: ");
    scanf("%s", pinLama);

    if (strcmp(pinLama, acc->pin) != 0) {
        printf("PIN lama salah.\n");
        
    } else {break;}
    }

    printf("Masukkan PIN baru: ");
    scanf("%s", pinBaru);

    strncpy(acc->pin, pinBaru, sizeof(acc->pin)-1);
    acc->pin[sizeof(acc->pin)-1] = '\0';
    simpanAkun(acc);

    printf("PIN berhasil diubah!\n");
}

