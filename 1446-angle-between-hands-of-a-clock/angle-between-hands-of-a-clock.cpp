class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle=30*hour+0.5*minutes;
        double minangle=minutes*6;
        double ans =abs(hourangle-minangle);
        return min(ans,360-ans);
        
    }
};