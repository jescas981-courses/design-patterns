#include <iostream>
#include <string>
#include <vector>

class FormattedText {
    std::string plain_text;
    bool *caps;

   public:
    FormattedText(const std::string &plain_text) : plain_text(plain_text) {
        caps = new bool[plain_text.length()]();
    }
    void capitalize(int start, int end) {
        for (int i = start; i <= end; i++) caps[i] = true;
    }
    ~FormattedText() { delete[] caps; }
    friend std::ostream &operator<<(std::ostream &os,
                                    const FormattedText &ftt) {
        std::string s;
        for (size_t i = 0; i < ftt.plain_text.length(); i++) {
            char c = ftt.plain_text[i];
            s += (ftt.caps[i] ? toupper(c) : c);
        }
        return os << s;
    }
};

class BetterFormattedText {
   public:
    struct TextRange {
        int start, end;
        bool capitalize;
        bool covers(int position) const {
            return start <= position && position <= end;
        }
    };

    BetterFormattedText(const std::string &plain_text)
        : plain_text(plain_text) {}

    TextRange &get_range(int start, int end) {
        formatting.emplace_back(TextRange{start, end});
        return *formatting.rbegin();
    }

    friend std::ostream &operator<<(std::ostream &os,
                                    const BetterFormattedText &bfft) {
        std::string s;
        for (size_t i = 0; i < bfft.plain_text.length(); i++) {
            char c = bfft.plain_text[i];
            for (const auto &rng : bfft.formatting) {
                if (rng.covers(i) && rng.capitalize) c = toupper(c);
                s += c;
            }
        }
        return os << s;
    }

   private:
    std::string plain_text;
    std::vector<TextRange> formatting;
};

int main(int argc, char const *argv[]) {
    FormattedText fft{"This is a brave world"};
    fft.capitalize(10, 15);
    std::cout << fft << std::endl;

    BetterFormattedText bfft{"This is a brave new world"};
    bfft.get_range(10, 15).capitalize = true;
    std::cout << bfft << std::endl;
}
