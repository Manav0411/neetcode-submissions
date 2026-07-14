class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;
        for(int i = 0 ; i < position.size(); i++){
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());
        stack<double> s;
        for(int i = cars.size()-1; i >=0; i--){
            if (s.empty() || cars[i].second > s.top()) {
                s.push(cars[i].second);
            }
        }
        return s.size();
    }
};
