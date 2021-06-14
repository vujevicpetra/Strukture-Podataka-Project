#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "student.h"
#include "kolegij.h"
#include "podatci.h"
#include "polozeno.h"


int main()
{
    posPolozeno headPolozeno = NULL;
    headPolozeno = CreateNodePolozeno();
    ReadPolozenoFromFile(headPolozeno);

    posST headST = NULL;
    posKO headKO = NULL;

    headST = CreateNodeST();
    headKO = CreateNodeKO();

    if(ReadStudentsFromFile(headST));
    ReadKolegijFromFile(headKO);
    ReadPodatciFromFile(headST, headKO);
    RacunanjePodataka(headST->next);


    char izbor = 0;

    while(toupper(izbor) != 'L')
	{
		printf("*************************************************************************\r\n");
		printf("*************     SEMINAR IZ KOLEGIJA STRUKTURE PODATAKA    *************\r\n");
		printf("*************************************************************************\r\n");
		printf("\r\n\r\n");
		printf("\t1. Ispis sortirane liste studenata\r\n");
		printf("\t2. Ispis liste kolegija\r\n");
		printf("\t3. Ispis podataka o studentima\r\n");
		printf("\t4. Unos novog studenta u listu\r\n");
		printf("\t5. Brisanje studenta\r\n");
        printf("\t6. Ispis studenata koji su polozili odredeni kolegij\r\n");
		printf("\t7. Ispis svih studenata koji su zavrsili akademsku godinu s odredenom ocjenom\r\n");
		printf("\t8. Ispis podataka o odredenom studentu po id-u\r\n");
		printf("\t9. Ispis podataka o odredenom studentu po prezimenu\r\n");
        printf("\tA. Ispis podataka o odredenom studentu prema godini rodenja\r\n");
		printf("\tB. Lista studenata koji moraju platiti puni iznos skolarine\r\n");
		printf("\tC. Lista studenata koji moraju platiti samo iznos upisnine\r\n");
		printf("\tD. Lista studenata koji moraju platiti iznos participacije\r\n");
		printf("\tE. Lista studenata koji ponavljaju akademsku godinu\r\n");
		printf("\tF. Lista kolegija koji nose odredeni broj ECTS bodova\r\n");
        printf("\tG. Lista studenata koji su polozili odredeni kolegij s odredenom ocjenom\r\n");
        printf("\tH. Ispis studenta s najvisim prosjekom\r\n");
        printf("\tI. Prosjecna ocjena svih studenata\r\n");

		printf("\tK. Izlaz iz programa\r\n");
		printf("\n\n**********  Izradile: Mia Gudic, Lara Mladinic, Petra Vujevic. **********\r\n");
		printf("\n\r\n\tIzbor : ");

		scanf(" %c", &izbor);

		switch(izbor)
		{
		case '1' :
		    printf("\n\nIspis liste studenata:\n\n");
			PrintStudentList(headST->next);
			printf("\n\n\n");
			break;
		case '2' :
		    printf("\n\nIspis liste kolegija:\n\n");
			PrintKolegijList(headKO->down);
			printf("\n\n\n");
			break;
		case '3' :
			printf("\n\n\nPODATCI O STUDENTIMA:\n\n__________________________________________________________________________\n\n");
            PrintList(headST->next);
			break;
		case '4' :
		    if(AddStudent(headPolozeno, headST, headKO))
                printf("\nUspjesno dodan novi student.\n\n\n");
            else
                {
                    printf("\nGreska pri unosu novog studenta.\n\n\n");
                    return 1;
                }
			break;
		case '5' :
		    if(DeleteStudent(headST, headPolozeno))
            {
                UpdateStudentFile(headST->next);
                printf("\nUspjesno izbrisan student.\n\n\n");
            }
            else
                {
                    printf("\nGreska pri brisanju studenta.\n\n\n");
                    return 1;
                }
			break;
		case '6':
			StudentiPoloziliKolegij(headST->next, headKO->down);
			break;
		case '7':
			DohvatiStudentPrekoProsjek(headST->next);
			break;
		case '8' :
			DohvatiStudentPrekoId(headST->next);
			break;
        case '9' :
			DohvatiStudentPrekoPrezime(headST->next);
			break;
        case 'A' :
			DohvatiStudentPrekoGodRod(headST->next);
			break;
        case 'B' :
			DohvatiStudentPrekoSkolarina(headST->next);
			break;
        case 'C' :
			DohvatiStudentPrekoUpisnina(headST->next);
			break;
        case 'D' :
			DohvatiStudentPrekoParticipacija(headST->next);
			break;
        case 'E' :
			DohvatiStudentPonavljac(headST->next);
			break;
        case 'F' :
			DohvatiKolegijPrekoECTS(headKO->down);
			break;
        case 'G' :
			DohvatiStudentPrekoKolegijOcjena(headST->next, headKO->down);
			break;
        case 'H' :
			DohvatiStudentMaxProsjek(headST->next, headST->next->next);
			break;
        case 'I' :
			ProsjekSviStudenti(headST->next);
			break;

		case 'k' :
		case 'K' :
			break;
		default:
			printf("\r\nPogresan izbor <%c>.\r\nPokusajte ponovno.\r\n\n\n", izbor);
			break;
        }
	}

    return 0;
}
