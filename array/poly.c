/*
Description:
This C program represents polynomials using structures and performs polynomial addition by comparing and combining terms with the same exponents. It also maintains terms in decreasing order of exponents.

Sample Output:

P1 = 2x^12+3x^7
P2 = 3x^8+8x^7+6x^2
sum = 2x^12+3x^8+11x^7+6x^2*/
#include<stdio.h>
#include<stdlib.h>
typedef struct { int coef, expo; } TERM;
typedef struct { TERM t[100]; int nT; } POLY;
POLY createPoly() {POLY p; p.nT=0; return p;}
void printPoly(POLY p)
{    printf("%dx^%d", p.t[0].coef, p.t[0].expo);
    for (int i=1; i<p.nT; i++)
        printf("+%dx^%d", p.t[i].coef, p.t[i].expo);
    return;
}
void sort(POLY *p)
{
    int i, j;
    TERM temp;

    for(i = 0; i < p->nT - 1; i++)
    {
        for(j = i + 1; j < p->nT; j++)
        {
            if(p->t[i].expo < p->t[j].expo)
            {
                temp = p->t[i];
                p->t[i] = p->t[j];
                p->t[j] = temp;
            }
        }
    }
}
POLY attachTerm(POLY p, TERM t)
{   int i = p.nT-1;
    while (i>=0) if (p.t[i].expo == t.expo) return p; else i = i - 1; //duplicate term testing
    i = p.nT-1;
    //attaching a new term in the decreasing order of exponent
    while ((i>=0) && (p.t[i].expo < t.expo)) {p.t[i+1] = p.t[i]; i = i - 1;}
    p.t[i+1] = t; p.nT = p.nT + 1;
    return p;
}

POLY add(POLY p1, POLY p2)
{
    POLY p3 = createPoly();
    int i = 0, j = 0, k = 0;

    while (i < p1.nT && j < p2.nT)
    {
        if (p1.t[i].expo == p2.t[j].expo)
        {
            p3.t[k].coef = p1.t[i].coef + p2.t[j].coef;
            p3.t[k].expo = p1.t[i].expo;

            i++;
            j++;
            k++;
        }
        else if (p1.t[i].expo > p2.t[j].expo)
        {
            p3.t[k] = p1.t[i];

            i++;
            k++;
        }
        else
        {
            p3.t[k] = p2.t[j];

            j++;
            k++;
        }
    }

    while (i < p1.nT)
    {
        p3.t[k] = p1.t[i];
        i++;
        k++;
    }

    while (j < p2.nT)
    {
        p3.t[k] = p2.t[j];
        j++;
        k++;
    }

    p3.nT = k;

    return p3;
}
int main()
{
    TERM t1 = {2, 12}, t2 = { 7, 12}, t3 = {3, 7}; POLY p1,p2,p3;
    p1 = createPoly();
    p1 = attachTerm(p1, t1);
    p1 = attachTerm(p1, t2);
    p1 = attachTerm(p1, t3);
    printf ("\n P1 = ");printPoly(p1);
    p2 = createPoly();
    TERM t4 = {3, 8}, t5 = { 6,2}, t6 = {8, 7};
    p2 = attachTerm(p2, t4);
    p2 = attachTerm(p2, t5);
    p2 = attachTerm(p2, t6);
    printf ("\n P2 = ");printPoly(p2);
    p3=createPoly();
    p3=add(p1,p2);
    printf ("\n sum = ");printPoly(p3);
    return 0;
}
