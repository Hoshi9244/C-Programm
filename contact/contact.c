#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_NOM 20
#define TAILLE_PRENOM 20
#define TAILLE_NUM 11

struct Contact
{
    char nom[TAILLE_NOM];
    char prenom[TAILLE_PRENOM];
    char numero[TAILLE_NUM];
};

int numero_valide(const char *numero);

void vider_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void afficher_contact(const struct Contact *c)
{
    printf("Nom : %s\nPrenom : %s\nNumero : +33%s\n\n", c->nom, c->prenom, c->numero + 1);
}

struct Contact *ajoute_contact(int *nb)
{
    printf("Combien de contacts voulez-vous ajouter : ");
    if (scanf("%d", nb) != 1 || *nb < 1)
    {
        vider_buffer();
        printf("Nombre invalide\n");
        *nb = 0;
        return NULL;
    }
    vider_buffer();

    struct Contact *contact = malloc(*nb * sizeof(struct Contact));
    if (contact == NULL)
    {
        printf("Erreur : memoire insuffisante.\n");
        *nb = 0;
        return NULL;
    }

    for (int i = 0; i < *nb; i++)
    {
        printf("Nom du contact : ");
        scanf("%19s", contact[i].nom);
        vider_buffer();

        printf("Prenom du contact : ");
        scanf("%19s", contact[i].prenom);
        vider_buffer();

        do
        {
            printf("Numero du contact : ");
            scanf("%10s", contact[i].numero);
            vider_buffer();
        } while (!numero_valide(contact[i].numero));
    }

    system("cls");

    return contact;
}

int numero_valide(const char *numero)
{
    if (strlen(numero) != 10 || numero[0] != '0')
        return 0;

    for (int i = 0; i < 10; i++)
    {
        if (numero[i] < '0' || numero[i] > '9')
            return 0;
    }
    return 1;
}

int main(void)
{
    struct Contact *contacts = NULL;
    int nb = 0;
    int act = 0;

    do
    {
        printf("\n --- Menu ---\n");
        printf(" 1 - Ajouter des contacts\n");
        printf(" 2 - Rechercher un contact\n");
        printf(" 3 - Afficher tous les contacts\n");
        printf(" 4 - Quitter\n");
        printf("Choix : ");

        if (scanf("%d", &act) != 1)
        {
            vider_buffer();
            act = 0;
            continue;
        }
        vider_buffer();

        switch (act)
        {
        case 1:

            system("cls");
            
            free(contacts);
            contacts = ajoute_contact(&nb);
            break;

        case 2:
        {
            char nom[TAILLE_NOM], prenom[TAILLE_PRENOM];
            int trouve = 0;

            system("cls");

            printf("Nom : ");
            scanf("%19s", nom);
            vider_buffer();
            printf("Prenom : ");
            scanf("%19s", prenom);
            vider_buffer();

            for (int i = 0; i < nb; i++)
            {
                if (_stricmp(nom, contacts[i].nom) == 0 && strcmp(prenom, contacts[i].prenom) == 0) /* _stricmp compare les chaines de caractères*/
                {
                    afficher_contact(&contacts[i]);
                    trouve = 1;
                }
            }
            if (!trouve)
                printf("Contact introuvable.\n");
            break;
        }

        case 3:

            system("cls");

            if (nb == 0)
                printf("Aucun contact.\n");
            for (int i = 0; i < nb; i++)
                afficher_contact(&contacts[i]);
            break;

        case 4:
            break;

        default:
            printf("Choix invalide.\n");
            break;
        }
    } while (act != 4);

    free(contacts);
    return 0;
}