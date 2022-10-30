#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* test_1_en(char a[])
{
    int i,j,k=0,x=1,y=1;
    k=strlen(a);
    for(j=0; j<k; j++)
    {
        a[j]=a[j]-x++;
        if(x>5){
            x=1;
        }
    }
    return a;
}
char* test_1_de(char a[])
{
    int i,j,k,x=1,y=5;
    k=strlen(a);
    for(j=0; j<k-1; j++)
    {
        a[j]=a[j]+x++;
        if(x>5){
            x=1;
        }
    }
    return a;
}
int main()
{
    fflush(stdin);
    char a[10000];
    int i=0,j=0,choose=0;
    printf("\nWelcome to encrypting tool.\n\n");
    printf("  1. Encrypt\n");
    printf("  2. Decrypt\n");
    printf("\n");
    printf("Enter option : ");
    scanf("%d",&choose);
    fflush(stdin);
    switch(choose)
    {
    case 1:
        printf("\n");
        char fname[20];
        printf("Enter Filename: ");
        gets(fname);
        int i,j,k=0,x=1,y=1;
        FILE *z;
        z=fopen(fname,"r");
        if(z==NULL){
            system("cls");
            printf("\nFile not found!\n");
            main();
        }
        j=0;
        a[j] = fgetc(z);
        while(a[j] != EOF)
        {
            j++;
            a[j] = fgetc(z);
        }
        fclose(z);
        a[j]='\0';
        FILE *f;
        f=fopen(fname,"w");
        if(f==NULL){
            printf("Try again!\n");
            main();
        }
        fprintf(f,"%s\n",test_1_en(a));
        fclose(f);
        system("cls");
        printf("\nSuccessfully encrypted.\n");
        printf("\n");
        main();
        break;
    case 2:
        printf("\n");
        char fname2[20];
        printf("Enter Filename: ");
        gets(fname2);
        FILE *g;
        g=fopen(fname2,"r");
        if(g==NULL){
            system("cls");
            printf("\nFile not found!\n");
            main();
        }
        j=0;
        a[j] = fgetc(g);
        while(a[j] != EOF)
        {
            j++;
            a[j] = fgetc(g);
        }
        fclose(g);
        a[j]='\0';
        FILE *h;
        h=fopen(fname2,"w");
        fprintf(h,"%s\n",test_1_de(a));
        fclose(h);
        system("cls");
        printf("\nSuccessfully decrypted.\n");
        printf("\n");
        main();
        break;
    default:
        printf("Error\n");
        main();
    }
    return 0;
}
