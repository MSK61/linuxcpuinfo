#include "cpuinfoteller.h"
#include "cpuinfoutils.h"

namespace CpuInfoUtils {
CpuInfoTeller::CpuInfoTeller(QObject *parent) : QObject(parent)
{

}

QString CpuInfoTeller::getInfo(void)
{

    return GetCpuInfo();

}
}
