/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    
    vector<int> r;
    int i;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack<NestedInteger> s;
        cout << nestedList.size() << endl;
        for (int j = nestedList.size()-1; j >= 0; j--) s.push(nestedList[j]);
        while (!s.empty()) {
            NestedInteger t = s.top(); s.pop();
            if (t.isInteger()) this->r.push_back(t.getInteger());
            else {
                const vector<NestedInteger> v = t.getList();
                for (int j = v.size()-1; j >= 0; j--) s.push(v[j]);
            }
        }
        this->i = 0;
        return;
    }

    int next() {
        return this->r[this->i++];
    }

    bool hasNext() {
        return this->i < this->r.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
