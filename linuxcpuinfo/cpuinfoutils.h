#ifndef CPUINFOUTILS_H
#define CPUINFOUTILS_H
#include <QString>

namespace CpuInfoUtils {
/**
 * @brief CPU core property
 */
class CoreProperty
{
public:
    /**
     * @brief Initializes this core property
     *
     * @param name  property name
     * @param value property value
     */
    CoreProperty(const QString& name, const QString& value);
    /**
     * @brief Tests CoreProperty equality
     *
     * @param rhs right-hand side property
     * @return    true if the two properties are equal, otherwise false
     */
    bool operator==(const CoreProperty& rhs) const;
    /**
     * @brief Retrieves the property name
     *
     * @return property name
     */
    const QString& GetName(void) const;
    /**
     * @brief Retrieves the property value
     *
     * @return property value
     */
    const QString& GetValue(void) const;
private:
    /**
     * @brief Property name
     */
    QString itsName;
    /**
     * @brief Property value
     */
    QString itsValue;
};

/**
 * @brief Core definition type
 */
typedef QLinkedList<CoreProperty> CoreDefinition;
/**
 * @brief Retreives core descriptions from the underlying OS
 *
 * @return text descriptions for all cores
 */
QLinkedList<CoreDefinition> GetCpuInfo(void);
/**
 * @brief Splits cores from the unified text description
 *
 * @param unifiedDesc unified text description for all cores
 * @return            list of core text descriptions
 */
QLinkedList<CoreDefinition> SplitCores(const QString& unifiedDesc);
}
#endif // CPUINFOUTILS_H
