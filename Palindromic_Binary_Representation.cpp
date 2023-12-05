//https://www.interviewbit.com/problems/palindromic-binary-representation/

vector<int> arr(32,0);
void find(vector<int> &palindrome, int i, int j, int rem)
{
    while(i<=j)
    {
        int diff = (j-i-1);
        if(diff<=0){
            if(rem == 1)
                palindrome[i] = palindrome[j] = 0;
            else
                palindrome[i] = palindrome[j] = 1;
            i++;
            j--;
        }
        else if(rem > arr[diff]*2)
        {
            rem -= 2*arr[diff];
            palindrome[i] = 1;
            palindrome[j] = 1;
            i++;
            j--;
        }
        else
        {
            palindrome[i] = 0;
            palindrome[j] = 0;
            i++;
            j--;
        }
    }
}

int Solution::solve(int A) {
    int prev = 1;
    for(int i=1;i<32;i+=2) {
        arr[i] = prev;
        arr[i+1] = prev;
        prev *= 2;
    }
    int k = 1;
    int count=1;
    while(k<32 && count < A) {
        count += arr[++k];
    }
    A -= (count-arr[k]);

    vector<int> palindrome(k);
    int i=0,j=k-1;
    palindrome[i] = palindrome[j] = 1;
    find(palindrome, ++i, --j, A);
    int ans = 0;
    for(int p=0;p<k;p++) {
        ans += (palindrome[p]==1?(1<<p):0);
    }
    return ans;
}
