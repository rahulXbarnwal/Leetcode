class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector <pair<int, pair<int, int>>> v;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            int x = arr[i].id;
            int dl = arr[i].dead;
            int pr = arr[i].profit;
            maxi = max(maxi, dl);
            v.push_back({pr, {x, dl}});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector <int> ans(maxi+1, -1), v1;
        int profit=0, count=0;
        for(int i=0; i<n; i++) {
            int pr = v[i].first;
            int id = v[i].second.first;
            int dl = v[i].second.second;
            if(ans[dl]==-1){
                ans[dl]=id;
                profit+=pr;
                count++;
            }
            else {
                int j = dl;
                while(ans[j]!=-1) {
                    j--;
                }
                if(j!=0) {
                    ans[j]=id;
                    profit+=pr;
                    count++;
                }
            }
        }
        v1.push_back(count);
        v1.push_back(profit);
        return v1;
    } 
};
