#ifndef FITUR_H
#define FITUR_H

#include <stdio.h>

struct Account {
    char nama[50];
    char pin[10];
    long saldo;
};

// function akun (login)
int akunAda(void);
void simpanAkun(const struct Account *acc);
void buatAkun(struct Account *acc);
void ambilAkun(struct Account *acc);
void login(const struct Account *acc);
void ubahPin(struct Account *acc);

// function games
void games(struct Account *acc);

// menu transaksi
void menuTarikUang(struct Account *acc);
void menuSetorUang(struct Account *acc);
void cekSaldo(const struct Account *acc);
void simpanRiwayat(const char transaksi[], long jumlah, long saldoAkhir);
void riwayatTransaksi(const struct Account *acc);
void menuRiwayat();

// menu transfer
void menuTransfer(struct Account *acc);

void keluar();

#endif // FITUR_H
