#include <stdio.h>
#include <stdlib.h>
#include "element.h"

typedef struct Cellule
{
	ELEMENT eCell;
	struct Cellule * ptr_CellSuiv;
	
}CELLULE;


typedef struct FIFO
{
	CELLULE * ptr_tete;
	CELLULE * ptr_queue;
	
}MA_FILE;




MA_FILE INIT_FILE(void)
{
	MA_FILE file;
	file.ptr_tete= NULL; //la tete de la file pointe vers rien
	file.ptr_queue= NULL; //la queue de la file pointe vers rien
	return file;
}

int FILE_EST_VIDE(MA_FILE * file)
{
	return ((file->ptr_tete == NULL)&&(file->ptr_queue == NULL));
}

void AFFICHE_FILE(MA_FILE file)
{
	if (FILE_EST_VIDE(&file)) {
		printf("la file est vide \n");
	}
	else{
		CELLULE* cell;
		cell = file.ptr_tete;
		while(cell != NULL) {
		  affiche_ELEMENT(cell->eCell);
		  cell = cell->ptr_CellSuiv;
		 }
    }
}

MA_FILE ENFILER(MA_FILE file, ELEMENT e)
{
	CELLULE * nouvelleQueue = (CELLULE *) malloc(sizeof (CELLULE));
	
	nouvelleQueue->eCell = e;
	nouvelleQueue->ptr_CellSuiv = NULL;
	
	if (FILE_EST_VIDE(&file)) {
      file.ptr_queue = nouvelleQueue;
      file.ptr_tete = file.ptr_queue;
	} 
	else {
      file.ptr_queue->ptr_CellSuiv = nouvelleQueue;
      file.ptr_queue = nouvelleQueue;
  }
	return file;
}

/*
PILE dePILE(PILE pile, ELEMENT * ancienE)
{
	if(PILE_estVide(pile)){
		printf("La pile est vide \n");
	}
	else {
		*ancienE = affect_ELEMENT(*ancienE,pile.ptr_Cell->eCell);
		pile.ptr_Cell = pile.ptr_Cell->ptr_CellSuiv;
	}
	return pile;

}

PILE saisir_PILE(){
	int i, valeur;
	ELEMENT e;
	PILE maPile;
	
	maPile = init_PILE();
	affiche_PILE(maPile);
	
	printf("Nombre de valeur pour la pile : ");
	scanf("%d",&valeur);	

	for(i=0; i<valeur; i++){
		printf("Valeur n°%d : ",(i+1));
		saisir_ELEMENT(&e);
		maPile = emPILE(maPile, e);
	}
	return maPile;
}*/





void main(void){
	MA_FILE maFile;
	ELEMENT e;
	
	e = 1.257947;


	maFile = INIT_FILE();
	
	printf("test affichage file \n");
	AFFICHE_FILE(maFile);
	
	maFile = ENFILER(maFile, e);
	maFile = ENFILER(maFile, 5.649);
	
	printf("test affichage file init \n");
	AFFICHE_FILE(maFile);
	
	
}
