This library was made for "Spot like" robot
=============================

Functions
---------
    void init(byte pinUp, byte pinDown)  - initialization servos: top servo|bottom servo
    
    void writeXY(double _x, double _y) - counting angles for top and bottom servo using x and y (uploads angles variables)
    
    void writeAngle(double angleUp, double angleDown) send angles to servos
    
    void fromTo(double startX, double startY, double endX, double endY, double spd = 20,bool stateDo = 1) move leg from start coordinates to end coordinates  with specific speed
    
    (private) void getAngle(double _x, double _y) - counts angles
    
Vars
----
    m,n - leg length 
    
    alfa, betta - angles...
    
    _side - leg side(left or right)
    
    _tuneUp,_tuneDown - accuracy adjustment
