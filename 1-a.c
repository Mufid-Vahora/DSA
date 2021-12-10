#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct employee
{
    char name[50];
    int age, id, sal;
}emp[50];

int n;
char c;

void add()
{
    printf("\n\n\t   *Adding details of new employee*\n");

    printf("\n\tEnter the no. of records to be entered: ");
	scanf("%d",&n);

	for(int i=0; i<n; i++)
	{
	    printf("\n\tEmployee No.: %d", i+1);
	    printf("\n\n\tEnter name of employee: ");
		scanf("%s",emp[i].name);

		printf("\tEnter employee id no.: ");
		scanf("%d", &emp[i].id);

		printf("\tEnter salary: ");
		scanf("%d",&emp[i].sal);

		printf("\tEnter employee's age: ");
		scanf("%d", &emp[i].age);

    }

    printf("\n\tDo you want to continue(y/n): ");
    scanf("%s", &c);

    if(c=='y')
    main();

    else
    exit(0);
}

void Delete()
{
    int no, j=0, num;
    printf("\n\n\t   *Removing employee details from the system*\n");

    printf("\n\tEnter the id no. of the employee: ");
    scanf("%d",&no);

    num=no;

    for(int i=0; i<n; i++)
    {
        if(no==emp[i].id)
        {
            for(j=i; j<n-1; j++)
            {
                strcpy(emp[j].name,emp[j+1].name);
                emp[j].sal=emp[j+1].sal;
                emp[j].id=emp[j+1].id;
            }
            n--;
            break;
        }
    }

    printf("\n\tDetails of employee are successfully deleted.\n");
    printf("\n\n\tDo you want to continue(y/n): ");
    scanf("%s", &c);

    if(c=='y')
    main();

    else
    exit(0);
}

void list()
{
    printf("\n\n\t   *Listing all employees' details*\n");

    printf("\n\tThe entered record of employees are: \n");

    for(int i=0; i<n; i++)
    {
        printf("\n\t\t%d. Name of employee: %s",i+1,emp[i].name);
        printf("\n\t\t   Employee id: %d",emp[i].id);
        printf("\n\t\t   Age: %d", emp[i].age);
        printf("\n\t\t   Salary: %d\n",emp[i].sal);
    }

    printf("\n\n\tDo you want to continue(y/n): ");
    scanf("%s", &c);

    if(c=='y')
    main();

    else
    exit(0);
}

void search()
{
    int no, flag=0;
    printf("\n\n\t   *Searching for employees' details*\n");

    printf("\n\tEnter the id no. to search: ");
    scanf("%d",&no);

    for(int i=0; i<n; i++)
    {
        if(no==emp[i].id)
        {
            flag=1;
            printf("\n\tRecord successfully found.\n");
            printf("\n\t  Name of employee: %s",emp[i].name);
            printf("\n\t  Employee id: %d",emp[i].id);
            printf("\n\t  Age: %d", emp[i].age);
            printf("\n\t  Salary: %d\n",emp[i].sal);
        }
    }

    if(flag==0)
    printf("\n\tRecord not found.\n");

    printf("\n\n\tDo you want to continue(y/n): ");
    scanf("%s", &c);

    if(c=='y')
    main();

    else
    exit(0);

}

void main()
{
    int ch;
    system("cls");
    printf("\t\t\tMenu\n");
    printf("\n\t1. Add details of new employee.");
    printf("\n\t2. Remove details of an employee from the system.");
    printf("\n\t3. Listing all employees and their details.");
    printf("\n\t4. Searching for details of an employee.");
    printf("\n\t5. Exit\n");

    printf("\n\t\t Enter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1: add();
                break;

        case 2: Delete();
                break;

        case 3: list();
                break;

        case 4: search();
                break;

        case 5: exit(0);

        default: printf("\n\n\t\tInvalid option. Try again.");
                 break;
    }
}
