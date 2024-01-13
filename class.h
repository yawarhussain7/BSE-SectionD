typedef struct teachers
{
    char name[30];
    char subject[30];
    int credithours;
    int id;
} t;

int teahermanu();
void getdateforteacher();
void showteacherlist();
void searchteacher();
void updateteach();
void DeleteTeacher();




typedef struct Students
{
    int id;
    char name[30];
    char reg[20];
    char section[10];
    float GPA;
    
 
}s;
int studentmeanu();
void showstudentlist();
void addnewstudents();
void search();
void removeStudents();
void updateStudent();



