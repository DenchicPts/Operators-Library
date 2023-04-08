#include "DenchicPts.h"

int main() {
    setlocale(LC_ALL, "lv_LV.UTF-8");
    string punctuation = ",./\'\";:?&^*(){}[]$#@!<>-=+";

    string filename = "text.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл" << endl;
        return 0;
    }
    map<string, int> word_counts = wordCounter(file, punctuation);
    file.close();

    vector<pair<string, int>> word_freq(word_counts.begin(), word_counts.end()); //

    sort(word_freq.begin(), word_freq.end(), [](auto const& p1, auto const& p2) {
        return p1.second > p2.second; // лямбда функция не обязательно, можно написать просто функцию
        });

    cout << "Top 5 words" << endl;
    for (int i = 0; i < 5 && i < word_freq.size(); ++i) {
        cout << word_freq[i].first << ": " << word_freq[i].second << endl; // Выводим ассоциативный массив
    }
    return 0;
}

map<string, int> wordCounter(ifstream& file, string& punctuation)
{
    map<string, int> word_counts;
    string word;
    while (file >> word) {
        // Пропускаем слова, короче 4 символов
        if (word.length() < 4) {
            continue;
        }
        // Удаляем знаки препинания из слова
        for (char const& c : punctuation) {
            word.erase(remove(word.begin(), word.end(), c), word.end());
            // Удаляем символ c из строки word с помощью функции remove
            // и затем удаляем символы, которые были перемещены в конец диапазона, с помощью метода erase
        }
        // Увеличиваем счетчик для данного слова
        ++word_counts[word];
    }
    return word_counts;
}
