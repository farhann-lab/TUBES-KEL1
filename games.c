#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fitur.h" 
//test
void games(struct Account *acc) {
    long saldo = acc -> saldo;
    int gamble, roll;
    int g1, g2, g3, r1, r2, r3;
    int cocok = 0;
    long hadiah = 0;

    if (saldo < 20000) {
        printf("You are too broke to gamble, minimal 20 ribu lah\n");
        return;
    }

    printf("      ----$----\n    Gamble 3 digits (000-999)\n\n  \t    -> ");
    if (scanf("%d", &gamble) != 1) {
        printf("\n\nX X X Input invalid. X X X \n");
        return;
    }

    if (gamble < 0 || gamble > 999) {
        printf("\n\n|   Nomor harus antara 000-999.   |\n");
        return;
    }

    // fee
    acc->saldo -= 20000;

    srand((unsigned)time(NULL));
    roll = rand() % 1000;

    g1 = gamble / 100;
    g2 = (gamble / 10) % 10;
    g3 = gamble % 10;

    r1 = roll / 100;
    r2 = (roll / 10) % 10;
    r3 = roll % 10;

    if (g1 == r1) cocok++;
    if (g2 == r2) cocok++;
    if (g3 == r3) cocok++;

    if (cocok == 1) hadiah = 10000;
    if (cocok == 2) hadiah = 30000;
    if (cocok == 3) hadiah = 100000;

    acc->saldo += hadiah;

    simpanAkun(acc);
    simpanRiwayat("LUCKY", hadiah, acc->saldo);

    time_t now = time(NULL);
    struct tm *w = localtime(&now);

    printf("\n\n | [%02d-%02d-%04d %02d:%02d] Roll: %03d         |", w->tm_mday, w->tm_mon + 1, w->tm_year + 1900,
           w->tm_hour, w->tm_min);
    getchar();
    printf("\n\tJRENG JRENG JRENG\n");
    getchar();
    printf("\n | Gamble: %03d                          |\n | Cocok: %d                           |\n | Hadiah: %ld                            |\n | Fee: -20000\n", roll, gamble, hadiah);

    printf("\n\n---=$ Saldo sekarang: %ld $=---\n\n", acc->saldo);
     printf("\n\nKETIK APA SAJA UNTUK KEMBALI KE MENU\n\n");
    getchar();
    system("cls");
}
