#include <QPushButton>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QRectF>
#include "Dificulties_Window.h"
#include "Game.h"
#include <iostream>



Dificulties_Window::Dificulties_Window(QWidget *parent)
{
    //Creation of the scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //Creation and configuration of the title
    QLabel *label = new QLabel("Pac-Man");
    QGraphicsProxyWidget *proxy_label = new QGraphicsProxyWidget(); //Widget that makes posible to use a QLabel in a QGraphicsscene
    proxy_label->setWidget(label);
    QFont font("Arial", 20, QFont::Helvetica);
    label->setStyleSheet("background-color: white");
    label->setFont(font);
    scene->addItem(proxy_label);
    proxy_label->setPos(335, 20);

    //Creation and configuration of easy mode button

    QPushButton * easy_mode = new QPushButton("Easy");
    easy_mode->setGeometry(0,0,170,50);
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget(); //Widget that makes posible to use a QPushButton in a QGraphicsscene
    proxy->setWidget(easy_mode);
    scene->addItem(proxy);
    proxy->setPos(320,150);
    connect(easy_mode, &QPushButton::released, this, &Dificulties_Window::easy); //Method that will activated when the button is released

    //Creaction and configuration of normal mode button



    QPushButton * play_button = new QPushButton("Classic 4");
    play_button->setGeometry(0,0,170,50);
    QGraphicsProxyWidget *proxy_normal = new QGraphicsProxyWidget(); //Widget that makes posible to use a QPushButton in a QGraphicsscene
    proxy_normal->setWidget(play_button);
    scene->addItem(proxy_normal);
    proxy_normal->setPos(320,240);
    connect(play_button, &QPushButton::released, this, &Dificulties_Window::classic);
    //Creaction and configuration of hard mode button

    QPushButton * hard_mode = new QPushButton("Hard");
    hard_mode->setGeometry(0,0,170,50);
    QGraphicsProxyWidget *proxy_hard = new QGraphicsProxyWidget(); //Widget that makes posible to use a QPushButton in a QGraphicsscene
    proxy_hard->setWidget(hard_mode);
    scene->addItem(proxy_hard);
    proxy_hard->setPos(320,330);
    connect(hard_mode, &QPushButton::released, this, &Dificulties_Window::hard); //Method that will activated when the button is released

    QPushButton * normal_mode = new QPushButton("Normal");
    normal_mode->setGeometry(0,0,170,50);
    QGraphicsProxyWidget *proxy_classic = new QGraphicsProxyWidget(); //Widget that makes posible to use a QPushButton in a QGraphicsscene
    proxy_classic->setWidget(normal_mode);
    scene->addItem(proxy_classic);
    proxy_classic->setPos(320,420);
    connect(normal_mode, &QPushButton::released, this, &Dificulties_Window::normal); //Method that will activated when the button is released


    //Configuration of the scene


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    show();
}

void Dificulties_Window::easy()
{
    int points = 200;
    int lifes = 3;
    char mapa[21][30] = {
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "X                           X",
            "X  XXXXXXXXXXXXXXXXXXXXXXXX X",
            "X                           X",
            "X  XXXXXXXXXXXXXXXXXXXXXXXX X",
            "X                           X",
            "X  XXXXXXXXXXXXXXXXXXXXXXXX X",
            "X                           X",
            "X  XXXXXXXXXXXXXXXXXXXXXXXX X",
            "X                           X",
            "X  XXXXXXXXXXX   XXXXXXXXXX X",
            "X                           X",
            "X  XXXXXXXXXXXXXXXXXXXXXXXX X",
            "X                           X",
            "X  XXXXXXXXXXXXXXXXXXXXXXXX X",
            "X                           X",
            "X  XXXXXXXXXXXXXXXXXXXXXXXX X",
            "X                           X",
            "X  XXXXXXXXXXXXXXXXXXXXXXXX X",
            "X                           X",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };

    Game *level_1 = new Game(mapa, 1100, 2);
    std::cout << "easyyy" << std::endl;
    level_1->show();
    this->close();
}

void Dificulties_Window::normal()
{
    int points = 200;
    int lifes = 3;
    char mapa[21][30] = {
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "X                           X",
            "X XXXXXXXXX          XXXXXX X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXX   XXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXX          XXXXXX X",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };


    Game *level_1 = new Game(mapa, 200, 2);
    std::cout << "normalll " << std::endl;
    level_1->show();
    this->close();
}
void Dificulties_Window::classic()
{
    int points = 200;
    int lifes = 3;
    char mapa[21][30] = {
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X                           X",
            "X           XXX             X",
            "X XXXXXXXX  XXX  XXXXXXXXXX X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "X                           X",
            "X XXXXXXXXXXXXXXXXXXXXXXXX  X",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };


    Game *level_1 = new Game(mapa, 200, 2);
    std::cout << "clasico de 4: 4 fantasmas " << std::endl;
    level_1->show();
    this->close();
}
void Dificulties_Window::hard()
{
    int points = 200;
    int lifes = 3;
    char mapa[21][30] = {
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
            "X            XXX            X",
            "X XXXXX XXXX XXX XXXX XXXXX X",
            "X                           X",
            "X XXX XXXXX XXXXX XXXXX XXX X",
            "X XXX X               X XXX X",
            "X XXX X XXXXXX   XXXX X XXX X",
            "X XXX X X           X X XXX X",
            "X XXX X X XXXXXXXXX X X XXX X",
            "X XXX X X X       X X X XXX X",
            "X                           X",
            "X XXX X X XXXXXXXXX X X XXX X",
            "X XXX X X           X X XXX X",
            "X XXX X X XXXXXXXXX X X XXX X",
            "X XXX X X           X X XXX X",
            "X XXX X X XXXXXXXXX X X XXX X",
            "X                           X",
            "X XXX X XXXX XXX XXXX XXXXX X",
            "X            XXX            X",
            "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    };


    Game *level_1 = new Game(mapa, 200, 2);
    std::cout << "hard lvl : 3 enemies " << std::endl;
    level_1->show();
    this->close();
}
