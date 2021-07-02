//
//  Previous.h
//  Project1
//
//  Created by Jene Hojin Choi on 2021/06/29.
//

#ifndef Previous_h
#define Previous_h

#include "globals.h"

class Previous
{
    public:
        Previous(int nRows, int nCols);
        bool dropACrumb(int r, int c);
        void showPreviousMoves() const;
    
    private:
        int m_rows;
        int m_cols;
        char m_arena[MAXROWS][MAXCOLS]; 
    
};
#endif /* Previous_h */
