#include <iostream>
using namespace std;

void insertRow(int**& array, int& rows, int cols, int* newRow, int position)
{

    int** newArray = new int* [rows + 1];
    for (int i = 0; i < position; ++i) 
    {
        newArray[i] = array[i];
    }
    newArray[position] = newRow;

    for (int i = position; i < rows; ++i) 
    {
        newArray[i + 1] = array[i];
    }

    delete[] array;

    array = newArray;
    ++rows;
}

void deleteRow(int**& array, int& rows, int cols, int position)
{
    int** newArray = new int* [rows - 1];

    for (int i = 0; i < position; ++i)
    {
        newArray[i] = array[i];
    }

    for (int i = position + 1; i < rows; ++i)
    {
        newArray[i - 1] = array[i];
    }

    delete[] array[position];
    delete[] array;

    array = newArray;
    --rows;
}

void printArray(int** array, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int rows = 3, cols = 4;
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        array[i] = new int[cols];
        for (int j = 0; j < cols; ++j) 
        {
            array[i][j] = i * cols + j;
        }
    }
    cout << "original array: " <<endl;
    printArray(array, rows, cols);

    int* newRow = new int[cols] {23, 6, 3, 2};
    int position = 2;

    insertRow(array, rows, cols, newRow, position);

    cout << "\narray after insert row: " <<endl;
    printArray(array, rows, cols);

    position = 1;

    deleteRow(array, rows, cols, position);

    cout << "\narray after delete row: " << endl;
    printArray(array, rows, cols);

    
    for (int i = 0; i < rows; ++i) 
    {
        delete[] array[i];
    }
    delete[] array;
    return 0;
}
