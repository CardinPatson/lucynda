/**
 * pnm.c
 * 
 * Ce fichier contient les définitions de types et 
 * les fonctions de manipulation d'images PNM.
 * 
 * @author: GANOUBONG TINGUE LESLIE LUCYNDA S218152
 * @date: 06/03/2022
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "pnm.h"


/**
 * Définition du type opaque PNM
 *
 */

struct PNM_t
{
unsigned int line;
unsigned int column;
Format type;
unsigned int maxValue;//valeur maximale utilisée pour coder les couleurs et pour les images au niveau de gris
unsigned int **matrice; //matrice de "pixels" qui a pour composante des lines et des columns;
};



// CONSTRUCTEUR

PNM *create_pnm(unsigned int line, unsigned int column ,Format type ,unsigned int maxValue,unsigned int **matrice){

   assert(matrice != NULL);
   PNM *pnm = malloc(sizeof(PNM));
   if(pnm==NULL){
      free(pnm);
      return NULL;
   }

  pnm->line = line;
  pnm->column = column;
  pnm->type = type;
  pnm->maxValue = maxValue;
  pnm->matrice = matrice;

  return pnm;
}// end cree_ppm()


// DESTRUCTEUR

void destroy_pnm(PNM *pnm){
   assert(pnm != NULL);
   free(pnm);
}
void destroy_matrice(PNM *pnm){
   assert(get_matrice(pnm) != NULL && get_line(pnm) > 0);
   //Libre chaque ligne de la matrice
   for (unsigned int i = 0; i < get_line(pnm); i++)
   {
      if (get_matrice(pnm)[i] != NULL)
         free(get_matrice(pnm)[i]);
   }
   free(get_matrice(pnm));
}

//end detruit_pnm()



 //GETTERS

char *get_type_string(Format type){
   assert(type);
   switch (type){
      case P1 : return "P1";
      case P2 : return "P2";
      case P3 : return "P3";
      default:
      printf("erreur!\n");
      abort();


   }//end switch()
}//end get_type()


unsigned int get_line(PNM *pnm)
{
   assert(pnm != NULL);

   return pnm->line;
}//end get_line()

unsigned int get_column(PNM *pnm)
{
   assert(pnm != NULL);

   return pnm->column;
}//fin get_column()

unsigned int get_maxValue(PNM *pnm)
{
  assert(pnm != NULL);

  return pnm->maxValue;
}//end get_maxValue()

unsigned int get_type(PNM *pnm)
{
  assert(pnm != NULL);

  return pnm->type;
}//end get_type()

unsigned int **get_matrice(PNM *pnm)
{
  assert(pnm != NULL);

  return pnm->matrice;
}//end get_matrice()


unsigned int get_case_matrice(PNM *pnm, unsigned int line, unsigned int column)
{
  assert(pnm != NULL);

  return pnm->matrice[line][column];
}//end get_case_matrice()


//END GETTERS

//SETTERS
void set_line(PNM *pnm, unsigned int line)
{
  assert(pnm != NULL && (pnm->line > 0));
  pnm->line = line;
}//end

void set_column(PNM *pnm, unsigned int column)
{
  assert(pnm != NULL && pnm->column > 0);
  pnm->column = column;
}

void set_maxValue(PNM *pnm, unsigned int maxValue)
{
  assert(pnm != NULL && pnm->maxValue);
  pnm->maxValue = maxValue;
}

void set_type(PNM *pnm, Format type)
{
  assert(pnm != NULL);
  pnm->type = type;
}

void set_matrice(PNM *pnm, unsigned int **matrice)
{
  assert(pnm != NULL && matrice != NULL);
  pnm->matrice = matrice;
}

 //END SETTERS

int compare_file_format(char *filename,Format type){
   assert(filename != NULL);

  //recuperer l'extension du fichier
  char *extension = &filename[strlen(filename) -4];

  switch (type)
  {
  case P1:
    //verifie si l'extension correspond au nbre magique
    if (strcmp(extension, ".pbm") != 0)
    {
      printf("L'extension doit être --> .pbm\n");
      return -2;
    }
    break;
  case P2:
    if (strcmp(extension, ".pgm") != 0)
    {
      printf("L'extension doit être --> .pgm\n");
      return -2;
    }
    break;
  case P3:
    if (strcmp(extension, ".ppm") != 0)
    {
      printf("L'extension doit être --> .ppm\n");
      return -2;
    }
    break;
  default:
    printf("mauvais format");
    return -2;
  }
  return 0;
}

void check_comment(FILE *fp, char *filename){
   assert(filename != NULL && fp != NULL);
   char line[255];   
   //Verifie si la line est un commentaire
   do
   {
      fgets(line, 255, fp);
   }
   while (line[0] == '#');

   
   //Remet le curseur au début de la line
   if(line[0] != '#'){

      fseek(fp, -(strlen(line) * sizeof(char)), SEEK_CUR);
   }
   
}

unsigned int **create_matrice(unsigned int column, unsigned int line, Format type)
{
  assert(column > 0 && line > 0);
  unsigned int **matrice = malloc(line * sizeof(unsigned int *));
  
  if (!matrice)
  {
    free(matrice);
    return NULL;
  }
  for (unsigned int i = 0; i < line; i++)
  {
      if (type == P3){

         matrice[i] = malloc((3*column) * sizeof(unsigned int));
      }
      else matrice[i] = malloc(column*sizeof(unsigned int));

      if (!matrice[i])
      {
         free(matrice[i]);
         return NULL;
      }
  }
  return matrice;
}
int load_pnm(PNM **pnm, char *filename)
{
  assert(pnm != NULL && filename != NULL);

  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    return -2;
  }
   unsigned int line;
   unsigned int column;
   unsigned int maxValue; //valeur maximale utilisée pour coder les couleurs et pour les images au niveau de gris
   Format type;

   char first_line[5];
   fgets(first_line, 5, fp);

   //premiere line du fichier + insertion dans la structure format
   switch (first_line[1])
   {
      case '1':
      type =  P1;
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
   switch ( compare_file_format(filename, type))
   {
      case -2:
      return -2;

      case -3:
      return -3;
   }

   check_comment(fp, filename);
   
   if (fscanf(fp, "%u %u", (&column), (&line)) != 2)
   {
      return -3;
      
   }

   check_comment(fp, filename);

   if (type == P2 || type == P3)
   {
      if (fscanf(fp, "%u", &(maxValue))==1)
      {
      if ((type == P2 && maxValue > 255) || (type == P3 && maxValue > 65536))
         {

            return -3;
         }

      }
   }

 unsigned int **matrice = create_matrice(column, line, type);
 if (matrice == NULL)
 {
   printf("erreur d'allocation");

   return -1;
 }

 if (type == P1 || type == P2 )
 {
   for (unsigned int i = 0; i < line; i++)
   {
     for (unsigned int j = 0; j < column; j++)
     {
       check_comment(fp, filename);
       if (fscanf(fp, "%u", &(matrice[i][j])) != 1)
       {
         return -3;
       }
       if (type == P1 && matrice[i][j] > 1)
       {
         return -3;
       }
       if (type == P2 && matrice[i][j] > maxValue)
       {
         return -3;
       }
     }
   }
 }
 if (type == P3)
 {

    //Boucle sur les lines
   for (unsigned int i = 0; i < line; i++)
   {
      //boucle sur les colonnes
     for (unsigned int j = 0; j < (3 * column); j++)
     {
       check_comment(fp, filename);

       //Inserer 
       if (fscanf(fp, "%u", &(matrice[i][j])) != 1)
       {
         return -3;
       }
       //vérifie si un pixel dépasse la valeur max autorisée
       if (matrice[i][j] > maxValue)
       {
         return -3;
       }
     }
   }
 }
 *pnm = create_pnm(line, column, type, maxValue, matrice);

 fclose(fp);

   return 0;

}

int write_pnm(PNM *pnm, char* filename) {

   assert(pnm != NULL && filename != NULL);

   if (compare_file_format(filename, get_type(pnm)) == -1)
   {
      return -1;
   }
   FILE *fp;
   fp = fopen(filename, "w");
   if (fp == NULL)
   {

      return -1;
   }


   //transformation du type Format en chaine (manquant)
   fprintf(fp, "%s\n", get_type_string(get_type(pnm)));

   //Ecrire le nombre de colonne et ligne dans le fichier 
   fprintf(fp, "%u %u\n", get_column(pnm), get_line(pnm));
   if (get_type(pnm) == P2 || get_type(pnm) == P3)
   {
      fprintf(fp, "%u\n", pnm->maxValue);
   }


   if (get_type(pnm) == P1 || get_type(pnm) == P2 )
   {
      for (unsigned int line = 0; line < get_line(pnm); line++)
      {
         if (line) fprintf(fp, "\n");
         for (unsigned int column = 0; column < get_column(pnm); column++)
         {
            fprintf(fp, "%u ", (get_case_matrice(pnm , line , column)));
         }
      }
   }

   //Copie la matrice dans le nouveau fichier 
   if (get_type(pnm) == P3)
   {
      for (unsigned int line = 0; line < get_line(pnm); line++)
      {
         if (line) fprintf(fp, "\n");
         for (unsigned int column = 0; column < (3 * (get_column(pnm))); column++)
         {
            fprintf(fp, "%u ", (get_case_matrice(pnm , line , column)));
         }
      }
   }

   

   destroy_matrice(pnm);
   destroy_pnm(pnm);

   fclose(fp);

   return 0;
 
}

