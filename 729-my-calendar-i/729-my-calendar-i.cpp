class MyCalendar {
public:
    vector<pair<int, int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i = 0; i < events.size(); i++){
            if(start < events[i].second && end > events[i].first)
                return false;
        }
        events.push_back(pair<int, int>(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */