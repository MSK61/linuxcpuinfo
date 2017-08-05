#ifndef CPUINFOUTILS_H
#define CPUINFOUTILS_H
class QString;
class QStringList;

namespace CpuInfoUtils {
/**
 * @brief Retreives core descriptions from the underlying OS
 *
 * @return text descriptions for all cores
 */
QStringList GetCpuInfo(void);
/**
 * @brief Splits cores from the unified text description
 *
 * @param unifiedDesc unified text description for all cores
 * @return            list of core text descriptions
 */
QStringList SplitCores(const QString& unifiedDesc);
}
#endif // CPUINFOUTILS_H
