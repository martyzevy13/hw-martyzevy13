#include <iostream>
#include <vector>
using namespace std;

void helper(string library, string curr, vector<int>& used);
void permutations(std::string in);

void permutations(std::string in){
    vector<int> temp;
    helper(in, "", temp);   //Call helper function
}

void helper(string s, string curr, vector<int>& used)
{
    if (curr.size() == s.size()){   //This happens when you have a valid permutation
        cout << curr << endl;
        return;
    }
    for (unsigned int i = 0; i < s.size(); i++){
        bool usedIdx = false;
        for (unsigned int k = 0; k < used.size(); k++){
            if (i == abs(used[k])) usedIdx = true;   //Make sure you haven't used this percise character before
        }
        if (!usedIdx){
            //Backtracking
            string permutation = curr + s[i];
            used.push_back(i);
            helper(s, permutation, used);   //Recursive call on updates used vector and updated string
            used.pop_back();    //Because I continue to use the old string, I did not use the current index index
        }
    }
}

int main(){
    permutations("USC");
    return 0;
}


