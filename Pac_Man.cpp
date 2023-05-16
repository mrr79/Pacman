#include "Pac_Man.h"
#include "Dots.h"
#include "SuperDot.h"
#include "Ghost.h"
#include "qgraphicsscene.h"
#include "Ghost2.h"
#include "Ghost3.h"
#include "Dificulties_Window.h"
#include "Ghost4.h"
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <iostream>
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sstream>

int cycle = 0;
bool poder_activo = false;
int poder_x;
int poder_y;
bool cazar = true;
Pac_Man::Pac_Man(int mapa[21][30], int points, int lifes, QGraphicsTextItem *points_label, QGraphicsScene *sceneint,int j, int i)
{
    this->points = points;
    this->lifes = lifes;
    this->points_label = points_label;
    this->scene = scene;
    this->act_pacman_x=j;
    this->act_pacman_y=i;
    poder_activo = false;


    setPixmap(QPixmap(":/Images/pac_man_0R.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move,SIGNAL(timeout()),this,SLOT(move())); //conect method that repeats the method everytime it recives the signal
    timer_move->start(500); //Signal every 50 miliseconds

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (mapa[i][j] != 0) {
                StarNode *node = new StarNode(j, i);
                lista_random.append(node);
            }
        }
    }
    lista_random.printList();
    lista_random.getRandomNode();

    connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_R())); //conect method that repeats the method everytime it recives the signal
    timer_animation->start(150); //Signal every 50 miliseconds
}

void Pac_Man::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        direcction = 'U';
        cycle = 0;
        connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_U())); //conect method that repeats the method everytime it recives the signal
    }
    if (event->key() == Qt::Key_Down){
        direcction = 'D';
        cycle = 0;
        connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_D())); //conect method that repeats the method everytime it recives the signal
    }
    if (event->key() == Qt::Key_Left){
        direcction = 'L';
        cycle = 0;
        connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_L())); //conect method that repeats the method everytime it recives the signal
    }
    if (event->key() == Qt::Key_Right){
        direcction = 'R';
        cycle = 0;
        connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_R())); //conect method that repeats the method everytime it recives the signal
    }
}

void Pac_Man::set_points_label(QGraphicsTextItem *points_label)
{
    this->points_label = points_label;
}
void Pac_Man::set_lifes_label(QGraphicsTextItem *lifes_label)
{
    this->lifes_label = lifes_label;
}
void Pac_Man::set_level_label(QGraphicsTextItem *level_label)
{
    this->level_label = level_label;
}

void Pac_Man::set_mapa(int mapa[21][30])
{
    for (int i = 0;i < 21;i++){
        for(int j = 0;j < 30;j++){
            this->mapa[i][j] = mapa[i][j];
            qDebug() << mapa[i][j];
        }
    }
}
void Pac_Man::set_values(int mapa[21][30], int points, int lifes, QGraphicsTextItem* points_label, QGraphicsScene* scene) {
    this->points = points;
    this->lifes = lifes;
    this->points_label = points_label;
    this->scene = scene;
}

int pointsR;


void Pac_Man::check_collision()
{

    QList<QGraphicsItem *> colliding_items = collidingItems(); //List of the colliding items
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Dot)){
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            points+= 10;
            pointsR = points;
            points_label->setPlainText("Points: " + QString::number(points));

            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(SuperDot)){
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            poder_activo = true;
            std::cout << "PODER ACTIVADOOOOOOOOOOOOOOOOO" << std::endl;
            cazar = false;
            poder_activo = false;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Ghost)){
            Ghost* ghost_ptr = dynamic_cast<Ghost*>(colliding_items[i]);
            if (cazar == false){
                points+= 50;
                pointsR = points;
                points_label->setPlainText("Points: " + QString::number(points));
                ghost_ptr->random_location();
            } else{
                vidas--;
                std::cout << "VIDAS RESTANTES:" << vidas << std::endl;
                random_location();
            }

        }
        else if (typeid(*(colliding_items[i])) == typeid(Ghost2)){
            Ghost2* ghost_ptr2 = dynamic_cast<Ghost2*>(colliding_items[i]);
            if (cazar == false){
                points+= 50;
                pointsR = points;
                points_label->setPlainText("Points: " + QString::number(points));
                ghost_ptr2->random_location();
            } else {
                vidas--;
                std::cout << "VIDAS RESTANTES:" << vidas << std::endl;
                random_location();

            }

        }
        else if (typeid(*(colliding_items[i])) == typeid(Ghost3)){
            Ghost3* ghost_ptr3 = dynamic_cast<Ghost3*>(colliding_items[i]);
            if (cazar == false){
                points+= 50;
                pointsR = points;
                points_label->setPlainText("Points: " + QString::number(points));
                ghost_ptr3->random_location();
            } else {
                vidas--;
                std::cout << "VIDAS RESTANTES:" << vidas << std::endl;
                random_location();

            }

        }
        else if (typeid(*(colliding_items[i])) == typeid(Ghost4)){
            Ghost4* ghost_ptr4 = dynamic_cast<Ghost4*>(colliding_items[i]);
            if (cazar == false){
                points+= 50;
                pointsR = points;
                points_label->setPlainText("Points: " + QString::number(points));
                ghost_ptr4->random_location();
            } else {
                vidas--;
                std::cout << "VIDAS RESTANTES:" << vidas << std::endl;
                random_location();

            }

        }
    }
}

void Pac_Man::check_points() {
    if (app == true){
        SocketServer();
    }
    lifes_label->setPlainText("Lifes: " + QString::number(vidas));
    level_label->setPlainText("Level: " + QString::number(nivel));

    if (vidas <= 0){
        loose = true;
    }
    if (nivel == 1){
        if (points >= 5000){
            nivel2 = true;
        }
    }
    else if (nivel == 2){
        if (points >= 100){
            nivel3 = true;
        }
    }
    else if (nivel == 3){
        if (points >= 150){
            nivel4 = true;
        }
    }
    else if (nivel == 4){
        if (points >= 170){
            win = true;
        }
    }
    if (points % 200==0 && points!=0) {
        points+= 10;
        points_label->setPlainText("Points: " + QString::number(puntos));
        srand(time(NULL));

        SuperDot *super_dot = new SuperDot();

        scene->addItem(super_dot);
        super_dot->setPos(1*30,1*30);
        poder_activo = true;
        std::cout << "Coordenadas aleatorias de SUPERDOT: (" << poder_x << ", " << poder_y << ")" << std::endl;
    }
}

void Pac_Man::move()
{
    if (direcction == 'R'){
        if (x() < 810 && mapa[act_pacman_x][act_pacman_y + 1] != 0){
            setPos(x() + speed,y());
            act_pacman_y++;
        }
    }
    else if (direcction == 'L'){
        if (x() > 30 && mapa[act_pacman_x][act_pacman_y - 1] != 0){
            setPos(x() - speed,y());
            act_pacman_y--;
        }
    }
    else if (direcction == 'U'){
        if (y() > 30 && mapa[act_pacman_x - 1][act_pacman_y] != 0){
            setPos(x(),y() - speed);
            act_pacman_x--;

        }
    }
    else if (direcction == 'D'){
        if (y() < 570 && mapa[act_pacman_x + 1][act_pacman_y] != 0){
            setPos(x(),y() + speed);
            act_pacman_x++;
        }
    }
    act_pacman_x = y() / 30;// posicion del pacman en el mapa
    act_pacman_y = x() / 30;

    emit pacman_posicion_actualizada(act_pacman_x, act_pacman_y);

}
void Pac_Man::setActPacmanX(int m) {
    act_pacman_x = m;
}

void Pac_Man::setActPacmanY(int n) {
    act_pacman_y = n;
}

int Pac_Man::getActPacmanX() {
    return act_pacman_x;
}

int Pac_Man::getActPacmanY() {
    return act_pacman_y;
    //std::cout << "Y PACMAN EN get" << act_pacman_y<< std::endl;
}

void Pac_Man::animation_R()
{
    if (cycle == 0){
        setPixmap(QPixmap(":/Images/pac_man_0R.png"));
        cycle++;
    }

    else if (cycle == 1){
        setPixmap(QPixmap(":/Images/pac_man_1R.png"));
        cycle++;
    }

    else if (cycle == 2){
        setPixmap(QPixmap(":/Images/pac_man_2.png"));
        cycle = 0;
    }
}

void Pac_Man::animation_L()
{
    if (cycle == 0){
        setPixmap(QPixmap(":/Images/pac_man_0L.png"));
        cycle++;
    }

    else if (cycle == 1){
        setPixmap(QPixmap(":/Images/pac_man_1L.png"));
        cycle++;
    }

    else if (cycle == 2){
        setPixmap(QPixmap(":/Images/pac_man_2.png"));
        cycle = 0;
    }
}

void Pac_Man::animation_U()
{
    if (cycle == 0){
        setPixmap(QPixmap(":/Images/pac_man_0U.png"));
        cycle++;
    }

    else if (cycle == 1){
        setPixmap(QPixmap(":/Images/pac_man_1U.png"));
        cycle++;
    }

    else if (cycle == 2){
        setPixmap(QPixmap(":/Images/pac_man_2.png"));
        cycle = 0;
    }
}

void Pac_Man::animation_D()
{
    if (cycle == 0){
        setPixmap(QPixmap(":/Images/pac_man_0D.png"));
        cycle++;
    }

    else if (cycle == 1){
        setPixmap(QPixmap(":/Images/pac_man_1D.png"));
        cycle++;
    }

    else if (cycle == 2){
        setPixmap(QPixmap(":/Images/pac_man_2.png"));
        cycle = 0;
    }
}
void Pac_Man::random_location(){
    poder_x = lista_random.getRandomNode()->getNodeX();
    poder_y = lista_random.getRandomNode()->getNodeY();
    setPos(poder_x*30, poder_y*30);

}
int puntaje = 100;

void Pac_Man::SocketServer() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Crear socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Error al crear socket" << std::endl;
        return;
    }

    // Opción de socket para reutilizar la dirección
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        std::cerr << "Error en setsockopt" << std::endl;
        return;
    }

    // Configurar dirección del socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(5001);

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt))) {
        std::cerr << "Error en setsockopt" << std::endl;
        return;
    }


    // Enlazar socket a la dirección y puerto especificados
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        std::cerr << "Error en bind" << std::endl;
        return;
    }

    // Escuchar conexiones entrantes
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Error en listen" << std::endl;
        return;
    }

    std::cout << "Servidor en espera de conexiones..." << std::endl;


    // Aceptar nueva conexión
    if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        std::cerr << "Error en accept" << std::endl;
        return;
    }

    std::cout << "Nueva conexión aceptada" << std::endl;

    // Procesar mensajes entrantes
    char buffer[1024] = {0};
    int valread = read(new_socket, buffer, 1024);
    if (valread <= 0) {
        std::cout << "Cliente desconectado" << std::endl;
        close(new_socket);
        return;
    }
    std::string data(buffer);
    std::vector<std::string> tokens;
    std::istringstream iss(data);
    std::string token;
    while (std::getline(iss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.size() != 3) {
        std::cerr << "Error al analizar la cadena." << std::endl;// Devolver 1 para indicar un error
    }

    std::string giro_xs = tokens[0];
    std::string giro_ys = tokens[1];
    std::string giro_zs = tokens[2];

    float giro_x = std::stof(giro_xs);
    float giro_y = std::stof(giro_ys);
    float giro_z = std::stof(giro_zs);

    std::cout << "Giro X: " << giro_x << ", Giro Y: " << giro_y << ", Giro Z: " << giro_z << std::endl;

    if (giro_x >= 3 && giro_y <= 2){
        std::cout << "Izquierda" << std::endl;
        direcction = 'L';
    } else if (giro_x <= -2 && giro_y <= 2){
        std::cout << "Derecha" << std::endl;
        direcction = 'R';
    } else if (giro_y >= 3 && giro_x <= 2){
        std::cout << "Arriba" << std::endl;
        direcction = 'U';
    } else if (giro_y <= -3 && giro_x <= 2){
        std::cout << "Abajo" << std::endl;
        direcction = 'D';
    }


    //Valores del juego
    puntaje = puntaje+1;

    char respuesta[] = "Mensaje recibo.\n";
    sprintf(respuesta, "%d,%d,%d\n", pointsR, vidas, nivel);
    send(new_socket, respuesta, sizeof(respuesta), 0);
    std::cout << "Respuesta: " << respuesta << std::endl;

    if (close(server_fd) == -1) {
        std::cerr << "Error al cerrar el socket: " << std::strerror(errno) << std::endl;
        return;
    }
    if (close(new_socket) == -1) {
        std::cerr << "Error al cerrar el socket: " << std::strerror(errno) << std::endl;
        return;
    }
}



