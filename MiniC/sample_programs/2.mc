func int main() {
    int N;
    input(N);

    if(N <= 1)
    {
        print("NO");
        return 0;
    }

    for(int i=2; i<N; i=i+1)
    {
        if(N % i == 0)
        {
            print("NO");
            return 0;
        }
    }

    print("YES");

    return 0;
}