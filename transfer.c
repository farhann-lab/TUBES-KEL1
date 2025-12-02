#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fitur.h"

static void tambahRekening(char namaRek[][100], char noRek[][30], int *jmlRek);
static void lihatRekening(char namaRek[][100], char noRek[][30], int jmlRek);
static void performTransfer(char namaRek[][100], char noRek[][30], int jmlRek, struct Account *acc);


void menuTransfer(struct Account *acc){

    char namaRek[50][100];
    char noRek[50][30];
    int jmlRek = 0;

    int menu;

    do{
        printf("\n===== MENU TRANSFER =====\n");
        printf("1. Tambah Rekening\n");
        printf("2. Lihat Rekening\n");
        printf("3. Transfer\n");
        printf("4. Kembali\n");
        printf("Pilih : ");
        if (scanf("%d", &menu) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            menu = 0;
        }
        getchar();

        if(menu == 1){
            tambahRekening(namaRek, noRek, &jmlRek);
        }
        else if(menu == 2){
            lihatRekening(namaRek, noRek, jmlRek);
        }
        else if(menu == 3){
            performTransfer(namaRek, noRek, jmlRek, acc);
        }

    } while(menu != 4);

    system("cls");
    printf("Kembali ke menu utama...\n");
}

void tambahRekening(char namaRek[][100], char noRek[][30], int *jmlRek){
    if(*jmlRek < 50){

        printf("Masukkan nama pemilik : ");
        fgets(namaRek[*jmlRek], 100, stdin);
        int p = strlen(namaRek[*jmlRek]);
        if(namaRek[*jmlRek][p-1] == '\n')
            namaRek[*jmlRek][p-1] = '\0';

        printf("Masukkan nomor rekening : ");
        fgets(noRek[*jmlRek], 30, stdin);
        int q = strlen(noRek[*jmlRek]);
        if(noRek[*jmlRek][q-1] == '\n')
            noRek[*jmlRek][q-1] = '\0';

        printf("Rekening berhasil ditambah!\n");
        (*jmlRek)++;
    }
    else{
        printf("Kapasitas penuh!\n");
    }
}

void lihatRekening(char namaRek[][100], char noRek[][30], int jmlRek){
    if(jmlRek == 0){
        printf("Belum ada rekening.\n");
    } else {
        printf("\n--- DAFTAR REKENING ---\n");
        for(int i=0; i<jmlRek; i++){
            printf("%d. %s | %s\n", i+1, namaRek[i], noRek[i]);
        }
    }
}

void performTransfer(char namaRek[][100], char noRek[][30], int jmlRek, struct Account *acc){
    if(jmlRek == 0){
        printf("Tidak ada rekening tujuan.\n");
    }else{
        int pilih;
        long nominal;
        printf("\n--- PILIH REKENING TUJUAN ---\n");
        for(int i=0; i<jmlRek; i++){
            printf("%d. %s (%s)\n", i+1, namaRek[i], noRek[i]);
        }

        printf("Pilih nomor : ");
        scanf("%d", &pilih);
        getchar();

        if(pilih < 1 || pilih > jmlRek){
            printf("Pilihan tidak ada!\n");
        } else {

                printf("Masukkan nominal : ");
                if (scanf("%ld", &nominal) != 1) {
                    int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    printf("Input nominal tidak valid.\n");
                    return;
                }
            getchar();
                if(nominal <= 0){
                printf("Nominal tidak valid!\n");
            } 
                else if(nominal > acc->saldo){
                    printf("Saldo tidak cukup!\n");
            } 
            else {

                    acc->saldo = acc->saldo - nominal;

                printf("\n=== TRANSFER BERHASIL ===\n");
                printf("Dari     : %s\n", acc->nama);
                printf("Ke       : %s (%s)\n", namaRek[pilih-1], noRek[pilih-1]);
                printf("Nominal  : %ld\n", nominal);
                printf("Sisa     : %ld\n", acc->saldo);

                char tujuanFull[200];
                sprintf(tujuanFull, "%s (%s)", namaRek[pilih-1], noRek[pilih-1]);

                simpanRiwayat("TRANSFER", nominal, acc->saldo);

                printf("(Tersimpan di riwayat.txt)\n");
            }
        }
    }
}