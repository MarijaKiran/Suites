/*
 * suites.c
 *
 *  Created on: Sep 13, 2016
 *      Author: marijak
 */

#include "suites.h"
#include <stdio.h>
#include <stdlib.h>

suite s_vide()
{
//define a struct array u
suite u;
//set its length to 0
u.lg=0;
//return the empty struct array
return u;
}

suite s_t2s(int tab[],int nb)
{
	//define a counter
	int i;
	//define a struct array u
	suite u;
	//set its length to the length nb of the array we wish to copy
	u.lg=nb;
	for(i=0;i<nb;i++)
	{
		//attribute to each elt on index i in the struct array the value of the ith elt of the array tab
		u.val[i]=tab[i];
	}
	//return the copy of the array tab as a struct array u
	return u;
}

suite s_const (int lg, int valeur)
{
	//define a counter
	int i;
	//define a struct array u
	suite u;
	//set the length of the struct array to the length passed in parameter
	//won't confuse the same name lg, as the first one is a part of a structure
	u.lg=lg;
	for(i=0;i<lg;i++)
	{
		//assign to ith elt of the struct array u the const value "valeur" passed in parameter
		u.val[i]=valeur;
	}
	//return the constant struct array
	return u;
}

suite s_adj(int t, suite u)
{
	//add a new elt "t" at the end of the struct array
	//increment the length of the array
	/*suppose l=30->
	 * add an elt on index 30->
	 * increment the length right after*/
	u.val[u.lg++]=t;
	//return the modified struct array
	return u;
}

int s_longueur (suite u)
{
	//return the length of the struct array
	return u.lg;
}

int s_ieme(suite u, int i)
{
	//return the value of the ieme elt of the struct array
	return u.val[i];
}

suite s_modif(suite u,int i,int elt)
{
	//assign value "elt" to ieme elt of the struct array
	u.val[i]=elt;
	//return the struct array
	return u;
}

int s_max(suite u)
{
	//suppose elt on index 0 of the struct array is the max elt
	int max=u.val[0];
	//define counter
	int i;
	//for each elt from 0 to length-1 check
	for(i=0;i<u.lg;i++)
	{
		//if the elt on index i is bigger than the max elt
		if(u.val[i]>max)
			{
				//if so change the value of the max elt
				max=u.val[i];
			}
	}
	//return the max elt of the struct array
	return max;
}

void s_print(suite u)
{
	//define counter
	int i;
	//for each elt from 0 to length-1
	for(i=0;i<u.lg;i++)
	{
	//print each elt
	printf("%d\t",u.val[i]);
	}
}

suite renverser(suite u)
{
	//define a new struct array
	suite w;
	//get the length of the struct array u by storing the return result of the function s_longueur into a int variable lg
	int size=s_longueur(u);
	//assign value "size" as length of the new struct array w
	w.lg=size;
	//define counters
	int i, k;
	//for i from size-1 to 0
	//for k from 0 to size-1
	for(i=size-1,k=0;i>=0 && k<size;i--,k++)
		{
		//assign value of last elt of u to first elt of w
		//TRY TO DO THE SAME BUT USING THE s_modif function!!!
		w.val[k]=u.val[i];
		}
	//return the reversed struct array w
	return w;
}

int main()
{
	int tab[]={1,2,3,4,5};
	suite u=s_t2s(tab,5);
	suite l=renverser(u);
	s_print(l);
	return 0;
}
