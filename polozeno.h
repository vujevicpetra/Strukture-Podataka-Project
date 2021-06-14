#ifndef POLOZENO_H
#define POLOZENO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "student.h"
#include "kolegij.h"

struct _polozeno;
typedef struct _polozeno* posPolozeno;
typedef struct _kolegij* posKO;
typedef struct _student* posST;

typedef struct _polozeno
{
    int id_student;
    int id_kolegij;
    int ocjena;

    posPolozeno next;
}polozeno;

posPolozeno CreateNodePolozeno(void);
void ReadPolozenoFromFile(posPolozeno p);
void UpdatePolozenoFile(posPolozeno p);
void AddToPolozenoList(posPolozeno m, posST p, posKO q, int ocjena);
void DeletePolozeno(posPolozeno p, posST q);

#endif
