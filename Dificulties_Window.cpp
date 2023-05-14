#include <QPushButton>
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QRectF>
#include "Dificulties_Window.h"
#include "Game.h"
#include <iostream>
#include "Pac_Man.h"



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
    //connect(play_button, &QPushButton::released, this, &Dificulties_Window::classic);
    //Creaction and configuration of hard mode button

    QPushButton * hard_mode = new QPushButton("Hard");
    hard_mode->setGeometry(0,0,170,50);
    QGraphicsProxyWidget *proxy_hard = new QGraphicsProxyWidget(); //Widget that makes posible to use a QPushButton in a QGraphicsscene
    proxy_hard->setWidget(hard_mode);
    scene->addItem(proxy_hard);
    proxy_hard->setPos(320,330);
    //connect(hard_mode, &QPushButton::released, this, &Dificulties_Window::hard); //Method that will activated when the button is released

    QPushButton * normal_mode = new QPushButton("Normal");
    normal_mode->setGeometry(0,0,170,50);
    QGraphicsProxyWidget *proxy_classic = new QGraphicsProxyWidget(); //Widget that makes posible to use a QPushButton in a QGraphicsscene
    proxy_classic->setWidget(normal_mode);
    scene->addItem(proxy_classic);
    proxy_classic->setPos(320,420);
    //connect(normal_mode, &QPushButton::released, this, &Dificulties_Window::normal); //Method that will activated when the button is released


    //Configuration of the scene


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkwin()));
    timer->start(500);

    show();
}

void Dificulties_Window::easy()
{
    int points = 0;
    int lifes = 3;
    int mapa[21][30] = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,1,1,1,1,1,0,1,1,1,1,9,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0},
            {0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,0,1,1,1,1,1,0,0,0,0},
            {0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0},
            {0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,0,0,1,0,0,0},
            {0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0},
            {0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,0,0},
            {0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0},
            {0,0,0,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0},
            {0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0},
            {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0},
            {0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0},
            {0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0},
            {0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0},
            {0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,1,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,11,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    level_1 = new Game(mapa, 0, 10);
    std::cout << "easyyy" << std::endl;
    level_1->show();
    this->close();


}

void Dificulties_Window::checkwin() {
    printf("jueputaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    std::cout << "PUNTOS ACTULAES " << pointsR << std::endl;
    if (pointsR == 20000){
        normal();
    }
    if (pointsR == 50000000000){
        classic();
    }
    if (pointsR == 70000000){
        hard();
    }

}


void Dificulties_Window::normal()
{

    int mapa[21][30] = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,11,1,1,1,1,0,1,1,1,1,9,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,0,0,0,1,1,1,1,0},
            {0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,0,1,1,1,1,1,0,0,1,0},
            {0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,1,0,0,0,0,0,1,0,0,1,0},
            {0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0},
            {0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0},
            {0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0},
            {0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0},
            {0,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0},
            {0,0,1,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0},
            {0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0},
            {0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0},
            {0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0},
            {0,0,0,0,0,0,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0},
            {0,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0},
            {0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0},
            {0,1,0,0,0,0,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,1,0,0,0},
            {0,1,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,1,1,1,1,1,1,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,11,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    level_2 = new Game(mapa, 200, 2);
    std::cout << "normal " << std::endl;
    level_2->show();
    level_1->close();
    delete level_1;
}

void Dificulties_Window::classic()
{

    int mapa[21][30] = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,11,1,1,1,1,0,1,1,1,1,9,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,0},
            {0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,1,0,0,1,0},
            {0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0},
            {0,1,1,1,0,0,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,1,0,0,0,1,0,1,0},
            {0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0},
            {0,1,0,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0},
            {0,1,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0},
            {0,1,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0},
            {0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0},
            {0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0},
            {0,1,1,1,0,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0},
            {0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
            {0,0,0,1,0,0,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0},
            {0,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0},
            {0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,0,0,0},
            {0,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,0,0,1,1,0,0,0,0,0,1,0,0,0},
            {0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0},
            {0,11,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,11,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };


    level_3 = new Game(mapa, 500, 2);
    std::cout << "clasico de 4: 4 fantasmas " << std::endl;
    level_3->show();
    level_2->close();
}
void Dificulties_Window::hard()
{
    int mapa[21][30] = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,11,1,1,1,1,0,1,1,1,1,9,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,11,0},
            {0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,1,1,1,0},
            {0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,0,0,1,0},
            {0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0},
            {0,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,1,0,0,0,1,0,1,0},
            {0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0},
            {0,1,1,1,1,0,1,0,1,1,0,1,1,1,0,0,0,0,0,1,0,1,0,1,1,1,0,1,0},
            {0,1,1,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0},
            {0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0},
            {0,1,1,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0},
            {0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0},
            {0,1,1,1,0,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0},
            {0,0,0,1,0,0,1,0,1,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
            {0,0,0,1,0,0,1,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0},
            {0,1,1,1,1,1,1,0,1,0,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0},
            {0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,0},
            {0,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,0,0},
            {0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,0,1,1,1,1,0,0,0},
            {0,11,1,1,1,1,1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,0,0,0,11,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    level_4 = new Game(mapa, 700, 2);
    std::cout << "hard lvl : 3 enemies " << std::endl;
    level_4->show();
    level_3->close();
}

