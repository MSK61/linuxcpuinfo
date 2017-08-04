#ifndef CPUINFOUTILS_H
#define CPUINFOUTILS_H
#include <QString>

namespace CpuInfoUtils {
/**
 * @brief Retreives CPU information from the underlying OS
 *
 * @return CPU text description
 */
QString GetCpuInfo(void);
}
#endif // CPUINFOUTILS_H
