#include "cpuinfoutils.h"
#include "propertyinfo.h"
#include <QLinkedList>
#include <QVariant>
using CpuInfoUtils::CoreDefinition;

namespace {
using ModelServices::PropertyInfo;

/**
 * @brief Retrieves the core properties
 *
 * @param core core to retrieve whose properties
 * @return     core properties
 */
QObjectList GetCoreProps(const CoreDefinition& core)
{
    QObjectList coreProps;

    coreProps.reserve(core.size());

    foreach (const CpuInfoUtils::CoreProperty &curProp, core)
        coreProps.append(
                    new PropertyInfo(curProp.GetName(), curProp.GetValue()));

    return coreProps;

}

/**
 * @brief Deletes the given core property objects
 *
 * @param core core to delete whose properties
 */
void DeleteCoreProps(const QVariantList& core)
{

    foreach (const QVariant &curProp, core)
        delete curProp.value<PropertyInfo*>();

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

void DeleteCoreList(const QVariantList& coreLst)
{

    foreach (const QVariant &curCore, coreLst)
        DeleteCoreProps(curCore.value<QVariantList>());

}
}
