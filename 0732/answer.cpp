class MyCalendarThree {
public:
    map<int, int> c;
    
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        c[start]++;
        c[end]--;
        int r = 0, t = 0;
        for (pair<int,int> e : c) {
            t += e.second;
            r = max(r, t);
        }
        return r;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
