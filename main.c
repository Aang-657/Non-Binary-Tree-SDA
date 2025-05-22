#include <stdio.h>
#include <stdlib.h>
#include "NB_Tree.h"



int main() {
    Isi_Tree T;
    int pilihan, jmlNode;
    char cari;

    do {
        printf("\n==== PROGRAM NON BINARY TREE ====\n");
        printf("1. Create Tree\n");
        printf("2. Traversal PreOrder\n");
        printf("3. Traversal InOrder\n");
        printf("4. Traversal PostOrder\n");
        printf("5. Traversal LevelOrder\n");
        printf("6. Print Tree\n");
        printf("7. Hitung Jumlah Node\n");
        printf("8. Hitung Jumlah Daun\n");
        printf("9. Cari Node\n");
        printf("10. Tampilkan Level Node\n");
        printf("11. Tampilkan Depth Tree\n");
        printf("12. Tampilkan Tree Visual\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan jumlah node (maks %d): ", jml_maks);
                scanf("%d", &jmlNode);
                Create_tree(T, jmlNode);
                // Contoh isi Tree sesuai PDF:
                T[1].info = 'A'; T[1].ps_fs = 2;
                T[2].info = 'B'; T[2].ps_pr = 1; T[2].ps_fs = 4; T[2].ps_nb = 3;
                T[3].info = 'C'; T[3].ps_pr = 1; T[3].ps_fs = 6;
                T[4].info = 'D'; T[4].ps_pr = 2; T[4].ps_nb = 5;
                T[5].info = 'E'; T[5].ps_pr = 2;
                T[6].info = 'F'; T[6].ps_pr = 3; T[6].ps_nb = 7;
                T[7].info = 'G'; T[7].ps_pr = 3; T[7].ps_nb = 8;
                T[8].info = 'H'; T[8].ps_pr = 3;
                T[0].ps_fs = 1; // root ada di indeks 1
                printf("Tree berhasil dibuat.\n");
                break;

            case 2:
                printf("Traversal PreOrder: ");
                PreOrder(T);
                printf("\n");
                break;

            case 3:
                printf("Traversal InOrder: ");
                InOrder(T);
                printf("\n");
                break;

            case 4:
                printf("Traversal PostOrder: ");
                PostOrder(T);
                printf("\n");
                break;

            case 5:
                printf("Traversal LevelOrder: ");
                Level_order(T, jml_maks);
                printf("\n");
                break;

            case 6:
                printf("Isi Tree : ");
                PrintTree(T);
                printf("\n");
                break;

            case 7:
                printf("Jumlah Node: %d\n", nbElmt(T));
                break;

            case 8:
                printf("Jumlah Daun: %d\n", nbDaun(T));
                break;

            case 9:
                printf("Masukkan karakter yang ingin dicari: ");
                scanf(" %c", &cari);
                if (Search(T, cari)) {
                    printf("Node '%c' ditemukan.\n", cari);
                } else {
                    printf("Node '%c' tidak ditemukan.\n", cari);
                }
                break;

            case 10:
                printf("Masukkan node yang ingin dicek level-nya: ");
                scanf(" %c", &cari);
                printf("Level node '%c' adalah %d\n", cari, Level(T, cari));
                break;

            case 11:
                printf("Depth Tree: %d\n", Depth(T));
                break;
            case 12:
                printf("Tampilkan Tree Visual:\n");
                PrintTreeVisual(T);
                break;
            case 0:
                printf("Keluar program.\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 0);

    return 0;
}


