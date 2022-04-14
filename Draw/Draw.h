#ifndef DRAW_H
#define DRAW_H
#define ANGLE 45
#define WINDOW 400
#define COS(a) cos((float)a/(float)180*(float)M_PI)
#define SIN(a) sin((float)a/(float)180*(float)M_PI)
#define TAN(a) tan((float)a/(float)180*(float)M_PI)
#include <cmath>
#include <functional>
#include <windows.h>
#include <vector>
#include "D:\c++\paint\3d engine\CoordStructures.h"

struct angle{
    int _1;
    int _2;
    void operator+=(angle in){
        this->_1+=in._1;
        this->_2+=in._2;
    }
    angle operator-(angle in){
        angle toReturn;
        toReturn._1=this->_1-in._1;
        toReturn._2=this->_2-in._2;
        return toReturn;
    }
};
struct angleTriangle{
    angle _1;
    angle _2;
    angle _3;
    angleTriangle operator-(angleTriangle in){
        angleTriangle toReturn;
        toReturn._1=this->_1-in._1;
        toReturn._2=this->_2-in._2;
        toReturn._3=this->_3-in._3;
        return toReturn;
    }
    angleTriangle operator-(angle in){
        angleTriangle toReturn;
        toReturn._1=this->_1-in;
        toReturn._2=this->_2-in;
        toReturn._3=this->_3-in;
        return toReturn;
    }
};
angle getAngle(double ,double ,double );

struct triangle{
private:
    angleTriangle angles;
public:

    COORD_3_POINT p1;
    COORD_3_POINT p2;
    COORD_3_POINT p3;
    triangle(){};
    triangle(COORD_3_POINT a,COORD_3_POINT b,COORD_3_POINT c){
        p1 = a;
        p2 = b;
        p3 = c;
    };
    void updateAngles(COORD_3_POINT); 
    angleTriangle getAngles();
};
class Render{
private:
    angle cumRay={0,0};
    bool inView(angle*);
    void leadAngle(angle*);
    POINT** getNeighborVertex(POINT*,POINT*);
    int polygonCut(POINT* vertex); 
public:
    struct drawCall{
        private:
            int _pointsNum;
            POINT* _points;
        public:
            drawCall(POINT* points,int pointsNum):_points(points),_pointsNum(pointsNum){}
            POINT* getPoint();
            ~drawCall();
    }; 
    angle updateCumAngle(angle);
    drawCall** viewTriangle(angleTriangle**,int);
    drawCall* viewTriangle(angleTriangle);
};
#endif