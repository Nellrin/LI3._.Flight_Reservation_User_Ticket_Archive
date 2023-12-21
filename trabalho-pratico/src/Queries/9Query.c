#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../include/Catalogs/Catalog.h"
#include "../../include/Utilities.h"

#include "../../include/DataStructures/Users.h"
#include "../../include/DataStructures/BTree.h"
#include "../../include/DataStructures/Flights.h"
#include "../../include/DataStructures/Reservations.h"
#include "../../include/Queries/9Query.h"



static void line_user(void * a, char *** list_id, char *** list_name, int * n, char * prefix){
    char * name = get_userNAME(a);

    if(!strncmp(prefix,name,strlen(prefix))&&get_userASTATUS(a)==1){
        (*list_id)[(*n)] = get_userID(a);

        // printf("%s\n",name);
        (*list_name)[(*n)] = get_userNAME(a);
            
        (*n) ++;
        
    }
        free(name);
}

static char * strcat_list_pre( char ** list_id,char ** list_dates, short F, int n){

    char * line = malloc(sizeof(char) * 200000);
    char * x = malloc(sizeof(char) * 3);
    line[0] = '\0';
    
    if(F){
            for (int i = 0; i < n; i++) {
                
                    sprintf(x, "%d", i+1);
                    strcat(line, "--- ");
                    strcat(line, x);
                    strcat(line, " ---\n");
                
                strcat(line, "id: ");
                strcat(line, list_id[i]);
                strcat(line, "\name: ");
                strcat(line, list_dates[i]);


                strcat(line, "\n\n");
            }


            line[strlen(line)-1] = '\0';
    }


    else{
        for(int i = 0; i < n; i++){
            strcat(line,list_id[i]);
            strcat(line,";");
            strcat(line,list_dates[i]);
            strcat(line,"\n");
        }
    }

    free(x);
    return line;

}

static char * query9_getter(Almanac * box, char * argument ,char F){
    char * result = NULL;
    
    int nt = 1000;

    char **list_user_id = malloc(sizeof(char *) * nt);
    char **list_user_name = malloc(sizeof(char *) * nt);

    nt = 0;


        void * users = almanac_get_prefix(box);


        get_prefix(users, &list_user_id,&list_user_name, argument,&nt, line_user);

        result = strcat_list_pre(list_user_id,list_user_name,F,nt);

            // for(int i = 0; i < nt; i++){
            //     if(list_user_id[i]!=NULL)
            //     free(list_user_id[i]);
            //     free(list_user_name[i]);
            // }

            // free(list_user_id);
            // free(list_user_name);

            return result;
}


char * query9(Almanac * box, char * argument,  short F){

        return query9_getter(box,argument,F);

}