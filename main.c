#include "include/utils.h"
void tambahMahasiswa(Mahasiswa **head) {
    int random_id;
    Mahasiswa *mahasiswa = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    puts("\n--- Tambah Mahasiswa ---");
    printf("Nama: ");
    scanf("%s", mahasiswa->nama);
    clearInputBuffer();
    printf("NIM: ");
    scanf("%s", mahasiswa->nim);
    clearInputBuffer();
    printf("Umur: ");
    scanf("%d", &mahasiswa->umur);
    clearInputBuffer();
    puts("Alamat");
    printf("- Jalan: ");
    scanf("%s", mahasiswa->alamat.jalan);
    clearInputBuffer();
    printf("- Kota: ");
    scanf("%s", mahasiswa->alamat.kota);
    clearInputBuffer();
    puts("Status: (0=AKTIF, 1=LULUS, 2=DROPOUT)");
    printf(">> ");
    scanf("%d", &mahasiswa->status);
    clearInputBuffer();
    puts("Kontak: (0=No HP, 1=Email)");
    printf(">> ");
    scanf("%d", &mahasiswa->tipe_kontak);
    clearInputBuffer();
    switch (mahasiswa->tipe_kontak) {
        case 0:
            printf("Masukan No HP: ");
            scanf("%s", mahasiswa->kontak.no_hp);
            clearInputBuffer();
            break;
        case 1:
            printf("Masukan Email: ");
            scanf("%s", mahasiswa->kontak.email);
            clearInputBuffer();
            break;
    }
    puts("\nData berhasil ditambahkan!");
    random_id = generateRandomID();
    printf("(ID Mahasiswa = %d)\n\n", random_id);
    mahasiswa->id = random_id;
    mahasiswa->next = *head;
    *head = mahasiswa;
}
void lihatMahasiswa(Mahasiswa *head) {
    int pilih_kontak;
    puts("\n--- Daftar Mahasiswa ---");
    if (head == NULL) {
        puts("\nData TIDAK ditemukan!");
    }
    while (head != NULL) {
        printf("ID\t\t: %d\n",head->id);
        printf("Nama\t: %s\n", head->nama);
        printf("NIM\t\t: %s\n", head->nim);
        printf("Umur\t: %d\n", head->umur);
        puts("Alamat");
        printf("- Jalan\t: %s\n", head->alamat.jalan);
        printf("- Kota\t: %s\n", head->alamat.kota);
        switch (head->status) {
            case AKTIF:
                puts("Status\t: AKTIF");
                break;
            case LULUS:
                puts("Status\t: LULUS");
                break;
            case DROPOUT:
                puts("Status\t: DROPOUT");
                break;
        }
        switch (head->tipe_kontak) {
            case 0:
                printf("Kontak\t: %s\n",head->kontak.no_hp);
                break;
            case 1:
                printf("Kontak\t: %s\n",head->kontak.email);
                break;
        }
        head = head->next;
        puts("----------------------------");
    }
}
Mahasiswa *cariMahasiswa(Mahasiswa *head, int id) {
    while (head != NULL) {
        if (head->id == id) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}
void editMahasiswa(Mahasiswa *head, int id) {
    int ubah_field;
    Mahasiswa *mahasiswa = head;
    Mahasiswa *cari_mahasiswa = cariMahasiswa(mahasiswa, id);
    if (cari_mahasiswa != NULL) {
        puts("Data ditemukan!");
        puts("Field yang bisa diubah: ");
        puts("1. Nama");
        puts("2. NIM");
        puts("3. Umur");
        puts("4. Alamat");
        puts("5. Status");
        puts("6. Kontak");
        printf(">> ");
        scanf("%d", &ubah_field);
        switch (ubah_field) {
            case 1:
                printf("Nama: ");
                scanf("%s", cari_mahasiswa->nama);
                break;
            case 2:
                printf("NIM: ");
                scanf("%s", cari_mahasiswa->nim);
                break;
            case 3:
                printf("Umur: ");
                scanf("%d", &cari_mahasiswa->umur);
                break;
            case 4:
                puts("Alamat");
                printf("- Jalan: ");
                scanf("%s", cari_mahasiswa->alamat.jalan);
                printf("- Kota: ");
                scanf("%s", cari_mahasiswa->alamat.kota);
                break;
            case 5:
                puts("Status: (0=AKTIF, 1=LULUS, 2=DROPOUT)");
                printf(">> ");
                scanf("%d", &cari_mahasiswa->status);
                break;
            case 6:
                puts("Kontak: (0=No HP, 1=Email)");
                printf(">> ");
                scanf("%d", &cari_mahasiswa->tipe_kontak);
                switch (cari_mahasiswa->tipe_kontak) {
                    case 0:
                        printf("Masukan No HP: ");
                        scanf("%s", cari_mahasiswa->kontak.no_hp);
                        break;
                    case 1:
                        printf("Masukan Email: ");
                        scanf("%s", cari_mahasiswa->kontak.email);
                        break;
                }
                break;
        }
        puts("\nUpdate berhasil!");
    } else {
        puts("\nData TIDAK ditemukan!");
    }
}
void hapusMahasiswa(Mahasiswa **head, int id) {
    Mahasiswa *current = *head;
    Mahasiswa *previous = NULL;
    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        puts("\nData TIDAK ditemukan!");
    } else if (current != NULL) {
        if (previous == NULL) {
            *head = current->next;
            free(current);
            puts("Data berhasil dihapus!\n");
        } else if (previous != NULL) {
            previous->next = current->next;
            free(current);
            puts("Data berhasil dihapus!\n");
        }
    }
}
void tampilkanStatistik(Mahasiswa *head) {
    puts("\n--- Statistik Mahasiswa ---");
    int total_mahasiswa = 0;
    int aktif_mahasiswa = 0;
    int lulus_mahasiswa = 0;
    int dropout_mahasiswa = 0;
    while (head != NULL) {
        total_mahasiswa++;
        switch (head->status) {
            case 0:
                aktif_mahasiswa++;
                break;
            case 1:
                lulus_mahasiswa++;
                break;
            case 2:
                dropout_mahasiswa++;
                break;
        }
        head = head->next;
    }
    printf("Total Mahasiswa : %d\n", total_mahasiswa);
    printf("AKTIF\t: %d\n",aktif_mahasiswa);
    printf("LULUS\t: %d\n",lulus_mahasiswa);
    printf("DROPOUT\t: %d\n\n",dropout_mahasiswa);
}
void tampilMenu() {
    puts("==============================");
    puts("MINI DATABASE MAHASISWA (CRUD)");
    puts("==============================");
    puts("1. Tambah Mahasiswa");
    puts("2. Lihat Mahasiswa");
    puts("3. Edit Mahasiswa");
    puts("4. Hapus Mahasiswa");
    puts("5. Statistik");
    puts("6. Save Data (COOMING SOON)");
    puts("7. Load Data (COOMING SOON");
    puts("8. Keluar");

}
void jalankanAplikasi() {
    void (*ptrTampilMenu)(void);
    ptrTampilMenu = &tampilMenu;
    ptrTampilMenu();
}
int main() {
    srand((unsigned int)time(NULL));
    int pilih_menu;
    int cari_mahasiswa;
    Mahasiswa *mahasiswa = NULL;
    do {
        jalankanAplikasi();
        printf(">> ");
        scanf("%d", &pilih_menu);
        switch (pilih_menu) {
            case 1:
                tambahMahasiswa(&mahasiswa);
                break;
            case 2:
                lihatMahasiswa(mahasiswa);
                break;
            case 3:
                printf("Masukan ID Mahasiswa yang ingin diedit: ");
                scanf("%d", &cari_mahasiswa);
                editMahasiswa(mahasiswa, cari_mahasiswa);
                break;
            case 4:
                printf("Masukan ID Mahasiswa yang ingin dihapus: ");
                scanf("%d", &cari_mahasiswa);
                hapusMahasiswa(&mahasiswa, cari_mahasiswa);
                break;
            case 5:
                tampilkanStatistik(mahasiswa);
                break;
            case 8:
                freeAll(&mahasiswa);
                puts("Membebaskan semua data...");
                puts("Terima kasih sudah menggunakan aplikasi ini!");
                exit(0);
        }
    } while (1);
    return 0;
}