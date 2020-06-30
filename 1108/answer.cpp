class Solution {
public:
    string defangIPaddr(string address) {
        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                address.insert(address.begin()+i+1, ']');
                address.insert(address.begin()+i, '[');
                i+=2;
            }
        }
        return address;
    }
};
