#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
int main()
{
    int x, y, z, e, f, r, t, u;
    printf("                                Welcome to IIIT-Nagpur!!!\n");
    printf("                               -----------------------------");
    printf("\n");
    printf("                                College Management System\n");
    printf("                               -----------------------------");
    printf("\n");
    printf("                                Select one to continue:\n");
    printf("                                       1.Admin\n");
    printf("                                       2.Student\n");
    scanf("%d", &x);
    typedef struct student
    {
        int rollno;
        char name[30];
        struct subject
        {
            int category;
            char name1[30];
            int marks;
        } s[5];
        int sum;
        float avg;
    } stu;
    void create()
    {
        stu *a;
        FILE *fptr;
        int n, i, j;
        printf("Enter how many students you want :");
        scanf("%d", &n);
        a = (stu*)calloc(n, sizeof(stu));
        fptr = fopen("test.txt", "w");
        for (i = 0; i < n; i++)
        {
            a[i].sum = 0;
            printf("Enter Roll No.:");
            a[i].avg = 0;
            scanf("%d", &a[i]);
            fflush(stdin);
            printf("Enter Name:");
            scanf("%[^\n]s", a[i].name);
            for (j = 0; j < 5; j++)
            {
                printf("Enter Marks of subjects %d: ", j + 1);
                scanf("%d", &a[i].s[j].marks);
                a[i].sum += a[i].s[j].marks;
            }
            a[i].avg = a[i].sum/ 5.0;
            fwrite(&a[i], sizeof(stu), 1, fptr);
        }
        fclose(fptr);
    }
    void display()
    {
        stu stu1;
        FILE *fptr1;
        int j;
        fptr1 = fopen("test.txt", "r");
        printf("    Name                     1    2   3    4   5   Total   Avg.\n");
        while (fread(&stu1, sizeof(stu), 1, fptr1))
        {
            printf("\n%-5d%-20s", stu1.rollno, stu1.name);
            for (j = 0; j < 5; j++)
            {
                printf("%5d", stu1.s[j].marks);
            }
            printf("%5d%6.3f", stu1.sum, stu1.avg);
        }
        fclose(fptr1);
    }
    void append()
    {
        stu *s;
        FILE *fp;
        int n, i, j;
        printf("Enter how many students you want :");
        scanf("%d", &n);
        s = (stu *)calloc(n, sizeof(stu));
        fp = fopen("test.txt", "a");
        for (i = 0; i < n; i++)
        {
            s[i].sum = 0;
            s[i].avg = 0;
            printf("Enter Roll No.:");
            scanf("%d", &s[i]);
            fflush(stdin);
            printf("Enter Name:");
            scanf("%[^\n]s", s[i].name);
            for (j = 0; j < 5; j++)
            {
                printf("Enter Marks of subjects %d: ", j + 1);
                scanf("%d", &s[i].s[j].marks);
                s[i].sum += s[i].s[j].marks;
            }
            s[i].avg = s[i].sum / 5.0;
            fwrite(&s[i], sizeof(stu), 1, fp);
        }
        fclose(fp);
    }
    void search()
    {
        stu s1;
        FILE *fptr3;
        int j, rollno, get = 0;
        fptr3 = fopen("test.txt", "r");
        printf("Enter roll no.:\n");
        scanf("%d", &rollno);
        while (fread(&s1, sizeof(stu), 1, fptr3))
        {
            if (s1.rollno == rollno)
            {
                printf("    Name                     1    2    3   4    5     T. Avg.\n");
                printf("\n%-5d%-20s", s1.rollno, s1.name);
                for (j = 0; j < 5; j++)
                {
                    printf("%5d", s1.s[j].marks);
                }
                printf("%6d%6.3f\n", s1.sum, s1.avg);
                break;
            }
        }
        if(s1.rollno!=rollno)
        {
            printf("No recored found!\n");
        }
        fclose(fptr3);
    }
    void create1()
    {
    FILE *fptr4;
        char lines[1000];
    fptr4 = fopen("club.txt", "a");
    
    if(fptr4 == NULL) {
        printf("file can't be opened\n");
        exit(1);
    }
    fflush(stdin);
    printf("Enter information:\n");
    gets(lines);
    fprintf(fptr4, "%s",lines);
    fclose(fptr4);
    }
    void update()
    {
        stu s1;
        FILE *fptr5,*fptr6;
        int j,rollno,get=0;
        fptr5 = fopen("test.txt","r");
        fptr6=fopen("update.txt","w");
        printf("Enter rollno to update: ");
        scanf("%d",&rollno);
        while(fread(&s1,sizeof(stu),1,fptr5))
        {
            if(s1.rollno == rollno){
               get=1;
                fflush(stdin);
            printf("Enter Name:");
            scanf("%[^\n]s", s1.name);
            for (j = 0; j < 5; j++)
            {
                printf("Enter new Marks of subjects %d: ", j + 1);
                scanf("%d", &s1.s[j].marks);
                s1.sum += s1.s[j].marks;
            }
            s1.avg = s1.sum / 5.0;

            }
            fwrite(&s1,sizeof(stu),1,fptr6);
        }
        fclose(fptr5);
        fclose(fptr6);
        if(get)
        {
           fptr5= fopen("update.txt","r");
           fptr6= fopen("test.txt","w");
           while(fread(&s1,sizeof(stu),1,fptr6)){
               fwrite(&s1,sizeof(stu),1,fptr5);
           }
           fclose(fptr5);
           fclose(fptr6);
        }
        else{
           printf("Sorry, record not found!!");
        }
        fclose(fptr5);
    }
    void display2()
    {
        FILE *fp3;

            char d;
            fp3 = fopen("studentinfo.txt", "r");
            if (fp3 == NULL)
            {
                printf("Cannot open file \n");
                exit(0);
            }
            d = fgetc(fp3);
            while (d != EOF)
            {
                printf("%c", d);
                d = fgetc(fp3);
            }
                printf("\n");

            fclose(fp3);
             printf("\n");
    }
    void display3()
    {
        FILE *fp4;

            char f;
            fp4 = fopen("syllabus.txt", "r");
            if (fp4 == NULL)
            {
                printf("Cannot open file \n");
                exit(0);
            }
            f = fgetc(fp4);
            while (f != EOF)
            {
                printf("%c", f);
               f= fgetc(fp4);
            }
                printf("\n");

            fclose(fp4);
             printf("\n");
    }
    if (x == 2)
    {
        do{
        printf("1.View Subject List\n");
        printf("2.Lecture Schedule\n");
        printf("3.Club List\n");
        printf("4.Academic Performance\n");
        printf("5.Exit\n");
        scanf("%d", &y);
        if (y == 1)
        {
            // Reads Sub
            char a;
            FILE *fptr1;

            fptr1 = fopen("sub.txt", "r");
            if (fptr1 == NULL)
            {
                printf("Cannot open file \n");
                exit(0);
            }
            a = fgetc(fptr1);
            while (a != EOF)
            {
                printf("%c", a);
                a = fgetc(fptr1);
            }

            fclose(fptr1);
             printf("\n");
        }
        else if (y == 3)
        {
            // reads club
            FILE *ptr2;

            char b;
            ptr2 = fopen("club.txt", "r");
            if (ptr2 == NULL)
            {
                printf("Cannot open file \n");
                exit(0);
            }
            b = fgetc(ptr2);
            while (b != EOF)
            {
                printf("%c", b);
                b = fgetc(ptr2);
            }

            fclose(ptr2);
             printf("\n");
        }
        else if (y == 2)
        {
            // reads schedule
            FILE *ptr3;

            char c;
            ptr3 = fopen("lecture.txt", "r");
            if (ptr3 == NULL)
            {
                printf("Cannot open file \n");
                exit(0);
            }
            c = fgetc(ptr3);
            while (c != EOF)
            {
                printf("%c", c);
                c = fgetc(ptr3);
            }

            fclose(ptr3);
            printf("\n");
        }
        else if (y == 4)
        {
            search();
             printf("\n");
        }
        }while(y!=0);
    }
    else
    {
        int ch, x,e;
        printf("1.Manage students\n");
        printf("2.Manage Course\n");
        printf("3.Manage Clubs\n");
        scanf("%d", &x);
        if (x == 1)
        {
            do
            {
                printf("\n1.Declare Result");
                printf("\n2.Display");
                printf("\n3.Add Result");
                printf("\n4.Update");
                printf("\n5.EXIT");
                printf("\nEnter Your Choice:");
                scanf("%d", &ch);
                if(ch==1)
                {
                    create();
                }
                else if(ch==2)
                {
                    display();
                }
                else if(ch==3)
                {
                    append();
                }
                else
                {
                    update();
                }
            } while (ch != 0);
        }
        else if (x == 3)
        {
            int y;
            printf("1.Club information:\n");
            printf("2.Exit:\n");
            scanf("%d", &y);
            if(y==1)
            {
                create1();
            }
        }
        else
        {
            printf("1.Display student information\n");
            printf("2.Syllabus of Course\n");
            scanf("%d", &e);
            switch (e)
            {
            case 1 :
                display2();
                break;
            case 2:
                display3();
                break;   
            }     
        }
    }
    return 0;
}
