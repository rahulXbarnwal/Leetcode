class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int plat=1;
    	int maxi=0;
    	for(int i=1, j=0; i<n; ) {
    	    if(arr[i]<=dep[j]) {
    	        plat++;
    	        maxi = max(maxi, plat);
    	        i++;
    	    }
    	    else {
    	        plat--;
    	        j++;
    	    }
    	}
    	return maxi;
    }
};
