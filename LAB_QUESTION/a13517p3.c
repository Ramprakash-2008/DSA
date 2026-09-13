#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *code;
    int credit;
    char grade;
} course;

typedef struct {
    course c[10];
} semester;

typedef struct {
    int regno;
    semester s[8];
	int totalcourse;
    int totalcredit;
} student;


/* ADT operation: Admit */
void admit(student s[], int *n, int r)
{
    s[*n].regno = r;
    (*n)++;

    printf("Student admitted successfully.\n");
}


/* ADT operation: Enrollment */
void enrollment(student s[], int n, int r,
                int sem, char *code, int credit)
{
    for(int i = 0; i < n; i++)
    {
        if(s[i].regno == r)
        {
            int j = 0;

            while(j < 10 &&
                  s[i].s[sem - 1].c[j].code != NULL)
            {
                j++;
            }

            if(j == 10)
            {
                printf("Semester is full.\n");
                return;
            }

            s[i].s[sem - 1].c[j].code = malloc(strlen(code) + 1);
            strcpy(s[i].s[sem - 1].c[j].code, code);

            s[i].s[sem - 1].c[j].credit = credit;
            s[i].s[sem - 1].c[j].grade = 'N';

			s[i].totalcourse++;
            s[i].totalcredit += credit;
            printf("Course enrolled successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void update_course(student s[], int n, int r, int sem,
                   char *code, int credit, char grade)
{
    for(int i = 0; i < n; i++)
    {
        if(s[i].regno == r)
        {
            for(int j = 0; j < 10; j++)
            {
                if(s[i].s[sem - 1].c[j].code != NULL &&
                   strcmp(s[i].s[sem - 1].c[j].code, code) == 0)
                {
                    /* Update total credit */
                    s[i].totalcredit -=
                        s[i].s[sem - 1].c[j].credit;

                    s[i].s[sem - 1].c[j].credit = credit;
                    s[i].s[sem - 1].c[j].grade = grade;

                    s[i].totalcredit += credit;

                    printf("Course updated successfully.\n");
                    return;
                }
            }

            printf("Course not found.\n");
            return;
        }
    }

    printf("Student not found.\n");
}
/* ADT operation: Delete enrollment */
void delete_enrol(student s[], int n, int r,
                  int sem, char *code)
{
    for(int i = 0; i < n; i++)
    {
        if(s[i].regno == r)
        {
            for(int j = 0; j < 10; j++)
            {
                if(s[i].s[sem - 1].c[j].code != NULL &&
                   strcmp(s[i].s[sem - 1].c[j].code, code) == 0)
                {
					s[i].totalcourse--;
                    free(s[i].s[sem - 1].c[j].code);

                    /* Shift courses */
                    for(int k = j; k < 9; k++)
                    {
                        s[i].s[sem - 1].c[k] =
                            s[i].s[sem - 1].c[k + 1];
                    }

                    s[i].s[sem - 1].c[9].code = NULL;
                    s[i].s[sem - 1].c[9].credit = 0;
                    s[i].s[sem - 1].c[9].grade = '\0';

                    printf("Enrollment deleted.\n");
                    return;
                }
            }

            printf("Subject not found.\n");
            return;
        }
    }

    printf("Student not found.\n");
}


/* ADT operation: Display */
void display(student s[], int n, int r)
{
    for(int i = 0; i < n; i++)
    {
        if(s[i].regno == r)
        {
            printf("\nRegister No: %d\n", s[i].regno);

            for(int sem = 0; sem < 8; sem++)
            {
                printf("\nSemester %d:", sem + 1);

                for(int j = 0; j < 10; j++)
                {
                    if(s[i].s[sem].c[j].code != NULL)
                    {
                        printf("\n  Code   : %s",
                               s[i].s[sem].c[j].code);

                        printf("\n  Credit : %d",
                               s[i].s[sem].c[j].credit);

                        printf("\n  Grade  : %c\n",
                               s[i].s[sem].c[j].grade);
                    }
                }
            }

            return;
        }
    }

    printf("Student not found.\n");
}


int main()
{
    student s[60] = {0};
    int n = 0;
    int choice;

    while(1)
    {
        printf("\n\n--- STUDENT ENROLLMENT ---");
        printf("\n1. Admit");
        printf("\n2. Enrollment");
        printf("\n3. Delete Enrollment");
        printf("\n4. Display");
        printf("\n5. Update");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            int r;

            printf("Register number: ");
            scanf("%d", &r);

            admit(s, &n, r);
        }

        else if(choice == 2)
        {
            int r, sem, credit;
            char code[20];

            printf("Register number: ");
            scanf("%d", &r);

            printf("Semester: ");
            scanf("%d", &sem);

            printf("Subject code: ");
            scanf("%s", code);

            printf("Credit: ");
            scanf("%d", &credit);

            enrollment(s, n, r, sem, code, credit);
        }

        else if(choice == 3)
        {
            int r, sem;
            char code[20];

            printf("Register number: ");
            scanf("%d", &r);

            printf("Semester: ");
            scanf("%d", &sem);

            printf("Subject code: ");
            scanf("%s", code);

            delete_enrol(s, n, r, sem, code);
        }

        else if(choice == 4)
        {
            int r;

            printf("Register number: ");
            scanf("%d", &r);

            display(s, n, r);
        }
		else if(choice == 5)
{
    int r, sem, credit;
    char code[20];
    char grade;

    printf("Register number: ");
    scanf("%d", &r);

    printf("Semester: ");
    scanf("%d", &sem);

    printf("Subject code: ");
    scanf("%s", code);

    printf("New credit: ");
    scanf("%d", &credit);

    printf("New grade: ");
    scanf(" %c", &grade);

    update_course(s, n, r, sem, code, credit, grade);
}
        else if(choice == 6)
        {
            break;
        }

        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}