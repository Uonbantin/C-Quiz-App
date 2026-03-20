#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
    char debai[200];
    char dapanA[100];
    char dapanB[100];
    char dapanC[100];
    char dapanD[100];
    char dapandung[5];
} info;

int main(){
    int diem = 0;

    srand(time(NULL));

    char hovaten[50];

    printf("Nhap ten cua ban: ");
    
    fgets(hovaten, 50, stdin); hovaten[strcspn(hovaten, "\r\n")] = '\0';

    FILE* de = fopen("cauhoi.txt", "r");

    info* cauhoi = (info*)calloc(201, sizeof(info));

    int cnt = 0;

    while (fgets(cauhoi[cnt].debai, 200, de) != NULL) {
        fgets(cauhoi[cnt].dapanA, 100, de);
        fgets(cauhoi[cnt].dapanB, 100, de);
        fgets(cauhoi[cnt].dapanC, 100, de);
        fgets(cauhoi[cnt].dapanD, 100, de);
        fgets(cauhoi[cnt].dapandung, 5, de);
        cnt++;
    }

    fclose(de);

    for (int i = cnt - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        info tmp = cauhoi[i];
        cauhoi[i] = cauhoi[j];
        cauhoi[j] = tmp;
    }

    for (int i = 0; i < 10; i++) {
        char ans;
        printf("Cau %d: %s\n%s %s %s %s\n", i + 1, cauhoi[i].debai, cauhoi[i].dapanA, cauhoi[i].dapanB, cauhoi[i].dapanC, cauhoi[i].dapanD);
        printf("Dap an cua ban la: ");
        scanf("%c", &ans); getchar();
        if(ans == cauhoi[i].dapandung[0]) diem++;
    }

    FILE* log = fopen("log.txt", "a");
    time_t curtime;
    time(&curtime);

    char* tg = ctime(&curtime); tg[strcspn(tg, "\n")] = '\0';
    fprintf(log, "\n%s %s %d", tg, hovaten, diem);
    fclose(log);

    printf("Ban dat duoc %d diem", diem);
    free(cauhoi);
    return 0;
}
