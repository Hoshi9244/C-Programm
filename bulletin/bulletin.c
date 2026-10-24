#include<stdio.h>
#include<stdlib.h>

#define MAX_MATIERES 20
#define TAILLE_NOM 20


int main(void)
{
    int m;
    char matieres[MAX_MATIERES][TAILLE_NOM];
    float notes[MAX_MATIERES], moy = 0;

    printf("combien de matiere avez-vous : ");
    scanf("%i", &m);

    for (int i = 0; i < m; i++)
    {
        printf("qu'elle est la matiere : ");
        scanf("%19s", matieres[i]);

        printf("qu'elle est ta note : ");
        scanf("%f", &notes[i]);
        system("cls");   
    }

    printf("\nVotre bulletin\n");
    for ( int j = 0; j < m; j++)
    {
        moy += notes[j]/m;
        printf("- %s : %.2f/20\n", matieres[j], notes[j]);
    }
    printf("\nnote general : %.2f\n", moy);

    if (moy >= 18)
    {
        printf("Tres bien\n");
    }
    else if ((moy < 18) && (moy >=14))
    {
        printf("Bien\n");
    }
    else if ((moy < 14) && (moy >=12))
    {
        printf("Félicitation\n");
    }
    else if ((moy < 12) && (moy >=10))
    {
        printf("continuer vos efforts\n");
    }
    else
    {
        printf("Pas d'effort\n");
    }
}