/*
This C program implements a menu-driven polynomial 
manipulation system using a singly linked list.

Each node represents one polynomial term containing:

coef → coefficient
expo → exponent
next → pointer to the next term

The polynomial is maintained in descending order of exponents.

Operations Available
Insert a new term
Inserts a term in the correct position.
inSert() prevents duplicate exponents.
Scalar Multiplication
Multiplies every coefficient of the polynomial by a given scalar.
Addition of Two Polynomials
Adds corresponding terms with the same exponent.
Subtraction of Two Polynomials
Subtracts the second polynomial from the first polynomial.
Multiplication of Two Polynomials
Multiplies every term of the first polynomial with every term of the second.
Terms with identical exponents are combined automatically.
Exit
Terminates the program.*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct term {
    int coef, expo;
} TERM;

typedef struct node {
    TERM t;
    struct node* next;
} NODE;


/* Create a new node */
NODE* makeNode(int expo, int coef)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));

    temp->t = (TERM){coef, expo};
    temp->next = NULL;

    return temp;
}


/* Insert without combining same exponents */
NODE* inSert(NODE* l, int coef, int expo)
{
    if (!l)
        return makeNode(expo, coef);

    if (l->t.expo == expo)
        return l;

    if (l->t.expo < expo)
    {
        NODE* t = makeNode(expo, coef);
        t->next = l;
        return t;
    }

    l->next = inSert(l->next, coef, expo);

    return l;
}


/* Insert in sorted order and combine same exponents */
NODE* inSort(NODE* l, int coef, int expo)
{
    if (!l)
        return makeNode(expo, coef);

    /* Same exponent */
    if (l->t.expo == expo)
    {
        l->t.coef += coef;
        return l;
    }

    /* Higher exponent goes first */
    if (l->t.expo < expo)
    {
        NODE* t = makeNode(expo, coef);
        t->next = l;
        return t;
    }

    l->next = inSort(l->next, coef, expo);

    return l;
}


/* Display polynomial */
void display(NODE* l)
{
    while (l)
    {
        if (l->t.expo == 0)
            printf("%d ", l->t.coef);

        else if (l->t.expo == 1)
            printf("%dX ", l->t.coef);

        else if (l->t.coef == 1)
            printf("X^%d ", l->t.expo);

        else
            printf("%dX^%d ", l->t.coef, l->t.expo);

        l = l->next;

        if (l)
            printf("+ ");
    }
}


/* Scalar multiplication */
NODE* scalar(int coef, NODE* l)
{
    NODE* t = l;

    while (t)
    {
        t->t.coef *= coef;
        t = t->next;
    }

    return l;
}


/* Addition */
NODE* add(NODE* l1, NODE* l2)
{
    NODE* result = NULL;
    NODE* t1 = l1;
    NODE* t2 = l2;

    while (t1 || t2)
    {
        if (t1 && (!t2 || t1->t.expo > t2->t.expo))
        {
            result = inSort(result, t1->t.coef, t1->t.expo);
            t1 = t1->next;
        }

        else if (t2 && (!t1 || t1->t.expo < t2->t.expo))
        {
            result = inSort(result, t2->t.coef, t2->t.expo);
            t2 = t2->next;
        }

        else
        {
            int sum = t1->t.coef + t2->t.coef;

            if (sum != 0)
                result = inSort(result, sum, t1->t.expo);

            t1 = t1->next;
            t2 = t2->next;
        }
    }

    return result;
}


/* Subtraction */
NODE* sub(NODE* l1, NODE* l2)
{
    NODE* result = NULL;
    NODE* t1 = l1;
    NODE* t2 = l2;

    while (t1 || t2)
    {
        if (t1 && (!t2 || t1->t.expo > t2->t.expo))
        {
            result = inSort(result, t1->t.coef, t1->t.expo);
            t1 = t1->next;
        }

        else if (t2 && (!t1 || t1->t.expo < t2->t.expo))
        {
            result = inSort(result, -t2->t.coef, t2->t.expo);
            t2 = t2->next;
        }

        else
        {
            int d = t1->t.coef - t2->t.coef;

            if (d != 0)
                result = inSort(result, d, t1->t.expo);

            t1 = t1->next;
            t2 = t2->next;
        }
    }

    return result;
}


/* Multiplication */
NODE* prod(NODE* l, NODE* l2)
{
    NODE* result = NULL;
    NODE* t1 = l;
    NODE* t2;

    while (t1)
    {
        t2 = l2;

        while (t2)
        {
            int coef = t1->t.coef * t2->t.coef;
            int expo = t1->t.expo + t2->t.expo;

            result = inSort(result, coef, expo);

            t2 = t2->next;
        }

        t1 = t1->next;
    }

    return result;
}

/* Display with heading */
void displayf(NODE* l)
{
    printf("Polynomial: ");
    display(l);
    printf("\n");
}
/* Get polynomial */
NODE* getPoly()
{
    NODE* l = NULL;

    int n, coef, expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent of term %d: ",
               i + 1);

        scanf("%d %d", &coef, &expo);

        l = inSort(l, coef, expo);
    }
    displayf(l);
    return l;
}





int main()
{
    NODE* l = NULL;
    NODE* l2 = NULL;

    int choice;
    int coef, expo;
    l=getPoly();
    do
    {
        printf("\n========== POLYNOMIAL MENU ==========\n");
        printf("1. Insert a new term\n");
        printf("2. Scalar multiplication\n");
        printf("3. Add two polynomials\n");
        printf("4. Subtract two polynomials\n");
        printf("5. Multiply two polynomials\n");
        printf("6. Exit\n");
        printf("=====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter coefficient and exponent: ");
                scanf("%d %d", &coef, &expo);

                l = inSert(l, coef, expo);

                printf("Updated polynomial: ");
                display(l);
                printf("\n");
                break;


            case 2:
                printf("Enter scalar: ");
                scanf("%d", &coef);

                l = scalar(coef, l);

                printf("Scaled polynomial: ");
                display(l);
                printf("\n");
                break;
        
            case 3:
            {
                printf("\nEnter the second polynomial:\n");
                l2 = getPoly();
                NODE* sum = add(l, l2);

                printf("Sum: ");
                display(sum);
                printf("\n");

                break;
            }


            case 4:
            {
                printf("\nEnter the second polynomial:\n");
                l2 = getPoly();
                NODE* difference = sub(l, l2);
                printf("Subtraction: ");
                display(difference);
                printf("\n");

                break;
            }


            case 5:
            {
                printf("\nEnter the second polynomial:\n");
                l2 = getPoly();
                NODE* product = prod(l, l2);
                printf("Product: ");
                display(product);
                printf("\n");

                break;
            }


            


            case 6:
                printf("\nExiting program...\n");
                break;


            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}