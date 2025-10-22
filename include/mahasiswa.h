#ifndef MINI_DATABASE_SYSTEM_MAHASISWA_H
#define MINI_DATABASE_SYSTEM_MAHASISWA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
enum StatusMahasiswa {
    AKTIF,
    LULUS,
    DROPOUT
};
struct Alamat {
    char jalan[100];
    char kota[50];
};
union Kontak {
    char no_hp[20];
    char email[50];
};
typedef struct Mahasiswa {
    int id;
    char nama[50];
    char nim[20];
    int umur;
    enum StatusMahasiswa status;
    struct Alamat alamat;
    union Kontak kontak;
    int tipe_kontak;
    struct Mahasiswa *next;
} Mahasiswa;
#endif //MINI_DATABASE_SYSTEM_MAHASISWA_H
