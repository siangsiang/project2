#include "Game.h"
#include <QGraphicsScene>
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BuildTowerIcon.h"

Game::Game(): QGraphicsView(){
    // create a scene
    scene = new QGraphicsScene();
      scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
      setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

      // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
      // it can be used to visualize scenes)
      setScene(scene);
      setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
      setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create a tower
    Tower * t = new Tower();
    t->setPos(650,250);

    // add the tower to scene
    scene->addItem(t);

    // set curosr
    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    // alter window
    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);

    // test code

}

void Game::setCursor(QString filename){
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if (cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    if (build){
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = nullptr;
        build = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }

}
