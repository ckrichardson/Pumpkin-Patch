/**
@file pumpkin.cpp
@Brief This program finds pumpkin patches and counts their pumpkins!

@author Clifford Richardson
*/


#include <iostream>
#include <string>

using namespace std;

const int MAX_ROWS = 40;
const int MAX_COLUMNS = 40;

/**
@brief reads in the inputs from the specified format of inputs

@param[in]  x = rows, y = columns, patch[][MAX_COLUMNS] = 2D array of size 40x40
@param[out] none
*/

void read(int x, int y, char patch[][MAX_COLUMNS]);

/**
@brief locates patches in the great field of vegetables and fruits

@param[in] x = rows, y = columns, path[][MAX_COLUMNS] = array with data, &count
 = the number of patches, sizes[] = the array holding the number of sizes Paramaterized
 patch
 @param[out] none
 */

void findPatches(int x, int y, char patch[][MAX_COLUMNS], int &count, int sizes[]);

/**
@brief calculates the number of pumpkins in the patch!

@param[in] x = x-position of located patch element, y = y0position of located patch element,
 path[][MAX_COLUMNS] = array with data, rows = number of rows, columns = number of columns.

@return returns the size of the patch
*/

int findPatchSize(int x, int y, char patch[][MAX_COLUMNS], int rows, int columns);

/**
@brief the main function incorporates all prior functions to produce
software capable of calculating the size of the pumpkin patch.

@return retuns int 1
*/



int main()
{
  int x = 1;
  int y = 1;

  int count = 0;
  int iterations = 0;

  int sizes [1600] = {0};

  int temp = 0;

  char patch[MAX_ROWS][MAX_COLUMNS] = {0};




  cin >> x;
  cin >> y;



  while(x != 0 && y != 0)
  {
    count = 0;


    read(x, y, patch);
    findPatches(x, y, patch, count, sizes);

    for(int i =0; i< x; i++)
    {
      for(int j = 0; j < y; j++)

      {
        cout << patch[i][j] <<" ";
      }
      cout << endl;
    }



    for(int i = 0; i < count - 1; i++)
    {
      for(int j = 0; j < count - i - 1; j++)
      {
        if(sizes[j] > sizes[j + 1])
        {
          temp = sizes[j];
          sizes[j] = sizes[j + 1];
          sizes[j + 1] = temp;
        }
      }
    }

    cout << "Garden # " << ++iterations << ": " << count << " patches, sizes:";
    for(int i = 0; i < count; i++)
    {
      cout << " " << sizes[i];
    }



    cout << endl;

    cin >> x;
    cin >> y;
  }



}

void read(int x, int y, char patch[][MAX_COLUMNS])
{
  char newData;
  //cout << "HERE";
  for(int i = 0; i < x; i++)
  {
    for(int j = 0; j < y; j++)
    {
      //cout << "[" << i << "]" << "[" << j << "]";
      cin >> newData;
      patch[i][j] = newData;
    }
  }


}

void findPatches(int x, int y, char patch[][MAX_COLUMNS], int &count, int sizes[])
{
  int pumpkins = 0;


  for(int i = 0; i < x; i++)
  {
    for(int j = 0; j < y; j++)
    {
      if(patch[i][j] == 'p')
      {
          pumpkins = findPatchSize(i, j, patch, x, y);
          sizes[count++] = pumpkins;
          //cout << "COUNT: " << count;


      }
    }

  }

}


int findPatchSize(int x, int y, char patch[][MAX_COLUMNS], int rows, int columns)
{

  patch[x][y] = '!';

int tracker = 0;

tracker++;


if(x != 0 && patch[x - 1][y] == 'p')
{
  tracker += findPatchSize(x - 1, y, patch, rows, columns);
}
if(x != rows - 1 && patch[x + 1][y] == 'p')
{
  tracker += findPatchSize(x + 1, y, patch, rows, columns);
}
if(y != 0 && patch[x][y - 1] == 'p')
{
  tracker += findPatchSize(x, y - 1, patch, rows, columns);
}
if(y != columns - 1 && patch[x][y + 1] == 'p')
{
  tracker += findPatchSize(x, y + 1, patch, rows, columns);
}



  return tracker;

}
