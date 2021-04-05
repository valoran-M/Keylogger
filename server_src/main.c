#include <stdio.h>
#include <string.h>

#include "server.h"

/** 
 *  This main fonction of server program
 * 
 *  @param argc number of string in argv
 *  @param argv an array of string
 *  @return  0 if the program is not interrupted before
 **/
int main(int argc, char const *argv[])
{
    app();
    
    return 0;
}