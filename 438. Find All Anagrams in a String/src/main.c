/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   leetcode                                           :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 04/02/2023 22:40:27 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 04 February 2023 - 22:40:27
 *
 *  \brief 
 *
 *
 */

//librairies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
short* solve(char * s, char * p, int* returnSize){
    short* res = malloc(0);               //result
    int len = strlen(p);                //lenght of p
    int tmp_len = len;                  //force to do so cause sanitize error ortherwise (not fun)
    unsigned short ascii[128] = {0};    //ascci table of p
    int i = 0;                          //index of res
    char *tmp = s;                      //where we start the check
    char *start = s;                    //where we started

    /* count number of caractere in p */
    for(char *t = p; *t; t++){
        ascii[(int)*t] ++;
    }

    /* check if s countain a permutation of p (same exercice as 567)*/
    while(*s)
    {
        if(ascii[(int)*s]){
            if(tmp_len == len) 
                tmp = s;
            
            ascii[(int)*s] --;
            tmp_len--;
        }
        else{

            while(s != tmp){
                ascii[((int)*(--s))] ++;
            }
            
            tmp++;
            tmp_len = len;
        }

        if(!tmp_len){
            res = realloc(res, (i + 1) * sizeof(short));
            /* little trick w/ pointeur adress ;p */
            res[i] = tmp - start;
            i++;
        }
        s++;
    }
    *returnSize = i;
    return (res);
}

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 04 February 2023 - 22:41:33
 *  \brief Main program
 *  \param argc : number of parameters
 *  \param argv : Values of the parameters 
 *  \return 0 if no error, -1 otherwise
 */
int main (int argc, char** argv) {
    //mesure execution time with clock
    clock_t deb = clock();
    

    int n;
    short *res = solve(argv[1], argv[2], &n);
    printf("n = %d\n", n);
    putchar('[');
    for(int i = 0; i < n; i++)
        printf("%d ", res[i]);
    printf("%c]\n\n", 8);
    free(res);
    
    //mesure execution time
    clock_t fin = clock();
    printf("Execution time : %fs\n", (double)(fin - deb)/CLOCKS_PER_SEC);    
    return (0);
}
