class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char, int> suit;
        map<int, int> rank;
        for(auto i: suits) suit[i]++;
        for(auto i: ranks) rank[i]++;

        for(auto [_, c]: suit) {
            if(c == 5) return "Flush";
        }
        for(auto [_, c]: rank) {
            if(c >= 3) return "Three of a Kind";
        }
        for(auto [_, c]: rank) {
            if(c >= 2) return "Pair";
        }
        return "High Card";
    }
};