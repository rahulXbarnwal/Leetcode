class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector <pair<int, pair<int, int>>> v;
        for(int i=0; i<n; i++) {
            v.push_back({end[i],{i+1, start[i]}});
        }
        sort(v.begin(), v.end());
        int end_limit=INT_MIN, ans=0;
        for(int i=0; i<v.size(); i++) {
            int f = v[i].first;
            int pos = v[i].second.first;
            int s = v[i].second.second;
            if(s>end_limit) {
                ans++;
                end_limit = f;
            }
        }
        return ans;
    }
};
