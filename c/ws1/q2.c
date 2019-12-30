#include <stdio.h>

void arrayLength(struct * );
int main()
{

struct student *ptr = NULL;
// student structure
  struct student {
  char id[15];
};

struct student std[1];
ptr = std;



	printf("Enter detail of student #1");
    printf("Enter ID: ");
    scanf("%s", ptr->id);

     printf("ID: %s\n", std[0].id);

arrayLength(&std);

return 0;
}

void arrayLength(struct student *ptr)
{
int x = sizeof(ptr->id)*sizeof(ptr->id[0]);
printf("size of id%d: x");
}