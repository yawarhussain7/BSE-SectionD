#include <stdio.h>
#include <stdlib.h>
#include "class.h"
int main()
{
    int opt;
    while (opt != 3)
    {

        printf("\n\t <<<<<<<<< Welcome to BSE 2D Section >>>>>>>>>>>\n");
        printf("\n\t 1-> Press for Show teacher List \n");
        printf("\n\t 2-> Press for Show Students List \n");
        printf("\n\t 3-> Press for Exit \n");
        printf("CHooice ... ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            int teachers = teahermanu();
            if (teachers == 1)
            {
                system("clear");
                getdateforteacher();
            }
            else if (teachers == 2)
            {
                system("clear");
                showteacherlist();
            }
            else if (teachers == 3)
            {
                system("clear");
                searchteacher();
            }
            else if (teachers == 4)
            {
                system("clear");
                updateteach();
            }
            else if (teachers == 5)
            {
                system("clear");
                DeleteTeacher();
            }
            
            else
            {
                exit(0);
            }
            break;
        case 2:
            int result = studentmeanu();
            if (result == 1)
            {
                system("clear");
                addnewstudents();
            }
            else if (result == 2)
            {
                system("clear");
                showstudentlist();
            }
            else if (result == 3)
            {
                system("clear");
                search();
            }
            else if (result == 4)
            {
                system("clear");
                removeStudents();
            }
            else if(result == 5)
            {
                system("clear");
                updateStudent();
            }
            else
            {
                exit(0);
            }
            break;
        case 3:
            printf("Exiting\n");
            exit(0);
            break;

        default:
            printf("Invlid \n");
            break;
        }
    }

    return 0;
}