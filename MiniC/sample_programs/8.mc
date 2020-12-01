int arr[100];

func void merge(int l, int mid, int r) {
    int output[r-l+1];

    int p1 = l, p2 = mid + 1;
    int ptr = 0;
    while(p1 <= mid && p2 <= r)
    {
        if(arr[p1] < arr[p2])
        {
            output[ptr] = arr[p1];
            p1 = p1 + 1;
        }
        else 
        {
            output[ptr] = arr[p2];
            p2 = p2 + 1;
        }
        ptr = ptr + 1;
    }

    while(p1 <= mid)
    {
        output[ptr] = arr[p1];
        ptr = ptr + 1;
        p1 = p1 + 1;
    }

    while(p2 <= r)
    {
        output[ptr] = arr[p2];
        ptr = ptr + 1;
        p2 = p2 + 1;
    }

    for(int i=l; i<=r; i=i+1)
    {
        arr[i] = output[i-l];
    }

    return;
}

func void sort(int l, int r) {
    if(l >= r)
    {
        return;
    }

    int mid = (l + r)/2;

    sort(l, mid);
    sort(mid+1, r);
    merge(l, mid, r);

    return;
}

func int main() {
    int n;
    // input(n);
    scanf("%d", n);

    // int arr[n];
    for(int i=0; i<n; i=i+1)
    {
        // input(arr[i]);
        scanf("%d", arr[i]);
    }

    sort(0, n-1);

    for(int i=0; i<n; i=i+1)
    {
        // print(arr[i], " ");
        printf("%d ", arr[i]);
    }
    // print("\n");

    return 0;
}