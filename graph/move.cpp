#include <math.h>
//#include "path.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
struct move{
    float begin;
    float end;
    struct move * next;
};
struct moves{
    struct move * up;
    struct move * down;
    struct move * right;
    struct move * left;
};
using namespace sf;
struct moves * path(RenderWindow &window)
{


    //RenderWindow window(sf::VideoMode(640, 480), "Lesson 7. kychka-pc.ru");
    //RenderWindow window = *win;
    Image image;
    image.loadFromFile("arrow.png");
    image.createMaskFromColor(Color(255, 255, 255));
    Texture herotexture;
    herotexture.loadFromImage(image);
    Sprite herosprite, tmpherosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(0, 0, 48, 33));
    herosprite.setPosition(250, 250);
    tmpherosprite = herosprite;
    float CurrentFrame = 0;//хранит текущий кадр
    Clock clock, clock1;
    float angle = 0;
    Vector2f vert;
    Vector2f pos;
    struct move move_up, move_down, move_left, move_right;
    struct move * tmpmove_up = NULL, * tmpmove_down = NULL, * tmpmove_left = NULL, * tmpmove_right = NULL;
    bool flag_up = false, flag_down = false, flag_left = false, flag_right = false;
    bool flag_up1 = false, flag_down1 = false, flag_left1 = false, flag_right1 = false;

    vert.x = 1;
    vert.y = 0;
    Image buffer;
    buffer.create(1366, 768, Color::White);
    Texture bufferTexture;
    bufferTexture.loadFromImage(buffer);
    Sprite bufferSprite;
    bufferSprite.setTexture(bufferTexture);
    float start = clock1.getElapsedTime().asMicroseconds();
    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            if (!flag_up)
            {
                flag_up = true;
                struct move * tmp = new struct move;
                if (!flag_up1)
                {
                    tmpmove_up = &move_up;
                    flag_up1 = true;
                }
                tmpmove_up->next = tmp;
                tmpmove_up = tmp;
                tmpmove_up->next = NULL;
                tmpmove_up->begin = clock1.getElapsedTime().asMicroseconds() - start;
            }
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            herosprite.move(0.1 * time * vert.x, 0.1 * time * vert.y);//происходит само движение персонажа вниз
        }
        else
        {
            if (tmpmove_up != NULL && flag_up)
            tmpmove_up->end = clock1.getElapsedTime().asMicroseconds() - start;
            flag_up = false;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
            if (!flag_down)
            {
                flag_down = true;
                struct move * tmp = new struct move;
                if (!flag_down1)
                {
                    tmpmove_down = &move_down;
                    flag_down1 = true;
                }
                tmpmove_down->next = tmp;
                tmpmove_down = tmp;
                tmpmove_down->next = NULL;
                tmpmove_down->begin = clock1.getElapsedTime().asMicroseconds() - start;
            }
            CurrentFrame += 0.005*time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            herosprite.move(-0.1 * time * vert.x, -0.1 * time * vert.y);//происходит само движение персонажа вниз
        }
        else
        {
            if (tmpmove_down != NULL && flag_down)
            tmpmove_down->end = clock1.getElapsedTime().asMicroseconds() - start;
            flag_down = false;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            if (!flag_right)
            {
                flag_right = true;
                struct move * tmp = new struct move;
                if (!flag_right1)
                {
                    tmpmove_right = &move_right;
                    flag_right1 = true;
                }
                tmpmove_right->next = tmp;
                tmpmove_right = tmp;
                tmpmove_right->next = NULL;
                tmpmove_right->begin = clock1.getElapsedTime().asMicroseconds() - start;
            }
            angle += float(time)/1000;
            vert.x = cos(angle);
            vert.y = sin(angle);
        }
        else
        {
            if (tmpmove_right != NULL && flag_right)
            tmpmove_right->end = clock1.getElapsedTime().asMicroseconds() - start;
            flag_right = false;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
            if (!flag_left)
            {
                flag_left = true;
                struct move * tmp = new struct move;
                if (!flag_left1)
                {
                    tmpmove_left = &move_left;
                    flag_left1 = true;
                }
                tmpmove_left->next = tmp;
                tmpmove_left = tmp;
                tmpmove_left->next = NULL;
                tmpmove_left->begin = clock1.getElapsedTime().asMicroseconds() - start;
            }
            angle -= float(time)/1000;
            vert.x = cos(angle);
            vert.y = sin(angle);
        }
        else
        {
            if (tmpmove_left != NULL && flag_left)
            tmpmove_left->end = clock1.getElapsedTime().asMicroseconds() - start;
            flag_left = false;
        }
        if ((Keyboard::isKeyPressed(Keyboard::Space))) {
            struct moves * mov = new struct moves;
            mov->up = &move_up;
            mov->left = &move_left;
            mov->right = &move_right;
            mov->down = &move_down;
            //window.close();
            return mov;
        }
        pos = herosprite.getPosition();
        tmpherosprite.setPosition(int(16.5 * vert.y + pos.x), int( - 16.5 * vert.x + pos.y));
        tmpherosprite.setRotation(angle * 180 / 3.14);

        if (pos.x > 1 && pos.y > 1 && pos.x < 1365 && pos.y < 765)
        {
            buffer.setPixel(int(pos.x), int(pos.y), Color::Black);
            buffer.setPixel(int(pos.x + 1), int(pos.y), Color::Black);
            buffer.setPixel(int(pos.x - 1), int(pos.y), Color::Black);
            buffer.setPixel(int(pos.x), int(pos.y - 1), Color::Black);
            buffer.setPixel(int(pos.x), int(pos.y + 1), Color::Black);
            bufferTexture.loadFromImage(buffer);
            bufferSprite.setTexture(bufferTexture);
        }

        window.clear(Color(255, 255, 255));
        window.draw(bufferSprite);
        window.draw(tmpherosprite);

        window.display();
    }
    struct moves * mov = new struct moves;
    mov->up = &move_up;
    mov->left = &move_left;
    mov->right = &move_right;
    mov->down = &move_down;
    return mov;

}

int add_way(RenderWindow &window)
{


    //RenderWindow window = *win;//(sf::VideoMode(640, 480), "Lesson 7. kychka-pc.ru");
    Image image;
    image.loadFromFile("machine.png");
    Texture herotexture;
    herotexture.loadFromImage(image);
    Sprite herosprite, tmpherosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(0, 0, 135, 72));
    herosprite.setPosition(250, 250);
    tmpherosprite = herosprite;
    Clock clock, clock1;
    float angle = 0;
    Vector2f vert;
    Vector2f pos;
    struct moves * mov = path(window);
    /*struct move * move_up = mov->up;
    struct move * move_down = mov->down;
    struct move * move_left = mov->left;
    struct move * move_right = mov->right;*/
    /*while (mov->up->next != NULL) {
        mov->up = mov->up->next;
        printf("%f %f\n", mov->up->begin, mov->up->end);
    }*/
    bool flag_up = mov->up->next == NULL, flag_down = mov->down->next == NULL, flag_left = mov->left->next == NULL, flag_right = mov->right->next == NULL;
    vert.x = 1;
    vert.y = 0;
    mov->up = mov->up->next;
    mov->down = mov->down->next;
    mov->right = mov->right->next;
    mov->left = mov->left->next;
    float start = clock1.getElapsedTime().asMicroseconds();
    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(!flag_up)
        if (clock1.getElapsedTime().asMicroseconds() - start > mov->up->begin) {
            if (clock1.getElapsedTime().asMicroseconds() - start > mov->up->end)
            {
                if (mov->up->next == NULL)
                    flag_up = true;
                mov->up = mov->up->next;
            }
            herosprite.move(0.1 * time * vert.x, 0.1 * time * vert.y);//происходит само движение персонажа вниз
        }
        if(!flag_down)
        if (clock1.getElapsedTime().asMicroseconds() - start > mov->down->begin) {
            if (clock1.getElapsedTime().asMicroseconds() - start > mov->down->end)
            {
                if (mov->down->next == NULL)
                    flag_down = true;
                mov->down = mov->down->next;
            }
            herosprite.move(-0.1 * time * vert.x, -0.1 * time * vert.y);//происходит само движение персонажа вниз
        }\
        if(!flag_right)
        if (clock1.getElapsedTime().asMicroseconds() - start > mov->right->begin ) {
            if (clock1.getElapsedTime().asMicroseconds() - start > mov->right->end)
            {
                if (mov->right->next == NULL)
                    flag_right = true;
                mov->right = mov->right->next;
            }
            angle += float(time)/1000;
            vert.x = cos(angle);
            vert.y = sin(angle);

        }
        if(!flag_left)
        if (clock1.getElapsedTime().asMicroseconds() - start > mov->left->begin) {
            if (clock1.getElapsedTime().asMicroseconds() - start > mov->left->end)
            {
                if (mov->left->next == NULL)
                    flag_left = true;
                mov->left = mov->left->next;
            }
        angle -= float(time)/1000;
            vert.x = cos(angle);
            vert.y = sin(angle);
        }
        if(flag_down && flag_left && flag_right && flag_up)
            menu(window);
        pos = herosprite.getPosition();
        tmpherosprite.setPosition(int(-vert.x * 67.5 + 36 * vert.y + pos.x), int(-vert.y * 67.5 - 36 * vert.x + pos.y));
        tmpherosprite.setRotation(angle * 180 / 3.14);
        window.clear(Color(255, 255, 255));
        window.draw(tmpherosprite);
        window.display();
    }

}
