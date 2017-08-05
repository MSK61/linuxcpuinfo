#include "cpuinfoutils.h"
#include <QFile>
#include <QLinkedList>
#include <QRegularExpression>
#include <QTextStream>

namespace {
using CpuInfoUtils::CoreDefinition;

/**
 * @brief Retreives information about all cores from the underlying OS
 *
 * @return unified text description of all cores
 */
QString GetAllCores(void)
{
    QFile infoFile(QStringLiteral("/proc/cpuinfo"));

    infoFile.open(QIODevice::Text | QIODevice::ReadOnly);
    return QTextStream(&infoFile).readAll();

}

/**
 * @brief Appends a new property to the given property list
 *
 * @param props property list to append the new property to
 * @param name  new property name
 * @param val   new property value
 */
void AppendPropDef(
        CoreDefinition &props, const QString &name, const QString &val)
{

    props.append(CpuInfoUtils::CoreProperty(
                     name, (val.isNull()) ? QStringLiteral("") : val));

}

/**
 * @brief Handles a property definition
 *
 * @param cores     core list
 * @param propMatch property match record
 */
void HandleProp(QLinkedList<CoreDefinition> &cores,
                const QRegularExpressionMatch &propMatch)
{
    // property part indices
    static const int nameGroupIndex = 1;
    static const int valGroupIndex = 2;
    const QString propName = propMatch.captured(nameGroupIndex);

    if (propName == QStringLiteral("processor")) cores.append(CoreDefinition());

    if (!cores.isEmpty()) AppendPropDef(
                cores.last(), propName, propMatch.captured(valGroupIndex));

}
}

namespace CpuInfoUtils {
CoreProperty::CoreProperty()
{
}

CoreProperty::CoreProperty(const QString &name, const QString &value) :
    itsName(name), itsValue(value)
{
}

bool CoreProperty::operator==(const CoreProperty &rhs) const
{

    return itsName == rhs.GetName() && itsValue == rhs.GetValue();

}

const QString &CoreProperty::GetName(void) const
{

    return itsName;

}

const QString &CoreProperty::GetValue(void) const
{

    return itsValue;

}

QLinkedList<CoreDefinition> SplitCores(const QString &unifiedDesc)
{
    QLinkedList<CoreDefinition> cores;
    QRegularExpressionMatchIterator matches = QRegularExpression(
                QStringLiteral("^(.*\\w)[[:blank:]]*:(?: (.*\\w)?)?"),
                QRegularExpression::MultilineOption).globalMatch(unifiedDesc);

    while (matches.hasNext()) HandleProp(cores, matches.next());

    return cores;

}

QLinkedList<CoreDefinition> GetCpuInfo(void)
{

    return SplitCores(GetAllCores());

}
}
