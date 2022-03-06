/**
 * pnm.h
 *
 * Ce fichier contient les déclarations de types et les prototypes
 * des fonctions pour la manipulation d'images PNM.
 *
 * @author: Rinallo Dario s204996  
 * @date: 5/03/2021
 * @projet: INFO0030 Projet 1
 */

/*
 * Include guard (pour éviter les problèmes d'inclusions multiplies
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __PNM__
#define __PNM__

/**
 * \enum Format
 * \brief une énumération qui représente les différents types de formats pour une image PNM
 */

typedef enum
{
    P1,
    P2,
    P3
} Format;

/**
 * \struct PNM
 * \brief structure de données qui représentent une image PNM
 */

typedef struct PNM_t PNM;

/**
 * \fn char *extension_fichier(char *filename)
 * \brief renvoie l'extension pnm d'une chaine de caractère 
 * 
 * \param filename, une chaine de caractère qui contient le nom du fichier
 * 
 * \return  l'extension de la chaine de caractère
 */

char *extension_fichier(char *filename);

/**
 * \fn int check_format_extension(char *filename, Format type)
 * \brief vérifie si l'extension entrée est compatible avec le nombre magique 
 * 
 * \param filename, une chaine de caractère qui contient le nom du fichier
 * \param type, une énumération qui contient le type de l'image(nombre magique)
 * 
 * \return  0 si le format et l'extension sont compatible, -2 si l'extension et le nombre magique ne correspondent pas et -3 si le nombre magique est malformé
 */

int check_format_extension(char *filename, Format type);

/**
 * \fn int check_file_name(char *filename)
 * \brief vérifie si le nom du fichier entré contient un caractère interdit
 * 
 * \param filename, une chaine de caractère qui contient le nom du fichier
 * 
 * \return 0 si le nom du fichier entré ne contient pas de caractère interdit , -2 s'il en contient
 */

int check_file_name(char *filename);

/**
 * \fn unsigned int obtient_ligne(PNM *image)
 * \brief donne l'accès, en lecture, au champs 'ligne' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * 
 * \return le champs ligne de la structure PNM *image
 */

unsigned int obtient_ligne(PNM *image);

/**
 * \fn unsigned int obtient_colone(PNM *image)
 * \brief donne l'accès, en lecture, au champs 'colone' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * 
 * \return le champs colone de la structure PNM *image
 */

unsigned int obtient_colone(PNM *image);

/**
 * \fn unsigned int obtient_valeurMax(PNM *image)
 * \brief donne l'accès, en lecture, au champs 'valeurMax' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * 
 * \return le champs valeurMax de la structure PNM *image
 */

unsigned int obtient_valeurMax(PNM *image);

/**
 * \fn Format obtient_Format(PNM *image)
 * \brief donne l'accès, en lecture, au champs 'type' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * 
 * \return le champs type de la structure PNM *image
 */

Format obtient_Format(PNM *image);

/**
 * \fn unsigned int **obtient_matrice(PNM *image);
 * \brief donne l'accès, en lecture, au champs '**matrice' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * 
 * \return le champs **matrice de la structure PNM *image
 */

unsigned int **obtient_matrice(PNM *image);

/**
 * \fn unsigned int obtient_case_matrice(PNM *image, unsigned int i, unsigned int j);
 * \brief donne l'accès, en lecture, à un élément du champs '**matrice' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * \param i, l'indice de la ligne de l'élément auquel on voudrais accéder
 * \param j, l'indice de la colone de l'élément auquel on voudrais accéder
 * 
 * \return un élément du champs **matrice de la structure PNM *image
 */

unsigned int obtient_case_matrice(PNM *image, unsigned int i, unsigned int j);

//FIN ACCESSEUR LECTURE

//ACCESSEUR ECRITURE

/**
 * \fn void ecrit_ligne(PNM *image, unsigned int ligne)
 * \brief donne l'accès, en écriture, au champs 'ligne' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * \param ligne, la valeur qui va être placée dans le champs 'ligne' de la structure
 */

void ecrit_ligne(PNM *image, unsigned int ligne);

/**
 * \fn void ecrit_colone(PNM *image, unsigned int colone)
 * \brief donne l'accès, en écriture, au champs 'colone' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * \param colone, la valeur qui va être placée dans le champs 'colone' de la structure
 */

void ecrit_colone(PNM *image, unsigned int colone);

/**
 * \fn void ecrit_valeurMax(PNM *image, unsigned int valeurMax)
 * \brief donne l'accès, en écriture, au champs 'valeurMax' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * \param valeurMax, la valeur qui va être placée dans le champs 'valeurMax' de la structure
 */

void ecrit_valeurMax(PNM *image, unsigned int valeurMax);

/**
 * \fn void ecrit_type(PNM *image, Format type)
 * \brief donne l'accès, en écriture, au champs 'type' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * \param type, la valeur qui va être placée dans le champs 'type' de la structure
 */

void ecrit_type(PNM *image, Format type);

/**
 * \fn void ecrit_matrice(PNM *image, unsigned int **matrice)
 * \brief donne l'accès, en écriture, au champs '**matrice' de la structure opaque
 * 
 * \param image, un pointeur vers l'image de type PNM
 * \param matrice, la valeur qui va être placée dans le champs 'matrice' de la structure
 */

void ecrit_matrice(PNM *image, unsigned int **matrice, unsigned int i, unsigned int j);

//FIN ACCESSEUR ECRITURE

//allouer la structure

/**
 * \fn PNM *cree_PNM(unsigned int ligne, unsigned int colone, unsigned int valeurMax, Format type, unsigned int **matrice)
 * \brief alloue dynamiquement la structure de type PNM
 * 
 * \param ligne, sera mis dans champs 'ligne' de la struct allouée
 * \param colone, sera mis dans champs 'colone' de la struct allouée
 * \param valeurMax, sera mis dans champs 'valeurMax' de la struct allouée
 * \param type, sera mis dans champs 'type' de la struct allouée
 * \param matrice, sera mis dans champs '**matrice' de la struct allouée
 * 
 * \return la structure nouvellement allouée ou Null si erreur
 */

PNM *cree_PNM(unsigned int ligne, unsigned int colone, unsigned int valeurMax, Format type, unsigned int **matrice);

//fin allouer structure

//allouer la matrice de tableau

/**
 * \fn unsigned int **cree_matrice(unsigned int colone, unsigned int ligne, Format type)
 * \brief alloue dynamiquement la matrice de type unsigned int **
 * 
 * \param ligne, ligne de la matrice à allouée
 * \param colone, colone de la matrice à allouée
 * \param type, type de matrice à allouée
 * 
 * \return la matrice nouvellement allouée ou NULL si erreur
 */

unsigned int **cree_matrice(unsigned int colone, unsigned int ligne, Format type);

//fin allouer la matrice de tableau

/**
 * \fn int libere_matrice(unsigned int **matrice, unsigned int colone)
 * \brief libere la matrice
 * 
 * \param ligne, ligne de la matrice à liberer
 * \param matrice, la matrice à libérer
 * 
 * \return -2 si erreur , 0 si tout c'est bien passé
 */

int libere_matrice(unsigned int **matrice, unsigned int ligne);

//FIN LIBERER LA MATRICE

//LIBERER LA STRUCTURE (dabort liberer la matrice)

/**
 * \fn int libere_struct(PNM *pnm)
 * \brief libere la structure
 * 
 * \param pnm, la structure à libérer
 * 
 * \return -2 si erreur , 0 si tout c'est bien passé
 */

int libere_struct(PNM *pnm);

/**
 * \fn char *format_vers_chaine(Format type)
 * \brief transforme une variable de type format vers une de type chaine
 * 
 * \param type, la variable a convertir
 * 
 * \return -3 si erreur , la chaine de caractère si tout c'est bien passé
 */

char *format_vers_chaine(Format type);

/**
 * \fn void passe_commentaire(FILE *fp, char *filename)
 * \brief passe les commentaires
 * 
 * \param fp, le descripteur de fichier
 * \param filename, le nom du fichier
 * 
 */

void passe_commentaire(FILE *fp, char *filename);

/*
 * Converti une valeur d'énumération en une chaine de caractère
 *
 * @param "type" de type Format
 *
 * @pré: énumeration valide
 *
 * @ post: converti un champs de l'énumeration en chaine de caractère
 */

/**
 * load_pnm
 *
 * Charge une image PNM depuis un fichier.
 *
 * @param image l'adresse d'un pointeur sur PNM à laquelle écrire l'adresse
 *              de l'image chargée.
 * @param filename le chemin vers le fichier contenant l'image.
 *
 * @pre: image != NULL, filename != NULL
 * @post: image pointe vers l'image chargée depuis le fichier.
 *
 * @return:
 *     0 Succès
 *    -1 Erreur à l'allocation de mémoire
 *    -2 Nom du fichier malformé
 *    -3 Contenu du fichier malformé
 *
 */
int load_pnm(PNM **image, char *filename);

/**
 * write_pnm
 *
 * Sauvegarde une image PNM dans un fichier.
 *
 * @param image un pointeur sur PNM.
 * @param filename le chemin vers le fichier de destination.
 *
 * @pre: image != NULL, filename != NULL
 * @post: le fichier filename contient l'image PNM image.
 *
 * @return:
 *     0 Succès
 *    -1 Nom du fichier malformé
 *    -2 Erreur lors de la manipulation du fichier
 *
 */
int write_pnm(PNM *image, char *filename);

#endif // __PNM__
