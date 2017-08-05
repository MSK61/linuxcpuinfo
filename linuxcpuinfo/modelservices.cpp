#include "cpuinfoutils.h"
#include "propertyinfo.h"
#include <QLinkedList>
#include <QVariant>
#include <QVector>
using CpuInfoUtils::CoreDefinition;

namespace {
using CpuInfoUtils::CoreProperty;
using ModelServices::PropertyInfo;

/**
 * @brief Copies the given property vector into a new list
 *
 * @param propVec property vector to copy
 * @return        new property list
 */
QObjectList CreatePropList(const QVector<CoreProperty> &propVec)
{
    QObjectList coreProps;

    coreProps.reserve(propVec.size());

    foreach (const CoreProperty &curProp, propVec) coreProps.append(
                new PropertyInfo(curProp.GetName(), curProp.GetValue()));

    return coreProps;

}

/**
 * @brief Deletes the given core property objects
 *
 * @param core core to delete whose properties
 */
void DeleteCoreProps(const QVariantList &core)
{

    foreach (const QVariant &curProp, core)
        delete curProp.value<PropertyInfo*>();

}

/**
 * @brief Sore core properties
 *
 * @param core core to sort whose properties
 * @return     sorted properties
 */
QVector<CoreProperty> SortProps(const CoreDefinition &core)
{
    QVector<CoreProperty> sortedProps;

    sortedProps.reserve(core.size());
    std::copy(core.cbegin(), core.cend(), std::back_inserter(sortedProps));
    std::sort(sortedProps.begin(), sortedProps.end(),
              [](const CoreProperty &lhs, const CoreProperty &rhs)
    {

        return lhs.GetName() < rhs.GetName();

    });
    return sortedProps;

}

/**
 * @brief Retrieves the core properties
 *
 * @param core core to retrieve whose properties
 * @return     core properties sorted by property name
 */
QObjectList GetCoreProps(const CoreDefinition &core)
{

    return CreatePropList(SortProps(core));

}
}

namespace ModelServices {
QVariantList GetProcessors(void)
{
    QVariantList cores;
    static const QLinkedList<CoreDefinition> cpuInfo =
            CpuInfoUtils::GetCpuInfo();

    cores.reserve(cpuInfo.size());

    foreach (const CoreDefinition &curCore, cpuInfo)
        cores.append(QVariant::fromValue(GetCoreProps(curCore)));

    return cores;

}

void DeleteCoreList(const QVariantList &coreLst)
{

    foreach (const QVariant &curCore, coreLst)
        DeleteCoreProps(curCore.value<QVariantList>());

}
}
