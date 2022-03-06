/**
 * pnm.c
 *
 * Ce fichier contient les définitions de types et
 * les fonctions de manipulation d'images PNM.
 *
 * @author: Rinallo Dario s204996
 * @date: 5/03/2021
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

  unsigned int ligne;
  unsigned int colone;
  Format type;
  unsigned int valeurMax; //valeur maximum pour la couleur/thon de gris
  unsigned int **matrice; //matrice de "pixels" qui a pour composante des lignes(hauteur) et des colones (largeur)
};

char *format_vers_chaine(Format type)
{
  switch (type)
  {
  case P1:
    return "P1";
  case P2:
    return "P2";
  case P3:
    return "P3";
  default:
    return "erreur";
  }
}

//PRENDS LEXTENSION DU FICHIER PASSER EN PARAMETRE
char *extension_fichier(char *filename)
{
  assert(filename != NULL);
  unsigned int taille = strlen(filename);

  char *extension = &filename[taille - 4];

  return extension;
}

int check_format_extension(char *filename, Format type)
{
  assert(filename != NULL);
  //recupere l'extension du fichier
  char *extension = extension_fichier(filename);

  switch (type)
  {
  case P1:
    //verifie si l'extension correspond au nbre magique
    if (strcmp(extension, ".pbm") != 0)
    {
      printf("Le nombre magique n'est pas compatible avec l'extension. L'extension attendue est \".pbm\"\n");
      return -2;
    }
    break;
  case P2:
    if (strcmp(extension, ".pgm") != 0)
    {
      printf("Le nombre magique n'est pas compatible avec l'extension. L'extension attendue est \".pgm\"\n");
      return -2;
    }
    break;
  case P3:
    if (strcmp(extension, ".ppm") != 0)
    {
      printf("Le nombre magique n'est pas compatible avec l'extension. L'extension attendue est \".ppm\"\n");
      return -2;
    }
    break;
  default:
    printf("mauvais format");
    return -3;
  }
  return 0;
}

int check_file_name(char *filename)
{
  assert(filename != NULL);
  unsigned int taille = strlen(filename);
  unsigned int nbrCaractereInterdit = 9;
  char *caractereInterdit = "/\\:*?\"<>|";
  //parcours de fileName
  for (unsigned int i = 0; i < taille; i++)
  {
    //verifie que le charactere courant ne fait pas partie des interdits
    for (unsigned int j = 0; j < nbrCaractereInterdit; j++)
    {
      if (filename[i] == caractereInterdit[j])
      {
        printf("> Le nom de fichier \"%s\" contient un caractere interdit : %c\n", filename, caractereInterdit[j]);
        return -2;
      }
    }
  }
  return 0;
}

//ACCESSEUR LECTURE

unsigned int obtient_ligne(PNM *image)
{
  assert(image != NULL);

  return image->ligne;
}

unsigned int obtient_colone(PNM *image)
{
  assert(image != NULL);

  return image->colone;
}

unsigned int obtient_valeurMax(PNM *image)
{
  assert(image != NULL);

  return image->valeurMax;
}

unsigned int obtient_Format(PNM *image)
{
  assert(image != NULL);

  return image->type;
}

unsigned int obtient_case_matrice(PNM *image, unsigned int i, unsigned int j)
{
  assert(image != NULL);

  return image->matrice[i][j];
}

unsigned int **obtient_matrice(PNM *image)
{
  assert(image != NULL);

  return image->matrice;
}

//FIN ACCESSEUR LECTURE

//ACCESSEUR ECRITURE
void ecrit_ligne(PNM *image, unsigned int ligne)
{
  assert(image != NULL && image->ligne > 0);
  image->ligne = ligne;
}

void ecrit_colone(PNM *image, unsigned int colone)
{
  assert(image != NULL && image->colone > 0);
  image->colone = colone;
}

void ecrit_valeurMax(PNM *image, unsigned int valeurMax)
{
  assert(image != NULL && image->valeurMax);
  image->valeurMax = valeurMax;
}

void ecrit_type(PNM *image, Format type)
{
  assert(image != NULL);
  image->type = type;
}

void ecrit_matrice(PNM *image, unsigned int **matrice, unsigned int i, unsigned int j)
{
  assert(image != NULL && matrice != NULL);
  image->matrice[i][j] = matrice[i][j];
}

//FIN ACCESSEUR ECRITURE

//allouer la structure

PNM *cree_PNM(unsigned int ligne, unsigned int colone, unsigned int valeurMax, Format type, unsigned int **matrice)
{
  assert(matrice != NULL);

  PNM *pnm = malloc(sizeof(PNM));
  if (!pnm)
  {
    free(pnm);
    printf("valeur retourner null\n");
    return NULL;
  }
  pnm->ligne = ligne;
  pnm->colone = colone;
  pnm->type = type;
  pnm->valeurMax = valeurMax;
  pnm->matrice = matrice;

  return pnm;
}
//fin allouer structure

//allouer la matrice d

unsigned int **cree_matrice(unsigned int colone, unsigned int ligne, Format type)
{
  assert(colone > 0 && ligne > 0);
  int nbrSousColone = 0;

  if (type == P3)
    nbrSousColone = 3 * (colone);
  else
    nbrSousColone = (colone);

  unsigned int **matrice = malloc(ligne * sizeof(unsigned int *));
  if (!matrice)
  {
    free(matrice);
    return NULL;
  }
  for (unsigned int i = 0; i < ligne; i++)
  {
    matrice[i] = malloc(nbrSousColone * sizeof(unsigned int));
    if (!matrice[i])
    {
      free(matrice[i]);
      return NULL;
    }
  }
  return matrice;
}

//fin allouer la matrice de tableau

//LIBERER LA MATRICE

int libere_matrice(unsigned int **matrice, unsigned int ligne)
{
  assert(matrice != NULL && ligne > 0);

  if (matrice == NULL)
  {
    return -2;
  }
  for (unsigned int i = 0; i < ligne; i++)
  {
    if (matrice[i] != NULL)
      free(matrice[i]);
  }
  free(matrice);
  return 0;
}

//FIN LIBERER LA MATRICE

//LIBERER LA STRUCTURE
int libere_struct(PNM *pnm)
{
  assert(pnm != NULL);
  if (pnm == NULL)
  {
    return -1;
  }

  free(pnm);
  return 0;
}

//FIN LIBERER LA STRUCTURE

//FONCTION QUI PASSE LES COMMENTAIRES

void passe_commentaire(FILE *fp, char *filename)
{
  assert(filename != NULL && fp != NULL);

  char str[1000];
  fgets(str, 1000, fp);

  if (str[0] == '#')
  {
    while (str[0] == '#')
    {
      fgets(str, 1000, fp);
    }
  }

  if (str[0] != '#')
  {
    fseek(fp, -(strlen(str) * sizeof(char)), SEEK_CUR);
  }
}

//FIN FONCTION QUI PASSE LES COMMENTAIRES

int load_pnm(PNM **image, char *filename)
{
  assert(image != NULL && filename != NULL);

  /*int testNomFichier = check_file_name(filename);
  if (testNomFichier == -2)
  {
    return -2;
  }*/

  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL)
  {
    return -2;
  }
  else
  {

    unsigned int ligne;
    unsigned int colone;
    Format type;
    unsigned int valeurMax; //valeur maximum pour la couleur/thon de gris

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
}

int write_pnm(PNM *image, char *filename)
{
  assert(image != NULL && filename != NULL);

  int testNomFichier = check_file_name(filename);
  if (testNomFichier == -2)
  {
    return -1;
  }
  int testFormatExtension = check_format_extension(filename, image->type);
  if (testFormatExtension == -2 || testFormatExtension == -3)
  {
    return -1;
  }
  FILE *fp;
  fp = fopen(filename, "w");
  if (fp == NULL)
  {

    return -1;
  }
  else
  {
    fprintf(fp, "%s\n", format_vers_chaine(image->type));
    fprintf(fp, "%u %u\n", image->colone, image->ligne);
    if (image->type == P2 || image->type == P3)
    {
      fprintf(fp, "%u\n", image->valeurMax);
    }

    if (image->type == P3)
    {
      for (unsigned int i = 0; i < image->ligne; i++)
      {
        if (i != 0)
          fprintf(fp, "\n");
        for (unsigned int j = 0; j < (3 * (image->colone)); j++)
        {
          fprintf(fp, "%u ", (image->matrice[i][j]));
        }
      }
    }

    if (image->type == P2 || image->type == P1)
    {
      for (unsigned int i = 0; i < image->ligne; i++)
      {
        if (i != 0)
          fprintf(fp, "\n");
        for (unsigned int j = 0; j < image->colone; j++)
        {
          fprintf(fp, "%u ", (image->matrice[i][j]));
        }
      }
    }

    libere_matrice(obtient_matrice(image), obtient_ligne(image));
    libere_struct(image);

    fclose(fp);

    return 0;
  }
}
