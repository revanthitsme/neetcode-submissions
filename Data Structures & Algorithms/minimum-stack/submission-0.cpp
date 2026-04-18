class MinStack {
public:
    list<int> _lst;
    list<int> _minLst;

    MinStack() {
    }
    
    void push(int val) {
        _lst.push_front(val);
        if (_minLst.empty() || val <= _minLst.front()) {
            _minLst.push_front(val);
        }
    }
    
    void pop() {
        if (_lst.front() == _minLst.front()) {
            _minLst.pop_front();
        }
        _lst.pop_front();
    }
    
    int top() {
        return _lst.front();
    }
    
    int getMin() {
        return _minLst.front();
    }
};