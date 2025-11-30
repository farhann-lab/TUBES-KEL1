#include <stdio.h>

struct Akun
{
    char nama[50];
    char pin[20];
    long saldo;
};
 
void headerMenu(){
    int pilihan;
    printf("+=======================================+\n");
    printf("|              ATM MACHINE              |\n");
    printf("+=======================================+\n");
    printf("|1. Tarik Uang\t\t\t\t|\n");
    printf("|2. Setor Uang\t\t\t\t|\n");
    printf("|3. Transfer Uang\t\t\t|\n");
    printf("|4. Lihat Saldo\t\t\t\t|\n");
    printf("|5. Riwayat Transaksi\t\t\t|\n");
    printf("|6. Lucky Draw\t\t\t\t|\n");
    printf("|7. Keluar\t\t\t\t|\n");
    printf("+=======================================+\n");
    printf("Pilih menu: ");
    // scanf("%d", &pilihan);

}
int main(){
    struct Akun akun;


    
    headerMenu();
    return 0;

}