#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][NAME_LEN];
    int count[MAX] = {0};
    int unique = 0;

    char input[NAME_LEN];

    for(int i = 0; i < n; i++) {
        scanf("%s", input);

        int found = -1;

        // Check if already exists
        for(int j = 0; j < unique; j++) {
            if(strcmp(names[j], input) == 0) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            count[found]++;
        } else {
            strcpy(names[unique], input);
            count[unique] = 1;
            unique++;
        }
    }

    // Find winner
    int maxVotes = -1;
    char winner[NAME_LEN];

    for(int i = 0; i < unique; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}