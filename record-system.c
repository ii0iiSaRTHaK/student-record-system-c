#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student *next;
};

struct Student *head = NULL;

void addStudent() {
    struct Student *newNode = malloc(sizeof(struct Student));
    printf("Enter Roll: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = head;
    head = newNode;
}

void displayStudents() {
    struct Student *temp = head;
    if (!temp) {
        printf("No records found\n");
        return;
    }
    while (temp) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n",
               temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}

void searchStudent() {
    int roll;
    printf("Enter roll to search: ");
    scanf("%d", &roll);

    struct Student *temp = head;
    while (temp) {
        if (temp->roll == roll) {
            printf("Found: %s %.2f\n", temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Add 2.Display 3.Search 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
