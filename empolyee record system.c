#include<stdio.h>
#include<stdlib.h>
#define size 1000
int l = 0;

struct Persons
{
    char name[20];
    int Id;
    int Age;
    char Dob[20];
    char Position[30];
    char Gender;
};
struct Persons member[size];

void input()
{

    if(l<size)
    {
        printf("\n Enter Employee id (number): ");
        scanf("%d",&member[l].Id);
        printf("Enter Employee Name (20 characters): ");
        fflush(stdin);
        gets(member[l].name);
        printf("Enter Age (number): ");
        scanf("%d",&member[l].Age);
        printf("Enter DOB (dd-mm-yy): ");
        fflush(stdin);
        gets(member[l].Dob);
        printf("Enter Position(20 characters): ");
        fflush(stdin);
        gets(member[l].Position);
        printf("Enter Gender (M/F) : ");
        member[l].Gender=getchar();
        l++;
    }
    else
    {
        printf("\n memory full: Limit is only %d",l);
    }
}
void modify()
{
    int i,j,k=0;
    char ch[20];
    printf("Enter Employee(Name/Id/Position): ");
    fflush(stdin);
    gets(ch);
    if((ch[0]>='a'&&ch[0]<='z')||(ch[0]>='A'&&ch[0]<='Z')||((ch[0]>='0'&&ch[0]<='9')))
    {
        for(i=0; i<l; i++)
        {
            if((strcmp(ch,member[i].name)==0)||(atoi(ch)==member[i].Id)||(strcmp(ch,member[i].Position)==0))
            {
                printf("\n Enter Employee id (number): ");
                scanf("%d",&member[i].Id);
                printf("Enter Employee Name (20 characters): ");
                fflush(stdin);
                gets(member[i].name);
                printf("Enter Age (number): ");
                scanf("%d",&member[i].Age);
                printf("Enter DOB (dd-mm-yy): ");
                fflush(stdin);
                gets(member[i].Dob);
                printf("Enter Position(20 characters): ");
                fflush(stdin);
                gets(member[i].Position);
                printf("Enter Gender(M/F) : ");
                member[i].Gender=getchar();

                k=1;
                break;
            }
        }


        if(k==1)
        {
            printf("Information has Modified.\n",ch);
        }
        else
        {
            printf("The Information not found on the record.\n") ;
        }
    }
    else
    {
        printf("Invalid Imput!.\n");
    }
    char c;
    printf("Press 0 to clear screen And return main function: ");
    fflush(stdin);
    scanf("%c",&c);
    if(c=='0')
    {
        system("CLS");
    }
    else
    {
        return;
    }
}
void delet()
{
    int i,j,k=0;
    char ch[20];
    printf("Enter Employee(Name/Id/Position): ");
    fflush(stdin);
    gets(ch);
    if((ch[0]>='a'&&ch[0]<='z')||(ch[0]>='A'&&ch[0]<='Z')||((ch[0]>='0'&&ch[0]<='9')))
    {
        for(i=0; i<l; i++)
        {
            if((strcmp(ch,member[i].name)==0)||(atoi(ch)==member[i].Id)||(strcmp(ch,member[i].Position)==0))
            {
                for(j=i; j<l; j++)
                {
                    member[j].Id=member[j+1].Id;
                    member[j].Age=member[j+1].Age;
                    member[j].Gender=member[j+1].Gender;
                    strcpy(member[j].name,member[j+1].name);
                    strcpy(member[j].Position,member[j+1].Position);
                    strcpy(member[j].Dob,member[j+1].Dob);

                }
                l--;
                k=1;
                break;
            }
        }


        if(k==1)
        {
            printf("Erased all of %s's information from the record.\n",ch);
        }
        else
        {
            printf("The Information not found on the record.\n") ;
        }
    }
    else
    {
        printf("Invalid Search!.\n");
    }
    char c;
    printf("Press 0 to clear screen And return main function: ");
    fflush(stdin);
    scanf("%c",&c);
    if(c=='0')
    {
        system("CLS");
    }
    else
    {
        return;
    }

}

void printAll()
{
    printf("\n **** **** Printing All Records **** ****");
    printf("\n total number of persons %d: \n",l);
    for(int i=0; i<l; i++)
    {
        printf("\n Id: %d",member[i].Id);
        printf("\tName: %s",member[i].name);
        printf("\tAge: %d",member[i].Age);
        printf("\tDOB: %s",member[i].Dob);
        printf("\tPosition: %s",member[i].Position);
        printf("\tGender: %c",member[i].Gender);
    }
    char c;
    printf("\nPress 0 to clear screen And return main function: ");
    fflush(stdin);
    scanf("%c",&c);
    if(c=='0')
    {
        system("CLS");
    }
    else
    {
        return;
    }

}
int main()
{

    int choice;

    while(1)
    {
        printf("============Program Menu==========");
        printf("\n 1 Input Records ");
        printf("\n 2 Print All Records");
        printf("\n 3 for Modify Record");
        printf("\n 4 for Delete");
        printf("\n c for screen clear");
        printf("\n 0 exit: ");
        printf("\n Enter you choice : ");
        fflush(stdin);
        choice=getchar();
        switch(choice)
        {

        case '1':
            input();
            break;
        case '2':
            if(l==0)
            {
                printf("The Rocord List is Empty!\n");
                break;
            }
            printAll();
            break;
        case '3':
            if(l==0)
            {
                printf("The Rocord List is Empty!\n");
                break;
            }
            modify();
            break;
        case '4':
            if(l==0)
            {
                printf("The Rocord List is Empty!\n");
                break;
            }
            delet();
            break;

        case 'c':
            system("CLS");
            break;
        case '0':
            exit(0);
            break;
        default:
            printf("\n Error: Invalid Selection\n");
        }

    }

    return 0;

}
