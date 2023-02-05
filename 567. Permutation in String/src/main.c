/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
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

/*!
 *  \fn int solve(char * s1, char * s2)
 *  \author DURAND Nicolas Erich Pierre <durandnico@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 04 February 2023 - 22:43:12
 *  \brief Check if s2 contain a permutation of s1
 *  \param s1 : first string$
 *  \param s2 : second string$$
 *  \return 1 if s2 contain a permutation of s1, 0 otherwise
 */
int solve(char * s1, char * s2){
    int len = strlen(s1);                   //lenght of s1
    int tmp_len = len;                      //force to do so cause sanitize error ortherwise (not fun)
    unsigned short ascii[128] = {0};        //ascci table of s1
    bool res = 0;                           // result
    char *tmp = s2;                         //where we start the check

    /* count number of caractere in s1 */
    for(char *p = s1; *p; p++){
        ascii[(int)*p] ++;
    }

    /* check if s2 countain a permutation of s1 */
    while(!res && *s2)
    {
        if(ascii[(int)*s2] > 0){
            if(tmp_len == len) 
                tmp = s2;
            
            ascii[(int)*s2] --;
            tmp_len--;
        }
        else{

            while(s2 != tmp){
                ascii[((int)*(--s2))] ++;
            }
            
            tmp++;
            tmp_len = len;
        }

        if(!tmp_len){
            res = 1;
        }
        s2++;
    }
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

    printf("%s\n", solve(argv[1], argv[2])? "true" : "false");
    
    //mesure execution time
    clock_t fin = clock();
    printf("Execution time : %fs\n", (double)(fin - deb)/CLOCKS_PER_SEC);    
    return (0);
}
