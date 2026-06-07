class Data{
    public:
    int value = 0;
    Data* bottom = nullptr;
};

class MinStack {
    Data* stk;
public:
    MinStack() {
        stk=nullptr;
    }
    
    void push(int val) {
        Data* an = new Data();
        an->value = val;
        an->bottom = stk;
        stk = an; 
    }
    
    void pop() {
        if(stk) {
            stk=stk->bottom;
        }
    }
    
    int top() {
        return stk!=nullptr ? stk->value : -1;
    }
    
    int getMin() {
        Data* point = stk;
        int mn = INT_MAX;
        while(point) {
            mn = min(mn,point->value);
            point=point->bottom;
        }
        return mn;
    }
};
