#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char firstName[50];
    char lastName[50];
    char program[150];
    char academicYear[20];

    // Get current date
    time_t t = time(NULL);
    struct tm *currentDate = localtime(&t);

    // Ask the user for information
    printf("Enter your first name: ");
    fgets(firstName, sizeof(firstName), stdin);
    firstName[strcspn(firstName, "\n")] = '\0';

    printf("Enter your last name: ");
    fgets(lastName, sizeof(lastName), stdin);
    lastName[strcspn(lastName, "\n")] = '\0';

    printf("Enter your study program: ");
    fgets(program, sizeof(program), stdin);
    program[strcspn(program, "\n")] = '\0';

    printf("Enter academic year (e.g. 2027/2028): ");
    fgets(academicYear, sizeof(academicYear), stdin);
    academicYear[strcspn(academicYear, "\n")] = '\0';

    // Print the acceptance letter
    printf("\n\n");
    printf("============================================================\n");
    printf("                 MAKERERE UNIVERSITY\n");
    printf("                  ACCEPTANCE LETTER\n");
    printf("============================================================\n\n");

    printf("Date: %02d/%02d/%d\n\n",
           currentDate->tm_mday,
           currentDate->tm_mon + 1,
           currentDate->tm_year + 1900);

    printf("To: %s %s,\n\n", firstName, lastName);

    printf("Dear %s,\n\n", firstName);

    printf("CONGRATULATIONS!\n\n");

    printf("I am pleased to inform you that the Makerere University\n");
    printf("Admissions Board has approved your application for admission\n");
    printf("to the %s academic year.\n\n", academicYear);

    printf("You have been offered a place for the following course:\n");
    printf("PROGRAM: %s\n\n", program);

    printf("As a student of Makerere University, you will be part of a\n");
    printf("historic institution dedicated to academic excellence and\n");
    printf("innovation. Please ensure that you report to the Academic\n");
    printf("Registrar's office with your original academic documents\n");
    printf("for verification during the orientation week.\n\n");

    printf("We look forward to welcoming you to Makerere University.\n\n");

    printf("Yours sincerely,\n\n\n");

    printf("Norah Magret\n");
    printf("Registrar\n");

    return 0;
}