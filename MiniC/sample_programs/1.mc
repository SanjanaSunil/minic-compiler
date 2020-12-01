func int computePower(int num, int k) {
    int power = 1;
    for(int i=1; i<=k; i=i+1)
    {
        power = num * power;
    }
    return power;
} 

func int main() {
    int N, k;
    scanf("%d %d", N, k);
    // input(N, k);

    int g = 0;

    for(int i=1; i<=N; i=i+1)
    {
        g = g + computePower(i, k); 
    }

    printf("%d", g);
    // print(g);

    return 0;
}