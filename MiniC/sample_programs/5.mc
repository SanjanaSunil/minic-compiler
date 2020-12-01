int n;
int arr[100];

func void swap(int l, int r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

    return;
}

func void combinations(int idx) {
    if(idx >= n)
    {
        for(int i=1; i<=n; i=i+1)
        {
            // print(arr[i-1], " ");
            printf("%d ", arr[i-1]);
        }
        printf(" | ");
    }

    for(int i=idx; i<n; i=i+1)
    {
        swap(idx, i);
        combinations(idx+1);
        swap(idx, i);
    }

    return;
}

func int main() {
    scanf("%d", n);
    // input(n);

    for(int i=1; i<=n; i=i+1)
    {
        arr[i-1] = i;
    }

    combinations(0);
    return 0;
}