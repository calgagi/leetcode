class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle = (((double) hour + (double) minutes / 60.0)/ 12.0);
        if (hourangle >= 1.0) {
            hourangle -= 1.0;
        }
        double minutesangle = (double) minutes / 60.0;
        return min(abs(minutesangle - hourangle), 1.0-abs(minutesangle - hourangle)) * 360.0;
    }
};
