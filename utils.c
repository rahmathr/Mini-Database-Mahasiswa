#include "include/utils.h"
int generateRandomID() {
    int angka_acak = (rand() % 90000) + 10000;
    return angka_acak;
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF){};
}
void freeAll(Mahasiswa **head) {
    Mahasiswa *current = *head;
    Mahasiswa *next_node = NULL;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
}
