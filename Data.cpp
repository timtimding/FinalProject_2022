#include "Data.h"

Data::Data(){
    //_tag = "undefined";
    _attack = 0;
    _blood = 0;
    _speed = 0;
    _pos_x = 0;
    _pos_y = 0;
    _cool = 0;
    _coolStart = 0;
}

Data::Data(const Data& data){
    //_tag = data._tag;
    _attack = data._attack;
    _blood = data._blood;
    _speed = data._speed;
    _pos_x = data._pos_x;
    _pos_y = data._pos_y;
    _cool = data._cool;
    _coolStart = data._coolStart;
}

Data::Data(const int attack, const int blood,
           const int speed, const int pos_x, const int pos_y, const int cool, uint32_t coolStart){
    //_tag = tag;
    _attack = attack;
    _blood = blood;
    _speed = speed;
    _pos_x = pos_x;
    _pos_y = pos_y;
    _cool = cool;
    _coolStart = coolStart;
}

Data::~Data(){}


//char* Data::get_tag(){return _tag;}
int Data::get_attack(){return _attack;}
int Data::get_blood(){return _blood;}
int Data::get_speed(){return _speed;}
int Data::get_pos_x(){return _pos_x;}
int Data::get_pos_y(){return _pos_y;}
int Data::get_cool(){return _cool;}
int Data::coolRemain(){return (_cool - (SDL_GetTicks() - _coolStart));}
bool Data::coolDone(){return (SDL_GetTicks() - _coolStart > _cool);std::cout << (SDL_GetTicks() - _coolStart);}


//void Data::modify_tag(char* tag){_tag = tag;}
void Data::modify_attack(int delta){_attack += delta;}
void Data::modify_blood(int delta){_blood += delta;}
void Data::modify_speed(int delta){_speed += delta;}
void Data::modify_pos_x(int delta){_pos_x += delta;}
void Data::modify_pos_y(int delta){_pos_y += delta;}
void Data::c_move(){_pos_x -= _speed;}
void Data::modify_coolStart(){_coolStart -= _cool;}

//void Data::set_tag(char* tag){_tag = tag;}
void Data::set_attack(int attack){_attack = attack;}
void Data::set_blood(int blood){_blood = blood;}
void Data::set_speed(int speed){_speed = speed;}
void Data::set_pos_x(int pos_x){_pos_x = pos_x;}
void Data::set_pos_y(int pos_y){_pos_y = pos_y;}
void Data::set_cool(int cool){_cool = cool;}
void Data::set_coolStart(){_coolStart = SDL_GetTicks();}
