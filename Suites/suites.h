/*
 * suites.h
 *
 *  Created on: Sep 13, 2016
 *      Author: marijak
 */
#include <stdbool.h>

#ifndef SUITES_H_
#define SUITES_H_
#define LG_MAX 128 //define the max length of the array

typedef struct{
	int val[LG_MAX];//define an array of max 128 elts
	int lg;//the actual size of the array
}suite;

//a function that returns an empty struct array
suite s_vide();

//a function that makes a copy of tab[] with length nb in a struct array
suite s_t2s(int tab[],int nb);

//a function that returns a constant array
suite s_const (int lg, int valeur);

//a function that adds an integer t at the end of the struct array
suite s_adj(int t, suite u);

//a function that returns the length of the struct array
//preconditions: s_longueur(u)<LG_MAX
int s_longueur (suite u);

//a function that returns the value of the element on index i in the struct array u
int s_ieme(suite u, int i);

/*a function that modifies the struct array by adding an integer elt on index i
 * and returns it*/
suite s_modif(suite u,int i,int elt);

//a function that returns the max elt of a struct array u
int s_max(suite u);

//a function that prints the elts of a struct array
void s_print(suite u);

//a function that takes a struct array, revearse it and returns the modified array
suite renverser(suite u);

#endif /* SUITES_H_ */
