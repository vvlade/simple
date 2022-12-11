#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include "myitem.hpp"
#include "scene.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    Scene *scene;
    QGraphicsLineItem *top;
    QGraphicsLineItem *right;
    QGraphicsLineItem *bottom;
    QGraphicsLineItem *left;
    MyItem *item;
};
#endif // MAINWINDOW_HPP
