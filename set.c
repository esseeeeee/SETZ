#include <stdio.h>
#include <stdbool.h>
#include "set.h"

void input_set(int set[], int *size, const char *set_name, int max_size) {
	int i;
	bool valid_input = false;
	
	while (!valid_input) {
		printf("\tEnter size for Set %s: ", set_name);
    	scanf("%d", size);
    	
    	if (*size > max_size) {
        printf("\tERROR: INVALID SIZE!\n\n");
    } else {
    	valid_input = true;
	}
}

    for (i = 0; i < *size; i++) {
        printf("\tEnter Set %s number %d: ", set_name, i + 1);
        scanf("%d", &set[i]);
        if (set[i] < 1 || set[i] > 20) {
            printf("\tERROR: Number must be between 1 and 20!\n\n");
            *size = 0;
            input_set (set, size, set_name, max_size);
            return;
        }
    }
}

void display_set(int set[], int size, const char *set_name) {
	int i;
	
    printf("\t%s = {", set_name);
    for (i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("}\n\n");
}

void union_sets(int setA[], int sizeA, int setB[], int sizeB) {
	int i;
    bool union_set[MAX_UNIVERSAL_SIZE] = {false};
    
    for (i = 0; i < sizeA; i++) {
        union_set[setA[i] - 1] = true;
    }
    for (i = 0; i < sizeB; i++) {
        union_set[setB[i] - 1] = true;
    }

    printf("\tUnion of Sets A and B = {");
    for (i = 0; i < MAX_UNIVERSAL_SIZE; i++) {
        if (union_set[i]) {
            printf("%d", i + 1);
            if (i < MAX_UNIVERSAL_SIZE - 1 && union_set[i + 1]) {
            	printf(",");
			}
        }
    }
    printf("}\n\n");
}

void intersection_sets(int setA[], int sizeA, int setB[], int sizeB) {
	int i;
    bool setA_members[MAX_UNIVERSAL_SIZE] = {false};
    
    for (i = 0; i < sizeA; i++) {
        setA_members[setA[i] - 1] = true;
    }

    printf("\tIntersection of Sets A and B = {");
    for (i = 0; i < sizeB; i++) {
        if (setA_members[setB[i] - 1]) {
            printf("%d", setB[i]);
        	if (i < sizeB - 1 && setA_members[setB[i + 1] - 1]) {
        		printf(",");
			}
        }
    }
    printf("}\n\n");
}

void complement_set(int set[], int size, int universal_set[], int universal_size) {
	int i;
	int count = 0;
    bool set_members[MAX_UNIVERSAL_SIZE] = {false};
    
    for (i = 0; i < size; i++) {
        set_members[set[i] - 1] = true;
    }

    printf("\tComplement of Set = {");
    for (i = 0; i < universal_size; i++) {
        if (!set_members[universal_set[i] - 1]) {
        	if (count > 0) {
        		printf(",");
			}
            printf("%d", universal_set[i]);
            count++;
        }
    }
    printf("}\n\n");
}
