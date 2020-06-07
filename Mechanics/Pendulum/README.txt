
In this field, you will find 3 files main.cpp, pendulum.cpp, pendulum.hpp .
The two last files allow to create an object pendulum by using the POO(Programmation Oriented-object).
In the main file, we draw a window with the pendulum with all of the caracterics you want.
You can change all of parameters:
        -the lenght: l1,l2
        -the initial angle: theta1, theta2
        -the initial velocity angle: dtheta1, dtheta2

of the first pendulum and the second pendulum.
If the simulation is too slow, increase a little bit the parameters h of euler method.
Conversely, if the simulation is too fast, decrease a little bit the parameters h of euler method.

To compile, Make sure to INSTALL SFML via https://www.sfml-dev.org/download-fr.php
// THEN COMPILE WITH : g++ Poiseuille_Flow.cpp -o Poiseuille_Flow.exe sfml-app -lsfml-graphics -lsfml-window -lsfml-system
or g++ main.cpp pendulum.cpp -o main.exe -lsfml-graphics -lsfml-window -lsfml-system
// EXECUTE WITH ./Poiseuille_Flow.exe


