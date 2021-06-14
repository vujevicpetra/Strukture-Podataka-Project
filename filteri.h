#ifndef FILTERI_H
#define FILTERI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "kolegij.h"
#include "podatci.h"

typedef struct _student* posST;
typedef struct _kolegij* posKO;
typedef struct _podatci* posPO;

void DohvatiStudentPrekoId(posST p);
void DohvatiStudentPrekoPrezime(posST p);
void DohvatiStudentPrekoGodRod(posST p);
void BrojStudenata(int br);
void StudentiPoloziliKolegij(posST p, posKO q);
void DohvatiStudentPrekoProsjek(posST p);
void ProvjeriProsjek(posST p, int ocjena);
void DohvatiStudentPrekoSkolarina(posST p);
void DohvatiStudentPrekoUpisnina(posST p);
void DohvatiStudentPrekoParticipacija(posST p);
void DohvatiStudentPonavljac(posST p);
void DohvatiKolegijPrekoECTS(posKO q);
void DohvatiStudentPrekoKolegijOcjena(posST p, posKO q);
void DohvatiStudentMaxProsjek(posST p, posST r);
void ProsjekSviStudenti(posST p);


#endif
