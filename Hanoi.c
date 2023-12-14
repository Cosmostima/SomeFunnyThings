#include <stdio.h>
#include <unistd.h> // This should be changed into "#include <windows.h>" in Windows.

int A[9]={7,6,5,4,3,2,1,0,7};  
int B[9]={0};
int C[9]={0};                  // Representing the three pillars.
int count=0;

void display(void);
void displaycore(int * arry);
int process(int n,int * arry);
void printc(int n);
void Hanoi(char start,char end,char help,int n);
void move(char start,char end);


int main(void)
{
    printf("This is a display of the Hanoi Game made by Cosmos.\n");
    display();
    printf("Click return to start.\n");
    getchar();
    Hanoi('A','C','B',7);
    printf("The display is over. We took %d steps to finish it!\n",count);
    return 0;
}

int process(int n,int * arry) // Tell Displaycore how many "* " to print.
{
    int number=0,add=0;
    for (int a = 0; a < arry[8]; a++)
    {
        number=((arry[a]-n)>=0)?1:0;
        add += number;
        number=0;
    }
    
    return add;
}

void display(void) // Print the three pillars.
{
    displaycore(A);
    printf("|\n");
    displaycore(B);
    printf("|\n");
    displaycore(C);
    printf("\n");
}

void displaycore(int * arry) // Print rows of a pillar.
{
    int afprocess[13]={0};
    for (int a = 0; a < 7; a++)
    {
        afprocess[a]=process((7-a),arry);
    }
    for (int a = 0; a < 6; a++)
    {
        afprocess[12-a]=afprocess[a];
    }
    for (int a = 0; a < 13; a++)
    {
        putchar('|');
        printc(afprocess[a]);
        putchar('\n');
    }
}

void printc(int n)  // Print n "* ".
{
    for (int a = 1; a <= n; a++)
    {
        printf("* ");
    }
}

void move(char start,char end) // Change the arrays, display, and wait some times.
{
    if (start == 'A')
    {
        if (end == 'B')
        {
            B[B[8]] = A[(A[8]-1)];
            A[(A[8]-1)] = 0;
            B[8]++;
            A[8]--;
        }
        if (end == 'C')
        {
            C[C[8]] = A[(A[8]-1)];
            A[(A[8]-1)] = 0;
            C[8]++;
            A[8]--;
        }  
    }
    
    if (start == 'B')
    {
        if (end == 'A')
        {
            A[A[8]] = B[(B[8]-1)];
            B[(B[8]-1)] = 0;
            A[8]++;
            B[8]--;
        }
        if (end == 'C')
        {
            C[C[8]] = B[(B[8]-1)];
            B[(B[8]-1)] = 0;
            C[8]++;
            B[8]--;
        }  
    }

    if (start == 'C')
    {
        if (end == 'B')
        {
            B[B[8]] = C[(C[8]-1)];
            C[(C[8]-1)] = 0;
            B[8]++;
            C[8]--;
        }
        if (end == 'A')
        {
            A[A[8]] = C[(C[8]-1)];
            C[(C[8]-1)] = 0;
            A[8]++;
            C[8]--;
        }  
    }

    display();
    count++;
    usleep(300000);         // Change this to adjust the framrate.
}

void Hanoi(char start,char end,char help,int n)  // Classical Hanoi function.
{
    if(n == 1)
    {
        move(start,end);
    }
    else
    {
        Hanoi(start,help,end,n-1);
        move(start,end);
        Hanoi(help,end,start,n-1);
    }
}

/* By Cosmos */