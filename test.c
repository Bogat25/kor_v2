#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    const int MAX_VAGYAS_IDO = 3;  // Maximum válaszidő másodpercben

    time_t start_time, current_time;
    double elapsed_time;
    char user_answer[100];

    printf("Kerlek, valasz 3 masodpercen belul: ");
    fflush(stdout);

    time(&start_time);  // Elindítjuk az időmérőt

    // Beolvassuk a választ, de figyelünk az időre is
    fgets(user_answer, sizeof(user_answer), stdin);

    time(&current_time);  // Megnézzük, mennyi idő telt el
    elapsed_time = difftime(current_time, start_time);

    // Ellenőrizzük, hogy a válasz időn belül lett-e beadva
    if (elapsed_time > MAX_VAGYAS_IDO) {
        printf("Automatikus valasz: Az idokorlat lejart.\n");
    } else {
        printf("A valaszod: %s\n", user_answer);
    }

    return 0;
}
