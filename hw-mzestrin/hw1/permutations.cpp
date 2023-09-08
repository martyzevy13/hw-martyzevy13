#include <iostream>
#include <vector>
using namespace std;

void helper(string library, string curr, vector<int>& used);
void permutations(std::string in);

void permutations(std::string in){
    vector<int> temp;
    helper(in, "", temp);
}

void helper(string s, string curr, vector<int>& used){
    if (curr.size() == s.size()){
        cout << curr << endl;
        return;
    }
    for (int i = 0; i < s.size(); i++){
        bool usedIdx = false;
        for (int k = 0; k < used.size(); k++){
            if (i == used[k]) usedIdx = true;
        }
        if (!usedIdx){
            string permutation = curr + s[i];
            used.push_back(i);
            helper(s, permutation, used);
            used.pop_back();
        }
    }
}


