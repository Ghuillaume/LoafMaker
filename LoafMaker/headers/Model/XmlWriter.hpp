#ifndef XMLWRITER_HPP
#define XMLWRITER_HPP

#include <string>
#include <iostream>

#include "libs/tinyxml2/tinyxml2.h"
#include "List.hpp"

#define XML_DECLARATION "xml version=\"1.0\" standalone=\"yes\" encoding=\"UTF-8\" "

using namespace std;

class XmlWriter {
public:
    XmlWriter(string filename);
    ~XmlWriter();

    void saveModel(vector<List*> rootElements);

private:
    string fileName;

    tinyxml2::XMLElement* buildXmlTree(tinyxml2::XMLDocument* doc, List* currentList);
    void buildListAttributes(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* currentElement, List* currentList);
};

#endif
