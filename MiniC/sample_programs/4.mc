func int main() {
    long ans = 0;
    long limit = 100000000;
    
    for(long x=0; x<=limit; x=x+1)
    {
        for(long y=x; y<=limit; y=y+1)
        {
            for(long z=y; z<=limit; z=z+1)
            {
                if((x*x)+(y*y) == z*z)
                {
                    ans = ans + 1;
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}