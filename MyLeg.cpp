#include "MyLeg.h"
#include <Arduino.h>
#include <Servo.h>


    myLeg::myLeg(bool side, int tuneUp = 0,int tuneDown = 0){
      _side = side;
      _tuneUp = tuneUp;
      _tuneDown = tuneDown;
    }
   
    void myLeg::init(byte pinUp, byte pinDown){
      legServoUp.attach(pinUp); 
      legServoDown.attach(pinDown); 
    }
    
    void myLeg::writeXY(double _x, double _y){
      getAngle(_x,_y);
      if(_side){alfa = 180 - alfa; betta = 180 - betta;}
      
      legServoUp.writeMicroseconds(map((alfa + _tuneUp)*100,0,18000,550,2400));
      legServoDown.writeMicroseconds(map((betta + _tuneDown)*100,0,18000,550,2400));
    }
    
    void myLeg::writeAngle(double angleUp, double angleDown){
      if(_side){angleUp = 180 - angleUp; angleDown = 180 - angleDown;}
      legServoUp.write(angleUp + _tuneUp);
      legServoDown.write(angleDown + _tuneDown);
    }

	void myLeg::fromTo(double startX, double startY, double endX, double endY, double spd = 20,bool stateDo = 1){
		if(stateDo){
			double startAlfa;
			double startBetta;
			double endAlfa;
			double endBetta;
			//================================================
			double k4 = startX * startX + startY * startY;
			double t = sqrt(k4);
			startBetta = acos((k2 - abs(k4)) / k3) * toGree;
			double teta1 = abs(asin(abs(startX) / t) * toGree);
			double teta2 = abs(acos((k1+t*t)/(2*m*t)) * toGree);
			if(startX<0){startAlfa = 90 - teta2 - teta1;}
			else{startAlfa = 90 - (teta2 - teta1);}
			//================================================
			k4 = endX * endX + endY * endY;
			t = sqrt(k4);
			endBetta = acos((k2 - abs(k4)) / k3) * toGree;
			teta1 = abs(asin(abs(endX) / t) * toGree);
			teta2 = abs(acos((k1+t*t)/(2*m*t)) * toGree);
			if(endX<0){endAlfa = 90 - teta2 - teta1;}
			else{endAlfa = 90 - (teta2 - teta1);}
			//================================================
			double lgA = abs(endAlfa-startAlfa);
			double lgB = abs(endBetta-startBetta);
			double deltaStep;
			if(lgA>=lgB){
				 deltaStep = lgB/lgA;			  
			}	  
		}
	}

	void myLeg::getAngle(double _x, double _y){
		double k4 = _x * _x + _y * _y;
		double t = sqrt(k4);
		betta = acos((k2 - abs(k4)) / k3) * toGree;
		double teta1 = abs(asin(abs(_x) / t) * toGree);
		double teta2 = abs(acos((k1+t*t)/(2*m*t)) * toGree);
		if(_x<0){alfa = 90 - teta2 - teta1;}
		else{    alfa = 90 - (teta2 - teta1);}
	}
