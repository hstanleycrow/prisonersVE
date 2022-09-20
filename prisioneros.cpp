#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

#define PRISONERS_TOTAL 1000
#define BOXES_TO_OPEN 500

using namespace std;

int genRand()
{

    return 1 + rand() % PRISONERS_TOTAL;
}

bool existsNumber(int *pointer, int searchNumber, int total)
{
    bool result = false;
    for (int i = 0; i < total; i++)
    {
        if (pointer[i] == searchNumber)
            result = true;
    }
    return result;
}

void fillList(int *pointer)
{
    int number;
    for (int i = 0; i < PRISONERS_TOTAL; ++i)
    {
        number = genRand();
        while (existsNumber(pointer, number, i) == true)
            number = genRand();

        pointer[i] = number;
    }
}

int main()
{
    setlocale(LC_ALL, "");

    int boxes[PRISONERS_TOTAL];
    int prisoners[PRISONERS_TOTAL];
    int foundHisNumber = 0;
    bool foundNumber;
    int prisonerNumber;
    int openBoxNumber;
    int totalOpenedBoxes = 0;
    srand((unsigned)time(0));
    fillList(boxes);
    fillList(prisoners);

    for (int prisonerCount = 0; prisonerCount < PRISONERS_TOTAL; prisonerCount++)
    {
        totalOpenedBoxes = 0;
        prisonerNumber = prisoners[prisonerCount];
        openBoxNumber = boxes[prisonerNumber];
        foundNumber = false;
        // cout << "Prisionero No.: " << prisonerCount + 1 << " Con el No: " << prisonerNumber << endl;
        do
        {
            // cout << "Caja No: " << totalOpenedBoxes + 1 << ". Numero dentro de la caja: " << openBoxNumber << endl;
            if (openBoxNumber == prisonerNumber)
            {
                foundHisNumber++;
                foundNumber = true;
                // cout << "Encontrado" << endl;
            }
            else
            {
                openBoxNumber = boxes[openBoxNumber];
            }
            totalOpenedBoxes++;
        } while (totalOpenedBoxes < BOXES_TO_OPEN && !foundNumber);
    }

    if (foundHisNumber == PRISONERS_TOTAL)
    {
        cout << "Everybody free!! Total found: " << foundHisNumber << endl;
    }
    else
    {
        cout << "Everybody dies!! Total found: " << foundHisNumber << endl;
    }

    getch();
    return 0;
}
