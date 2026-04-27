#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    // Step 1: Count frequency
    for(int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find first non-repeating
    for(int i = 0; s[i] != '\0'; i++) {
        if(freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // Step 3: If none found
    printf("$\n");

    return 0;
}