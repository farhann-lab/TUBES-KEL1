// transaksi.h — transaction API for the ATM program
#ifndef TRANSAKSI_H
#define TRANSAKSI_H

#include "akun.h" // struct Account

// transaction operations (use Account pointer so changes persist)
void menuTarikUang(struct Account *acc);
void menuSetorUang(struct Account *acc);
void cekSaldo(const struct Account *acc);
void simpanSaldo(const struct Account *acc);
void simpanRiwayat(const char transaksi[], long jumlah, long saldoAkhir);

#endif // TRANSAKSI_H