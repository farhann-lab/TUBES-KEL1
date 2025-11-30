#include <stdio.h>
#include "akun.h"

void headerMenu(struct Account *user){
    int pilihan, loop;

    while (1) {
    printf("+=======================================+\n");
    printf("|              ATM MACHINE              |\n");
    printf("+=======================================+\n");
    printf("|1. Tarik Uang\t\t\t\t|\n");
    printf("|2. Setor Uang\t\t\t\t|\n");
    printf("|3. Transfer Uang\t\t\t|\n");
    printf("|4. Lihat Saldo\t\t\t\t|\n");
    printf("|5. Riwayat Transaksi\t\t\t|\n");
    printf("|6. Lucky Draw\t\t\t\t|\n");
    printf("|7. Ganti Pin\t\t\t\t|\n");
    printf("|8. Keluar\t\t\t\t|\n");
    printf("+=======================================+\n");
    printf("Pilih menu: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:

        break;
    case 4:
        printf("Saldo Anda: %ld\n", user->saldo);
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        ubahPin(user);
        break;
    case 8:
        printf("Keluar dari menu.\n");
        return;
        break;
    default:
        break;
    }
    }
    }
int main(){
    struct Account user;

    printf("+=================================+\n");
    printf("|    SELAMAT DATANG DI ATM C11    |\n");
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