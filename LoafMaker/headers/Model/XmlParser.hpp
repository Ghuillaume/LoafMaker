#ifndef XMLPARSER_HPP
#define XMLPARSER_HPP

#include <string>
#include <iostream>

#include "libs/tinyxml2/tinyxml2.h"
#include "List.hpp"
#include "Time.hpp"

using namespace std;

class XmlParser {
public:
    string filename;

    XmlParser(string name);
    ~XmlParser();

    List* parse();
    List* buildList(tinyxml2::XMLElement* current_element);

private:
    Time* buildDate(tinyxml2::XMLElement* current_element);
};

#endif
