#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include "Common.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent = nullptr);
};

#endif // GRAPHICSSCENE_H
