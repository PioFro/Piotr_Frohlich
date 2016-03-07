#include <stdio.h>
#include <stdlib.h>
void pointline( float A, float B, float C, float x, float y)
{
    if((A*x)+(B*y)+(C)==0)
        {
             printf("\nPunkt lezy na prostej");
        }
        else
            printf("\nPunkt NIE lezy na prostej");
}
void parts( float x, float y)
{
    if(x<0)
        {
            if(y<0) printf("\nIII cw");
            else printf("\nII cw");
        }
        else
        {
            if(y<0) printf("\nIV cw");
            else printf("\nI cw");
        }

}

int main()
{
    float A, B, C, x, y;
    int pom;
    do{
        do{
            pom = 0;
            printf("Rownanie w formie: Ax + By + C \nA = ");
            scanf("%f", &A);
            printf("\nB = ");
            scanf("%f", &B);
            printf("\nC = ");
            scanf("%f", &C);
            printf("\nWspolrzedne punktu p(x,y): \nx= ");
            scanf("%f",&x);
            printf("\ny = ");
            scanf("%f",&y);
            if ( A==0 && B==0)
            {
                pom = 1;
                printf("\n Podane rownanie nie jest rownaniem prostej\n");
            }
        }while(pom);
        pointline(A, B, C, x, y);
        parts(x, y);
        printf("\n WCISNIJ 0 BY WYJSC \n");
        pom = 0;
        scanf("%d", &pom);

    }
    while( pom!=0 );


    return 0;
}
