#include "QDist.h"
int QDist::getRow()const {
    return this->rowD;
}

int QDist::getCol()const {
    return this->colD;
}

void QDist::setRow(int x) {
    rowD = x;
}

void QDist::setCol(int y) {
    colD = y;
}

//finding minum distance between pac and ghost
char QDist::getMinumDistance(bool keepTrack[][SIZECOL],int row, int col, ghost& currGhost, const Point& pac) {

    //createArrTrack(keepTrack, boardGame,row,col);
    QDist source(currGhost.getX(), currGhost.getY(), 0);
    return calDistance(source, keepTrack,row,col,pac);
}
//
//// To keep track of visited QDist and marking wall as visited
//void QDist::createArrTrack(bool keepTrack[][SIZECOL], char boardGame[][SIZECOL], int row, int col) {
//
//    int i, j;
//    for (i = 0; i < row; ++i) {
//        for (j = 0; j < col; ++j) {
//            if (boardGame[i][j] == '#') {
//                keepTrack[i][j] = true;
//            }
//            else {
//                keepTrack[i][j] = false;
//            }
//        }
//    }
//
// /*   for (auto& ghost : board.getArrGhost()) {
//        keepTrack[ghost->getX()][ghost->getY()] = true;
//    }*/
//}

// applying BFS on keppTrack starting from the point of the ghost
char QDist::calDistance(QDist& source, bool keepTrack[SIZEROW][SIZECOL],int row, int col, const Point& pac) {

    bool isFirst = true;
    Point pos;
    queue<QDist> q;

    //location of ghost
    q.push(source);
    keepTrack[source.getRow()][source.getCol()] = true;
    //while queue is not empty

    while (!q.empty()) {
        QDist p = q.front();
        q.pop();

        //we found pacman
        if (p.getRow() == pac.getX() && p.getCol() == pac.getY())
            return p.getDirection();

        // moving up
        if (p.getRow() - 1 >= 0 && keepTrack[p.getRow() - 1][p.getCol()] == false) {
            if (isFirst) {
                q.push(QDist(p.getRow() - 1, p.getCol(), 'w'));
            }
            else {
                q.push(QDist(p.getRow() - 1, p.getCol(), p.getDirection()));
            }
            keepTrack[p.getRow() - 1][p.getCol()] = true;
        }

        // moving down
        if (p.getRow() + 1 < row && keepTrack[p.getRow() + 1][p.getCol()] == false) {
            if (isFirst) {
                q.push(QDist(p.getRow() + 1, p.getCol(), 'x'));
            }
            else {
                q.push(QDist(p.getRow() + 1, p.getCol(), p.getDirection()));
            }

            keepTrack[p.getRow() + 1][p.getCol()] = true;
        }

        // moving left
        if (p.getCol() - 1 >= 0 && keepTrack[p.getRow()][p.getCol() - 1] == false) {
            if (isFirst) {
                q.push(QDist(p.getRow(), p.getCol() - 1, 'a'));
            }
            else {
                q.push(QDist(p.getRow(), p.getCol() - 1, p.getDirection()));
            }

            keepTrack[p.getRow()][p.getCol() - 1] = true;
        }

        // moving right
        if (p.getCol() + 1 < col && keepTrack[p.getRow()][p.getCol() + 1] == false) {
            if (isFirst) {
                q.push(QDist(p.getRow(), p.getCol() + 1, 'd'));
            }
            else {
                q.push(QDist(p.getRow(), p.getCol() + 1, p.getDirection()));
            }
            keepTrack[p.getRow()][p.getCol() + 1] = true;
        }
        isFirst = false;
    }
    return 's';
}

const char& QDist::getDirection()const {
    return direction;
}