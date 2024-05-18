#include <stdio.h>
#include <stdbool.h>
#include "set.h"

int main() {
    int setA[MAX_SIZE], setB[MAX_SIZE], universal_set[MAX_UNIVERSAL_SIZE];
    int sizeA = 0, sizeB = 0, universal_size = 0;
    int choice;

    printf("\t\t         SET OPERATIONS\n\t\t   Programmer: ASHTON N. RUIZ\n\n");

    do {
    	printf("\t|================================================|\n");
        printf("\t|                   Main Menu:                   |\n");
        printf("\t|                      \t                         |\n");
        printf("\t| 1. Input Sets A and B                          |\n");
        printf("\t| 2. Input Universal Set                         |\n");
        printf("\t| 3. Union of Sets A and B                       |\n");
        printf("\t| 4. Intersection of Sets A and B                |\n");
        printf("\t| 5. Complement of Set A                         |\n");
       	printf("\t| 6. Complement of Set B                         |\n");
        printf("\t| 7. Display Sets A and B                        |\n");
        printf("\t| 8. Display Universal Set                       |\n");
        printf("\t| 9. Exit                                        |\n");
        printf("\t|================================================|\n\n");
        printf("\tEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_set(setA, &sizeA, "A", MAX_SIZE);
                input_set(setB, &sizeB, "B", MAX_SIZE);
                break;
            case 2:
                input_set(universal_set, &universal_size, "Universal", MAX_UNIVERSAL_SIZE);
                break;
            case 3:
                union_sets(setA, sizeA, setB, sizeB);
                break;
            case 4:
                intersection_sets(setA, sizeA, setB, sizeB);
                break;
            case 5:
                complement_set(setA, sizeA, universal_set, universal_size);
                break;
            case 6:
                complement_set(setB, sizeB, universal_set, universal_size);
                break;
            case 7:
                display_set(setA, sizeA, "Set A");
                display_set(setB, sizeB, "Set B");
                break;
            case 8:
                display_set(universal_set, universal_size, "Universal Set");
                break;
            case 9:
                printf("\tExit Program. Thank you!\n");
                break;
            default:
                printf("\tERROR: INVALID CHOICE!\n\n");
        }
    } while (choice != 9);

    return 0;
}
