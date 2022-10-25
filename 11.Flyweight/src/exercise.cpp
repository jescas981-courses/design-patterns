#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
using namespace std;

struct Sentence {
    const std::string text;
    struct WordToken {
        bool capitalize;
        int start, end;
        bool covers() {}
        WordToken(int start, int end) : start(start), end(end) {}
    };
    std::vector<WordToken> words;

    Sentence(const string& text) : text(text) {
        int i = 0;
        while (text[i] == ' ') i++;
        for (; i < text.length(); i++) {
            words.push_back({});
            while (text[i] == ' ') i++;
        }
    }

    WordToken& operator[](size_t index) {
        // todo
    }

    string str() const {
        // todo
    }
};