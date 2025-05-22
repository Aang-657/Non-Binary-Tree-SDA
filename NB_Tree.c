#include "NB_Tree.h"

void Create_tree(Isi_Tree X, int Jml_Node) {
    for (int i = 0; i <= jml_maks; i++) {
        X[i].info = ' ';
        X[i].ps_fs = nil;
        X[i].ps_nb = nil;
        X[i].ps_pr = nil;
    }
}

bool IsEmpty(Isi_Tree P) {
    return (P[0].ps_fs == nil);
}

/*** Traversal ***/

void PreOrderNode(Isi_Tree P, int idx) {
    if (idx != nil) {
        printf("%c ", P[idx].info);
        PreOrderNode(P, P[idx].ps_fs);  // anak
        PreOrderNode(P, P[idx].ps_nb);  // saudara
    }
}
void PreOrder(Isi_Tree P) {
    if (!IsEmpty(P)) {
        PreOrderNode(P, P[0].ps_fs);
    }
}

void InOrderNode(Isi_Tree P, int idx) {
    if (idx != nil) {
        InOrderNode(P, P[idx].ps_fs);   // anak
        printf("%c ", P[idx].info);
        InOrderNode(P, P[idx].ps_nb);   // saudara
    }
}
void InOrder(Isi_Tree P) {
    if (!IsEmpty(P)) {
        InOrderNode(P, P[0].ps_fs);
    }
}

void PostOrderNode(Isi_Tree P, int idx) {
    if (idx != nil) {
        PostOrderNode(P, P[idx].ps_fs);  // anak
        PostOrderNode(P, P[idx].ps_nb);  // saudara
        printf("%c ", P[idx].info);
    }
}
void PostOrder(Isi_Tree P) {
    if (!IsEmpty(P)) {
        PostOrderNode(P, P[0].ps_fs);
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    for (int i = 1; i <= Maks_node; i++) {
        if (X[i].info != ' ') {
            printf("%c ", X[i].info);
        }
    }
}

void PrintTree(Isi_Tree P) {
    printf("Seluruh Node pada Non Binary Tree:\n\n");

    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != ' ') {
            printf("--> Indeks ke-%d\n", i);
            printf("--------------------------------------------------\n");
            printf("info array ke %d        : %c\n", i, P[i].info);
            printf("first son array ke %d   : %d\n", i, P[i].ps_fs);
            printf("next brother array ke %d: %d\n", i, P[i].ps_nb);
            printf("parent array ke %d      : %d\n", i, P[i].ps_pr);
            printf("--------------------------------------------------\n\n");
        }
    }
}

/*** Search ***/

bool SearchNode(Isi_Tree P, int idx, infotype X) {
    if (idx == nil) return false;
    if (P[idx].info == X) return true;
    return SearchNode(P, P[idx].ps_fs, X) || SearchNode(P, P[idx].ps_nb, X);
}

bool Search(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return false;
    return SearchNode(P, P[0].ps_fs, X);
}

/*** Fungsi Lain ***/

int CountAll(Isi_Tree P, int idx) {
    if (idx == nil) return 0;
    return 1 + CountAll(P, P[idx].ps_fs) + CountAll(P, P[idx].ps_nb);
}

int nbElmt(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    return CountAll(P, P[0].ps_fs);
}

int CountLeaves(Isi_Tree P, int idx) {
    if (idx == nil) return 0;
    if (P[idx].ps_fs == nil) return 1 + CountLeaves(P, P[idx].ps_nb);
    return CountLeaves(P, P[idx].ps_fs) + CountLeaves(P, P[idx].ps_nb);
}

int nbDaun(Isi_Tree P) {
    if (IsEmpty(P)) return 0;
    return CountLeaves(P, P[0].ps_fs);
}

int LevelNode(Isi_Tree P, int idx, infotype X, int current_level) {
    if (idx == nil) return -1;
    if (P[idx].info == X) return current_level;

    int child_result = LevelNode(P, P[idx].ps_fs, X, current_level + 1);
    if (child_result != -1) return child_result;

    return LevelNode(P, P[idx].ps_nb, X, current_level);
}

int Level(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return -1;
    return LevelNode(P, P[0].ps_fs, X, 0);
}

int DepthNode(Isi_Tree P, int idx) {
    if (idx == nil) return -1;

    int max_child_depth = -1;
    int child = P[idx].ps_fs;
    while (child != nil) {
        int d = DepthNode(P, child);
        if (d > max_child_depth) {
            max_child_depth = d;
        }
        child = P[child].ps_nb;
    }
    return max_child_depth + 1;
}

int Depth(Isi_Tree P) {
    if (IsEmpty(P)) return -1;
    return DepthNode(P, P[0].ps_fs);
}

int Max(int a, int b) {
    return (a > b) ? a : b;
}

void PrintVisual(Isi_Tree P, int idx, char *prefix, bool isLast) {
    if (idx == nil) return;

    printf("%s", prefix);

    if (isLast) {
        printf("`-");
    } else {
        printf("|-");
    }

    printf("%c\n", P[idx].info);

    // Buat prefix baru untuk anak-anak
    char newPrefix[100];
    sprintf(newPrefix, "%s%s", prefix, isLast ? "  " : "| ");

    // Ambil anak-anak
    int children[20];
    int count = 0;
    int child = P[idx].ps_fs;
    while (child != nil) {
        children[count++] = child;
        child = P[child].ps_nb;
    }

    // Cetak anak-anak
    for (int i = 0; i < count; i++) {
        PrintVisual(P, children[i], newPrefix, i == count - 1);
    }
}

void PrintTreeVisual(Isi_Tree P) {
    if (!IsEmpty(P)) {
        PrintVisual(P, P[0].ps_fs, "", true);
    }
}
//