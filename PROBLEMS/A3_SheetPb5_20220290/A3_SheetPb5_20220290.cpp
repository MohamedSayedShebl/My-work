// File name:A3_SheetPb5_20220290
// Purpose:A program that can load and display processes from the process list of OS
// Author(s):Mohamed sayed shebl
// ID(s):20220290
// Section:S20
// Date:12/7/2023

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>


using namespace std;

class process{
private:
    string name;
    int PID;               //Process ID
    string memoryUsage;

public:
    //Constructor that gives the process its information
    process(string Name,int pid,string memoryusage): name(Name), PID(pid), memoryUsage(memoryusage){}

    //Default constructor
    process(){
        name="null";
        PID=0;
        memoryUsage="0 K";
    }

    //Function to display all information about a process to help with the process list
    void displayInfo(){
        int x = 23 - name.size();
        cout << name ;
        while(x!=0) {
            cout << " ";
            if(x<0)x++;
            else if(x>0)x--;
        }
        cout << PID;
        x = 15 - to_string(PID).size();
        while(x!=0) {
            cout << " ";
            if(x<0)x++;
            else if(x>0)x--;
        }
        cout<< memoryUsage << endl;

    }

    //Function to display name of a process
    void displayName(){
        cout << "Process's Name: " << name << endl;
    }

    //Function to display ID of a process
    void displayID(){
        cout << "Process's ID: " << PID << endl;
    }

    //Function to display memory usage of a process
    void displayMemoryUsage(){
        cout << "Process's memory usage: " << memoryUsage << endl;
    }

    //Getters to help with the sorting of the list
    string getName(){
        return name;
    }

    int getPID(){
        return PID;
    }
    //Converting the memory usage string to an integer to help with the sorting of the list
    int getMemoryUsage(){
        return stoi(memoryUsage);
    }

    //Overloading the = operator to help with the sorting
    process operator=(process const &other){
        this->name=other.name;
        this->PID=other.PID;
        this->memoryUsage=other.memoryUsage;
        return *this;
    }

};
class processList {
private:
    vector<process> list;
public:
    //Function to add a process to the process list
    void addProcess(process &p1) {
        list.push_back(p1);
    }

    //Function to display process list
    void displayList() {
        cout << "Process name          PID           Mem usage" << endl;
        cout << "=============================================" << endl;
        for (auto k: list) {
            k.displayInfo();
        }
    }

    // Function using sort to sort the list by names of processes in ascending order
    void sortByName() {
        sort(list.begin(), list.end(), [](process &a, process &b) {
            return a.getName() < b.getName();
        });
    }

    //Function to sort the list by the PID of the processes ascendingly
    void sortByPID(){
        vector<process>j(list.size());
        for(int i = 0 ; i < list.size() ; i++) {
            j[i]=list[i];
        }
        for(int k = 0 ; k < list.size() ; k++) {
            int x = 0, y = 0;
            while (y < j.size()) {
                if (j[x].getPID() > j[y].getPID())x = y;
                y++;
            }
            list[k]=j[x];
            j.erase(j.begin()+x);
        }

    }
    //Function to sort the list by the memory usage of the processes ascendingly
    void sortByMemoryUsage(){
        vector<process>j(list.size());
        for(int i = 0 ; i < list.size() ; i++) {
            j[i]=list[i];
        }
        for(int k = 0 ; k < list.size() ; k++) {
            int x = 0, y = 0;
            while (y < j.size()) {
                if (j[x].getMemoryUsage() > j[y].getMemoryUsage())x = y;
                y++;
            }
            list[k]=j[x];
            j.erase(j.begin()+x);
        }

    }

};

class ProcessLoader {
public:
    // Function to load process list from the operating system
    vector<process> getProcessesFromOS() {
        vector<process> processes;

        HANDLE hProcessSnap;
        PROCESSENTRY32 pe32;
        hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

        if (hProcessSnap == INVALID_HANDLE_VALUE) {
            return processes;
        }

        pe32.dwSize = sizeof(PROCESSENTRY32);

        if (!Process32First(hProcessSnap, &pe32)) {
            CloseHandle(hProcessSnap);
            return processes;
        }

        do {
            string name = pe32.szExeFile;
            string memoryUsage = "0K";
            process newProcess(name, pe32.th32ProcessID, memoryUsage);
            processes.push_back(newProcess);
        } while (Process32Next(hProcessSnap, &pe32));

        CloseHandle(hProcessSnap);

        return processes;
    }
};

int main(){
    processList sd;
    ProcessLoader loader;
    vector<process> processesFromOS = loader.getProcessesFromOS();
    for (auto &p : processesFromOS) {
        sd.addProcess(p);
    }
    sd.sortByName();
    sd.displayList();
    return 0;
}