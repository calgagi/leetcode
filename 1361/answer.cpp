class Solution {
public:
    // DSU
    vector<int> link;
    vector<int> size;
    int num;
    
    void unite(int a, int b) {
        if (b == -1) {
            return;
        }
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (size[b] < size[a]) {
            swap(a, b);
        }
        link[a] = b;
        size[b] += size[a];
        num--;
        return;
    }
    
    int find(int a) {
        while (a != link[a]) {
            a = link[a];
        }
        return a;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        link.resize(n);
        size.resize(n);
        num = n;
        for (int i = 0; i < n; i++) {
            link[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if ((leftChild[i] != -1 && find(i) == find(leftChild[i])) || (rightChild[i] != -1 && find(i) == find(rightChild[i]))) {
                return 0;
            }
            unite(i, leftChild[i]);
            unite(i, rightChild[i]);
        }
        return num == 1;
    }
};
