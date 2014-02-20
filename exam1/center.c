/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char *s, int n, char fillchar)
{
    int i, front, end;
    int numchar = n - strlen(s);
    char *dest, *buf;

    if (numchar % 2 == 1){
        front = numchar/2;
        end = numchar/2 +1;
    }
    else{
        front = numchar/2;
        end = numchar/2;
    }

    buf = (char *) malloc(n + 1);
    dest = buf;

    for (i=0; i<front; i++) {
        strcpy(dest, fillchar);
        dest++;
    }
    for (i=front; i<end; i++){
        strcpy(dest, s[i-front]);
        dest ++;
    }
    for (i=end; i<n; i++){
        strcpy(dest, fillchar);
        dest ++;
    }

    return buf;
}


int main (int argc, char *argv[])
{
    char *s = center("Softwar", 30, '.');
    printf("%s\n", s);

    // char *s2 = center("Systems", 31, '-');
    // printf("%s\n", s2);

    // char *s3 = center("Spring 2014", 32, '*');
    // printf("%s\n", s3);

    // char *s4 = center("Exam 1", 33, '^');
    // printf("%s\n", s4);

    return 0;
}
