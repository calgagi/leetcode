class UndergroundSystem {
public:
    map<int,pair<int,string>> begin;
    map<string,int> count;
    map<string,double> avg;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        begin[id] = {t, stationName};
        return;
    }
    
    void checkOut(int id, string stationName, int t) {
        int diff = t - begin[id].first;
        string x = begin[id].second + " " + stationName;
        count[x]++;
        avg[x] *= (count[x]-1);
        avg[x] += (double) diff;
        avg[x] /= count[x];
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return avg[startStation + " " + endStation];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
