#include "XmlWriter.hpp"

XmlWriter::XmlWriter(string filename) : fileName(filename){

}

XmlWriter::~XmlWriter() {

}

void XmlWriter::saveModel(vector<List*> rootElements) {
    tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();

    //
    tinyxml2::XMLDeclaration* xmlDeclaration = doc->NewDeclaration(XML_DECLARATION);
    doc->InsertFirstChild(xmlDeclaration);

    // Build xml document
    tinyxml2::XMLElement* parentElement = doc->NewElement("listes");
    doc->InsertEndChild(parentElement);
    if (rootElements.size() >= 1) {
        for (int i = 0; i < rootElements.size(); i++) {
            tinyxml2::XMLElement* currentElement = buildXmlTree(doc, rootElements[i]);
            buildListAttributes(doc, currentElement, rootElements[i]);
            parentElement->InsertEndChild(currentElement);
        }
    }

    // Save xml document in the file
    doc->SaveFile(fileName.c_str());
}

tinyxml2::XMLElement* XmlWriter::buildXmlTree(tinyxml2::XMLDocument* doc, List* currentList) {
    tinyxml2::XMLElement* element = NULL;
    if (currentList != NULL) {
        element = doc->NewElement("liste");

        // Build list part of the xml document
        vector<List*> listChildren = currentList->getAllLists();
        for (int i = 0; i < listChildren.size(); i++) {
            tinyxml2::XMLElement* child = buildXmlTree(doc, listChildren.at(i));
            // Set all node attributes
            buildListAttributes(doc, child, listChildren.at(i));
            element->InsertEndChild(child);
        }

        // Build task part of the xml document
        vector<Task*> taskChildren = currentList->getAllTasks();
        for (int i = 0; i < taskChildren.size(); i++) {
            tinyxml2::XMLElement* child = doc->NewElement("tache");
            string taskName = taskChildren.at(i)->getName();
            child->SetAttribute("nom", taskName.c_str());

            char* boolean = "non";
            if (taskChildren.at(i)->isFinished()) {
                boolean = "oui";
            }
            child->SetAttribute("terminee", boolean);


            // Set the date
            tinyxml2::XMLElement* dateChild = doc->NewElement("date");
            string dateString;
            if (taskChildren.at(i)->isDeadlineRelative()) {
                boolean = "oui";
                dateString = taskChildren.at(i)->getDeadline()->getXmlDate().c_str();
            } else {
                boolean = "non";
                std::stringstream out;
                out << taskChildren.at(i)->getDayInterval();
                dateString = out.str();

                vector<Task*> references = taskChildren.at(i)->getRequiredTasks();
                const char* nameReference = "";
                if (references.size() > 0) {
                    nameReference = references[0]->getName().c_str();
                    dateChild->SetAttribute("reference", nameReference);
                }
            }
            // Set other attributes
            dateChild->SetAttribute("absolue", boolean);
            tinyxml2::XMLText* dateTask = doc->NewText(dateString.c_str());
            dateChild->InsertFirstChild(dateTask);
            child->InsertEndChild(dateChild);
            element->InsertEndChild(child);
        }
    }
    return element;
}

void XmlWriter::buildListAttributes(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* currentElement, List* currentList) {
    // Set all node attributes
    const char* listName = currentList->getName().c_str();
    currentElement->SetAttribute("nom", listName);
    char* boolean = "non";
    if (currentList->isOrdered()) {
        boolean = "oui";
    }
    currentElement->SetAttribute("ordonnee", boolean);
    // Set the date
    tinyxml2::XMLElement* dateChild = doc->NewElement("date");
    dateChild->SetAttribute("absolue", "oui");
    tinyxml2::XMLText* dateList = doc->NewText(currentList->getDate()->getXmlDate().c_str());
    dateChild->InsertFirstChild(dateList);
    currentElement->InsertEndChild(dateChild);
}
