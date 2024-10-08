class Solution {
public:
    string nearestPalindromic(string n) {
        long my_number = stol(n), res = -1;
        const vector<long>& candidates = getCandidates(n);
        for (auto& candidate:candidates) {
            if (candidate != my_number){
                if (res == -1 ||
                    abs(candidate - my_number) < abs(res - my_number) ||
                    abs(candidate - my_number) == abs(res - my_number) && candidate < res){ // abs same then choose small
                    res = candidate;
                }
            }
        }
        return to_string(res);
    }

    vector<long> getCandidates(const string& n) {
        int len = n.length();
        vector<long> candidates = {(long)pow(10, len-1) - 1, (long)pow(10, len)+1};
        long selfPrefix = stol(n.substr(0, (len+1)/2)); // get first half
        for(int i : {selfPrefix - 1, selfPrefix, selfPrefix + 1}){
            string prefix = to_string(i);
            string candidate = prefix + string(prefix.rbegin()+(len&1), prefix.rend()); // （len & 1） check len odd or even
            candidates.push_back(stol(candidate));
        }
        return candidates;
    }
};
