/**
 * pnm.c
 * 
 * Ce fichier contient les définitions de types et 
 * les fonctions de manipulation d'images PNM.
 * 
 * @author: GANOUBONG TINGUE LESLIE LUCYNDA S218152
 * @date: 
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "pnm.h"

struct PNM_t
{
    unsigned int ligne;
    unsigned int colonne;
    Format nbrMagik;
    unsigned int maxValue;//valeur maximale utilisée pour coder les couleurs et pour les images au niveau de gris
    unsigned int **matrice; //matrice de "pixels" qui a pour composante des lignes et des colonnes;
};


//CONSTRUCTEUR
//GETTERS


//ACCESSEUR EN LECTURE

char *get_nbrMagik(Format nbrMagik){
   assert(nbrMagik!=NULL);
      switch (nbrMagik){
         case P1 : return P1;
         case P2 : return P2;
         case P3 : return P3;
         default:
         printf("erreur!\n");
         abort();

   return Format->nbrMagik;
   }//end switch()
}//end get_type()

char*get_type(PNM*Format){
   assert(Format!=NULL);
      switch (type){
         case P1 : return P1;
         case P2 : return P2;
         case P3 : return P3;
         default:
         printf("erreur!\n");
         abort();

   return Format->type;
   }//fin switch()
}//end get_type()


unsigned int get_ligne(PNM *image)
{
  assert(image != NULL);

  return image->ligne;
}//end get_ligne()

unsigned int get_colonne(PNM *image)
{
  assert(image != NULL);

  return image->colone;
}//fin get_colonne()

unsigned int get_maxvalue(PNM *image)
{
  assert(image != NULL);

  return image->valeurMax;
}//end get_maxvalue()

unsigned int get_Format(PNM *image)
{
  assert(image != NULL);

  return image->type;
}//end get_Format()

unsigned int get_case_matrice(PNM *image, unsigned int i, unsigned int j)
{
  assert(image != NULL);

  return image->matrice[i][j];
}//end get_case_matrice()

unsigned int **get_matrice(PNM *image)
{
  assert(image != NULL);

  return image->matrice;
}//end get_matrice()

//END ACCESSEUR LECTURE

int load_pnm(PNM **image, char *filename)
{
  assert(image != NULL && filename != NULL);

  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    return -2;
  }

    unsigned int ligne;
    unsigned int colonne;
    Format type;
    unsigned int maxValue; //valeur maximum pour la couleur/thon de gris

    char str[10];
    fgets(str, 10, fp);

    //premiere ligne

    switch (str[1])
    {
    case '1':
      type = P1;
      break;
    case '2':
      type = P2;
      break;
    case '3':
      type = P3;
      break;
    default:
      return -3;
    }
    int testFormatExtension = check_format_extension(filename, type);
    switch (testFormatExtension)
    {
    case -2:
      return -2;

    case -3:
      return -3;
    }

    passe_commentaire(fp, filename);

    //printf("test scanf : %d\n",fscanf(fp, "%u %u", (&colone), (&ligne)));

    if (fscanf(fp, "%u %u", (&colone), (&ligne)) != 2)
    {
      return -3;
    }
    passe_commentaire(fp, filename);

    if (ligne == 0 || colone == 0)
    {
      return -3;
    }

    if (type == P2 || type == P3)
    {
      if (fscanf(fp, "%u", &(valeurMax)) != 1)
      {
        return -3;
      }
    }

    if ((type == P2 && valeurMax > 255) || (type == P3 && valeurMax > 65536))
    {
      return -3;
    }

    unsigned int **matrice = cree_matrice(colone, ligne, type);
    if (matrice == NULL)
    {
      printf("erreur d'allocation");

      return -1;
    }

    if (type == P3)
    {

      for (unsigned int i = 0; i < ligne; i++)
      {
        for (unsigned int j = 0; j < (3 * colone); j++)
        {
          passe_commentaire(fp, filename);
          if (fscanf(fp, "%u", &(matrice[i][j])) != 1)
          {
            return -3;
          }
          //test qui vérifie si un pixel dépasse la valeur max autorisée
          if (matrice[i][j] > valeurMax)
          {
            return -3;
          }
        }
      }
    }

    if (type == P2 || type == P1)
    {
      for (unsigned int i = 0; i < ligne; i++)
      {
        for (unsigned int j = 0; j < colone; j++)
        {
          passe_commentaire(fp, filename);
          if (fscanf(fp, "%u", &(matrice[i][j])) != 1)
          {
            return -3;
          }
          if (type == P1 && matrice[i][j] > 1)
          {
            return -3;
          }
          if (type == P2 && matrice[i][j] > valeurMax)
          {
            printf("salut\n");
            return -3;
          }
        }
      }
    }

    //check pour voir si on a lu tout les pixels
    for (unsigned int i = 0; i < 10; i++)
    {
      int graph = isgraph(fgetc(fp));

      if (graph != 0)
      {
        return -3;
      }
    }
    (*image) = cree_PNM(ligne, colone, valeurMax, type, matrice);

    fclose(fp);

    return 0;
  
}