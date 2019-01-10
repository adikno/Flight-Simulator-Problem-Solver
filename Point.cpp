//
// Created by michal on 1/9/19.
//

class Point{
private:
    int x;
    int y;
public:
    Point(int x , int y) {
        this->x = x;
        this->y = y;
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
};