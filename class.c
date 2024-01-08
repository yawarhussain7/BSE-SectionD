#include <stdio.h>
#include <stdlib.h>
#include "class.h"

// teacher 
int teahermanu()
{
    system("cls");
    int opt;
    printf("\n\t <<<<<<<< Teacher OPeration >>>>>>>>>>\n");
    printf("\n\t 1-> Press for add teacher \n");
    printf("\n\t 2-> Press for Show teacher list\n");
    printf("\n\t 3-> Press for Exit\n");
    printf("CHooice... ");
    scanf("%d", &opt);

    return opt;
}
// show teacher list 
void showteacherlist()
{
    system("cls");
    FILE *read = fopen("teacher.txt", "r");
    if (read == NULL)
    {
        puts("ERROR file does't exist \n");
    }
    char c = getc(read);
    while (c != EOF)
    {
        printf("%c",c);
        c = getc(read);
    }
    fclose(read);
}

// adding new teacher

void getdateforteacher()
{
    system("cls");
    FILE *write;
    write = fopen("teacher.txt", "a");
    if (write == NULL)
    {
        printf("ERROR");
    }
    int size;
    printf("Enter the total number of teacher in your Class : ");
    scanf("%d", &size);
    t teach[size];

    for (int i = 0; i < size; i++)
    {
        printf("\n\t Enter the name of Teacher : ");
        scanf("%s", teach[i].name);
        printf("\n\t Enter the Subject of Teacher : ");
        scanf("%s", teach[i].subject);
        printf("\n\t Enter the Credit Hourse of Course : ");
        scanf("%d", &teach[i].credithours);
            printf("\n\t Enter the ID of the Student : ");
        scanf("%d",&teach[i].id);
    }

    // fprintf(write, "%s\t\t%s\t\t\t\t\t%s\t\t\t\t\t%s\n","ID", "Name", "Subject", "CreditHours");
    for (int i = 0; i < size; i++)
    {
        fprintf(write, "%d\t\t%s\t\t\t%s\t\t\t\t%d\n",teach[i].id, teach[i].name, teach[i].subject, teach[i].credithours);
    }

    fclose(write);
}

// student meanu 
int studentmeanu()
{
    system("cls");
    int opt;
    printf("\n\t <======= Students OPeration ========>\n");
    printf("\n\t 1-> Press for add student \n");
    printf("\n\t 2-> Press for Show show list\n");
    printf("\n\t 3-> Press for Exit\n");
    printf("CHooice... ");
    scanf("%d", &opt);

    return opt;
}

// Adding new students 
void addnewstudents()
{
    system("cls");
    FILE *write;
    write = fopen("students.txt", "a");
    if (write == NULL)
    {
        printf("ERROR");
    }
    int size;
    printf("Enter the total number of Students in your Class : ");
    scanf("%d", &size);
    s bse[size];

    for (int i = 0; i < size; i++)
    {
      
        printf("\n\t Enter the name of Student : ");
        scanf("%s",bse[i].name);
        printf("\n\t Enter the Registration number of student : ");
        scanf("%s",bse[i].reg);
        printf("\n\t Enter the Section of Student : ");
        scanf("%s", bse[i].section);
        printf("\n\t Enter the CGPA of the Student : ");
        scanf("%f",&bse[i].cgpa);
          printf("\n\t Enter the ID of the Student : ");
        scanf("%d",&bse[i].id);
    }

    // fprintf(write, "%s\t\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n","ID", "Name", "Registration", "Section","CGPA");
    for (int i = 0; i < size; i++)
    {
    fprintf(write, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%0.2f\n",bse[i].id,bse[i].name,bse[i].reg,bse[i].section,bse[i].cgpa);
    }

    fclose(write);
}

// show list of studnet 
void showstudentlist()
{
    system("cls");
    FILE *read = fopen("students.txt", "r");
    if (read == NULL)
    {
        puts("ERROR file does't exist \n");
    }
    char c = getc(read);
    while (c != EOF)
    {
        printf("%c",c);
        c = getc(read);
    }
    fclose(read);
}

// subject detail
void subjects()
{
    FILE *write = fopen("subjects.txt","w");
    if(write == NULL)
    {
        puts("ERROR");
    }
    int size;
    printf("Enter the total number of subjects : ");
    scanf("%d",&size);
    
}