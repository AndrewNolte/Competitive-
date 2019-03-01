
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <queue>
#include <stack>
#include <unordered_map>
#include <climits>

using namespace std;

int main()
{
    int rows, cols;

    cin >> rows;
    cin >> cols;
    bool rowPattern[rows];
    bool colPattern[cols];
    for (int i = 0; i < rows; i++)
    {
        char c;
        cin >> c;
        rowPattern[i] = c == '>';
    }
    for (int i = 0; i < cols; i++)
    {
        char c;
        cin >> c;
        colPattern[i] = c == 'v';
    }
    bool works = true;
    if (!(colPattern[0] ^ rowPattern[0]))
        works = false;
    if (!(colPattern[cols - 1] ^ !rowPattern[0]))
        works = false;
    if (!(colPattern[0] ^ !rowPattern[rows - 1]))
        works = false;
    if (!(colPattern[cols - 1] ^ rowPattern[rows - 1]))
        works = false;

    if (rows == 1 || cols == 1)
        works = false;

    if (works)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}