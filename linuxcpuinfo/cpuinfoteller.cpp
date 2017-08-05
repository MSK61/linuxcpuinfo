#include "cpuinfoteller.h"
#include "cpuinfoutils.h"

namespace CpuInfoUtils {
CpuInfoTeller::CpuInfoTeller(QObject *parent) : QObject(parent)
{

}

QStringList CpuInfoTeller::getProcessors(void)
{

    return GetCpuInfo();

}
}
