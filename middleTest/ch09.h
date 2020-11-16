#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dlfcn.h>
#include <setjmp.h>
#include <wait.h>
#include <errno.h>
#define InFile "./in.txt"
#define OutFile "out.txt"
#define MODE 664