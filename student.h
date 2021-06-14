#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "kolegij.h"
#include "polozeno.h"

struct _student;

typedef struct _student* posST;
typedef struct _podatci* posPO;
typedef struct _kolegij* posKO;
typedef struct _polozeno* posPolozeno;

typedef struct _student
{
    int id_student;
    char ime[100];
    char prezime[100];
    int god_rod;

    posST next;
    posPO down;

}student;

posST CreateNodeST(void);
posPO CreateNodePO(void);
posST CreateNodeSTAndInitialize(int Id, char* Name, char *LastName, int Year);

int GetRandomIdStudent(posST start, posST p);
int ReadStudentsFromFile(posST p);
void SortiraniUnos(posST p, posST r);
int IsStudentListEmpty(posST p);
void PrintStudent(posST p);
void PrintStudentList(posST p);
void UpdateStudentFile(posST p);
posST FindStudent(posST p, int st);
void ReadFromKeyboard(posST q);
int AddStudent(posPolozeno m, posST p, posKO r);
void PrintList(posST p);
int DeleteStudent(posST p, posPolozeno q);
void DeleteStudentById(posST p, posPolozeno m);
void DeleteStudentByGivenId(posST p, posPolozeno m, int GivenId);
void DeleteStudentBySurname(posST p, posPolozeno m);



#endif
