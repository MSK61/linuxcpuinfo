#include "propertyinfo.h"

namespace ModelServices {
PropertyInfo::PropertyInfo(
        const QString& propName, const QString& propValue, QObject *parent) :
    QObject(parent), itsName(propName), itsValue(propValue)
{

}

const QString& PropertyInfo::GetName(void) const
{

    return itsName;

}

const QString& PropertyInfo::GetValue(void) const
{

    return itsValue;

}
}
