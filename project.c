#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct emp {
 int id;
 char name[50];
 float salary;
 int age;
} Employee;
// Function prototypes
void addEmployee(Employee* employees, int* numEmployees);
void listEmployees(Employee* employees, int numEmployees);
void modifyEmployee(Employee* employees, int numEmployees,
int id);
void deleteEmployee(Employee* employees, int* numEmployees,
int id);
// Function to perform user login
int login() {
 char username[50];
 char password[50];
 int attempts = 0;
 do {
9 | P a g e
 printf("\nEnter username: ");
 scanf("%s", username);
 printf("Enter password: ");
 scanf("%s", password);
 if (strcmp(username, "admin") == 0 && strcmp(password,
"password") == 0) {
 printf("\nLogin successful!\n");
 return 1; // Successful login
 } else {
 printf("\nInvalid username or password. Please try
again.\n");
 attempts++;
 }
 } while (attempts < 3);
 printf("\nExceeded maximum login attempts. Exiting
program.\n");
 exit(1); // Exit program if login attempts are exceeded
}
int main() {
 // Create an array to store employee records.
 Employee employees[100];
 // Initialize the number of employees to 0.
 int numEmployees = 0;
 // Perform login
10 | P a g e
 if (login()) {
 // Display a menu to the user.
 int choice;
 do {
 printf("\nEmployee Record System");
 printf("\n1. Add employee");
 printf("\n2. List employees");
 printf("\n3. Modify employee");
 printf("\n4. Delete employee");
 printf("\n5. Exit");
 printf("\n\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 addEmployee(employees, &numEmployees);
 break;
 case 2:
 listEmployees(employees, numEmployees);
 break;
 case 3:
 int id;
 printf("\nEnter employee ID: ");
 scanf("%d", &id);
 modifyEmployee(employees, numEmployees, id);
 break;
 case 4:
 printf("\nEnter employee ID to be deleted: ");
 scanf("%d", &id);
 deleteEmployee(employees, &numEmployees, id);
11 | P a g e
 break;
 case 5:
 exit(0);
 break;
 default:
 printf("\nInvalid choice!");
 }
 } while (1); // Infinite loop until the user chooses to exit
 }
 return 0;
}
// Function implementations
void addEmployee(Employee* employees, int* numEmployees) {
 printf("\nEnter employee ID: ");
 scanf("%d", &employees[*numEmployees].id);
 printf("\nEnter employee name: ");
 scanf("%s", employees[*numEmployees].name);
 printf("\nEnter employee salary: ");
 scanf("%f", &employees[*numEmployees].salary);
 printf("\nEnter employee age: ");
 scanf("%d", &employees[*numEmployees].age);
 (*numEmployees)++;
}
12 | P a g e
void listEmployees(Employee* employees, int numEmployees) {
 printf("\nEmployee Records\n");
 printf("ID\tName\tSalary\t\tAge\n");
 for (int i = 0; i < numEmployees; i++) {
 printf("%d\t%s\t%f\t%d\n", employees[i].id,
employees[i].name, employees[i].salary, employees[i].age);
 }
}
void modifyEmployee(Employee* employees, int numEmployees,
int id) {
 int index = -1;
 for (int i = 0; i < numEmployees; i++) {
 if (employees[i].id == id) {
 index = i;
 break;
 }
 }
 if (index == -1) {
 printf("\nEmployee record not found!");
 return;
 }
 printf("\nEnter employee name: ");
 scanf("%s", employees[index].name);
 printf("\nEnter employee salary: ");
 scanf("%f", &employees[index].salary);
13 | P a g e
 printf("\nEnter employee age: ");
 scanf("%d", &employees[index].age);
}
void deleteEmployee(Employee* employees, int* numEmployees,
int id) {
 int index = -1;
 for (int i = 0; i < *numEmployees; i++) {
 if (employees[i].id == id) {
 index = i;
 break;
 }
 }
 if (index == -1) {
 printf("\nEmployee record not found!");
 return;
 }
 for (int i = index; i < *numEmployees - 1; i++) {
 employees[i] = employees[i + 1];
 }
 (*numEmployees)
