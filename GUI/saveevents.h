#ifndef SAVEEVENTS_H
#define SAVEEVENTS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

struct Event {
    char name_of_event[50];
    char start_time[25];
    char end_time[25];
};

class EventData {
private:
    char name_of_event[50];
    char start_time[25];
    char end_time[25];
public:
    EventData() { }
    ~EventData() { }

    void SetData(string str_name, string str_start, string str_end) {
        sprintf(this->name_of_event, "%s", str_name.c_str());
        sprintf(this->start_time, "%s", str_start.c_str());
        sprintf(this->end_time, "%s", str_end.c_str());
    }
    void Save(ofstream &of) {
        of.write(static_cast<char*>(name_of_event), sizeof(name_of_event));
        of.write(static_cast<char*>(start_time), sizeof(start_time));
        of.write(static_cast<char*>(end_time), sizeof(end_time));
    }
    void WriteBinaryFile(string str_file) {
        ofstream fs;
        fs.open(str_file, ios::out | ios::binary | ios::app);
        if (!fs.is_open()) {
            cout << "cannot open file" << str_file << endl;
        }
        else {
            this->Save(fs);
        }
        fs.close();
    }
    void ReadBinaryFile(string str_file) {
        Event event;
        ifstream binary_file;
        int size = 0;
        binary_file.open(str_file, ios::in | ios::binary);
        if (!binary_file.is_open()) {
            cout << "cannot open file" << str_file << endl;
        }
        binary_file.seekg(0, ios::end);
        size = static_cast<int>(binary_file.tellg());
        binary_file.seekg(0, ios::beg);
        while (binary_file.tellg() < size) {
            binary_file.read(static_cast<char*>(event.name_of_event), sizeof(event.name_of_event));
            binary_file.read(static_cast<char*>(event.start_time), sizeof(event.start_time));
            binary_file.read(static_cast<char*>(event.end_time), sizeof(event.end_time));
            cout << event.name_of_event << "\t" << event.start_time << "\t" << event.end_time <<  endl;
        }
        binary_file.close();
    }
};
#endif // SAVEEVENTS_H
