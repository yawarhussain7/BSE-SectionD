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
    printf("\n\t 3-> Press for Search Teacher \n");
    printf("\n\t 4-> Press for Update Teacher \n");
    printf("\n\t 5-> Press for Exit\n");
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

    printf("%s\t\t%s\t\t\t%s\t\t\t\t%s\n", "ID", "Teacher Name", "Subject Name", "CreditHours");
    char c = getc(read);
    while (c != EOF)
    {
        printf("%c", c);
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
        scanf("%d", &teach[i].id);
    }

    // fprintf(write, "%s\t\t%s\t\t\t\t\t%s\t\t\t\t\t%s\n","ID", "Name", "Subject", "CreditHours");
    for (int i = 0; i < size; i++)
    {
        fprintf(write, "%d\t\t%s\t\t\t%s\t\t\t\t%d\n", teach[i].id, teach[i].name, teach[i].subject, teach[i].credithours);
    }

    fclose(write);
}

// search teaher
void searchteacher()
{
    FILE *read;
    read = fopen("teacher.txt", "r");
    if (read == NULL)
    {
        puts("ERROR \n ");
    }

    t teach;
    int id;
    printf("Enter the id of user : ");
    scanf("%d", &id);
    int found = 0;
    while (fscanf(read, "%d %s %s %d", &teach.id, teach.name, teach.subject, &teach.credithours))
    {
        if (teach.id == id)
        {
            printf("ID : %d\n", teach.id);
            printf("Name : %s\n", teach.name);
            printf("SUbject : %s\n", teach.subject);
            printf("CreditHours: %d\n", teach.credithours);

            found = 1;
            break;
        }
    }

    if (found != 1)
    {
        printf("Account not foound \n");
    }

    fclose(read);
}
//UPgrade Teacher
void updateteach()
{
    FILE *read, *write;
    read = fopen("teacher.txt", "r");
    write = fopen("newTeacher.txt", "a");
    if (read == NULL && write == NULL)
    {
        puts("ERROR in update teacher ");
    }

    t teach;

    t newtech;
    int id;
    printf("Enter the id of teacher : ");
    fflush(stdin);
    scanf("%d", &id);
    int opt = 0;
    while (fscanf(read, "%d %s %s %d", &teach.id, teach.name, teach.subject, &teach.credithours)!=EOF)
    {
        newtech = teach;
        if (teach.id == id)
        {
            printf("\n\t <<<< UPdate your information >>>>>\n");
            printf("\n\t 1 => Press for update ID : ");
            printf("\n\t 2 => Press for update Name : ");
            printf("\n\t 3 => Press for update Subject : ");
            printf("\n\t 4 => Press for update name : ");
            printf("\nChooice ... ");
            scanf("%d", &opt);

            switch (opt)
            {
            case 1:
                printf("\n\t Enter your new ID : ");
                fflush(stdin);
                scanf("%d", &newtech.id);
              
                break;
            case 2:
                printf("\n\t Enter your New Name : ");
                fflush(stdin);
                scanf("%s", newtech.name);
                
                break;
            case 3:
                printf("\n\t Enter your New Subject : ");
                fflush(stdin);
                scanf("%s", newtech.subject);
               
                break;
            case 4:
                printf("\n\t Enter your New Subject Credit Hours : ");
                fflush(stdin);
                scanf("%d", &newtech.credithours);
              
                break;
            default:
                printf("\n\t Invalid option\n");
                break;
            }
            fprintf(write,"%d\t\t%s\t\t\t%s\t\t\t\t%d\n",newtech.id,newtech.name,newtech.subject,newtech.credithours);
        }
        else
        {

        fprintf(write,"%d\t\t%s\t\t\t%s\t\t\t\t%d\n",newtech.id,newtech.name,newtech.subject,newtech.credithours);
        }
    }

    fclose(read);
    fclose(write);

    remove("teacher.txt");
    rename("newTeacher.txt", "teacher.txt");
}

//Delete Teacher










// student meanu
int studentmeanu()
{
    system("cls");
    int opt;
    printf("\n\t <======= Students OPeration ========>\n");
    printf("\n\t 1-> Press for add student \n");
    printf("\n\t 2-> Press for Show show list\n");
    printf("\n\t 3-> Press for search student \n");
    printf("\n\t 4-> Press for Exit\n");
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
        scanf("%s", bse[i].name);
        printf("\n\t Enter the Registration number of student : ");
        scanf("%s", bse[i].reg);
        printf("\n\t Enter the Section of Student : ");
        scanf("%s", bse[i].section);
        printf("\n\t Enter the CGPA of the Student : ");
        scanf("%f", &bse[i].cgpa);
        printf("\n\t Enter the ID of the Student : ");
        scanf("%d", &bse[i].id);
    }

    // fprintf(write, "%s\t\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\n","ID", "Name", "Registration", "Section","CGPA");
    for (int i = 0; i < size; i++)
    {
        fprintf(write, "%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%0.2f\n", bse[i].id, bse[i].name, bse[i].reg, bse[i].section, bse[i].cgpa);
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
        printf("%c", c);
        c = getc(read);
    }
    fclose(read);
}

// search particular student
void search()
{
    FILE *read = fopen("students.txt", "r");
    if (read == NULL)
    {
        puts("ERROR \n ");
    }

    s student;
    int id;
    printf("Enter the id of user : ");
    scanf("%d", &id);
    int found = 0;

    while (fscanf(read, "%d %s %s %s %0.1f", &student.id, student.name, student.reg, student.section, &student.GPA))
    {
        if (student.id == id)
        {
            printf("ID : %d\n", student.id);
            printf("Name : %s\n", student.name);
            printf("Registration no : %s\n", student.reg);
            printf("Section : %s\n", student.section);
            printf("GPA : %0.1f\n", student.GPA);
            found = 1;
            break;
        }
    }

    if (found != 1)
    {
        printf("Account not foound \n");
    }

    fclose(read);
}

// subject detail
void subjects()
{
    FILE *write = fopen("subjects.txt", "w");
    if (write == NULL)
    {
        puts("ERROR");
    }
    int size;
    printf("Enter the total number of subjects : ");
    scanf("%d", &size);
}