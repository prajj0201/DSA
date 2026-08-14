class Solution {
public:
    static bool compare(pair<char,int> a,pair<char,int> b)
        {
            return a.second>b.second;
        }
    string frequencySort(string s) {
        map<char,int> mp;
        for(char ch:s)
            mp[ch]++;
        vector<pair<char,int>> v;
        for(auto it:mp)
        {
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),compare);
        string ans="";
        for(auto it:v)
        {
            ans+=string(it.second,it.first);
        }
        return ans;
    }
};