#ifndef AKUN_H
#define AKUN_H

#include <stdio.h>

// Keep the struct in header so every file including this header knows the type
struct Account {
    char nama[50];
    char pin[10];
    long saldo;
};

// Function prototypes (declarations only) -------------------------------
// check if account file exists
int akunAda(void);

// save an account; const pointer indicates this function won't modify the account
void simpanAkun(const struct Account *acc);

// create/load/change account helpers
void buatAkun(struct Account *acc);
void ambilAkun(struct Account *acc);

// login (read-only - accepts pointer to account)
void login(const struct Account *acc);

// update operations
void ubahPin(struct Account *acc);

// main menu for ATM operations (receives pointer so changes persist)
void menuATM(struct Account *acc);

#endif // AKUN_H
