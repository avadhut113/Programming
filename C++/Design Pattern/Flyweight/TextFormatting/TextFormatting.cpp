// TextFormatting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ostream>
#include <vector>

class Formattedtext
{
    std::string plain_text;
    bool* caps;
public:
    Formattedtext(const std::string& text) : plain_text(text) {
        caps = new bool[plain_text.length()];
        memset(caps, 0, plain_text.length());
    }

    ~Formattedtext() {
        delete[] caps;
    }

    void capitalize(int start, int end) {
        for (int i = start; i <= end; i ++ ) {
            caps[i] = true;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, Formattedtext& text) {
        std::string str;
        for (int i = 0; i < text.plain_text.length(); i++) {
            char c = text.plain_text[i];
            str += (text.caps[i] ? toupper(c) : c);
        }
        return os << str;
    }
};

class BetterFormattedText
{
public:
    struct TextRange {
        int start, end;
        bool capitalize;

        bool covers(int position) const {
            return position >= start && position <= end;
        }
    };

    TextRange& GetRange(int start, int end) {
        formmating.emplace_back(TextRange{ start,end });
        return *formmating.rbegin();
    }

    BetterFormattedText(const std::string& text) : plain_text(text) {
         
    }

    friend std::ostream& operator<<(std::ostream& os, BetterFormattedText& text) {
        std::string str;
        for (int i = 0; i < text.plain_text.length(); i++) {
            auto c = text.plain_text[i];
            for (const auto& rang : text.formmating) {
                if (rang.covers(i) && rang.capitalize) {
                    c = toupper(c);
                }
                str += c;
            }
        }
        return os << str;
    }

private:
    std::string plain_text;
    std::vector<TextRange> formmating;
};

int main()
{
    Formattedtext text("Megha Avadhut Patil");
    text.capitalize(7, 14);
    std::cout << text << std::endl;

    BetterFormattedText bftext("Megha Avadhut Patil");
    bftext.GetRange(7, 14).capitalize = true;
    std::cout << bftext << std::endl;
}

