#define MAX_SIZE 10
#define MAX_UNIVERSAL_SIZE 20

void input_set(int set[], int *size, const char *set_name, int max_size);
void display_set(int set[], int size, const char *set_name);
void union_sets(int setA[], int sizeA, int setB[], int sizeB);
void intersection_sets(int setA[], int sizeA, int setB[], int sizeB);
void complement_set(int set[], int size, int universal_set[], int universal_size);
