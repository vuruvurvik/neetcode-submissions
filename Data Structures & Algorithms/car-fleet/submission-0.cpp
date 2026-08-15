class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();
        
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        } 
        
        // Correctly sort in descending order (closest to target first)
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        
        // Stack MUST store double, not int
        stack<double> st;
        
        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            
            // Push if the stack is empty, OR if this car is slower than the fleet ahead
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        
        return st.size();
    }
};
