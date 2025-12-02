#include <stdio.h>
#include "fitur.h"

void headerMenu(struct Account *user){
    int pilihan, loop;

    while (1) {
    printf("+=======================================+\n");
    printf("|              ATM MACHINE              |\n");
    printf("+=======================================+\n");
    printf("|   1. Tarik Uang\t\t\t|\n");
    printf("|   2. Setor Uang\t\t\t|\n");
    printf("|   3. Transfer Uang\t\t\t|\n");
    printf("|   4. Lihat Saldo\t\t\t|\n");
    printf("|   5. Riwayat Transaksi\t\t|\n");
    printf("|   6. Lucky Draw\t\t\t|\n");
    printf("|   7. Ganti Pin\t\t\t|\n");
    printf("|   8. Keluar\t\t\t\t|\n");
    printf("+=======================================+\n");
    printf("Pilih menu: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        menuTarikUang(user);
        break;
    case 2:
        menuSetorUang(user);
        break;
    case 3:
        menuTransfer(user);
        break;
    case 4:
        cekSaldo(user);
        break;
    case 5:
        menuRiwayat();
        break;
    case 6:
        games(user);
        break;
    case 7:
        ubahPin(user);
        break;
    case 8:
        keluar();
        return;
        break;
    default:
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
        break;
    }
    }
    }
int main(){
    struct Account user;

    printf("+=================================+\n");
    printf("|   SELAMAT DATANG DI ATM MINI    |\n");
    printf("+=================================+\n");
    if (!akunAda()) {
        buatAkun(&user);
    } else {
        ambilAkun(&user);
    }

    login(&user);

    headerMenu(&user);
    return 0;

}