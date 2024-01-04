#include <stdio.h>
#include "sign_up.h"
#include "log_in.h"
#include "rezervasyon_yapma.h"
#include "rezervasyon_gorme.h"
#include "iptal_etme.h"

#define MAX_USERS 50 // Sistemin isleyebilecegi maksimum kullanici sayisi

int main() {

    int variable = 0;
    int choice;
    int logCtrl;

    do {
        printf("\n\n_______________ANA SAYFA_____________\n\n");
        loginAgain:
        printf("\t1. Uye ol\n\t2. Giris yap\n\t3. Programdan cik\n\n");
        printf("_____________________________________\n\n");

        printf("\tSeciminiz:");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                signup();
                break;
            case 2:
                logCtrl = login();
                if (logCtrl == 1) {
                    do {
                        printf("_______________SAYFANIZ______________\n");
                        printf("\n1. Ucus rezervasyonu yap\n2. Ucuslarimi goster\n3. Rezervasyonumu iptal et\n4. Cikis yap\n");
                        printf("_____________________________________\n");

                        printf("Seciminiz:");
                        scanf("%d", &choice);

                        switch (choice) {
                            case 1:
                                rezYap();
                                break;
                            case 2:
                                rezGor();
                                break;
                            case 3:
                                iptalEt() ;
                                break;
                            case 4:
                                variable = 0;
                                break;
                            default:
                                printf("Gecersiz secim yaptiniz. Lutfen tekrar deneyiniz.\n");
                        }
                    } while (choice != 4);
                }
                else {
                    printf("Gecersiz kullanici ID ya da sifre\n\n");
                    goto loginAgain;
                }
                break;
            case 3:
                printf("Programdan cikiliyor\n");
                variable = 1;
                break;
            default:
                printf("Gecersiz secim yaptiniz. Lutfen tekrar deneyiniz.\n");
        }
    }while (variable == 0); // 3 secilene kadar sonsuz donguye girer
}
