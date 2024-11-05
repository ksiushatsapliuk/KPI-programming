#include <complex.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

#define MIN_NUM -100000
#define MAX_NUM 100000

int main() {
    double a=0, b=0, c=0, p=0, q=0, d=0, u=0, v=0, r=0, phi=0, Y1=0, y2=0, y3=0, X1=0, x2=0, x3=0;
    char ch;
    double complex Y2=0, Y3=0, X2=0, X3=0;
    int precision=0;

    do {
        printf("Enter the coefficients (a,b,c) of cubic equation x^3 + a*x^2 + b*x + c = 0: \n");
        char inputvalid=0;
        while (!inputvalid) {
            printf("Enter coefficient a: \n");
            if (scanf("%lf%c", &a, &ch) != 2 || ch != '\n')
            {
                printf("Wrong input! Please enter a valid number.\n");
                fflush(stdin);
            }
            else if (a==0)
            {
                printf("The coefficient cannot be zero.\n");
            }
            else if (a<MIN_NUM)
            {
                printf("Too little. The coefficient must be between (%d;%d).\n", MIN_NUM, MAX_NUM);
            }
            else if (a>MAX_NUM)
            {
                printf("Too large. The coefficient must be between (%d;%d).\n", MIN_NUM, MAX_NUM);
            }
            else {
                inputvalid = 1;
            }
        }
        inputvalid=0;
        while (!inputvalid) {
            printf("Enter coefficient b: \n");
            if (scanf("%lf%c", &b, &ch) != 2 || ch != '\n')
            {
                printf("Wrong input! Please enter a valid number.\n");
                fflush(stdin);
            }
            else if (b==0)
            {
                printf("The coefficient cannot be zero.\n");
            }
            else if (b<MIN_NUM)
            {
                printf("Too little. The coefficient must be between (%d;%d).\n", MIN_NUM, MAX_NUM);
            }
            else if (b>MAX_NUM)
            {
                printf("Too large. The coefficient must be between (%d;%d).\n", MIN_NUM, MAX_NUM);
            }
            else {
                inputvalid = 1;
            }
        }
        inputvalid=0;
        while (!inputvalid) {
            printf("Enter coefficient c: \n");
            if (scanf("%lf%c", &c, &ch) != 2 || ch != '\n')
            {
                printf("Wrong input! Please enter a valid number.\n");
                fflush(stdin);
            }
            else if (c==0)
            {
                printf("The coefficient cannot be zero.\n");
            }
            else if (c<MIN_NUM)
            {
                printf("Too little. The coefficient must be between (%d;%d).\n", MIN_NUM, MAX_NUM);
            }
            else if (c>MAX_NUM)
            {
                printf("Too large. The coefficient must be between (%d;%d).\n", MIN_NUM, MAX_NUM);
            }
            else {
                inputvalid = 1;
            }
        }
        printf("Enter number of decimal places (1-15): \n");
        while (scanf("%d%c", &precision, &ch) != 2 || ch != '\n' || precision < 1 || precision > 15)
            {
            printf("Invalid input! Please enter the number of decimal places between 1 and 15.\n");
            fflush(stdin);
            }

        p=b-(pow(a,2)/3);
        q=((2*pow(a,3))/27)-((a*b)/3)+c;
        d=(pow(p,3)/27)+(pow(q,2)/4);

        if (d>0)
            {
            u=cbrt(-q/2+sqrt(d));
            v=-p/(3*u);

            Y1=u+v;
            Y2=-(u+v)/2+I*(sqrt(3)*(u-v))/2;
            Y3=-(u+v)/2-I*(sqrt(3)*(u-v))/2;

            X1=Y1-a/3;
            X2=Y2-a/3;
            X3=Y3-a/3;

            printf("Your solution is:\n x1=%.*lf\n x2=%.*lf%c%.*lf*i\n x3=%.*lf%c%.*lf*i\n",
                precision, X1, precision, creal(X2), cimag(X2) >= 0 ? '+' : '-', precision, fabs(cimag(X2)),
                precision, creal(X3), cimag(X3) >= 0 ? '+' : '-', precision, fabs(cimag(X3)));
            }
        else if (d==0 && p!=0)
            {
            Y1=3*q/p;
            y2=y3=-(3*q)/(2*p);

            X1=Y1-a/3;
            x2=y2-a/3;
            x3=y3-a/3;
            printf("Your solution is:\n x1=%.*lf\n x2=%.*lf\n x3=%.*lf\n", precision, X1, precision, x2, precision, x3);
            }
        else if (d==0 && p==0)
            {
            printf("The equalation can not have roots as there dividing by 0 occurs in calculations.\n");
            }
        else if (d<0)
            {
            r=sqrt(-pow(p,3)/27);
            phi=acos(-q/(2*r));

            Y1=2*(fabs(cbrt(r)))*cos(phi/3);
            y2=2*(fabs(cbrt(r)))*cos((phi+2*M_PI)/3);
            y3=2*(fabs(cbrt(r)))*cos((phi+4*M_PI)/3);

            X1=Y1-a/3;
            x2=y2-a/3;
            x3=y3-a/3;
            printf("Your solution is:\n x1=%.*lf\n x2=%.*lf\n x3=%.*lf\n", precision, X1, precision, x2, precision, x3);
            }

        printf("Press ENTER to continue or any key to EXIT.");
        fflush(stdout);
    } while (getch()==13);
    return 0;
}