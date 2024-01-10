typedef struct teachers
{
    char name[30];
    char subject[30];
    int credithours;
    int id;
} t;

void searchteacher();
int teahermanu();
void getdateforteacher();
void showteacherlist();

typedef struct Students
{
    int id;
    char name[30];
    char reg[20];
    char section[10];
    float cgpa;
   
        float PF;
        float SE;
        float PS;
        float AP;
        float GPA;
  
}s;
int studentmeanu();
void showstudentlist();
void addnewstudents();
void search();