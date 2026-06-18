class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12) hour=0;
        double hourAngle=(hour * 30) + (0.5* minutes);
        double minuteAngle=(6*minutes);
        double diff= abs(hourAngle-minuteAngle);
        return min(diff,360-diff);
        
    }
};