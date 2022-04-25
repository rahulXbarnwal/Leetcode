class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector <pair<double, pair<int, int>>> v;
        for(int i=0; i<n; i++) {
            double x = (1.0*arr[i].value)/(1.0*arr[i].weight);
            v.push_back({x, {arr[i].value, arr[i].weight}});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        double ans=0;
        for(int i=0; i<n; i++) {
            double x = v[i].first;
            int val = v[i].second.first;
            int weight = v[i].second.second;
            if(weight<=W) {
                ans+=val;
                W-=weight;
            }
            else {
                ans+=x*W;
                break;
            }
        }
        return ans;
    }
        
};
