func int main() {
    int n1, m1, n2, m2;
    // input(n1, n2, m1, m2);
    scanf("%d %d %d %d", n1, m1, n2, m2);

    if(m1 != n2)
    {
        printf("Cannot multiply");
        return 0;
    }

    int mat1[n1][m1], mat2[n2][m2];
    for(int i=0; i<n1; i=i+1)
    {
        for(int j=0; j<m1; j=j+1)
        {
            // input(mat1[i][j]);
            scanf("%d", mat1[i][j]);
        }
    }

    for(int i=0; i<n2; i=i+1)
    {
        for(int j=0; j<m2; j=j+1)
        {
            // input(mat2[i][j]);
            scanf("%d", mat2[i][j]);
        }
    }

    int ans[n1][m2];
    for(int i=0; i<n1; i=i+1)
    {
        for(int j=0; j<m2; j=j+1)
        {
            ans[i][j] = 0;
        }
    }

    for(int i=0; i<n1; i=i+1)
    {
        for(int j=0; j<m2; j=j+1)
        {
            for(int k=0; k<m1; k=k+1)
            {
                ans[i][j] = ans[i][j] + (mat1[i][k] * mat2[k][j]);
            }
        }
    }

    for(int i=0; i<n1; i=i+1)
    {
        printf(" | ");
        for(int j=0; j<m2; j=j+1)
        {
            printf("%d ", ans[i][j]);
        }
        // print("\n");
    }

    return 0;
}