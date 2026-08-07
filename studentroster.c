#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
    char name[30];
    int age;
} student;

student *addstudent(student *newstudent, int *count, char *name, int age)
{ 
    newstudent = realloc(newstudent, (*count + 1) * sizeof(student));

    strcpy(newstudent[*count].name, name);
    newstudent[*count].age = age;
    (*count)++;

    return newstudent;
}

int main(void)
{
    printf("Hello, Welcome to the Student terminal!\n");
    printf("When you're finished enter \"Done\" to end.\n");

    int count = 0;

    student *roster = malloc(sizeof(student));

    while (1)
    {
        char terminate[10];
        char name[30];
        char agebuffer[10];
        int age;

        printf("Student count: %d\n", count);
        printf("Continue?\n");
        fgets(terminate, sizeof(terminate), stdin);
        terminate[strcspn(terminate, "\n")] = '\0';

        if(strcmp(terminate, "Done") == 0)
        {
            break;
        }

        printf("Name of Student: \n");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Age of Student: \n");
        fgets(agebuffer, sizeof(agebuffer), stdin);
        agebuffer[strcspn(agebuffer, "\n")] = '\0';
        age = atoi(agebuffer);

        roster = addstudent(roster, &count, name, age);
    }

    if(count == 0)
    {
        printf("See you next time!\n");
    }

    else
    {
        int i;
        printf("Your students: %d\n", count);
        for(i = 0; i < count; i++)
        {
            printf("%s, %d \n", roster[i].name, roster[i].age);
        }
        
        printf("See you next time!\n");
    }

    free(roster);

    return 0;
}