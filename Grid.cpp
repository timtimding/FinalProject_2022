#include "Grid.h"
#include <iostream>
///default constructor
Grid::Grid(){
    _isEmpty = true;
    _pos_x = 0;
    _pos_y = 0;
    _humanNum = 0;
    _vegetableNum = 0;
    _gridHumans = NULL;
    _gridVegetables = NULL;

}


///copy constructor
Grid::Grid(Grid& grid){
    _isEmpty = grid._isEmpty;
    _pos_x = grid._pos_x;
    _pos_y = grid._pos_y;
    _humanNum = grid._humanNum;
    _vegetableNum = grid._vegetableNum;
    if(!_humanNum){
        _gridHumans = NULL;
    }
    else{
        _gridHumans = new Character[_humanNum];
        for(int i=0;i<_humanNum;i++){
            _gridHumans[i] = grid._gridHumans[i];
        }
    }

    if(!_vegetableNum){
        _gridVegetables = NULL;
    }
    else{
        _gridVegetables = new Character[_vegetableNum];
        for(int i=0;i<_vegetableNum;i++){
            _gridVegetables[i] = grid._gridVegetables[i];
        }
    }
}

///constructor with initialization
Grid::Grid(bool isEmpty, int pos_x, int pos_y, int humanNum, int vegetableNum, Character* gridHumans, Character* gridVegetables){
    _isEmpty = isEmpty;
    _pos_x = pos_x;
    _pos_y = pos_y;
    _humanNum = humanNum;
    _vegetableNum = vegetableNum;
    if(!_humanNum){
        _gridHumans = NULL;
    }
    else{
        _gridHumans = new Character[_humanNum];
        for(int i=0;i<_humanNum;i++){
            _gridHumans[i] = gridHumans[i];
        }
    }
    if(!_vegetableNum){
        _gridVegetables = NULL;
    }
    else{
        _gridVegetables = new Character[_vegetableNum];
        for(int i=0;i<_vegetableNum;i++){
            _gridVegetables[i] = gridVegetables[i];
        }

    }
}


///destructor
Grid::~Grid(){
    delete [] _gridHumans;
    delete [] _gridVegetables;
}

///maintain each round/fight on this grid
void Grid::gridFight(){
    if(_isEmpty){
        return;
    }
    else if(!(_humanNum*_vegetableNum)){
        return;
    }
    else{
        ///blood --
        for(int i=0;i<_humanNum;i++){
            for(int j=0;j<_vegetableNum;j++){
                _gridHumans[i].attackEnemy(_gridVegetables[j]);
                _gridVegetables[j].attackEnemy(_gridHumans[i]);
            }
        }
        ///check alive
        int casualtyHuman = 0;
        int casualtyVegetable = 0;

        for(int i=0;i<_humanNum;i++){
            if(_gridHumans[i].checkAlive()){
                continue;
            }
            else{
                casualtyHuman+=1;
                _gridHumans[i].modify_tag(BLANK);
            }
        }

        for(int j=0;j<_vegetableNum;j++){
            if(_gridVegetables[j].checkAlive()){
                continue;
            }
            else{
                casualtyVegetable+=1;
                _gridVegetables[j].modify_tag(BLANK);
            }
        }
        ///reallocate the dynamic arrays
        if(casualtyHuman){
            Character* temp = new Character[_humanNum-casualtyHuman];
            for(int i=0;i<_humanNum;i++){
                if(_gridHumans[i].get_tag()!=BLANK){
                    temp[i] = _gridHumans[i];
                }
            }
            _humanNum -= casualtyHuman;
            delete [] _gridHumans;
            _gridHumans = new Character[_humanNum];
            for(int i=0;i<_humanNum;i++){
                _gridHumans[i] = temp[i];
            }
            delete [] temp;
        }
        if(casualtyVegetable){
            Character* temp = new Character[_vegetableNum-casualtyVegetable];
            for(int j=0;j<_vegetableNum;j++){
                if(_gridVegetables[j].get_tag()!=BLANK){
                    temp[j] = _gridVegetables[j];
                }
            }
            _vegetableNum -= casualtyVegetable;
            delete [] _gridVegetables;
            _gridVegetables = new Character[_vegetableNum];
            for(int j=0;j<_vegetableNum;j++){
                _gridVegetables[j] = temp[j];
            }
            delete [] temp;
        }
        if(!(_humanNum+_vegetableNum)){
            _isEmpty = true;
        }
        return;

    }
}


