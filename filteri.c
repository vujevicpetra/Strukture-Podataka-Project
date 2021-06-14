#include "filteri.h"

void DohvatiStudentPrekoId(posST p)
{
    int id;
    printf("\nUnesite id studenta cije podatke zelite dohvatiti:\n\n");
    PrintStudentList(p);
    printf("\n");
    scanf("%d", &id);
    printf("\n");

    while(p!=NULL)
    {
        if(p->id_student == id)
        {
            PrintStudent(p);
            PrintPodatci(p);
            PrintKolegijList(p->down->down);
        }
        p = p->next;
    }

    printf("\n\n\n");
}


void DohvatiStudentPrekoPrezime(posST p)
{
    char prezime[100];
    printf("\nUnesite prezime studenta cije podatke zelite dohvatiti:\n\n");
    PrintStudentList(p);
    printf("\n");
    scanf("%s", prezime);
    printf("\n");

    while(p!=NULL)
    {
        if(_stricmp(p->prezime, prezime)==0)
        {
            PrintStudent(p);
            PrintPodatci(p);
            PrintKolegijList(p->down->down);
            printf("\n----------------------------------------------------------------------------------------------\n\n");
        }
        p = p->next;
    }

    printf("\n\n\n");
}


void DohvatiStudentPrekoGodRod(posST p)
{
    int god_rod;

    printf("\nUnesite godinu rodenja :\n\n");
    PrintStudentList(p);
    printf("\n");

    scanf("%d", &god_rod);
    printf("\n");

    if(p->god_rod != god_rod)
    {
        printf("\nNe postoji student s upisanom godinom rodenja.\n");
        DohvatiStudentPrekoGodRod(p);
    }

    while(p!=NULL)
    {
        if(p->god_rod == god_rod)
            PrintStudent(p);

        p = p->next;
    }

}


void BrojStudenata(int br)
{
    printf("\n\nBroj studenata koji su polozili kolegij: %d.",br);
    printf("\n\n\n");
}


void StudentiPoloziliKolegij(posST p, posKO q)
{
    int id;
    int brojac = 0;
    printf("Unesite id kolegija za kojeg zelite dohvatiti studente koji su ga polozili:\n");
    PrintKolegijList(q);
    printf("\n");
    scanf("%d", &id);
    printf("\n");

    while(p != NULL)
    {
        posKO temp = p->down->down;

        while(temp != NULL)
        {
            if(temp->id_kolegij == id)
                {
                    PrintStudent(p);
                    brojac++;
                }
            temp = temp->down;
        }
        p = p->next;
    }

    BrojStudenata(brojac);
}


void DohvatiStudentPrekoProsjek(posST p)
{
    int ocjena;

    printf("\nUnesite ocjenu: \n");
    scanf("%d", &ocjena);
    printf("\n");

    if(ocjena == 1)
        printf("Sljedeci studenti nisu polozili niti jedan kolegij:\n\n");
    else
        printf("Sljedeci studenti su polozili akademsku godinu s ocjenom %d:\n\n", ocjena);

    while(p != NULL)
    {
        ProvjeriProsjek(p, ocjena);

        p = p->next;
    }

    printf("\n\n\n");
}


void ProvjeriProsjek(posST p, int ocjena)
{
    posPO r = p->down;

    if(ocjena == 1)
    {
        if(r->prosjek < 2.0)
            {
                PrintStudent(p);
            }
    }
    else if(ocjena == 2)
    {
        if(r->prosjek >= 2.0 && r->prosjek < 2.5)
            PrintStudent(p);
    }
    else if(ocjena == 3)
    {
        if(r->prosjek >= 2.5 && r->prosjek < 3.5)
            PrintStudent(p);
    }
    else if(ocjena == 4)
    {
        if(r->prosjek >= 3.5 && r->prosjek < 4.5)
            PrintStudent(p);
    }
    else if(ocjena == 5)
    {
        if(r->prosjek >= 4.5)
            PrintStudent(p);
    }
}


void DohvatiStudentPrekoSkolarina(posST p)
{
    while(p!=NULL)
    {
        if (p->down->skolarina == 8400)
            PrintStudent(p);

        p = p->next;
    }

     printf("\n\n\n");
}


void DohvatiStudentPrekoUpisnina(posST p)
{
    while(p!=NULL)
    {
        if (p->down->skolarina == 400)
            PrintStudent(p);

        p = p->next;
    }

     printf("\n\n\n");
}


void DohvatiStudentPrekoParticipacija(posST p)
{
    while(p!=NULL)
    {
        if (p->down->skolarina > 400 && p->down->skolarina < 8400)
            PrintStudent(p);

        p = p->next;
    }

     printf("\n\n\n");
}


void DohvatiStudentPonavljac(posST p)
{
    while(p!=NULL)
    {
        if(p->down->pol_ects < 42)
             PrintStudent(p);

        p = p ->next;
    }

     printf("\n\n\n");
}


void DohvatiKolegijPrekoECTS(posKO q)
{
    int ects;

    printf("Unesite broj ECTS bodova:\n");
    scanf("%d", &ects);


    while(q != NULL)
    {
        if(q->ects_kol == ects)
            PrintKolegij(q);

        q = q->down;
    }

    printf("\n\n\n");
}


void DohvatiStudentPrekoKolegijOcjena(posST p, posKO q)
{
    int id_kol, ocjena;

    printf("\nLista kolegija:\n\n");
    PrintKolegijList(q);
    printf("\n\nUnesite id kolegija i ocjenu:\n");
    scanf("%d %d", &id_kol, &ocjena);
    printf("\n");

    if(id_kol > 10 || ocjena > 5)
    {
        printf("Unijeli ste pogresan id kolegija ili ocjenu.\n\n");
        DohvatiStudentPrekoKolegijOcjena(p,q);
    }

    while(p != NULL)
    {
        posKO temp = p->down->down;

        while(temp != NULL)
        {
            if(temp->id_kolegij == id_kol && temp->ocjena == ocjena)
                PrintStudent(p);

            temp = temp->down;
        }

        p = p->next;
    }
        printf("\n\n\n");
}


void DohvatiStudentMaxProsjek(posST p, posST r)
{
    posPO tempP = NULL;
    posPO tempR = NULL;

    while(p != NULL && r != NULL)
    {
        tempP = p->down;
        tempR = r->down;

        if(tempP->prosjek < tempR->prosjek || tempP->prosjek == tempR->prosjek)
            p = p -> next;
        else if(tempP->prosjek > tempR->prosjek)
            r = r -> next;
    }

    printf("\nStudent s najboljim prosjekom (%.2f) je:\n", r->down->prosjek);
    PrintStudent(r);
    printf("\n\n\n");
}


void ProsjekSviStudenti(posST p)
{
    int br = 0;
    double ukupanprosjek = 0.00;
    double x;

    posPO temp = NULL;

    while(p != NULL)
    {
        temp = p->down;
        ukupanprosjek += temp->prosjek;
        br++;
        p = p->next;
    }

    x = ukupanprosjek/(double)br;
    printf("\nProsjecna ocjena svih studenata je: %.2f.\n", x);
    printf("\n\n\n");
}
