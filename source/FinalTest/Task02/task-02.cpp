#include "task-02.h"
#include <fstream>
#include "List.h"
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

void processData()
{
    string fileName = "data.txt";
    ifstream data(fileName, ios::in);

    // Check that file can be properly open
    if (!data.is_open())
    {
        cerr << "ERROR: File not found." << endl;
        // And throw exception if it can not be opened
        throw runtime_error(string("Failed opening: ") + fileName);
    }

    cout << "\nStart reading your data...\n" << endl;
    int recordCounter = 0;

    const int baseSize = 5;
    //auto *list= new List();

    while (!data.eof())
    {
        // somehow read the AWESOME data
        ++recordCounter;
    }

    cout << "\nSuccessfully read " << recordCounter << " records.\n" << endl;
    data.close();
}


void findMaxVisitorsTimestamp()
{
    const char fileName[] = "data.txt";
    ifstream data(fileName);

    if (!data.is_open())
    {
        cerr << "Error opening: " << fileName << endl;
        // And throw exception if it can not be opened
        throw runtime_error(string("Failed opening: ") + fileName);
    }

    int visitors = 0;
    int maxVisitors = 0;
    vector<string> maxTimestamp;
    //List *maxTimeStamp = *newList();

    // тут мы извращённо достаём данные
    for (string dataLine; getline(data, dataLine);)
    {
        string action(dataLine.substr(0, 3));

        if (action == "IN ")
        {
            if (++visitors >= maxVisitors)
            {
                if (visitors > maxVisitors)
                {
                    maxVisitors = visitors;
                    maxTimestamp.clear();
                }
                maxTimestamp.push_back(dataLine.substr(4, 10));
            }
        }
        else if (action == "OUT")
        {
            --visitors;
        }
    }

    setlocale(LC_ALL, "Russian");
    cout << "Всего посетителей: " << visitors << endl;
    cout << "Максимум посетителей одновременно: " << maxVisitors << endl;
    cout << "Время наибольшее по посетителям:" << endl;

    copy(maxTimestamp.begin(), maxTimestamp.end(), ostream_iterator<string>(cout, "\n"));
}