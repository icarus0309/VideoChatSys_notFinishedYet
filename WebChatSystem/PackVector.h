#ifndef PACKVECTOR_H
#define PACKVECTOR_H

#include <QVector>
#include "Pack.h"

class PackVector
{
public:
    PackVector();
    static PackVector* instance;
public:
    QVector<Pack> vpack;
    static PackVector* getInstance();
};

#endif // PACKVECTOR_H
