#ifndef UTILITIES_H
#define UTILITIES_H


///////////////////////////////////////////////////////////////
typedef struct almanac Almanac;
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
int string_to_time(char *format, char *date1, char *date2);
float total_pay(float ppn, float tax, int nights);
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
int valid_user(Almanac * a, const char * string);
int valid_flight(Almanac * a, const  char * string);
int valid_reservation(Almanac * a, const  char * string);
int valid_passenger(Almanac * a, const  char * string);
///////////////////////////////////////////////////////////////


#endif