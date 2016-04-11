#include <SFML/Graphics.hpp>
#include "window.h"
using namespace sf;


int main(){
    RenderWindow window( VideoMode(1300, 700), "Test!"); //Style::Fullscreen);
    menu(window);

    Clock clock;

    while(window.isOpen())
    {
        window.clear(Color::Black);
        menu(window);
        window.display();

    }
    return 0;
}
