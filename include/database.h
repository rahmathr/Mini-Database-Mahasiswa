#ifndef MINI_DATABASE_SYSTEM_DATABASE_H
#define MINI_DATABASE_SYSTEM_DATABASE_H
#include "mahasiswa.h"
void saveData(Mahasiswa *head, const char *filename);
void loadData(Mahasiswa **head, const char *filename);
#endif //MINI_DATABASE_SYSTEM_DATABASE_H