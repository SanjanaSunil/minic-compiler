func int main() {
    int N;
    // input(N);
    scanf("%d", N);

    if(N <= 1)
    {
        printf("NO");
        return 0;
    }

    for(int i=2; i<N; i=i+1)
    {
        if(N % i == 0)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}