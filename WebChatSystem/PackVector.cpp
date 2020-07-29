#include "PackVector.h"

PackVector::PackVector()
{

}

PackVector* PackVector::instance = 0;

PackVector* PackVector::getInstance()
{
    if(0 == instance)
        instance = new PackVector;
    return instance;
}
