//
//  Previous.cpp
//  Project1
//
//  Created by Jene Hojin Choi on 2021/06/29.
//

#include <iostream>
#include "Arena.h"
#include "Previous.h"
using namespace std;

Previous::Previous(int nRows, int nCols)
{
    m_rows = nRows;
    m_cols = nCols;
    for (int r=0; r<m_rows; r++)
        
    {
        for (int c=0; c<m_cols; c++)
        {
            m_arena[r][c] = 0;
        }
    }
}
// arena constructor of previous

bool Previous::dropACrumb(int r, int c)
{
    
    if (r>0 && r<=m_rows && c>0 && c<=m_cols)
    {
         m_arena[r-1][c-1]++;
         return true;
    }
    else
    {
        return false;
    }
}

void Previous::showPreviousMoves() const
{
    // displays previous_arena with characters
    char previous_arena[MAXROWS][MAXCOLS];

//    for (int r=0; r<MAXROWS; r++)
//    {
//        for (int c=0; c<MAXCOLS; c++)
//        {
//            previous_arena[r][c] = '.';
//        }
//    }

    // convert numbers in m_arena to letters in previous_arena
    for (int r=0; r<m_rows; r++)
    {
        for (int c=0; c<m_cols; c++)
        {
            
            if (m_arena[r][c]==0)
                previous_arena[r][c]='.';
            
            else if (m_arena[r][c]>=26)
                previous_arena[r][c]='Z';
            else
                previous_arena[r][c] = 64 + m_arena[r][c];
        }
    }
    
    clearScreen();
    
    for (int r=0; r<m_rows; r++)
    {
        for (int c=0; c<m_cols; c++)
        {
            cout << previous_arena[r][c];
        }
        cout << endl;
    }
        
    cout << endl;
}
