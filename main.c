#include <stdio.h>
#include <string.h>

#define MAX 100

// ================= STRUCTURES =================

struct Produit {
    char ref[30];
    char categorie[30];
    int quantite;
};

struct Client {
    int id;
    char nom[50];
};

struct Commande {
    int id;
    int idClient;
    char refProduit[30];
    int quantite;
};

struct Stock {
    char refProduit[30];
    int quantite;
    char emplacement[30];
};

struct Lot {
    char refProduit[30];
    char numLot[20];
    char datePeremption[20];
};

// ================= PRODUITS =================

void ajouterProduit(struct Produit p[], int *n) {
    printf("Reference: ");
    scanf("%s", p[*n].ref);

    printf("Categorie: ");
    scanf("%s", p[*n].categorie);

    printf("Quantite: ");
    scanf("%d", &p[*n].quantite);

    (*n)++;
}

void afficherProduits(struct Produit p[], int n) {
    for(int i=0; i<n; i++) {
        printf("%s | %s | %d\n", p[i].ref, p[i].categorie, p[i].quantite);
    }
}

// ================= ENTREE STOCK =================

void entreeStock(struct Produit p[], int n) {
    char ref[30];
    int qte;

    printf("Reference produit: ");
    scanf("%s", ref);

    printf("Quantite ajoutee: ");
    scanf("%d", &qte);

    for(int i=0; i<n; i++) {
        if(strcmp(p[i].ref, ref) == 0) {
            p[i].quantite += qte;
            printf("Stock mis a jour.\n");
            return;
        }
    }

    printf("Produit non trouve.\n");
}

// ================= SORTIE STOCK =================

void sortieStock(struct Produit p[], int n) {
    char ref[30];
    int qte;

    printf("Reference produit: ");
    scanf("%s", ref);

    printf("Quantite sortie: ");
    scanf("%d", &qte);

    for(int i=0; i<n; i++) {
        if(strcmp(p[i].ref, ref) == 0) {
            if(p[i].quantite >= qte) {
                p[i].quantite -= qte;
                printf("Sortie effectuee.\n");
            } else {
                printf("Stock insuffisant !\n");
            }
            return;
        }
    }

    printf("Produit non trouve.\n");
}

// ================= CLIENTS =================

void ajouterClient(struct Client c[], int *n) {
    printf("ID: ");
    scanf("%d", &c[*n].id);

    printf("Nom: ");
    scanf("%s", c[*n].nom);

    (*n)++;
}

void afficherClients(struct Client c[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d | %s\n", c[i].id, c[i].nom);
    }
}

// ================= COMMANDES =================

void creerCommande(struct Commande cmd[], int *nCmd) {
    printf("ID commande: ");
    scanf("%d", &cmd[*nCmd].id);

    printf("ID client: ");
    scanf("%d", &cmd[*nCmd].idClient);

    printf("Reference produit: ");
    scanf("%s", cmd[*nCmd].refProduit);

    printf("Quantite: ");
    scanf("%d", &cmd[*nCmd].quantite);

    (*nCmd)++;
}

void afficherCommandes(struct Commande cmd[], int nCmd) {
    for(int i=0; i<nCmd; i++) {
        printf("Cmd %d | Client %d | %s | %d\n",
               cmd[i].id, cmd[i].idClient,
               cmd[i].refProduit, cmd[i].quantite);
    }
}

// ================= EMPLACEMENTS =================

void affecterEmplacement(struct Stock s[], int *n) {
    printf("Reference produit: ");
    scanf("%s", s[*n].refProduit);

    printf("Quantite: ");
    scanf("%d", &s[*n].quantite);

    printf("Emplacement: ");
    scanf("%s", s[*n].emplacement);

    (*n)++;
}

void afficherStockParEmplacement(struct Stock s[], int n) {
    for(int i=0; i<n; i++) {
        printf("%s | %d | %s\n",
               s[i].refProduit,
               s[i].quantite,
               s[i].emplacement);
    }
}

// ================= LOTS =================

void ajouterLot(struct Lot l[], int *n) {
    printf("Reference produit: ");
    scanf("%s", l[*n].refProduit);

    printf("Numero lot: ");
    scanf("%s", l[*n].numLot);

    printf("Date peremption: ");
    scanf("%s", l[*n].datePeremption);

    (*n)++;
}

void afficherLots(struct Lot l[], int n) {
    for(int i=0; i<n; i++) {
        printf("%s | %s | %s\n",
               l[i].refProduit,
               l[i].numLot,
               l[i].datePeremption);
    }
}

// ================= TABLEAU DE BORD =================

void afficherStockDisponible(struct Produit p[], int n) {
    printf("\n--- STOCK DISPONIBLE ---\n");
    for(int i=0; i<n; i++) {
        printf("%s : %d\n", p[i].ref, p[i].quantite);
    }
}

// ================= MAIN =================

int main() {
    struct Produit produits[MAX];
    struct Client clients[MAX];
    struct Commande commandes[MAX];
    struct Stock stocks[MAX];
    struct Lot lots[MAX];

    int nP=0, nC=0, nCmd=0, nS=0, nL=0;
    int choix;

    do {
        printf("\n===== MENU MODULE 3 =====\n");
        printf("1. Ajouter produit\n");
        printf("2. Entree stock\n");
        printf("3. Sortie stock\n");
        printf("4. Ajouter client\n");
        printf("5. Creer commande\n");
        printf("6. Affecter emplacement\n");
        printf("7. Ajouter lot\n");
        printf("8. Afficher produits\n");
        printf("9. Tableau de bord\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterProduit(produits, &nP); break;
            case 2: entreeStock(produits, nP); break;
            case 3: sortieStock(produits, nP); break;
            case 4: ajouterClient(clients, &nC); break;
            case 5: creerCommande(commandes, &nCmd); break;
            case 6: affecterEmplacement(stocks, &nS); break;
            case 7: ajouterLot(lots, &nL); break;
            case 8: afficherProduits(produits, nP); break;
            case 9: afficherStockDisponible(produits, nP); break;
        }

    } while(choix != 0);

    return 0;
}
