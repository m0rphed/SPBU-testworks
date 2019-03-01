// 1953 год. В связи с усилением влияния Запада и необходимостью предпринять ответные меры,
// Иосиф Сталин разрабатывает новый эффективный алгоритм внутрипартийной чистки:
// сначала расстреливаются n самых опасных членов, а затем оставшиеся
// упорядочиваются в алфавитном порядке и первые m отправляются в Сибирь.
// Л.П. Берия уже успел провести предварительные работы:
// определил степень лояльности к СССР среди членов партии и предоставил списки генеральному секретарю.
// На входе файл формата "фамилия - степень лояльности".
// n и m вводятся с клавиатуры.
// Задача: определить, кто будет расстрелян, кого отправят в Сибирь, кто останется невредим. Пока невредим.

#include "./task-02-2.h"
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void StalinInterface()
{
    string fileName = "data.txt";
    ifstream data(fileName, ios::in);

    // Check that file can be found, and throw exception if it can not
    if (!data.is_open())
    {
        cerr << "ОШИБКА: Список предателей украли враги!" << endl;
        throw runtime_error(string("Failed opening: ") + fileName);
    }

    cout << "\nНачинаем...\n" << endl;

    int killCount = 0;
    cout << "Товарищ Сталин, сколько расстреливаем сегодня?" << endl;
    cin >> killCount;

    int sendCount = 0;
    cout << "Товарищ Сталин, скольких предателей в Сибирь?" << endl;
    cin >> sendCount;

    Node **list = nullptr;
    int listSize = 0;

    while (!data.eof())
    {
        string name;
        getline(data, name);

        string loyaltyString;
        getline(data, loyaltyString);

        int loyalty = stoi(loyaltyString);

        if (data.eof())
        {
            break;
        }

        insertNode(list, listSize, name, loyalty);
    }

    data.close();

    if (killCount + sendCount > listSize || killCount < 0 || sendCount < 0)
    {
        cout << "\nМноговато, Товарищь Сталин!" << endl;

        if (list)
        {
            for (int i = 0; i < listSize; i++)
            {
                delete list[i];
            }

            delete list;
        }

        data.close();
        return;
    }

    sortByLoyalty(list, listSize);
    sortBySecondName(list, listSize - killCount);

    cout << "\nРасстрелять:" << endl;

    for (int i = 0; i < killCount; i++)
    {
        cout << list[i]->Name << endl;
    }

    cout << "\nВ Сибирь:" << endl;
    for (int i = 0; i < sendCount; i++)
    {
        cout << (list[i + killCount])->Name << endl;
    }

    cout << "\nПотенциальные предатели:" << endl;
    for (int i = 0; i < listSize - (killCount + sendCount); i++)
    {
        cout << list[i + killCount + sendCount]->Name << endl;
    }

    if (list != nullptr)
    {
        for (int i = 0; i < listSize; i++)
        {
            delete list[i];
        }

        delete[] list;
    }
}

void insertNode(Node **&list, int &listSize, const string &secondName, int const loyalty)
{
    auto *newPerson = new Node();
    newPerson->Name = secondName;
    newPerson->loyalty = loyalty;

    auto **newList = new Node *[listSize + 1];
    newList[listSize] = newPerson;

    if (list != nullptr)
    {
        for (int i = 0; i < listSize; i++)
        {
            newList[i] = new Node();
            newList[i] = list[i];
        }

        for (int i = 0; i < listSize; i++)
        {
            delete list[i];
        }

        delete[] list;
    }

    list = newList;
    listSize++;
}

void sortByLoyalty(Node **list, int const listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[i]->loyalty < list[j]->loyalty)
            {
                Node *temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void sortBySecondName(Node **list, int const listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (list[i]->Name == list[j]->Name)
            {
                Node *temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void printList(Node **list, int const listSize)
{
    for (int i = 0; i < listSize; i++)
    {
        cout << "\nТоварищ: " << list[i]->Name << " (" << list[i]->loyalty << ")" << endl;
    }
}
