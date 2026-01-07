#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==============================================================
   STUDENT RECORD MANAGEMENT SYSTEM – DSA MINI PROJECT
   BASE            : SINGLY LINKED LIST
   INTERFACE       : COMMAND LINE (MENU DRIVEN)
   MEMORY          : DYNAMIC (malloc / free)
   FEATURES        : ADD, DISPLAY, SEARCH, UPDATE, DELETE, SORT
   ============================================================== */

/* ================= FRONTEND =================
   Handles:
   - Menu display
   - User interaction (command line)
   ============================ */

void showMenu();

/* ================= BACKEND =================
   Handles:
   - Linked list data structure
   - Core logic and operations
   ============================ */

struct Student {
    int id;                     // Unique student ID
    char name[50];              // Student name
    int age;                    // Student age
    char course[50];            // Course name
    float marks;                // Student marks
    struct Student *next;       // Pointer to next node
};

struct Student *head = NULL;    // Head pointer of linked list

/* Function declarations */
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void sortByMarks();

/* ================= MAIN FUNCTION ================= */
int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortByMarks(); break;
            case 7:
                printf("Exiting Student Record Management System...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

/* ================= FRONTEND FUNCTION ================= */

void showMenu() {
    printf("\n========== STUDENT RECORD MANAGEMENT SYSTEM ==========");
    printf("\n1. Add Student Record");
    printf("\n2. Display All Student Records");
    printf("\n3. Search Student Record (by ID)");
    printf("\n4. Update Student Record");
    printf("\n5. Delete Student Record");
    printf("\n6. Sort Students by Marks");
    printf("\n7. Exit");
    printf("\n=====================================================\n");
}

/* ================= BACKEND FUNCTIONS ================= */

void addStudent() {
    struct Student *newNode, *temp;

    // Allocate memory for new student node
    newNode = (struct Student *)malloc(sizeof(struct Student));

    // Read student details
    printf("Enter Student ID: ");
    scanf("%d", &newNode->id);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Age: ");
    scanf("%d", &newNode->age);
    printf("Enter Course: ");
    scanf("%s", newNode->course);
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    // New node will point to NULL
    newNode->next = NULL;

    // Insert node at end of linked list
    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Student record added successfully.\n");
}

void displayStudents() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }

    printf("\n--- STUDENT RECORDS ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Age: %d | Course: %s | Marks: %.2f\n",
               temp->id, temp->name, temp->age, temp->course, temp->marks);
        temp = temp->next;
    }
}

void searchStudent() {
    int id;
    struct Student *temp = head;

    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Student Found:\n");
            printf("ID: %d | Name: %s | Age: %d | Course: %s | Marks: %.2f\n",
                   temp->id, temp->name, temp->age, temp->course, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student record not found.\n");
}

void updateStudent() {
    int id;
    struct Student *temp = head;

    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter New Name: ");
            scanf("%s", temp->name);
            printf("Enter New Age: ");
            scanf("%d", &temp->age);
            printf("Enter New Course: ");
            scanf("%s", temp->course);
            printf("Enter New Marks: ");
            scanf("%f", &temp->marks);

            printf("Student record updated successfully.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Student record not found.\n");
}

void deleteStudent() {
    int id;
    struct Student *temp = head, *prev = NULL;

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Student record deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Student record not found.\n");
}

void sortByMarks() {
    struct Student *i, *j;
    struct Student temp;

    if (head == NULL) {
        printf("No records to sort.\n");
        return;
    }

    // Bubble sort on linked list by swapping data
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->marks < j->marks) {
                temp = *i;
                *i = *j;
                *j = temp;
                i->next = j->next;
                j->next = temp.next;
            }
        }
    }

    printf("Students sorted by marks successfully.\n");
}
