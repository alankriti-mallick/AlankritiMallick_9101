#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void commonStrings(char *X, char *Y, int x, int y, int *ops, int subStrings[], int *numSubstrings)
{

    int i,j;
    int a[x+1][y+1],k;
    char b[x][y];

    for(i=x; i>=0; i--)
    {
        a[i][y]=-1;
    }
    for(j=y; j>=0; j--)
    {
        a[x][j]=-1;
    }

    for(i=x-1; i>=0; i--)
    {
        for(j=y-1; j>=0; j--)
        {
            (*ops)++;
            if(X[i]==Y[j])
            {
                b[i][j]='X';
                if(a[i+1][j+1]==-1)
                {
                    a[i][j]=(*numSubstrings);
                    subStrings[(*numSubstrings)*4+ 1]=i;
                    subStrings[(*numSubstrings)*4 + 3]=j;
                    if(i==0||j==0)
                    {
                        subStrings[(*numSubstrings)*4 ]=i;
                        subStrings[(*numSubstrings)*4 + 2]=j;
                    }
                    (*numSubstrings)++;
                }
                else
                {
                    a[i][j]=a[i+1][j+1];

                }

                if((i==0||j==0)&&(a[i+1][j+1]!=-1))
                {
                    k=a[i+1][j+1];
                    subStrings[k*4]=i;
                    subStrings[k*4 + 2]=j;
                }

            }
            else
            {
                a[i][j]=-1;
                b[i][j]='.';
                if(a[i+1][j+1]!=-1)
                {
                    k=a[i+1][j+1];
                    subStrings[k*4]=i+1;
                    subStrings[k*4 + 2]=j+1;
                }

            }
        }
    }


    for(i=0; i<=x; i++)
    {
        for(j=0; j<=y; j++)
        {
            if(i==0&&j==0)
                printf("  ");
            else if(i==0)
                printf("%c ",Y[j-1]);
            else if(j==0)
                printf("%c ",X[i-1]);
            else
                printf("%c ",b[i-1][j-1]);
        }

        printf("\n");
    }

}

void printString(char* a, int n){
    int i;
    for(i=0;i<n;i++)
        printf("%c",a[i]);
    printf("\n");
}

void printSelectedSubStrings(char* a, int subS[], int sunS_len, int lengthFilter){
    ///print all the substrings that are greater than or equal to length lengthFilter

    int i,j;
    for(i=0; i<sunS_len; i++)
    {
        if(subS[i*4 + 1]-subS[i*4]+1>=lengthFilter)
        {
            for(j=subS[i*4];j<=subS[i*4+1];j++)
                printf("%c",a[j]);
            printf("\n");
        }
    }

}

int main()
{

    char Y[] = "only the dead has seen the end of war - Plato";
    char X[] = "the deadly war continued without any seen benifit";

    int m = strlen(X);
    int n = strlen(Y);
    int ops=0;

    printf("\n\nThe input strings are:\n");
    printString(X,m);
    printString(Y,n);

    int subStrings[(m+n)*16];
    int numSubStrings=0;///The matrix contains 4 elements as i*4 = start idx from X i*4+1 = end idx from X + 1
                        ///i*4+2 = start idx from Y i*4+3= end idx from Y + 1
    int filterSize=4;
    printf("\n\nAll the matches are:\n");
    commonStrings(X,Y,m,n,&ops,subStrings,&numSubStrings);
    printf("\n\nThe number of ops, m x n: %d %d\n",ops,m*n);
    printf("\nThe common substrings of size >= %d are:\n",filterSize);

    printSelectedSubStrings(X, subStrings, numSubStrings, filterSize);

    ///sequence 2
    char Y2[] = "why so serious?";
    char X2[] = "seriously? why just why?!";

    int m2 = strlen(X2);
    int n2 = strlen(Y2);
    int ops2=0;

    printf("\n\nThe input strings are:\n");
    printString(X2,m2);
    printString(Y2,n2);

    int subStrings2[(m2+n2)*16];
    int numSubStrings2=0;///The matrix contains 4 elements as i*4 = start idx from X i*4+1 = end idx from X + 1
                        ///i*4+2 = start idx from Y i*4+3= end idx from Y + 1
    int filterSize2=3;
    printf("\n\nAll the matches are:\n");
    commonStrings(X2,Y2,m2,n2,&ops2,subStrings2,&numSubStrings2);
    printf("\n\nThe number of ops, m x n: %d %d\n",ops2,m2*n2);
    printf("\nThe common substrings of size >= %d are:\n",filterSize2);

    printSelectedSubStrings(X2, subStrings2, numSubStrings2, filterSize2);


    ///sequence 3
    char Y3[] = "technology is getting smarter every day";
    char X3[] = "smartphones are a gift from technology for human kind";

    int m3 = strlen(X3);
    int n3 = strlen(Y3);
    int ops3=0;

    printf("\n\nThe input strings are:\n");
    printString(X3,m3);
    printString(Y3,n3);

    int subStrings3[(m3+n3)*16];
    int numSubStrings3=0;///The matrix contains 4 elements as i*4 = start idx from X i*4+1 = end idx from X + 1
                        ///i*4+2 = start idx from Y i*4+3= end idx from Y + 1
    int filterSize3=5;
    printf("\n\nAll the matches are:\n");
    commonStrings(X3,Y3,m3,n3,&ops3,subStrings3,&numSubStrings3);
    printf("\n\nThe number of ops, m x n: %d %d\n",ops3,m3*n3);
    printf("\nThe common substrings of size >= %d are:\n",filterSize3);

    printSelectedSubStrings(X3, subStrings3, numSubStrings3, filterSize3);


    ///sequence 4
    char Y4[] = "She has a dog";
    char X4[] = "He has a cat";

    int m4 = strlen(X4);
    int n4 = strlen(Y4);
    int ops4=0;

    printf("\n\nThe input strings are:\n");
    printString(X4,m4);
    printString(Y4,n4);

    int subStrings4[(m4+n4)*16];
    int numSubStrings4=0;///The matrix contains 4 elements as i*4 = start idx from X i*4+1 = end idx from X + 1
                        ///i*4+2 = start idx from Y i*4+3= end idx from Y + 1
    int filterSize4=3;
    printf("\n\nAll the matches are:\n");
    commonStrings(X4,Y4,m4,n4,&ops4,subStrings4,&numSubStrings4);
    printf("\n\nThe number of ops, m x n: %d %d\n",ops4,m4*n4);
    printf("\nThe common substrings of size >= %d are:\n",filterSize4);

    printSelectedSubStrings(X4, subStrings4, numSubStrings4, filterSize4);

    return 0;
}
