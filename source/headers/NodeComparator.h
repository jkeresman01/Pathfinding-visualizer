#pragma once

#include "Node.h"

struct NodeComp
{
    bool operator()(Node *t_leftNode, Node *t_rightNode)
    {
        return t_leftNode->getDistance() > t_rightNode->getDistance();
    }
};
