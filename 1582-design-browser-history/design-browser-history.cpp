

class BrowserHistory {
public:
    list<string> ll;
    list<string>::iterator curr;
    BrowserHistory(string homepage) {
        ll.push_front(homepage);
        curr = ll.begin();
    }

    void visit(string url) {
        auto itr = ll.begin();
        while (itr != curr) {
            itr = ll.erase(itr);
        }
        ll.push_front(url);
        curr = ll.begin();
    }

    string back(int steps) {
        while (steps > 0 && next(curr) != ll.end()) {
            curr = next(curr);
            steps--;
        }
        return (*curr);
    }

    string forward(int steps) {
        while (steps > 0 && curr != ll.begin()) {
            curr = prev(curr);
            --steps;
        }
        return *curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */