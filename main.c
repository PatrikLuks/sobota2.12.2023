#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DELKA_HESLA 10
#define POVOLENE_ZNAKY "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

char generujNahodnyZnak() { // funkce slouzici k generovani nahodnych znaku
    int index = rand() % (sizeof(POVOLENE_ZNAKY) - 1);  // promena index se nastavi na nahodne cislo od 0 po pocet znaku z povolenych znaku
    return POVOLENE_ZNAKY[index]; //vybere znak ze vsech povolenych znaku
}

void generujHeslo(char heslo[]) {  //funkce bez hodnoty, do ktere se vlozi pole znaku
    for (int i = 0; i < DELKA_HESLA; i++) {     //cyklus, ve kterem se dopocitava do velikosti delky hesla
        heslo[i] = generujNahodnyZnak();        //ke kazdmu indexu od 0 po 10 se priradi nahodny znak z povolenych znaku
    }
    heslo[DELKA_HESLA] = '\0';      //jedenacty index pole nastavi na nulu, aby znacil konec retezce
}

int jeHesloUnikatni(const char heslo[]) {   //promena, do ktere se vlozi vygenerovane heslo
    for (int i = 0; i < DELKA_HESLA - 1; i++) {   //cyklus, ve kterem se dopocitava do indexu hesla
        for (int j = i + 1; j < DELKA_HESLA; j++) { //druhy cyklus, ve kterem se dopocitava do indexu hesla
            if (heslo[i] == heslo[j]) { //pokud se nejake znaky v hesle (krome 0 na konci) shoduji, returnuje se chyba
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand((unsigned int)time(NULL)); //nahodne cislo vytvorene s pomoci casu

    char heslo[DELKA_HESLA + 1]; //vytvori se pole znaku o velikosti delky hesla i nuly pro ukonceni retezce

    printf("Program generuje náhodná hesla z povolené skupiny znaků.\n");

    while (1){  //nekonecna smycka diky nenulovemu cislu
        generujHeslo(heslo);  //vyvolani funkce pro generaci hesla s argumentem heslo

        while (!jeHesloUnikatni(heslo)) {  //pokud se v puvodnim hesle znaky opakovali, vytvori se heslo nove
            generujHeslo(heslo);
        }

        printf("Vygenerované heslo: %s\n", heslo); //za %s se dosadi heslo

        printf("Chcete generovat další heslo? (ano/ne): \n");
        char volba[3];  //vytvori se pole znaku se tremi prvky
        scanf("%3s", volba);    //scanf oscanuje zadany text konzoli a ulozi je do  promene volba

        int porovnani = 1;  //promena porovnani se nastavi na hodnotu 1
        for (int i = 0; i < 2; i++) {   //cyklus, ve kterem se dopocitava od nuly do dvou
            if (volba[i] != "ne"[i]) {   //podminka, ve ktere pokud se do konzole vpise "ne", ukonci program
                porovnani = 0; //pokud se nevpise "ne", provnani se nastavi na nulu a ukonci pouze tento cyklus
                break;
            }
        }

        if (porovnani) {    //pokud se porovnani rovna "ne", prorovnani se nastavi na kladnou hodnotu, ukonci se program
            break;
        }
    }

    return 0;
}
