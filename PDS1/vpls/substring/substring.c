#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[100];
    char s2[100];
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    int i, j, ts1, ts2, ehsubstring;

    // Remove newline characters from input strings
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    // Calculate the length of string 1
    ts1 = strlen(s1);

    // Calculate the length of string 2
    ts2 = strlen(s2);

    // Loop through string 1
    for (i = 0; i <= ts1 - ts2; i++) {  // Loop until there's enough characters left in s1 for a substring check
        ehsubstring = 1; // Assume it's a substring until proven otherwise

        // Check if substring starting at i in s1 matches s2
        for (j = 0; j < ts2; j++) {
            if (s1[i + j] != s2[j]) {  // If characters don't match
                ehsubstring = 0;  // Not a substring
                break; // Exit inner loop
            }
        }

        // If it's a substring, print and exit
        if (ehsubstring) {
            printf("É substring\n");
            return 0;
        }
    }

    printf("Não é substring\n");

    return 0;
}

