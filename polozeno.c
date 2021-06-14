#include "polozeno.h"


posPolozeno CreateNodePolozeno(void)
{
    posPolozeno q = NULL;
    q = (posPolozeno)malloc(sizeof(polozeno));
    q -> next = NULL;

    if(q == NULL)
    {
        printf("Neuspjela alokacija memorije u funkciji CreateNode Polozeno. Vracen NULL pointer");
        return NULL;
    }

    return q;
}


void ReadPolozenoFromFile(posPolozeno p)
{
    FILE *fp;
	posPolozeno q = NULL;
	posPolozeno last = p;

	fp = fopen("polozeno.txt", "r");

	if (fp == NULL)
    {
        printf("\nDatoteka ne postoji!");
        return;
    }

	while (feof(fp) == 0)
	{
        q = CreateNodePolozeno();
		fscanf(fp, "%d %d %d", &q->id_student, &q->id_kolegij, &q->ocjena);
		q->next = p->next;
		p->next = q;
	}

	fclose(fp);
}


void UpdatePolozenoFile(posPolozeno p)
{
    FILE *fp;
    fp = fopen("polozeno.txt", "w");

    if (fp == NULL)
		printf("\nDatoteka ne postoji!");

    while(p != NULL)
    {
        fprintf(fp,"%d %d %d", p->id_student, p->id_kolegij, p->ocjena);

        if(p->next != NULL)
            fprintf(fp, "\n");

            p = p->next;
    }

    fclose(fp);
}


void AddToPolozenoList(posPolozeno m, posST p, posKO q, int ocjena)
{
    posPolozeno z = NULL;

    while(m->next != NULL)
    {
        m = m->next;
    }

    z = CreateNodePolozeno();

    z->id_student = p->id_student;
    z->id_kolegij = q->id_kolegij;
    z->ocjena = ocjena;

    z->next = m->next;
    m->next = z;
}


void DeletePolozeno(posPolozeno p, posST q)
{
    posPolozeno z = NULL;
    posPolozeno g = NULL;

    z = p->next;


    while(p -> next != NULL && p-> next->id_student != q->id_student)
    {
        p = p -> next;
    }

    if(p -> next != NULL)
    {
        z = p -> next;

        while(z!= NULL && z->id_student == q->id_student)
        {
            g = z->next;
            free(z);

            z = g;
        }

        p->next = g;
    }
}

