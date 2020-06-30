class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int rB = 0, rF = 0, i = start, j = start;
        while (i != destination) {
            rF += distance[i];
            i++;
            if (i == distance.size()) i = 0;
        }
        while (j != destination) {
            rB += distance[j];
            j--;
            if (j == -1) j = distance.size()-1;
        }
        rB += distance[destination];
        rB -= distance[start];
        return min(rB, rF);
    }
};
