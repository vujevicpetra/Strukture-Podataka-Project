#include "podatci.h"

posPO CreateNodePO(void)
{
    posPO q = NULL;
    q = (posPO)malloc(sizeof(podatci));
    q -> down = NULL;

    if(q == NULL)
    {
        printf("Neuspjela alokacija memorije u funkciji CreateNode Polozeno. Vracen NULL pointer");
        return NULL;
    }

    return q;
}


void RacunanjePodataka(posST p)
{
  while(p != NULL)
  {
    double tempProsjek = 0;
    int tempEcts = 0;
    int ectsOcjena = 0;


    posPO pojedinac = p->down;
    posKO pocetak = pojedinac->down;

    while(pocetak != NULL)
    {
        tempEcts += pocetak->ects_kol;
        ectsOcjena += (pocetak->ocjena*pocetak->ects_kol);
        pocetak = pocetak->down;

    }
    if(tempEcts == 0)
        tempProsjek = 0;
    else
        tempProsjek = (double)ectsOcjena/tempEcts;

    pojedinac->prosjek = tempProsjek;
    pojedinac->pol_ects = tempEcts;

    tempEcts = RacunanjeSkolarine(pojedinac, tempEcts);

    p = p->next;
  }
}


int RacunanjeSkolarine(posPO pojedinac, int tempEcts)
{
    int skolarina = 0;

    if(tempEcts >= 55)
    pojedinac->skolarina = 400;

    else if(tempEcts < 55 && tempEcts >= 30)
    {
        skolarina = ((60 - tempEcts)*140) + 400;
        pojedinac->skolarina = skolarina;
    }
    else
        pojedinac->skolarina = 8400;

    return tempEcts;
}


void PrintPodatci(posST p)
{
    printf("\n\nProsjek: %.3g   Broj polozenih ECTS bodova: %d   Skolarina: %d kn\n\n", p->down->prosjek, p->down->pol_ects, p->down->skolarina);
}

