#ifndef PODATCI_H
#define PODATCI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "student.h"
#include "kolegij.h"

struct _podatci;

typedef struct _student* posST;
typedef struct _kolegij* posKO;
typedef struct _podatci* posPO;

typedef struct _podatci
{
    double prosjek;
    int pol_ects;
    int skolarina;

    posKO down;

}podatci;

posPO CreateNodePO(void);
void RacunanjePodataka(posST p);
int RacunanjeSkolarine(posPO pojedinac, int tempEcts);
void PrintPodatci(posST p);


#endif
