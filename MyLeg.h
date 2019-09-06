#ifndef MyLeg_h
#define MyLeg_h

#include <Servo.h>


class myLeg{
	
	public:
		myLeg(bool side, int tuneUp = 0,int tuneDown = 0);		//Класс ноги, принимает сторону и корректировку серв

		void init(byte pinUp, byte pinDown);    				//Инициализация серв ноги, принимает пин верхней и нижней сервы

		void writeXY(double _x, double _y);    					//Перемещение в заданные координаты X Y
		void writeAngle(double angleUp, double angleDown);		//Перемещение на заданные углы Alfa Betta
		void fromTo(double startX, double startY, double endX, double endY, double spd = 20,bool stateDo = 1);		//Перемещение серв из координат в координаты со скоростью spd

		double m = 9.7, n = 8.98;								//Переменные
		double k1 = m * m - n * n;
		double k2 = m * m + n * n;
		double k3 = 2 * m*n;
		double toGree = 57.29578;
		
	private:
		Servo legServoUp;								//Инициализация верхней сервы
		Servo legServoDown;							//Инициализация нижней сервы

		double alfa;									//Угол альфа
		double betta;									//Угол бетта

		bool _side;									//Сторона

		int _tuneUp;									//Корректировка верхней сервы
		int _tuneDown;								//Корректировка нижней сервы

		void getAngle(double _x, double _y);			//Получить угол от заданных координат
};

#endif
