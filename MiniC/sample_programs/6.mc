func int main() {
    int n;
    // input(n);
    scanf("%d", n);

    int arr[n];
    for(int i=0; i<n; i=i+1)
    {
        // input(arr[i]);
        scanf("%d", arr[i]);
    }

    for(int i=1; i<n; i=i+1)
    {
        int val = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > val)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = val;
    }

    for(int i=0; i<n; i=i+1)
    {
        // print(arr[i], " ");
        printf("%d ", arr[i]);
    }

    return 0;
}