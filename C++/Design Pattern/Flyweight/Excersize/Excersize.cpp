// Excersize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Sentence
{
    struct WordToken
    {
        bool capitalize;
    };

    WordToken* wordToken{ nullptr };

    Sentence(const string& text): plain_text{text}
    {          
        string word;
        stringstream iss(plain_text);
        while (iss >> word)
            formmating.push_back({ false });
    }

    WordToken& operator[](size_t index)
    {
        return formmating[index];
    }

    string str() const
    {
        string formatted_string{};
        string word;
        stringstream iss(plain_text);
        int index{ 0 };
        while (iss >> word)
        { 
            if (formmating[index].capitalize) {
                for (int i = 0; i < word.length(); i++)
                    word[i] = toupper(word[i]);
            }
            formatted_string += word;
            formatted_string += " ";
            index++;
        }    
        formatted_string = formatted_string.substr(0, formatted_string.length() - 1);
        return formatted_string;
    }
    ~Sentence()
    {
        delete wordToken;
    }
private :
    std::string plain_text;
    std::vector<WordToken> formmating;
};

int main()
{
    Sentence sentence("hello world");
    sentence[1].capitalize = true;
    cout << sentence.str(); // prints "hello WORLD"
}

