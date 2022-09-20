#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

#define PRISONERS_TOTAL 100
#define BOXES_TO_OPEN 50

using namespace std;

/*int binarySearch(int *numbers, int dato, int total)
{
    int inf, sup, mitad;
    bool sinEncontrar = true;

    inf = 0;
    sup = total;
    while ((inf < sup) && sinEncontrar)
    {
        mitad = (inf + sup) / 2;
        if (numbers[mitad] == dato)
        {
            sinEncontrar = true;
        }
        else
        {
            if (numbers[mitad] > dato)
            {
                sup = mitad;
                mitad = (inf + sup) / 2;
            }
            if (numbers[mitad < dato])
            {
                inf = mitad;
                mitad = (inf + sup) / 2;
            }
        }
    }
    return sinEncontrar;
}
*/
/*void bubbleSort(int *numbers, int total)
{
    int temp;
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
        {
            temp = numbers[i];
            if (numbers[i] > numbers[j])
            {
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}*/

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