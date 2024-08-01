#pragma once

#include "Node.h"

namespace pfv
{

struct NodeComp
{
    bool operator()(Node *leftNode, Node *rightNode)
    {
        return leftNode->getDistance() > rightNode->getDistance();
    }
};

} // namespace pfv
