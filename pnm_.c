/**
 * pnm.c
 * 
 * Ce fichier contient les définitions de types et 
 * les fonctions de manipulation d'images PNM.
 * 
 * @author: Nom Prenom Matricule
 * @date: 
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pnm.h"


/**
 * Définition du type opaque PNM
 *
 */
struct PNM_t {

   /* Insérez ici les champs de la structure PNM */



};




int load_pnm(PNM **image, char* filename) {

   /* Insérez le code ici */
   char tab[255];
   FILE *fichier = fopen(filename , "r") ;
   int lettre = 0;
   if (fichier == NULL){
         exit(0);

   }
   lettre = fgets(tab , 5 , fichier);

   printf(lettre);


   return 0;
}

int write_pnm(PNM *image, char* filename) {

   /* Insérez le code ici */

   return 0;
}

