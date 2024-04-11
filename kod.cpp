#include<iostream> 
#include<string> 
#include<map> 

using namespace std;

map<char, string> Morze = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."},
    {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."},
    {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"},
    {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."},
    {'d', "-.."}, {'e', "."}, {'f', "..-."},
    {'g', "--."}, {'h', "...."}, {'i', ".."},
    {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."},
    {'m', "--"}, {'n', "-."}, {'o', "---"},
    {'p', ".--."}, {'q', "--.-"}, {'r', ".-."},
    {'s', "..."}, {'t', "-"}, {'u', "..-"},
    {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
    {'y', "-.--"}, {'z', "--.."}
};
string getMorzeLetter(char ch) {
    auto it = Morze.find(ch);

    if (it != Morze.end()) {
        return it->second;
    }
    else {
        return string(1, ch);
    }
}

string getMorzeWord(string& word) {
    string morzeWord;
    for (char ch : word) {
        morzeWord += getMorzeLetter(ch) + " ";

    }
    return morzeWord;
}


string getMorzeString(string& input) {
    string cur;
    string morzeString;
    for (char ch : input) {
        if (ch == ' ') {
            morzeString += getMorzeWord(cur) + '/';
            cur = "";
        }
        else {
            cur += ch;
        }
    }
    if (cur.empty()) {
        morzeString += getMorzeWord(cur);
    }
    return morzeString;
}




int main() {
    string input;

    while (true) {
        cout << "Enter a phrase (or 'exit' to quit):";
        getline(cin, input);

        if (input == "exit") {
            break;
        }
        string result;
        result = getMorzeString(input);
        cout << "Morze code:" << result << endl;
    }

    return 0;
}