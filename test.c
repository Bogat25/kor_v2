#define _CRT_SECURE_NO_WARNINGS //itt tesztelem az új ismereteket
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("alma");
    int a = 0;
    scanf("%d", &a);
    printf("\x1b[1F"); // elso karakter a sorban
    printf("\x1b[2K"); // kitorli a sort
    printf("Korte");
    scanf("%d", &a);
    printf("and");
}