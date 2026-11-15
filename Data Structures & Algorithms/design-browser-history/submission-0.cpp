class Tab {
public:
    string url;

    Tab* back = nullptr;
    Tab* forward = nullptr;
};

class BrowserHistory {
    Tab *home = nullptr;
public:
    BrowserHistory(string homepage) {
        Tab* t = new Tab();
        t->url = homepage;
        home = t;
    }
    
    void visit(string url) {
        Tab* t = new Tab();
        t->url = url;
        t->back = home;
        home->forward = t;
        home = t;
    }
    
    string back(int steps) {
        while(home->back && steps--) {
            home = home->back;
        }
        return home->url;
    }
    
    string forward(int steps) {
        while(home->forward && steps--) {
            home = home->forward;
        }
        return home->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */