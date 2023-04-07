#include "DenchicPts.h"

map<string, int> count_words(string const& str, const string& punctutation) {

    map<string, int> word_counts;
    string word;
    stringstream stream(str);
    while (stream >> word) {
        // Исключаем слова, короче 4 символов
        if (word.length() < 4) {
            continue;
        }
        // Удаляем знаки препинания из слова
        for (char const& c : punctutation) {
            word.erase(remove(word.begin(), word.end(), c), word.end());
        }
        // Увеличиваем счетчик для данного слова
        ++word_counts[word];
    }
    return word_counts;
}

void main() {
    setlocale(LC_ALL, "lv_LV.UTF-8");
	string punctutation = ",./\'\";:?&^*(){}[]$#@!<>-=+";
	const string filename = "text.txt";
	vector<string> vardi;

	ifstream file(filename);
	stringstream buffer;
	buffer << file.rdbuf();
	string content = buffer.str();

    map<string, int> word_counts = count_words(content, punctutation);
    vector<pair<string, int>> word_freq(word_counts.begin(), word_counts.end());

    sort(word_freq.begin(), word_freq.end(), [](auto const& p1, auto const& p2) {
        return p1.second > p2.second;
        });


    cout << "Vardi:" << endl;
    for (int i = 0; i < min(5, static_cast<int>(word_freq.size())); ++i) {
        cout << word_freq[i].first << ": " << word_freq[i].second << endl;
    }
	return;
}
