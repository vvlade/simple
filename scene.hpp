#ifndef SCENE_HPP
#define SCENE_HPP

#include <QGraphicsScene>

class MyItem;

class Scene : public QGraphicsScene
{
public:
    Scene(QObject *parent = nullptr);

private:
    QVector<MyItem *> mItems;
};

#endif // SCENE_HPP
