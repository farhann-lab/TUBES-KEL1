#include <stdio.h>
#include <string.h>

int cekSaldo(){
    return 1500000;
}

void simpanRiwayat(char tipe[], char tujuan[], int jml){
    FILE *fp;
    fp = fopen("riwayat.txt","a");
    if(fp != NULL){
        fprintf(fp,"%s | TUJUAN: %s | NOMINAL: %d\n", tipe, tujuan, jml);
        fclose(fp);
    }
}

int main(){

    char namaRek[50][100];
    char noRek[50][30];
    int jmlRek = 0;

    int menu;
    int saldo = cekSaldo();

    do{
        printf("\n===== MENU BANK =====\n");
        printf("1. Tambah Rekening\n");
        printf("2. Lihat Rekening\n");
        printf("3. Transfer\n");
        printf("4. Keluar\n");
        printf("Pilih : ");
        scanf("%d", &menu);
        getchar();

        if(menu == 1){
            if(jmlRek < 50){

                printf("Masukkan nama pemilik : ");
                fgets(namaRek[jmlRek], sizeof(namaRek[jmlRek]), stdin);
                int p = strlen(namaRek[jmlRek]);
                if(namaRek[jmlRek][p-1] == '\n') namaRek[jmlRek][p-1] = '\0';

                printf("Masukkan nomor rekening : ");
                fgets(noRek[jmlRek], sizeof(noRek[jmlRek]), stdin);
                int q = strlen(noRek[jmlRek]);
                if(noRek[jmlRek][q-1] == '\n') noRek[jmlRek][q-1] = '\0';

                printf("Rekening berhasil ditambah!\n");
                jmlRek++;
            }
            else{
                printf("Kapasitas penuh!\n");
            }
        }

        else if(menu == 2){
            if(jmlRek == 0){
                printf("Belum ada rekening.\n");
            } else {
                printf("\n--- DAFTAR REKENING ---\n");
                for(int i=0; i<jmlRek; i++){
                    printf("%d. %s | %s\n", i+1, namaRek[i], noRek[i]);
                }
            }
        }

        else if(menu == 5){
            if(jmlRek == 0){
                printf("Tidak ada rekening tujuan.\n");
            }else{
                int pilih, nominal;

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
                    scanf("%d", &nominal);
                    getchar();

                    if(nominal <= 0){
                        printf("Nominal tidak valid!\n");
                    } else if(nominal > saldo){
                        printf("Saldo tidak cukup!\n");
                    } else {
                        saldo -= nominal;

                        printf("\n=== TRANSFER BERHASIL ===\n");
                        printf("Dari     : Tiara\n");
                        printf("Ke       : %s (%s)\n", namaRek[pilih-1], noRek[pilih-1]);
                        printf("Nominal  : %d\n", nominal);
                        printf("Sisa     : %d\n", saldo);

                        char tujuanFull[200];
                        sprintf(tujuanFull, "%s (%s)", namaRek[pilih-1], noRek[pilih-1]);

                        simpanRiwayat("TRANSFER", tujuanFull, nominal);

                        printf("(Tersimpan di riwayat.txt)\n");
                    }
                }
            }
        }

    }while(menu != 4);

    printf("Keluar dari program...\n");

    return 0;
}