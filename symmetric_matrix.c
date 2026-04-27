#include <stdio.h>

int main() {
    int m, n;
    
    // Read number of rows and columns
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    // Read matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Check if matrix is square
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }
    
    // Check symmetry condition
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }
    
    printf("Symmetric Matrix");
    
    return 0;
}