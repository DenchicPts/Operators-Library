#include "DenchicPts.h"

int main() {
    setlocale(LC_ALL, "lv_LV.UTF-8");
    string punctuation = ",./\'\";:?&^*(){}[]$#@!<>-=+";

    string filename = "text.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "�� ������� ������� ����" << endl;
        return 0;
    }
    map<string, int> word_counts = wordCounter(file, punctuation);
    file.close();

    vector<pair<string, int>> word_freq(word_counts.begin(), word_counts.end()); //

    sort(word_freq.begin(), word_freq.end(), [](auto const& p1, auto const& p2) {
        return p1.second > p2.second; // ������ ������� �� �����������, ����� �������� ������ �������
        });

    cout << "Top 5 words" << endl;
    for (int i = 0; i < 5 && i < word_freq.size(); ++i) {
        cout << word_freq[i].first << ": " << word_freq[i].second << endl; // ������� ������������� ������
    }
    return 0;
}

map<string, int> wordCounter(ifstream& file, string& punctuation)
{
    map<string, int> word_counts;
    string word;
    while (file >> word) {
        // ���������� �����, ������ 4 ��������
        if (word.length() < 4) {
            continue;
        }
        // ������� ����� ���������� �� �����
        for (char const& c : punctuation) {
            word.erase(remove(word.begin(), word.end(), c), word.end());
            // ������� ������ c �� ������ word � ������� ������� remove
            // � ����� ������� �������, ������� ���� ���������� � ����� ���������, � ������� ������ erase
        }
        // ����������� ������� ��� ������� �����
        ++word_counts[word];
    }
    return word_counts;
}
