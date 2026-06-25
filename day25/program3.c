
#include <stdio.h>
#include <string.h> 
#define MAX_NAMES 5
#define MAX_LEN 50
int main() {
    
    char names[MAX_NAMES][MAX_LEN] = {
        "khushi",
        "abhi",
        "soniya",
        "kriti",
        "priya"
    };
    int i, j;
    printf("Original names:\\n");
    for (i = 0; i < MAX_NAMES; i++) {
        printf("%s\\n", names[i]);
    }
    printf("\\n");
    for (i = 0; i < MAX_NAMES - 1; i++)
     {
        for (j = 0; j < MAX_NAMES - 1 - i; j++)
         {
            if (strcmp(names[j], names[j+1]) > 0)
             {
                char temp[MAX_LEN];
            
                strcpy(temp, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], temp);
            }
        }
    }
    printf("Sorted names (Bubble Sort):\\n");
    for (i = 0; i < MAX_NAMES; i++) {
        printf("%s\\n", names[i]);
    }
    return 0;
}