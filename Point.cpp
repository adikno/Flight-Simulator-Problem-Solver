//
// Created by michal on 1/9/19.
//

class Point{
private:
    int x;
    int y;
    int value;
public:
    Point(int x , int y, int value){
        this->x = x;
        this->y = y;
        this->value = value;
    }
    void setX(int x){
        this->x =x;
    }
    void setY(int y){
        this->y =x;
    }
    int getX(){
        return this->x;
    }
    int getY(){
        return this->y;
    }
    int setValue(int n) {
        this->value = n;
    }
};