//https://www.interviewbit.com/problems/bitwise-and-sum/

vector<int> arr;
long long ans = 0;
const int mod = 1e9+7;
int find(int sum) {
    int l = 0 , r = arr.size()-1;
    int res = 0;
    while(l<r)
    {
        if(arr[l]+arr[r]>=sum) {
            res += (r-l);
            res %= mod;
            r--;
        }
        else
            l++;
    }
    return res;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    ans = 0;
    for(int i=0;i<30;i++) {
        arr.clear();
        for(int j=0;j<n;j++) {
            if(A[j] & (1<<i))
                arr.push_back(A[j]%(1<<i));
        }
        sort(arr.begin(), arr.end());
        ans = (ans + (1 << i)*1ll*find(1<<i))%(1ll*mod);
    }
    return ans;
}
