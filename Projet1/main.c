/**
 * main.c
 *
 * Ce fichier contient la fonction main() du programme de manipulation
 * de fichiers pnm.
 *
 * @author: Rinallo Dario s204996  
 * @date: 5/03/2021
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>
#include <string.h>

#include "pnm.h"

int main(int argc, char *argv[])
{

	const char *optstring = ":f:i:o:";
	int val;
	char *input;
	char *output;
	char *format;
	PNM *image;
	//getopt retourne chacun des options passé en arguments
	while ((val = getopt(argc, argv, optstring)) != EOF)
	{
		switch (val)
		{
		case 'f':
			format = optarg;
			if (strcmp(format, "PGM") == 0 || strcmp(format, "PBM") == 0 || strcmp(format, "PPM") == 0)
			{
				//printf("%s\n",format);     test
			}
			else
			{
				printf("le format donné n'est pas correct ,les formats accepté sont PGM ou PBM ou PPM");
				return -2;
			}
			break;
		case 'i':
			input = optarg;

			break;
		case 'o':
			output = optarg;
			break;
		}
	}

	int essayeLoad = load_pnm(&image, input);
	printf("essayeload : %d\n", essayeLoad);
	switch (essayeLoad)
	{
	case -1:
		printf("erreur dans l'allocation de mémoire\n");
		return 1;

	case -2:
		printf("Nom du fichier malformé\n");
		return 1;

	case -3:
		printf("Contenu du fichier malformé\n");
		return 1;
	}

	int essayeWrite = write_pnm(image, output);

	switch (essayeWrite)
	{
	case -1:
		printf("Nom du fichier malformé\n");
		return 1;

	case -2:
		printf("Erreur lors de la manipulation du fichier\n");
		return 1;
	}

	return 0;
}
