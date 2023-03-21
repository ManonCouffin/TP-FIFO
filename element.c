#include <stdio.h>
#include "element.h"

//fonctions

void affiche_ELEMENT(ELEMENT e) {
    printf("La valeur de l'élément est : %f \n", e);
}

void saisir_ELEMENT(ELEMENT* e) {
    printf("Entrer la valeur de l'élément: ");
    scanf("%f", &(*e));
}

void affect_ELEMENT(ELEMENT *e, float value) {
    *e = value;
}

int compare_ELEMENT(ELEMENT e1, ELEMENT e2) {
    return (e1 == e2);
}
