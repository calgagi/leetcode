class Solution {
public:

    
    map<string,int> helper(string const& formula, int& i) {
        map<string, int> elements;
        string element = "", number = "";
        while (i < formula.length() && formula[i] != ')') {
            if (element == "" && (formula[i] <= 'Z' && formula[i] >= 'A')) {
                element += formula[i];
            } else if (element != "" && (formula[i] <= 'z' && formula[i] >= 'a')) {
                element += formula[i];
            } else if (element != "" && (formula[i] <= '9' && formula[i] >= '0')) {
                number += formula[i];
            } else if (element != "" && number == "" && (formula[i] <= 'Z' && formula[i] >= 'A')) {
                elements[element]++;
                element = "";
                i--;
            } else if (element != "" && number != "" && (formula[i] <= 'Z' && formula[i] >= 'A')) {
                elements[element] += stoi(number);
                number = "";
                element = "";
                i--;
            } else if (formula[i] == '(') {
                if (element != "") {
                    if (number == "") number = "1";
                    elements[element] += stoi(number);
                }
                number = "";
                i++;
                map<string, int> inner = helper(formula, i);
                // get number
                while (i < formula.length() && (formula[i] <= '9' && formula[i] >= '0')) {
                    number += formula[i];
                    i++;
                }
                if (number != "") i--;
                int num = number == "" ? 1 : stoi(number);
                for (auto it : inner) {
                    elements[it.first] += num * it.second;
                }
                number = "";
                element = "";
            }
            i++;
        }
        if (i < formula.length() && formula[i] == ')') i++;
        if (element != "") {
            if (number == "") number = "1";
            elements[element] += stoi(number);
        }
        return elements;
    }
    
    string countOfAtoms(string formula) {
        int i = 0;
        map<string,int> elements = helper(formula, i);
        string res = "";
        for (auto it : elements) {
            res += it.first;
            if (it.second != 1) res += to_string(it.second);
        }
        return res;
    }
};
