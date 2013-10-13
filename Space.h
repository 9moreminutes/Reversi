#include <stdlib.h>
#include <vector>

using namespace std;

enum Tile{
    WHITE,
    BLACK,
    EMPTY,
};
enum Column{
    a, b, c, d, e, f, g, h,
};
enum Row{
    ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,
};

class Space{
    private:
        Tile tile;
        Row row;
        Column column;
    public:
        Space(Tile t, int r, int col){
            tile = t;
            switch(r){
                case 1:
                    row = ONE;
                break;
                case 2:
                    row = TWO;
                break;
                case 3:
                    row = THREE;
                break;
                case 4:
                    row = FOUR;
                break;
                case 5:
                    row = FIVE;
                break;
                case 6:
                    row = SIX;
                break;
                case 7:
                    row = SEVEN;
                break;
                case 8:
                    row = EIGHT;
                break;
            }
            switch(col){
                case 1:
                    column = a;
                break;
                case 2:
                    column = b;
                break;
                case 3:
                    column = c;
                break;
                case 4:
                    column = d;
                break;
                case 5:
                    column = e;
                break;
                case 6:
                    column = f;
                break;
                case 7:
                    column = g;
                break;
                case 8:
                    column = h;
                break;
            }
        }
        
        Tile getTile(){
            return tile;
        }
        void setTile(Tile t){
            tile = t;
        }
        
        Row getRow(){
            return row;
        }
        void setRow(Row r){
            row = r;
        }
        
        Column getColumn(){
            return column;
        }
        void setColumn(Column c){
            column = c;
        }
};