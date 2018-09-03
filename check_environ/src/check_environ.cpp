//============================================================================
// Name        : check_environ.cpp
// Author      : Deepak Mane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
        char **p = environ;

        while (*p != NULL)
        {
                printf("%s (%p)\n", *p);
                *p++;
        }

        return 0;
}
//
//#include <stdio.h>
//
//
//int main(int argc, char *argv[], char *envp[])
//{
//        char **p = envp;
//
//        while (*p != NULL)
//        {
//                printf("%s (%p)\n", *p, *p);
//                *p++;
//        }
//
//        return 0;
//}
