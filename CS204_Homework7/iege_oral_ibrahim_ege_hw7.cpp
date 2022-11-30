#include <iostream>
#include <random>
#include <time.h>
#include <chrono>
#include <string>
#include <cstring>
#include <ctime>
#include <mutex>
#include <thread>
#include "iege_oral_ibrahim_ege_hw7_myfuncs.h"
using namespace std;
// ege
// cs204 29299
//Functions
void getInputs(int &maxPrintJobs,int &minTime,int &maxTime,int &minPage,int &maxPage);
int random_range(const int &min, const int &max);
string getTime();

//Thread functions
void userThread(const int userId,const int &minTime,const int &maxTime,const int &minPage,const int &maxPage);
void printerThread();

//GLobal variables
int maxPrintJobs;
int currentJob = 0;
int printedJob = 0;
HW7PrintQueue printQueue;
mutex queueMutex,outputMutex;

int main(){
    int minTime,maxTime,minPage,maxPage;
    getInputs(maxPrintJobs,minTime,maxTime,minPage,maxPage);
    cout << "Simulation starts: " << getTime() << endl;
    
    //Creating the threads
    thread users[3],printer;
    for(int i=0;i<3;i++) users[i] = thread(userThread,i+1,minTime,maxTime,minPage,maxPage);
    printer = thread(printerThread);
    
    //Joininig threads
    for(int i=0;i<3;i++) users[i].join();
    printer.join();
    cout << "End of the simulation ends " << getTime() << endl;

    return 0;
}

//Getting all the inputs from user
void getInputs(int &maxPrintJobs,int &minTime,int &maxTime,int &minPage,int &maxPage){
    cout << "Please enter the max number of print jobs: ";
    cin >> maxPrintJobs;
    cout << "Please enter the min and max values for the waiting time period (in seconds) after creating a print job:" << endl;
    cout << "Min: ";
    cin >> minTime;
    cout << "Max: ";
    cin >> maxTime;
    cout << "Please enter the min and max values for the number of pages in a print job:" << endl;
    cout << "Min number of pages: ";
    cin >> minPage;
    cout << "Min number of pages: ";
    cin >> maxPage;
}

//Random function provided in pdf
int random_range(const int & min, const int & max) {
    static mt19937 generator(time(0));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

//Getting current time
string getTime(){
    chrono::system_clock::time_point nowTime = chrono::system_clock::now();
    time_t sleepTime = chrono::system_clock::to_time_t(nowTime);
    char* rtr = std::ctime(&sleepTime);
    
    //parsing the time string to aqquire hour minute second information
    strtok(rtr," ");
    strtok(NULL," ");
    strtok(NULL," ");
    return strtok(NULL," ");;
}

//User thread function
void userThread(const int userId,const int &minTime,const int &maxTime,const int &minPage,const int &maxPage){
    //Sleeping before producing 
    this_thread::sleep_for(chrono::seconds(random_range(minTime,maxTime)));
    while(true){
        
        //-- Critical section --
        queueMutex.lock();
        if(currentJob >= maxPrintJobs){
            queueMutex.unlock();
            return;
        }
        int numPage = random_range(minPage,maxPage);
        printQueue.enqueue(++currentJob,numPage);
        queueMutex.unlock();
        //-- Critical section --
        
        //Using a dedicated mutex to prevent outputs from mixing
        outputMutex.lock();
        cout << "User " << userId << " sent new print job with ID " << currentJob << " sent to the printer queue, number of pages: "
            <<  numPage <<  "(print queue size: " << printQueue.getCurrentSize() << ") " << getTime() << endl;
        outputMutex.unlock();
        this_thread::sleep_for(chrono::seconds(random_range(minTime,maxTime)));
    }
}

void printerThread(){
    while(true){
        //If queue is not empty, dequeue and print
        if(!printQueue.isEmpty()){
            int id,numPage;
            
            //-- Critical section --
            queueMutex.lock();
            printQueue.dequeue(id,numPage);
            queueMutex.unlock();
            //-- Critical section --
            
            //Using a dedicated mutex to prevent outputs from mixing
            outputMutex.lock();
            cout << "The printer started to print the job with ID: " << id << ", number of pages: " << numPage 
            << "(queue size is: " << printQueue.getCurrentSize() << ")" << getTime() << endl;
            outputMutex.unlock();
            for(int i=0;i<numPage;i++) this_thread::sleep_for(chrono::seconds(1));
            
            //Using a dedicated mutex to prevent outputs from mixing
            outputMutex.lock();
            cout << "The printer finished to print the job with ID: " << id << ", number of pages: " << numPage 
            << " " <<  getTime() << endl;
            outputMutex.unlock();
            printedJob++;
        }
        //If all the jobs are printed finishing the thread
        else if(printedJob >= maxPrintJobs) return;
    }
}
