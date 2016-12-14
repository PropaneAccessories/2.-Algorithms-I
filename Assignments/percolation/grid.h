#ifndef GRID_H
#define GRID_H

class Grid
{
public:
    Grid(int row, int column);
    void printOut();
    void openCell();
    bool percolated();
    ~Grid();

private:
    int* id;
    int* sz;
    int* seedArray;
    char* display;
    int row;
    int column;
    int area;
    int counter;
    double threshold;

    int findRoot(int x);
    void connect(int num);
    void createIDarray();
    void createSizeArray();
    void createDisplayArray();
    void createSeedArray();
    void findThreshold();
};

#endif // GRID_H
