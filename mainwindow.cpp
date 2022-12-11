#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new Scene(this))
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(ui->graphicsView->rect());
    ui->graphicsView->setRenderHint(QPainter::RenderHint::Antialiasing);
    ui->graphicsView->setAlignment(Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignVCenter);

    item = new MyItem();
    scene->addItem(item);


/*
 * (left, top)                  (left+width, top)
    x----------------------------x
    |                            |
    |                            |
    x----------------------------x (right, bottom)
  (leftt, top+height)
*/

    QPen pen(Qt::black);
    pen.setWidth(6);

    top = new QGraphicsLineItem(scene->sceneRect().left(), scene->sceneRect().top(), scene->sceneRect().left() + scene->width(), scene->sceneRect().top());
    top->setPen(pen);

    right = new QGraphicsLineItem(scene->sceneRect().left() + scene->width(), scene->sceneRect().top(), scene->sceneRect().right(), scene->sceneRect().bottom());
    right->setPen(pen);

    bottom = new QGraphicsLineItem(scene->sceneRect().left(), scene->sceneRect().top() + scene->height(), scene->sceneRect().right(), scene->sceneRect().bottom());
    bottom->setPen(pen);

    left = new QGraphicsLineItem(scene->sceneRect().left(), scene->sceneRect().top(), scene->sceneRect().left(), scene->sceneRect().top() + scene->height());
    left->setPen(pen);

    scene->addItem(top);
    scene->addItem(right);
    scene->addItem(bottom);
    scene->addItem(left);
}

MainWindow::~MainWindow()
{
    std::cout << scene->width() << "x" << scene->height() << std::endl;
    std::cout << ui->graphicsView->width() << "x" << ui->graphicsView->height() << std::endl;
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);


    std::cout << "*********************************" << std::endl;
    std::cout << "New scene size: " << scene->width() << "x" << scene->height() << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "New gv size: " << ui->graphicsView->width() << "x" << ui->graphicsView->height() << std::endl;
    std::cout << "-----------------------" << std::endl;

    update();
    std::cout << "New window size: " << width() << "x" << height() << std::endl;
}














