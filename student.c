#include "student.h"
#include "podatci.h"
#include "polozeno.h"

posST CreateNodeST(void)
{
    posST q = NULL;
    q = (posST)malloc(sizeof(student));
    q -> next = NULL;

    if(q == NULL)
    {
        printf("Neuspjela alokacija memorije u funkciji CreateNode Student. Vracen NULL pointer.");
        return NULL;
    }

    return q;
}


posST CreateNodeSTAndInitialize(int Id, char* Name, char *LastName, int Year)
{
    posST q = NULL;
    q = (posST)malloc(sizeof(student));
    q -> next = NULL;

    if(q == NULL)
    {
        printf("Neuspjela alokacija memorije u funkciji CreateNode Student. Vracen NULL pointer.");
        return NULL;
    }

    q -> id_student = Id;
    strcpy(q ->ime, Name);
    strcpy(q->prezime, LastName);
    q->god_rod = Year;

    return q;
}


int GetRandomIdStudent(posST start, posST p)
{
   time_t t;
   srand((unsigned) time(&t));

   posST z = start->next;

   int uvjet = 1;
   int test;

   while(uvjet)
   {
       test = rand() % RAND_MAX;

       while(z != NULL && z->id_student != test)
            z = z->next;

       if(z == NULL)
            uvjet = 0;
       else
            uvjet = 1;
   }

    p->id_student = test;

   return 0;
}

int ReadStudentsFromFile(posST p)
{
    FILE *fp;
	int id_student;
	char ime[100];
	char prezime[100];
	int god_rod;

	posST q;

	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
    {
        printf("\nDatoteka ne postoji!");
        return 0;
    }

	while (!feof(fp))
	{

		fscanf(fp, "%d %s %s %d\n", &id_student, ime, prezime, &god_rod);
		q = CreateNodeSTAndInitialize(id_student, ime, prezime, god_rod);

		SortiraniUnos(p,q);
	}

	fclose(fp);

	return 1;
}


void SortiraniUnos(posST p, posST r)
{
    posPO d = NULL;
    posST z = p;

    d = CreateNodePO();
    r -> down = d;

    while(z->next != NULL && _stricmp(z->next->prezime, r -> prezime) < 0)
    {
        z = z->next;
    }


    if(z->next != NULL && _stricmp(z->next->prezime, r -> prezime) == 0)
    {
        while(z->next != NULL && _stricmp(z->next->ime, r -> ime) < 0 && _stricmp(z->next->prezime, r -> prezime) == 0)
        {
            z = z->next;
        }
    }

    r->next = z->next;
    z->next = r;

}


int IsStudentListEmpty(posST p)
{
    if(p == NULL)
    {
        printf("\nGreska! Poslana je prazna lista studenata.\n\n");
        return 1;
    }
    else
        return 0;
}


void PrintStudent(posST p)
{
   printf("%d %s %s %d\n", p->id_student, p->ime, p->prezime, p->god_rod);
}


void PrintStudentList(posST p)
{
    if(IsStudentListEmpty(p));

    while(p!=NULL)
    {
        PrintStudent(p);

        p = p->next;
    }
}


void UpdateStudentFile(posST p)
{
    FILE *fp;
    fp = fopen("studenti.txt", "w");

    if (fp == NULL)
		printf("\nDatoteka ne postoji!");

    while(p != NULL)
    {
        fprintf(fp,"%d %s %s %d\n", p->id_student, p->ime, p->prezime, p->god_rod);
        p = p->next;
    }

    fclose(fp);

    return;
}


posST FindStudent(posST p, int st)
{

    while(p != NULL && st != p ->id_student)
        {
        p = p -> next;
        }
    return p;

}


void ReadFromKeyboard(posST q)
{
    printf("\n\nUnesite ime, prezime i godinu rodenja studenta kojeg zelite dodati u listu: \n");
    scanf("%s %s %d", q->ime, q->prezime, &q->god_rod);
}


int AddStudent(posPolozeno m, posST p, posKO r)
{
    posST q = NULL;

    if(IsStudentListEmpty(p))return 0;

    q = CreateNodeST();

    GetRandomIdStudent(p, q);
    ReadFromKeyboard(q);
    SortiraniUnos(p,q);

    UpdateStudentFile(p->next);
    AddKolegijToNewStudent(r, q, m);

    return 1;
}


void PrintList(posST p)
{
    posKO temp = NULL;

    while(p!=NULL)
    {

        PrintStudent(p);
        PrintPodatci(p);
        temp = p->down->down;


        while(temp != NULL)
        {
            PrintKolegij(temp);
            temp = temp->down;
        }

        printf("\n----------------------------------------------------------------------------------------------\n\n");

        p = p -> next;
    }

}


int DeleteStudent(posST p, posPolozeno q)
{
    if(IsStudentListEmpty(p))
        return 0;

    int odabir = 0;


    printf("\n\n\nOdaberite nacin brisanja:\n 1) po id-u studenta\n 2) po prezimenu studenta:\n\n");

    while(odabir != 1 && odabir != 2)
    {
        scanf("%d", &odabir);
        if(odabir==1)
        {
            DeleteStudentById(p, q);

        }

        else if(odabir==2)
        {
            DeleteStudentBySurname(p, q);
        }
        else
            printf("Pogresan odabir. Pokusajte ponovno.\n");
    }

    return 1;
}


void DeleteStudentById(posST p, posPolozeno m)
{
    int id_brisanja = 0;

    posST PrethodniStudent = NULL;
    posST TrazeniStudent = NULL;
    posKO PrviKolZaBrisanje = NULL;
    posKO PomocniKolZaBrisanje = NULL;

    printf("\n\nUnesite id studenta kojeg zelite izbrisati: \n");
    PrintStudentList(p->next);
    scanf("%d", &id_brisanja);

    PrethodniStudent = p;

    while(PrethodniStudent->next != NULL && PrethodniStudent->next->id_student != id_brisanja)
    {
        PrethodniStudent = PrethodniStudent->next;
    }

    if(PrethodniStudent->next != NULL)
    {
        TrazeniStudent = PrethodniStudent->next;

        if(TrazeniStudent->down->down != NULL)
        {
            DeletePolozeno(m, TrazeniStudent);
            UpdatePolozenoFile(m->next);

            PrviKolZaBrisanje = TrazeniStudent->down->down;

            while(PrviKolZaBrisanje != NULL)
            {
                PomocniKolZaBrisanje = PrviKolZaBrisanje->down;
                free(PrviKolZaBrisanje);
                PrviKolZaBrisanje = PomocniKolZaBrisanje;
            }
        }

        PrethodniStudent->next = TrazeniStudent->next;
        free(TrazeniStudent->down);
        free(TrazeniStudent);
        printf("\n\nLista studenata nakon brisanja:\n");
        PrintStudentList(p->next);
    }
    else
        printf("Ne postoji student s unesenim id-em.\n");

}


void DeleteStudentByGivenId(posST p, posPolozeno m, int GivenId)
{
    posST PrethodniStudent = NULL;
    posST TrazeniStudent = NULL;
    posKO PrviKolZaBrisanje = NULL;
    posKO PomocniKolZaBrisanje = NULL;

    PrethodniStudent = p;

    while(PrethodniStudent->next != NULL && PrethodniStudent->next->id_student != GivenId)
    {
        PrethodniStudent = PrethodniStudent->next;
    }

    if(PrethodniStudent->next != NULL)
    {
        TrazeniStudent = PrethodniStudent->next;

        if(TrazeniStudent->down->down != NULL)
        {
            DeletePolozeno(m, TrazeniStudent);
            UpdatePolozenoFile(m->next);

            PrviKolZaBrisanje = TrazeniStudent->down->down;

            while(PrviKolZaBrisanje != NULL)
            {
                PomocniKolZaBrisanje = PrviKolZaBrisanje->down;
                free(PrviKolZaBrisanje);
                PrviKolZaBrisanje = PomocniKolZaBrisanje;
            }
        }

        PrethodniStudent->next = TrazeniStudent->next;
        free(TrazeniStudent->down);
        free(TrazeniStudent);
        printf("\n\nLista studenata nakon brisanja:\n");
        PrintStudentList(p->next);
    }
    else
        printf("Ne postoji student s unesenim id-em.\n");
}


void DeleteStudentBySurname(posST p, posPolozeno m)
{
    char prezime[100];
    int count = 0;
    int odabir = 0;

    posST temp = NULL;
    posST PrethodniStudent = NULL;
    posST TrazeniStudent = NULL;
    posKO PrviKolZaBrisanje = NULL;
    posKO PomocniKolZaBrisanje = NULL;

    posST NewList = NULL;

    printf("\n\nUnesite prezime studenta kojeg zelite izbrisati: \n");
    PrintStudentList(p->next);
    scanf("%s", prezime);

    temp = p ->next;

    while(temp!=NULL)
    {
        if(_stricmp(prezime,temp->prezime) == 0)
            count++;
        temp = temp->next;
    }

    if(count == 0)
    {
        printf("Nije pronadjen student s unesenim prezimenom.\n");
        return;
    }
    else if(count == 1)
    {
        PrethodniStudent = p;
        while(PrethodniStudent->next != NULL && _stricmp(PrethodniStudent->next->prezime, prezime) != 0)
        {
            PrethodniStudent = PrethodniStudent->next;
        }

        DeleteStudentByGivenId(p,m,PrethodniStudent->next->id_student);
        printf("\n\nLista studenata nakon brisanja:\n");
        PrintStudentList(p->next);
    }

    else if(count > 1)
    {
        printf("Pronadjeno vise studenata s istim prezimenom. Zelite li ih izbrisati sve?\n y - yes , n - nastavi brisati po id-u, c - odustani od brisanja");

        char choice = 'a';

        while(choice != 'y' && choice != 'n' && choice != 'c')
        {
            scanf("%c", &choice);

            if(choice == 'y')
            {
                temp = p->next;

                while(temp!=NULL)
                {
                    if(_stricmp(prezime,temp->prezime) == 0)
                        DeleteStudentByGivenId(p,m,temp->id_student);
                    temp = temp -> next;
                }
            }
            else if (choice == 'n')
            {
                temp = p->next;

                while(temp!=NULL)
                {
                    if(_stricmp(prezime,temp->prezime) == 0)
                        PrintStudent(temp);
                    temp = temp -> next;
                }
                printf("\n\nUnesite id studenta kojeg zelite izbrisati: \n");
                scanf("%d", &odabir);

                DeleteStudentByGivenId(p,m,odabir);
                printf("\n\nLista studenata nakon brisanja:\n");
                PrintStudentList(p->next);

            }
            else if(choice == 'c')
            {
                return;
            }
            else
                printf("Pokusajte ponovno.\n");

        }
    }
}
