#include "XmlParser.hpp"

XmlParser::XmlParser(string name) : filename(name) {

}

XmlParser::~XmlParser() {

}

List* XmlParser::parse() {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename.c_str());
    List* rootList = NULL;

    tinyxml2::XMLElement* root = doc.FirstChildElement( "listes" );
    if(!root->NoChildren()) {
       rootList = buildList(root, &tasks);
    }
    return rootList;
}

List* XmlParser::buildList(tinyxml2::XMLElement* current_element, vector<Task*>* tasks) {
    // Creation of the list
    const char* listName = current_element->Attribute("nom");
    if(listName == NULL) {
        listName = "";
    }
    bool orderedList = (current_element->Attribute("ordonnee", "oui") == 0);

    Time* time = buildDate(current_element);
    List* newList = new List(string(listName), time, orderedList);

    if (!current_element->NoChildren()) {
        // Build of the vector of lists
        tinyxml2::XMLElement* child_element = current_element->FirstChildElement("liste");
        while (child_element != NULL) {
            newList->addSubList(buildList(child_element, tasks));
            child_element = child_element->NextSiblingElement("liste");
        }

        // Build of the vector of tasks
        child_element = current_element->FirstChildElement("tache");
        while (child_element != NULL) {
            const char* taskName = child_element->Attribute("nom");
            if(taskName == NULL) {
                taskName = "";
            }

            Time* taskDate = buildDate(child_element);
            Task* newTask = new Task(string(taskName), taskDate);
            tasks->push_back(newTask);
            newTask = buildRelativeDate(child_element, tasks);
            newList->addTask(newTask);
            child_element = child_element->NextSiblingElement("tache");
        }
    }
    return newList;
}

Time* XmlParser::buildDate(tinyxml2::XMLElement* current_element) {
    int day = 1;
    int month = 1;
    int year = 1970;
    if (current_element != NULL) {
        tinyxml2::XMLElement* date_element = current_element->FirstChildElement("date");
        if (current_element->Attribute("absolue", "oui") == 0) {
            if (date_element != NULL) {
                const char* date_t = date_element->GetText();
                if (date_t != NULL) {
                    string dateString(date_t);
                    int pos = dateString.find('/');
                    day = atoi(dateString.substr(0, pos).c_str());
                    int pos2 = dateString.find('/', pos+1);
                    month = atoi(dateString.substr(pos+1, pos2-3).c_str());
                    year = atoi(dateString.substr(pos2+1).c_str());
                }
            }
        }
    }
    return new Time(0, 0, day, month, year);
}

Task* XmlParser::buildRelativeDate(tinyxml2::XMLElement* current_element, vector<Task*>* tasks) {
    Task* lastTask = tasks->back();

    int delay = 0;
    Task* reference = NULL;//new Task("", new Time());

    // Build delay with date attribute
    if (current_element != NULL) {
        tinyxml2::XMLElement* date_element = current_element->FirstChildElement("date");
        const char* absolute = date_element->Attribute("absolue");
        if (absolute != NULL) {
            if (strcmp(absolute, "non") == 0) {
                if (date_element != NULL) {
                    const char* date_t = date_element->GetText();
                    if (date_t != NULL) {
                        string dateString(date_t);
                        delay = atoi(dateString.c_str());
                    }

                    // Build task reference for relative task
                    const char* attributeReference_t = date_element->Attribute("reference");
                    if (attributeReference_t != NULL) {
                        string attributeReference(attributeReference_t);
                        for (int i = 0; i < tasks->size(); i ++) {
                            if (tasks->at(i)->getName().compare(attributeReference) == 0) {
                               reference = tasks->at(i);
                            }
                        }
                    }
                }
            }
        }
    }

    if (reference != NULL) {
        lastTask->setRelativeDate(reference, delay);
    }

    return lastTask;
}
