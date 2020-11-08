#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "user.dat"
#define SORTBYNAME 1
#define SORTBYID 0

typedef struct user
{
    int id;
    char name[8];
    char htel[12];
    char tel[12];
} USER;

typedef struct userList
{
    USER* user;
    struct userList* next;  
} UList;

FILE* fp;
int total;


int addToList(USER* user,UList* head);
int saveAll(UList* head);
USER* input(void);
int save(USER*userinfo);
int output(UList* users);
UList* read();
int giveId(UList* head);
int removeById(UList* head,int id);
UList* copyOne(UList *head);

UList *mysort(UList *head,UList *end,int type);
void quick_sort(UList *pbegin,UList *pend,int type);
UList *partion(UList *pbegin ,UList * pend,int type);
void swap(USER*a,USER*b);
UList* getEnd(UList *head);

USER* randData();