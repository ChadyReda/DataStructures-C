#include <stdio.h>
#include <stdlib.h>

float moyenGeneral(float* p, int nombre_etudiant)
{
    float somme;
    for (int i = 0; i < nombre_etudiant; i++)
    {
        printf("Entrer la note detudiant %d: ", i + 1);
        scanf("%f", (p + i));
    }
    for (int i = 0; i < nombre_etudiant; i++)
    {
        somme += p[i];
    }
    return somme / nombre_etudiant;
}

int main()
{
    // malloc() free() calloc() realloc()
    // void free (pointer);
    // void* calloc (nbrs_element, taill_element);
    // void* realloc (pointeur, taille_octet);
    // realloc augmente ou diminuer ta taille reserver par le pointeur

    int *p;
    p = (int *)malloc(sizeof(int));

    if (p == NULL)
    {
        printf("Not enough memory");
        exit(0);
    }

    int *T;
    T = (int *)malloc(4 * sizeof(int));

    *(T + 1) = 15;

    printf("%d\n", T[0]); // garbage value

    int *T2 = (int *)calloc(4, sizeof(int));

    printf("%d ", T2[0]); // 0
    printf("%d ", T2[1]); // 0

    int *P = (int *)malloc(2 * sizeof(int));
    P = realloc(P, 4 * sizeof(int));
    printf("\n%d\n", sizeof(*P) * 4);

    free(p);
    free(T);
    free(T2);
    free(P);

    // program moyen general
    int nombre_detudiant;
    float moyen;
    printf("Entrer le nombre detudiants: ");
    scanf("%d", &nombre_detudiant);
    float *pointer = (float *)malloc(nombre_detudiant * sizeof(float));
    moyen = moyenGeneral(pointer, nombre_detudiant);
    printf("La moyen de cette class est: %.2f", moyen);

    return 0;
}
