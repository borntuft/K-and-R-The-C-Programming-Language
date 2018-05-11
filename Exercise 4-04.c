/*

Exercise 4-4. Add commands to print the top element of the stack without pop-
ping, to duplicate it, and to swap the top two elements. Add a command to
clear the stack.

Date:       May 9, 2018

Author:     BornTuft

*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */

#define MAXVAL 100  /* maximum depth of val satck */

#define BUFSIZE 100

int getop (char []);
void push (double);
double pop (void);
void commands (void);
void clearStack (void);
void topStack (void);
void swapStack (void);

/* reverse polish caculator */
int main (void)
{
    int type;
    double op2;
    char s[MAXOP];

    printf("Reverse Polish Notation Calculator\n");

    commands();

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case 't':
                topStack();
                break;
            case 'x':
                swapStack();
                break;
            case 'c':
                clearStack();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                commands();
                break;
        }
    }

    return 0;
}

void commands(void)
{
printf ("\nCommands Available:\n+ (Addition)\n- (Subtraction)\n* (Multiplication)\n/ (Division)\n% (Modulu)\nx (Swap Top 2 In Stack)\nt (Print Top Of Stick)\nc (Clear Stack)\n");
}

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* valur stack */

/* push: push f onto value stack */
void push (double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop (void)
{
    if (sp > 0)
        return val[--sp];
    else    {
        printf("Stack empty\n");
        return 0.0;
    }
}

void swapStack(void)
{
    double x, y;
    x = pop();
    y = pop();
    push(x);
    push (y);
}

void topStack(void)
{
    printf("Top Of Stack: \t%.8g\n", val[sp - 1]);
}

void clearStack (void)
{
    sp = 0;
    printf("Stack cleared\n");
}

int getch (void);
void ungetch (int);

/* getop: get next operatr or numeric oeprand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;   /* not a number */
    i = 0;

    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) /* get a possibly pushed back character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)    /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
