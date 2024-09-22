#include <stdio.h>

int main() {
    int grades[100]; 
    int count = 0;
    int sum = 0, highest = 0, lowest = 100, passCount = 0;
    char choice;

    do {
        printf("Enter marks for student %d: ", count + 1);
        scanf("%d", &grades[count]);

        sum += grades[count];
        if (grades[count] > highest) {
            highest = grades[count];
        }
        if (grades[count] < lowest) {
            lowest = grades[count];
        }
        if (grades[count] >= 50) {
            passCount++;
        }

        count++;

        printf("Do you want to enter another marks? (y/n): ");
        scanf(" %c", &choice); 

    } while (choice == 'y' || choice == 'Y');

    float average = (float)sum / count;

    printf("Average marks: %.2f\n", average);
    printf("Highest marks: %d\n", highest);
    printf("Lowest marks: %d\n", lowest);
    printf("Number of students who passed: %d\n", passCount);

    return 0;
}

