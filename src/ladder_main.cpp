#include "ladder.h"

int main() {
    set<string> word_list;

    load_words(word_list, "src/words.txt");
    vector<string> word_ladder = generate_word_ladder("cat", "kit", word_list);
    print_word_ladder(word_ladder);

    //cout << edit_distance_within("cat", "sat", 0) << endl;

    return 0;
}