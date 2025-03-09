#include "ladder.h"

void error(string word1, string word2, string msg) {
    std::cout << word1 << msg << word2;
}

/*
bool edit_distance_within(const std::string &str1, const std::string &str2, int d) {
}

bool is_adjacent(const string &word1, const string &word2) {
}*/

vector<string> generate_word_ladder(const string &begin_word, const string &end_word, const set<string> &word_list) {
    // if the end word is not in the word list
    if (word_list.find(end_word) == word_list.end()) return vector<string>();

    queue<string> next_word;
    map<string, string> current_prev;
    set<string> visited;

    next_word.push(begin_word);
    visited.insert(begin_word);
    while (!next_word.empty()) {
        string current_word = next_word.front();
        next_word.pop();

        if (current_word == end_word) {
            vector<string> path;

            string current_word_in_path = end_word;
            while (current_word_in_path != begin_word) {
                path.insert(path.begin(), 1, current_word_in_path);
                current_word_in_path = current_prev[current_word_in_path];
            }
            path.insert(path.begin(), 1, begin_word);

            return path;
        }

        unsigned int current_word_len = current_word.size();

        if (current_word_len < end_word.size()) {
            // the current word is smaller than the end word
            for (unsigned int i = 0; i <= current_word_len; ++i) {
                // add new letter
                for (unsigned int letter = 'a'; letter <= 'z'; ++letter) {
                    string new_word_candidate = current_word;
                    new_word_candidate.insert(i, 1, static_cast<char>(letter));
                    // if it is a valid word that has not been seen, add it to the next_word queue
                    if (word_list.find(new_word_candidate) != word_list.end() && visited.find(new_word_candidate) ==
                        visited.end()) {
                        next_word.push(new_word_candidate);
                        current_prev[new_word_candidate] = current_word;
                        visited.insert(new_word_candidate);
                    }
                }
            }
        } else if (current_word_len > end_word.size()) {
            // the current word is larger than the end word
            for (unsigned int i = 0; i < current_word_len; ++i) {
                string new_word_candidate = current_word;
                new_word_candidate.erase(i, 1);
                // if it is a valid word that has not been seen, add it to the next_word queue
                if (word_list.find(new_word_candidate) != word_list.end() && visited.find(new_word_candidate) ==
                    visited.end()) {
                    next_word.push(new_word_candidate);
                    current_prev[new_word_candidate] = current_word;
                    visited.insert(new_word_candidate);
                }
            }
        }

        // replace existing letter
        for (unsigned int i = 0; i < current_word_len; ++i) {
            for (unsigned int letter = 'a'; letter <= 'z'; ++letter) {
                string new_word_candidate = current_word;
                new_word_candidate[i] = static_cast<char>(letter);
                // if it is a valid word that has not been seen, add it to the next_word queue
                if (word_list.find(new_word_candidate) != word_list.end() && visited.find(new_word_candidate) ==
                    visited.end()) {
                    next_word.push(new_word_candidate);
                    current_prev[new_word_candidate] = current_word;
                    visited.insert(new_word_candidate);
                }
            }
        }
    }

    return vector<string>();
}

void load_words(set<string> &word_list, const string &file_name) {
    ifstream in(file_name);
    string word;
    while (getline(in, word)) {
        word_list.insert(word);
    }
    in.close();
}

void print_word_ladder(const vector<string> &ladder) {
    for (const string &word: ladder) std::cout << word << ' ';
}

/*
void verify_word_ladder() {
}
*/
