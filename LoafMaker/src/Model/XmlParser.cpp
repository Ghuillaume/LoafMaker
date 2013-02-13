#include "XmlParser.hpp"

XmlParser::XmlParser(string name) : filename(name) {

}

XmlParser::~XmlParser() {

}

void XmlParser::parse() {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename.c_str());

    cout << "Test" << endl;

    tinyxml2::XMLElement* root = doc.FirstChildElement( "listes" );
    if(!root->NoChildren()) {
        buildList(root);
    }
}

List* XmlParser::buildList(tinyxml2::XMLElement* current_element) {
    // Creation of the list
    const char* listName = current_element->Attribute("nom");
    if(listName == NULL) {
        listName = "";
    }
    cout << "liste : " << listName << endl;

    bool orderedList = (current_element->Attribute("ordonnee", "oui") == 0);

    tinyxml2::XMLElement* date_element = current_element->FirstChildElement("date");
    if (date_element != NULL) {
        if (date_element->Attribute("absolue", "oui") == 0) {
            // TODO : traiter date
        } else {
            // TODO : traiter date
        }
    }

    Time* time = new Time(1,1,1,1,1970);
    List* newList = new List(string(listName), time, orderedList);

    if (!current_element->NoChildren()) {
        // Build of the vector of lists
        tinyxml2::XMLElement* child_element = current_element->FirstChildElement("liste");
        while (child_element != NULL) {
            newList->addSubList(buildList(child_element));
            child_element = child_element->NextSiblingElement("liste");
        }
        // Build of the vector of tasks
        child_element = current_element->FirstChildElement("tache");
        while (child_element != NULL) {
            // TODO : gérer les dates
            const char* taskName = child_element->Attribute("nom");
            if(taskName == NULL) {
                taskName = "";
            }
            cout << "tache : " << taskName << endl;
            newList->addTask(new Task(string(taskName), time));
            child_element = child_element->NextSiblingElement("tache");
        }
    }


    return newList;
}
