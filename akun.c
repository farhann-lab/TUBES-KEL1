#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct Account is declared in akun.h so include that instead
#include "akun.h"

// Cek apakah file akun ada
int akunAda(void) {
    FILE *file = fopen("akun.txt", "r");
    if (file == NULL) {
        printf("Anda belum memiliki akun.\n");
        return 0;
    }
    fclose(file);
    return 1;
}

// Simpan data ke file
void simpanAkun(const struct Account *acc) {
    FILE *file = fopen("akun.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    fprintf(file, "%s %s %ld", acc->nama, acc->pin, acc->saldo);
    fclose(file);
}

// Buat akun baru
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

// Ambil data dari file
void ambilAkun(struct Account *acc) {
    FILE *fp = fopen("akun.txt", "r");
    if (fp == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    fscanf(fp, "%49s %9s %ld", acc->nama, acc->pin, &acc->saldo);
    fclose(fp);
}

// Login
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

// Ubah PIN
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

// Menu utama
void menuATM(struct Account *acc) {
    int pilihan;

    while (1) {
        printf("\n=== SELAMAT DATANG %s ===\n", acc->nama);
        printf("1. Lihat Saldo\n");
        printf("2. Ubah PIN\n");
        printf("3. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            printf("Saldo Anda: %ld\n", acc->saldo);
        } 
        else if (pilihan == 2) {
            ubahPin(acc);
        }
        else if (pilihan == 3) {
            printf("Terima kasih.\n");
            return;
        }
        else {
            printf("Pilihan tidak valid.\n");
        }
    }
}

// Note: main is in main.c — this file provides account implementations only.
