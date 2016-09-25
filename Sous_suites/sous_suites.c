/*
 * sous_suites.c
 *
 *  Created on: Sep 25, 2016
 *      Author: marijak
 */

#include "suites.h"
#include "sous_suites.h"
#include <stdlib.h>
#include <stdio.h>

//a function that takes a ptr to an array u and returns an empty sub array
//in our context an empty subarray would be an array which has -1 as values of the array ch
sous_suite ss_vide(suite *u)
{
	//we define a subarray
	sous_suite su;
	//we set ms from the structure of sous_suite equal to array u
	su.ms=u;
	//we set prem to 0
	su.prem=0;
	for(int i=0;i<LG_MAX;i++)
	{
	su.ch[i]=-1;
	}
	return su;
}

int ss_longueur(sous_suite su)
{
	//initialize int variable lg to 0
	int lg=0;
	//starting from i=index of first elt,
	//as longs as elt on ith position are different from -1 and
	//i does not acceed the length of the array u,
	//i gets the value of elt on ith position in array ch
	//as ch already contains values of indexes,
	//this is how we set up the values for our next elts
	for(int i=su.prem;su.ch[i]!=-1 && i<su.ms->lg;i=su.ch[i])
	{
		lg++;
	}
	return lg;
}

int ss_ieme (sous_suite su,int i)
{
	//initialize j to index of the first elt in the subarray su
	int j=su.prem;
	//for j initialized as above
	//as longs as value on jth position in array ch is different than -1
	//and i is bigger than 0?
	//j takes value of ch[j]
	//as ch contains already values of indexes of the next elts
	for(;su.ch[j]!=-1 && i>0;j=su.ch[j])
	{
		i--;
	}
	if(i==0)
	{
		return su.ms->val[j];
	}
	else
	{
		perror("Out of the array!");
		exit(-1);

	}
}

sous_suite ss_modifie_suiv (sous_suite su,int i, int n_suiv)
{
	su.ch[i]=n_suiv;
	return su;
}

void ss_print(sous_suite su)
{
	//store the length of the subarray su in variable l by calling the funct ss_longueur
	int l=ss_longueur(su);
	//from i 0 to index l-1
	for(int i=0;i<l;i++)
	{
	//print the ieme elt of array su on index i
    //CAUTION: We have to understand that
	//the struct sous_suite doesnt contain an array with its values,
	//instead it contains an array of the indexes
	//referring to the next elts
    //that the subarray would contain,
	//thats why we need to use this aux function
	//which gives exactly the values of the subarray su
		printf("%d",ss_ieme(su,i));
	}
}

sous_suite ss_1sur2 (suite *u)
{
	//define a subarray
	sous_suite su;
	//set ms to array u
	su.ms=u;
	//set index of first elt of the subarray to 0
	//as we will be taking every second elt starting from indez 0
	//meaning we will take only elts on pair positions
	su.prem=0;
	int i;
	for(i=0;i<u.lg-2;i+=2)
	{
		//elt on pair position gets as value
		//the pair index of next elt in the array
		su.ch[i]=i+2;
	}
	//takes care of last elt by making sure that
	//index on last position does not point to another index as there are no more elts afterwards
	su.ch[i]=-1;
	return su;
}

sous_suite ss_suite_croiss (suite *u)
{
	//define a subarray
	sous_suite su;
	//set ms of su to array u
	su.ms=u;
	//set first elts index starting at 0
	su.prem=0;
	//for i from 0 to length of array u -1
	//and as longs as value of elt on ith position in array u is smaller than the next one
	//bacause thats what consequently mean
	for(int i=0;i<u->lg-1 && u.val[i]<u.val[i+1];i++)
	{
		//set elts on ith position in ch to i+1
		su.ch[i]=i+1;
	}
	return su;
}





