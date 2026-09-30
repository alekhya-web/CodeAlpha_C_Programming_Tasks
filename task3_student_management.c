#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.dat"
#define TEMP_FILENAME "temp.dat"

struct Student {
    int id;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp;
    struct Student s;

    fp = fopen(FILENAME, "ab");
    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    printf("\n--- Add Student Record ---\n");
    printf("Enter Student ID: ");
    if (scanf("%d", &s.id) != 1) {
        printf("Invalid ID input!\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    if (scanf("%f", &s.marks) != 1) {
        printf("Invalid marks input!\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("Student record added successfully!\n");
}

void viewStudents() {
    FILE *fp;
    struct Student s;
    int count = 0;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo student records found. Add a record first.\n");
        return;
    }

    printf("\n--------------------------------------------------------------\n");
    printf("%-10s %-30s %-10s\n", "ID", "Name", "Marks");
    printf("--------------------------------------------------------------\n");

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        printf("%-10d %-30s %-10.2f\n", s.id, s.name, s.marks);
        count++;
    }

    printf("--------------------------------------------------------------\n");
    if (count == 0) {
        printf("No records found in file.\n");
    } else {
        printf("Total records: %d\n", count);
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp;
    struct Student s;
    int targetId;
    int found = 0;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo records available to search.\n");
        return;
    }

    printf("\nEnter Student ID to search: ");
    if (scanf("%d", &targetId) != 1) {
        printf("Invalid ID input!\n");
        while (getchar() != '\n');
        fclose(fp);
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.id == targetId) {
            printf("\n--- Student Found ---\n");
            printf("ID:    %d\n", s.id);
            printf("Name:  %s\n", s.name);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", targetId);
    }

    fclose(fp);
}

void updateStudent() {
    FILE *fp, *tempFp;
    struct Student s;
    int targetId;
    int found = 0;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo records available to update.\n");
        return;
    }

    tempFp = fopen(TEMP_FILENAME, "wb");
    if (tempFp == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Student ID to update: ");
    if (scanf("%d", &targetId) != 1) {
        printf("Invalid ID input!\n");
        while (getchar() != '\n');
        fclose(fp);
        fclose(tempFp);
        remove(TEMP_FILENAME);
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.id == targetId) {
            found = 1;
            printf("\nCurrent Details:\n");
            printf("ID: %d | Name: %s | Marks: %.2f\n", s.id, s.name, s.marks);

            printf("Enter new Name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter new Marks: ");
            scanf("%f", &s.marks);

            fwrite(&s, sizeof(struct Student), 1, tempFp);
        } else {
            fwrite(&s, sizeof(struct Student), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILENAME);
    rename(TEMP_FILENAME, FILENAME);

    if (found) {
        printf("Student record updated successfully!\n");
    } else {
        printf("Student with ID %d not found.\n", targetId);
    }
}

void deleteStudent() {
    FILE *fp, *tempFp;
    struct Student s;
    int targetId;
    int found = 0;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("\nNo records available to delete.\n");
        return;
    }

    tempFp = fopen(TEMP_FILENAME, "wb");
    if (tempFp == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Student ID to delete: ");
    if (scanf("%d", &targetId) != 1) {
        printf("Invalid ID input!\n");
        while (getchar() != '\n');
        fclose(fp);
        fclose(tempFp);
        remove(TEMP_FILENAME);
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.id == targetId) {
            found = 1;
        } else {
            fwrite(&s, sizeof(struct Student), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    remove(FILENAME);
    rename(TEMP_FILENAME, FILENAME);

    if (found) {
        printf("Student record deleted successfully!\n");
    } else {
        printf("Student with ID %d not found.\n", targetId);
    }
}

int main() {
    int choice;

    do {
        printf("\n===================================\n");
        printf("     Student Management System     \n");
        printf("===================================\n");
        printf("1. Add Student Record\n");
        printf("2. View All Records\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("\nExiting Student Management System. Goodbye!\n");
                break;
            default:
                printf("\nInvalid option! Please select between 1 and 6.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}
