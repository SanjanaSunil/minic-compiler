int n;

func void swap(int arr[], int l, int r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;

    return;
}

func void combinations(int arr[], int idx) {
    if(idx >= n)
    {
        for(int i=1; i<=n; i=i+1)
        {
            print(arr[i-1], " ");
        }
        print("\n");
    }

    for(int i=idx; i<n; i=i+1)
    {
        swap(arr, idx, i);
        combinations(arr, idx+1);
        swap(arr, idx, i);
    }

    return;
}

func int main() {
    input(n);

    int arr[n];
    for(int i=1; i<=n; i=i+1)
    {
        arr[i-1] = i;
    }

    combinations(arr, 0);
    return 0;
}