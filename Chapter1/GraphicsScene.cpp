#include "GraphicsScene.h"

GraphicsScene::GraphicsScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setBackgroundBrush(
        BritainFog
        );
    Common::setGraphicsScene(this);
}
