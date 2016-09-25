/*
 * sous_suites.h
 *
 *  Created on: Sep 18, 2016
 *      Author: marijak
 */

#include "suites.h"

#ifndef SOUS_SUITES_H_
#define SOUS_SUITES_H_

typedef struct {
	//pointer to the suite from which the sub array is extracted
	suite *ms;
	//the value/index? of the first element in the sub array
	int prem;
	//the array of indexes of the next elements in the array forming the sub array
	int ch[LG_MAX];

}sous_suite;

//returns an empty subarray of array u
sous_suite ss_vide(suite *u);

//returns the length of the subarray su
int ss_longueur(sous_suite su);

//returns the elt on index i in the subarray
int ss_ieme(sous_suite su,int i);

//returns the modified subarray where ch[i]=n_suiv
//where n_suiv is the index of the next elt we want to add
sous_suite ss_modifie_suiv(sous_suite su,int i,int n_suiv);

//prints the subarray
void ss_print(sous_suite su);

//a function that generates a subarray from an array u by taking every second elt
//returns the subarray
sous_suite ss_1sur2 (suite *u);

//a function that generates an array of consequently increasing values in the array u
//returns the subarray
sous_suite ss_suite_croiss (suite *u);


#endif /* SOUS_SUITES_H_ */
