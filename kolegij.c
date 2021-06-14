#include "kolegij.h"


posKO CreateNodeKO(void)
{
    posKO q = NULL;
    q = (posKO)malloc(sizeof(kolegij));
    q -> down = NULL;

    if(q == NULL)
    {
        printf("Neuspjela alokacija memorije u funkciji CreateNode Kolegij. Vracen NULL pointer");
        return NULL;
    }

    return q;
}


int IsKolegijListEmpty(posKO p)
{
    if(p == NULL)
    {
        printf("\nU funkciju poslana prazna lista. Vracena nula.\n\n");
        return 1;
    }
    else
        return 0;
}


void ReadKolegijFromFile(posKO p)
{
    IsKolegijListEmpty(p);

    FILE *fp;

    fp = fopen("kolegij.txt", "r");
	if (fp == NULL)
        printf("\nDatoteka ne postoji!");

    while(!feof(fp))
    {
        posKO q = NULL;
        q = CreateNodeKO();

        fscanf(fp, "%d %s %d", &q->id_kolegij, q->ime_kolegij, &q->ects_kol);

        q->ocjena = 0;

        q->down = p->down;
        p->down = q;
    }
    fclose(fp);
}


void PrintKolegij(posKO p)
{
  printf("%d %s %d %d\n", p->id_kolegij, p->ime_kolegij, p->ects_kol, p->ocjena);
}


void PrintKolegijList(posKO p)
{
    while(p!=NULL)
    {
        PrintKolegij(p);

        p = p->down;
    }
}


posKO FindKolegij(posKO p, int ko)
{
    while(p != NULL && ko != p->id_kolegij)
    {
        p = p -> down;
    }
    return p;
}


void ReadPodatciFromFile(posST p, posKO q)
{
    int id_student;
    int id_kolegij;
    int ocjena;

    FILE *fp = NULL;
    fp = fopen("polozeno.txt","r");

    if(fp==NULL)
    {
        printf("U funkciji ListKolegij neuspjelo otvaranje datoteke.\n");

        return;
    }


    while(!feof(fp))
    {
        fscanf(fp, "%d %d %d", &id_student, &id_kolegij, &ocjena);
        AddKolegijToStudent(p, q, id_student, id_kolegij, ocjena);
    }

}


void AddKolegijToStudent(posST p, posKO q, int id_student, int id_kolegij, int ocjena)
{

    posST tmp_student = FindStudent(p, id_student);
    posKO tmp_kolegij = FindKolegij(q, id_kolegij);

    CreateKolegij(tmp_student, tmp_kolegij, ocjena);
}


void CreateKolegij(posST p, posKO q, int ocjena)
{
    posKO new_kolegij = CreateNodeKO();

    new_kolegij->id_kolegij = q->id_kolegij;
    strcpy(new_kolegij->ime_kolegij, q->ime_kolegij);
    new_kolegij->ects_kol = q->ects_kol;
    new_kolegij->ocjena = ocjena;

    new_kolegij->down = p->down->down;
    p->down->down = new_kolegij;

}


void AddKolegijToNewStudent(posKO headKO, posST p, posPolozeno m)
{
    int i, id_kol, ocjena;
    int n;
    posKO q = NULL;

    printf("\n\nUnesite broj polozenih kolegija novog studenta: \n");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("id kolegija i ocjena:");
        scanf("%d %d", &id_kol, &ocjena);

        q = FindKolegij(headKO, id_kol);

        CreateKolegij(p, q, ocjena);

        AddToPolozenoList(m, p, q, ocjena);

    }

    UpdatePolozenoFile(m->next);
    RacunanjePodataka(p);
}
