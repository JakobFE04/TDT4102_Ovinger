#include "CourseCatalog.h"
#include <filesystem>


// BEGIN: 3a
void CourseCatalog::addCourse(const string& key, const string& value){
    CourseCatalog::courses.insert({key, value});
    //CourseCatalog::courses[key]=value;
}
// END: 3a

// BEGIN: 3b
void CourseCatalog::removeCourse(const string& key){
    CourseCatalog::courses.erase({key});
}
// END: 3b

// BEGIN: 3c
string CourseCatalog::getCourse(const string& key) const{
    return CourseCatalog::courses.at(key);
}
// END: 3c

// BEGIN: 3d
ostream& operator<<(ostream& os, const CourseCatalog& cc){
    vector<string> keys;
    for (auto it = cc.courses.begin(); it != cc.courses.end(); ++it){
        keys.push_back(it->first);
    }
    for (int i = 0; i < keys.size(); i++){
        os << "Emnekode: " << keys.at(i) << " Emnenavn: " << cc.courses.at(keys.at(i)) << endl;
    }
    return os;
}
// END: 3d

// BEGIN: 3e
void testCourseCatalog(){
    CourseCatalog CC{};
    CC.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    CC.addCourse("TDT4100", "Informasjonsteknologi grunnkurs");
    CC.addCourse("TMA4100", "Matematikk 1");
    cout << CC << endl;
    /*CC.addCourse("TDT4102", "C++"); //3 f) .insert() endrer ikke noe mens operator gjør, men operator kan skape minnefeil som er bad. 
    //bedre måte å gjøre på ville vært å sjekke om det allerede ligger i mapet, også fjerne gamle og sette inn nye om så.
    cout << CC << endl;

    CC.saveToFile("Test.txt");
    CC.removeCourse("TDT4100");
    CC.removeCourse("TDT4102");
    CC.removeCourse("TMA4100");
    cout << "Removed" << endl;
    cout << CC << endl;
    CC.loadFromFile("Test.txt");
    cout << "Loaded" << endl;
    cout << CC << endl;*/
}
// END: 3e


// BEGIN: 3g
void CourseCatalog::saveToFile(const std::string& filename) const{
    filesystem::path fileName{filename};
    ofstream outputStream{fileName};
    vector<string> keys;
    for (auto it = courses.begin(); it != courses.end(); ++it){
        keys.push_back(it->first);
    }
    for (int i = 0; i < keys.size(); i++){
        outputStream << keys.at(i) << ":" << courses.at(keys.at(i)) << endl;
    }
}
// END: 3g

// BEGIN: 3h
void CourseCatalog::loadFromFile(const std::string& filename){
    ifstream inputStream(filename);
    if (!inputStream){
        cout << "Could not open file" << endl;
    }
    string nextLine;
    while(getline(inputStream, nextLine)){
            istringstream stringLine(nextLine);
            string key;
            string value;

            if (getline(stringLine, key, ':') && getline(stringLine, value)){
                courses.insert({key,value});
            }
    }
}

// END: 3h