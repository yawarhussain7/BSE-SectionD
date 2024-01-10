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
                system("cls");
                getdateforteacher();
            }
            else if (teachers == 2)
            {
                system("cls");
                showteacherlist();
            }
            else if (teachers ==3)
            {
                 searchteacher();
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
                system("cls");
                addnewstudents();
            }
            else if (result == 2)
            {
                system("cls");
                showstudentlist();
            }
            else if (result == 3)
            {
                system("cls");
                search();
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