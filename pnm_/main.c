/**
 * main.c
 *
 * Ce fichier contient la fonction main() du programme de manipulation
 * de fichiers pnm.
 *
 * @author: GANOUBONG TINGUE LESLIE LUCYNDA S218152 
 * @date: 06/03/2022
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


int main(int argc , char *argv[]){

    const char *optstring = ":f:i:o:";
	int value;
	char *input_file;
	char *output_file;
	char *format_file;
	PNM *pnm;

    while ((value = getopt(argc, argv, optstring)) != EOF)
	{
		switch (value)
		{
		case 'f':
			format_file = optarg;
			if(strcmp(format_file, "PGM") && strcmp(format_file, "PBM")&& strcmp(format_file, "PPM"))
			{
				printf("le format mal formé,les formats acceptés sont PGM ou PBM ou PPM");
				return -2;
			}
			break;
		case 'i':
			input_file = optarg;

			break;
		case 'o':
			output_file = optarg;
			break;
		}
	}

	switch ( load_pnm(&pnm, input_file))
	{
	case -1:
		printf("impossible d'allouer suffisamment de memoire\n");
		return 1;

	case -2:
		printf("Nom du fichier mal formé\n");
		return 1;

	case -3:
		printf("Contenu du fichier malformé\n");
		return 1;
	}



	switch ( write_pnm(pnm, output_file))
	{
	case -1:
		printf("Nom du fichier mal formé \n");
		return 1;

	case -2:
		printf("Erreur lors de la manipulation du fichier \n");
		return 1;
	}

	return 0;
}
