/**
 * pnm.h
 * 
 * Ce fichier contient les déclarations de types et les prototypes
 * des fonctions pour la manipulation d'images PNM.
 * 
 * @author: GANOUBONG TINGUE LESLIE LUCYNDA S218152
 * @date: 06/03/2022
 * @projet: INFO0030 Projet 1
 */

/*
 * Include guard (pour éviter les problèmes d'inclusions multiplies
 * Bonne pratique: toujours encadrer un header avec un include guard
 */
#ifndef __PNM__
#define __PNM__

/**
 * Déclaration du type opaque PNM
 *
 */
typedef struct PNM_t PNM;


/*

**/
typedef enum{
    P1,
    P2,
    P3,
}Format;

/***/
void check_comment(FILE *fp , char *filename);
int compare_file_format(char *filename,Format type);

/*AWAIT*/


/**
 * create_pnm
 *
 * cree la structure pnm
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
PNM *create_pnm(unsigned int line, unsigned int column ,Format type ,unsigned int maxValue,unsigned int **matrice);


/**
 * create_pnm
 *
 * cree la structure pnm
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
void destroy_pnm(PNM *pnm);

/**
 * create_pnm
 *
 * cree la structure pnm
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
void destroy_matrice(PNM *pnm);

/**
 * get_type_string
 *
 * cree la structure pnm
 *
 * @param type nombre magique
 * 
 * @pre: type != NULL
 * 
 */
char *get_type_string(Format type);

/**
 * get_line
 * 
 * Donne la value de line de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @pre: pnm != NULL
 * */
unsigned int get_line(PNM *pnm);

/**
 * get_column
 * 
 * Donne la valeur de column de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @pre: pnm != NULL
 * */
unsigned int get_column(PNM *pnm);

/**
 * get_maxValue
 * 
 * Donne la value de maxValue de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @pre: pnm != NULL
 * */
unsigned int get_maxValue(PNM *pnm);

/**
 * get_type
 * 
 * Donne la valeur de type de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @pre: pnm != NULL
 * */
unsigned int get_type(PNM *pnm);

/**
 * get_matrice
 * 
 * Donne la matrice de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @pre: pnm != NULL
 * */
unsigned int **get_matrice(PNM *pnm);

/**
 * get_case_matrice
 * 
 * Donne la valeur d'une case de la matrice dans la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @param line l'indice de la ligne dans la matrice
 * @param column l'indice de la colonne
 * @pre pnm != NULL
 * */
unsigned int get_case_matrice(PNM *pnm, unsigned int line, unsigned int column);


/**
 * set_line
 * 
 *  Donne l'accès en ecriture au champ line de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @param line l'indice de la ligne dans la matrice
 * @pre pnm != NULL && pnm->line > 0
 * */
void set_line(PNM *pnm, unsigned int line);



/**
 * set_line
 * 
 *  Donne l'accès en ecriture au champ column de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @param column l'indice de la column dans la matrice
 * @pre pnm != NULL
 * */
void set_column(PNM *pnm, unsigned int column);


/**
 * set_maxValue
 * 
 *  Donne l'accès en ecriture au champ line de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @param maxValue l'indice de la ligne dans la matrice
 * @pre pnm != NULL && pnm->maxValue
 * */
void set_maxValue(PNM *pnm, unsigned int maxValue);


/**
 * set_type
 * 
 *  Donne l'accès en ecriture au champ type de la struture opaque
 * 
 * @param pnm un pointeur sur pnm 
 * @param type l'indice de dans la matrice
 * @pre pnm != NULL
 * */
void set_type(PNM *pnm, Format type);


/**
 * set_matrice
 * 
 *  Donne l'accès en ecriture au champ matrice de la struture opaque
 * 
 * @param pnm un pointeur sur PNM 
 * @param matrice la matrice
 * @pre pnm != NULL && matrice != NULL
 * */
void set_matrice(PNM *pnm, unsigned int **matrice);


/**
 * compare_file_extension
 * 
 *  Donne l'accès en ecriture au champ line de la struture opaque
 * 
 * @param filename un pointeur sur char 
 * @param type l'indice de la ligne dans la matrice
 * @pre pnm != NULL && matrice != NULL
 * */
int compare_file_format(char *filename,Format type);


/**
 * check_comment
 * 
 *  Donne l'accès en ecriture au champ line de la struture opaque
 * 
 * @param fp un pointeur sur le fichier 
 * @param filename le nom du fichier
 * @pre filename != NULL && fp != NULL
 * */

void check_comment(FILE *fp, char *filename);


/**
 * create_matrice
 * 
 *  Donne l'accès en ecriture au champ line de la struture opaque
 * 
 * @param column l'indice de la colonne dans la matrice
 * @param line l'indice de la ligne dans la matrice
 * @param  type nombre magique du format
 *
 * */
unsigned int **create_matrice(unsigned int column, unsigned int line, Format type);


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
int load_pnm(PNM **image, char* filename);

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
int write_pnm(PNM *image, char* filename);

#endif // __PNM__

