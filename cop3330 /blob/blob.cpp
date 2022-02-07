#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// *******************************************************************************
// * Name: blob.cpp
// * Class: COP3330
// * Description: Program to count and output the number of blob (groups of text) in a file
// * Author: Jerry Laplante
// * Date: June 18, 2020
// *******************************************************************************


void Delete_Blob ( int, int, char [22][72]);


int main() {

ifstream inStream;
inStream.open("blob.txt");


char blobmatrix [22][72];
char blobchar;
int row = 1, col = 1;
int numblob = 0;

if (inStream.fail())
{
    cout << "input file fail";
    exit(1);
}
for (int i = 1; i < 71; i ++ )
{
    if ((i%10) != 0 )
    {
        cout << " ";
    }
    else
    {
        cout << (i/10);
    }
}
cout << endl;
for (int i = 1; i < 71; i++)
{
    if ((i%10 != 0))
    {
        cout << (i%10);
    }
    else
    {
        cout << "0";
    }
}

cout << endl << endl << endl;

for (row = 1; row < 21 && !inStream.eof(); row++)
{
    col = 1;
    inStream.get(blobchar);
    cout << blobchar;

    while (blobchar != '\n')
    {
        blobmatrix[row][col++] = blobchar;
        inStream.get(blobchar);
        cout << blobchar;
    }
}
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if ( blobmatrix[i][j] == 'X')
            {
                cout << "Blob found at Row " << i << " Col " << j << endl;
                Delete_Blob(i,j,blobmatrix);
                numblob++;
            }


        }
            
    }

    cout << endl <<"Number of blobs " << numblob << endl;

    inStream.close();

    return 0;
}

void Delete_Blob(int x, int y, char blobmatrix[22][72])
// * Function Name:  deleteblob
// * Description:  when first instance of blob is detected,
// *this function deletes the remainder of the blob recursively
// * Parameter Description: x and y are the array indexes and
// * blobmatrix lets the function access and test array contents
// * Date:  06/18/2020
// * Author: Jerry Laplante
// * References: Lecture 10 notes and David Gaitros Youtube page
{

    if (x > 21 || y > 71)
    {
        return;
    }

    blobmatrix[x][y] = ' ';

    if (blobmatrix[x][y-1] == 'X')
    {
        Delete_Blob(x,y-1,blobmatrix);
    }
    if (blobmatrix[x][y+1] == 'X')
    {
        Delete_Blob(x,y+1,blobmatrix);
    }
    if (blobmatrix[x+1][y-1] == 'X')
    {
        Delete_Blob(x+1,y-1,blobmatrix);
    }
    if (blobmatrix[x+1][y] == 'X')
    {
        Delete_Blob(x+1,y,blobmatrix);
    }
    if (blobmatrix[x+1][y+1] == 'X')
    {
        Delete_Blob(x+1,y+1,blobmatrix);
    }
    if (blobmatrix[x-1][y-1] == 'X')
    {
        Delete_Blob(x-1,y-1,blobmatrix);
    }
    if (blobmatrix[x-1][y] == 'X')
    {
        Delete_Blob(x-1,y,blobmatrix);
    }
    if (blobmatrix[x-1][y+1] == 'X')
    {
        Delete_Blob(x-1,y+1,blobmatrix);
    }
}