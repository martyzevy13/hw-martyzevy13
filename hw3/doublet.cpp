#include "MinHeap.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <map> 
#include <set>

using namespace std;

//Function prototypes
set<string> getWords(istream& infile, unsigned int size);
int getHeuristic(string word1, string word2);
map<string, set<string>> buildGraph(set<string>& data);
void graphSearch(map<string, set<string>>& graph, string start, string end);

int main(int argc, char* argv[]){
    ifstream file(argv[3]);
    string startWord = argv[1];
    string endWord = argv[2];

    //Case-insensitive, so make everything uppercase to standardize
    for (unsigned int i = 0; i < startWord.size(); i++) startWord[i] = toupper(startWord[i]);
    for (unsigned int i = 0; i < endWord.size(); i++) endWord[i] = toupper(endWord[i]);

    set<string> wordBank = getWords(file, startWord.size());    
    map<string, set<string>> graph = buildGraph(wordBank);

    //A* Search
    graphSearch(graph, startWord, endWord);

    return 0;
}

set<string> getWords(istream& infile, unsigned int size){
    int numWords;
    infile >> numWords;
    set<string> wordList;
    for (int i = 0; i < numWords; i++){
        string currWord; 
        infile >> currWord;
        if (currWord.size() != size) continue;  //Words that have different length than start/end work are inapplicable

        //Make everything upper-case so that < operator will work appropriately
        for (unsigned int j = 0; j < currWord.size(); j++){
            currWord[j] = toupper(currWord[j]);
        }   
        wordList.insert(currWord);
    }
    return wordList;
}

int getHeuristic(string word1, string word2){
    int h = 0;
    for (unsigned int i = 0; i < word1.size(); i++){
        if (word1[i] != word2[i]) h++;  //Counts number of letters which do not match letter in same position in endWord
    }
    return h;
}

map<string, set<string>> buildGraph(set<string>& data){
    map<string, set<string>> graph;
    for (auto it = data.begin(); it != data.end(); ++it){
        set<string> neighbors;
        //For every letter of the word, try replacing it with every uppercase English letter
        for (unsigned int i = 0; i < (*it).size(); i++){
            string currWord = *it;
            for (int j = 65; j <= 90; j++){
                currWord[i] = static_cast<char>(j);
                //Make sure the modified word is in the word bank and is not the same as the original word
                if (currWord != *it && data.find(currWord) != data.end()){
                    neighbors.insert(currWord);
                }
            }
        }
        graph[*it] = neighbors;
    }
    return graph;
}

void graphSearch(map<string, set<string>>& graph, string start, string end){
    MinHeap<string> heap(2);
    set<string> removed;
    map<string, int> g; //Stores the number of moves since the start state
    map<string, int> p; //Stores the priority of a node in the heap

    p[start] = getHeuristic(start, end) * (start.size() + 1) + getHeuristic(start, end);
    heap.add(start, p[start]);
    g[start] = 0;
    int expansions = 0;

    while (!heap.isEmpty()){
        string curr = heap.peek();
        if (curr == end){
            cout << g[curr] << endl << expansions << endl;
            return;
        }

        /*Since priorities are updated by re-adding the node, it is necessary
        to check the node removed from the heap has not already been removed*/
        while (removed.find(curr) != removed.end() && !heap.isEmpty()){
            heap.remove();
            if (!heap.isEmpty()) curr = heap.peek();
        }
        if (heap.isEmpty()){
            cout << "No transformation" << endl << expansions << endl;
            return;
        } 
        heap.remove();
        removed.insert(curr);
        expansions++;

        //Iterate through all words within one letter of the current word
        for (auto it = graph[curr].begin(); it != graph[curr].end(); ++it){
            int priority = (start.size() + 1) * (g[curr] + 1 + getHeuristic(*it, end)) + getHeuristic(*it, end);
            //Make sure word is undiscovered, or a shorter path to the word has been discovered
            if (g.find(*it) == g.end() || p[*it] > priority){
                heap.add(*it, priority);
                g[*it] = g[curr] + 1; 
                p[*it] = priority;
            }
        }
    }
    cout << "No transformation" << endl << expansions << endl;
}
