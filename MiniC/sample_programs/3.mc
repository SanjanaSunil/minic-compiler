func bool isPrime(int n) {
    if(n <= 1)
    {
        return false;
    }

    for(int i=2; i<n; i=i+1)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true;
}

func int main() {
    int N;
    input(N);

    int ans = 0;
    for(int i=1; i<N; i=i+1)
    {
        if(isPrime(i))
        {
            ans = ans + i;
        }
    }

    print(ans);
    
    return 0;
}