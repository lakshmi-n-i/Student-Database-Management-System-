#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void addstudent();
void studentrecord();
void search();
void delete ();
void timetable();
int check(long long int n);

struct student
{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char class[10];
    long long int phone_no;
    float gpa;
};

int main()
{
    int choice;

    while(choice!=5)
    {
        printf("STUDENT DATABASE MANAGEMENT SYSTEM \n");
        printf("1. ADD A STUDENT \n");
        printf("2. DISPLAY STUDENT RECORDS \n");
        printf("3. SEARCH STUDENT \n");
        printf("4. DISPLAY THE TIMETABLE \n");
        printf("5. EXIT \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            
            addstudent();
            
            break;

        case 2:
            
            studentrecord();
            printf("PRESS ANY KEY TO EXIT \n");
            getch();
            
            break;

        case 3:
            search();
            break;

        
        case 4:
            timetable();
            break;
        case 5:
            printf("SUCCESSFULLY EXITED");
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
    return 0;
}
void timetable()
{
    FILE *fp = fopen("timetable.txt", "r");
    char ch;
    char line[500];
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ',')
        {
            printf("\t||\t");
        }
        else
        {
            fputc(ch, stdout);
        }
        
    }
    fclose(fp);
}


void addstudent()
{
    char another;
    FILE *fp;
    struct student info;
    do
    {
        
        system("cls");
        printf("ADD STUDENT INFO \n");
        fp = fopen("student_info.txt", "a");
        printf("ADD STUDENT FIRST NAME \n");
        scanf("%s", &info.first_name);
        printf("ADD STUDENT LAST NAME \n");
        scanf("%s", &info.last_name);
        printf("ADD STUDENT ROLL NO \n");
        scanf("%d", &info.roll_no);
        printf("ADD STUDENT SECTION \n");
        scanf("%s", &info.class);
        printf("ADD STUDENT PHONE NUMBER \n");
        scanf("%lld", &info.phone_no);
        int a=check(info.phone_no);
        if(a<10)
        {
            printf("INVALID PHONE NUMBER \n");
            printf("ADD STUDENT PHONE NUMBER \n");
            scanf("%lld", &info.phone_no);
        }
        printf("ADD STUDENT GPA \n");
        scanf("%f", &info.gpa);
        printf("--------------------------------------");

        if (fp == NULL)
        {
            fprintf(stderr, "Can't open file \n");
        }
        else
        {
            printf("RECORD SUCCESFULLY STORED \n");
        }
        fprintf(fp, "%s %s %d %s %lld %.1f\n", info.first_name, info.last_name, info.roll_no, info.class, info.phone_no, info.gpa);
        fflush(stdin);

        printf("DO YOU WANT TO ENTER ANOTHER? (Y/N) \n");
        scanf("%c", &another);

    } while (another == 'y' || another == 'Y');
    fclose(fp);
}

void studentrecord()
{
    FILE *fp;
    struct student info;
    fp = fopen("student_info.txt", "r");
    printf("STUDENT RECORDS \n");
    if (fp == NULL)
    {
        fprintf(stderr, "CAN'T OPEN FILE \n");
    }
    else
    {
        printf("RECORDS \n");
        char ch;
        char line[500];
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == ' ')
            {
                printf("\t||\t");
            }
            else
            {
                fputc(ch, stdout);
            }
        }
        
            
        
    }
    fclose(fp);

}

void search()
{
    char name[20];
    printf("Enter The name of the student you want to search: ");
    scanf("%s", &name);
    FILE *fp2 = fopen("student_info.txt", "r");
    char line[20];
    int tell=0;
    while (!feof(fp2))
    {

        
        char str[20];
        fscanf(fp2, "%s", str);

        if (strcmp(name, str) == 0)
        {
            printf("%s ", name);
            tell=1;
            
            char ch;
            while (((ch = fgetc(fp2)) != '\n'))
            {
                if (ch != EOF)
                    printf("%c", ch);
            }


        }
        
    }
    if(tell==0)
    {
        printf("STUDENT NOT FOUND");
    }
}

int check(long long int n)
{
    int count =0;
    while(n>0)
    {
        count=count+1;
        n=n/10;
    }
    return count;
}
