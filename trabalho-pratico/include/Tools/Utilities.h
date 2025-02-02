#ifndef UTILITIES_H
#define UTILITIES_H


///////////////////////////////////////////////////////////////
typedef struct almanac Almanac;
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
int string_to_time(char * format,char *date1, char *date2);
void swap_pointers(void ** s1, void ** s2);
void swap_strings(char ** s1, char ** s2);
void swap_ints(int * a, int * b);
int count_lines(const char *str);
int count_chars(const char *str, char c);
void sort_strings(char*** arr, char*** ids, int count, int (*f)(char*,char*,char*,char*));
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
int median(int * array, int amount);
int compare_strings(char* str1, char* str2, char* id1, char* id2);
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
int valid_user(Almanac * a, const char * string);
int valid_flight(Almanac * a, const  char * string);
int valid_reservation(Almanac * a, const  char * string);
int valid_passenger(Almanac * a, const  char * string);
///////////////////////////////////////////////////////////////


#endif