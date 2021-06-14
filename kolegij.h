#ifndef KOLEGIJ_H
#define KOLEGIJ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "student.h"
#include "podatci.h"
#include "polozeno.h"

struct _kolegij;

typedef struct _kolegij* posKO;
typedef struct _student* posST;
typedef struct _polozeno* posPolozeno;

typedef struct _kolegij
{
    int id_kolegij;
    char ime_kolegij[100];
    int ects_kol;
    int ocjena;

    posKO down;

}kolegij;

posKO CreateNodeKO(void);
int IsKolegijListEmpty(posKO p);
void ReadKolegijFromFile(posKO p);
void PrintKolegij(posKO p);
void PrintKolegijList(posKO p);
posKO FindKolegij(posKO p, int ko);
void ReadPodatciFromFile(posST p, posKO q);
void AddKolegijToStudent(posST p, posKO q, int id_student, int id_kolegij, int ocjena);
void CreateKolegij(posST p, posKO q, int ocjena);
void AddKolegijToNewStudent(posKO headKO, posST p, posPolozeno m);




#endif
