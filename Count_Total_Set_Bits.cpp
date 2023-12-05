//https://www.interviewbit.com/problems/count-total-set-bits/

int Solution::solve(int A) {
    int val = (1<<31)-1;
    const int mod = 1e9+7;
    int sbits=0;
    while(val > A) {
        val >>= 1;
        sbits++;
    }
    int count = 0;
    int lastbits = 30-sbits;
    // cout << sbits << " " <<  lastbits << "\n";
    for(int i=lastbits;i>=0;i--) {
        count += (val+1)/2;
        count %= mod;
    }
    int left = A-(val);
    count += left;
    // cout << left  << "\n";
    for(int i=lastbits;i>=0;i--) {
        int div = left/(1<<i);
        int rem = left%(1<<i);
        count += (div/2)*(1<<i);
        int startValue = A-rem+1;
        // cout << "Before " << div << " " << rem << " " << count << "\n";
        count += (startValue&(1<<i))?rem:0;
        count %= mod;
        // cout << "After " << div << " " << rem << " " << count << "\n";
    }
    return count;
}

