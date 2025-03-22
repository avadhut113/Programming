// Static_Stratergy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Dynamic_Stratergy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

enum class OutPutFormat
{
    markdown,
    html
};

class ListStratergy
{
public:
    virtual void start(std::ostringstream& os) {};
    virtual void add_list_item(std::ostringstream& os, std::string& item) = 0;
    virtual void end(std::ostringstream& os) {};
};

class MarkdownListStratergy : public ListStratergy
{
public:
    void add_list_item(std::ostringstream& oss, std::string& item) override {
        oss << "*" << item << "\n";
    }
};

class HtmlListStratergy : public ListStratergy
{
public:
    void start(std::ostringstream& oss) override {
        oss << "<ul>\n";
    }
    void end(std::ostringstream& oss) override {
        oss << "</ul>\n";
    }
    void add_list_item(std::ostringstream& oss, std::string& item) override {
        oss << "   " << item << "\n";
    }
};

template<class LS>
class textProcessor
{
public:
    void clear() {
        text.str("");
        text.clear();
    }

    void append_list(const std::vector<std::string>& items) {
        list_stratergy.start(text);
        for (std::string item : items) {
            list_stratergy.add_list_item(text, item);
        }
        list_stratergy.end(text);
    }

    std::string str() {
        return text.str();
    }

private:
    std::ostringstream text;
    LS list_stratergy;
};

int main()
{
    std::vector<std::string> list_items{ "Pune","Kolhapur","Satara","Sangli" };
    textProcessor<MarkdownListStratergy> doc;
    doc.append_list(list_items);
    std::cout << doc.str() << std::endl;

    textProcessor<HtmlListStratergy> doc1;
    doc1.append_list(list_items);
    std::cout << doc1.str() << std::endl;

}
