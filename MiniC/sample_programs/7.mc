func int numberOfDigits(int n) {
    if(n == 0)
    {
        return 1;
    }

    int digits = 0;
    while(n > 0)
    {
        digits = digits + 1;
        n = n / 10;
    }

    return digits;
}

func int main() {
    int n;
    // input(n);
    scanf("%d", n);
    
    int arr[n], final[n];
    for(int i=0; i<n; i=i+1)
    {
        // input(arr[i]);
        scanf("%d", arr[i]);
    }

    int maxDigits = 0;
    for(int i=0; i<n; i=i+1)
    {
        int digits = numberOfDigits(arr[i]);
        if(digits > maxDigits)
        {
            maxDigits = digits;
        }
    }

    int pow = 1;
    for(int i=1; i<=maxDigits; i=i+1)
    {
        int cnt[10];
        for(int j=0; j<10; j=j+1)
        {
            cnt[j] = 0;
        }

        for(int j=0; j<n; j=j+1)
        {
            cnt[(arr[j]/pow) % 10] = cnt[(arr[j]/pow) % 10] + 1;
        }

        for(int j=1; j<10; j=j+1)
        {
            cnt[j] = cnt[j] + cnt[j-1];
        }

        for(int j=n-1; j>=0; j=j-1)
        {
            final[cnt[(arr[j]/pow) % 10]-1] = arr[j];
            cnt[(arr[j]/pow) % 10] = cnt[(arr[j]/pow) % 10] - 1;
        }

        for(int j=0; j<n; j=j+1)
        {
            arr[j] = final[j];
        }
        pow = pow * 10;
    }

    for(int i=0; i<n; i=i+1)
    {
        // print(arr[i], " ");
        printf("%d ", arr[i]);
    }
    return 0;
}