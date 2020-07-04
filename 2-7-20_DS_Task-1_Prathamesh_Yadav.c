#include<stdio.h>

struct student
{
    int id;
    float CGPA;
    char name,year;
};

int main(){
    printf("Enter number of students: ");
    int n;
    scanf("%d",&n);

    int all_ids[n];
    char all_name[n], all_year[n];
    float all_cgpa[n];

    struct student stud;

    for (int i=0; i<n; i++){
        printf("Enter student details:");
        printf("\nEnter id: ");
        scanf("%d",&stud.id);
        all_ids[i] = stud.id;
        printf("\nEnter CGPA: ");
        scanf("%f",&stud.CGPA);
        all_cgpa[i] = stud.CGPA;
        printf("\nEnter name: ");
        scanf("%s",stud.name);
        all_name[i] = stud.name;
        printf("\nEnter year: ");
        scanf("%s",stud.year);
        all_year[i] = stud.CGPA;  
    } 
    fflush(stdin);

    // printing
    for (int i;i<n;i++){
        printf("%3d %13s %7s %.2f",&all_ids[i],all_name[i],all_year[i],all_cgpa[i]);
    }
    

}
