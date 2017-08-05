#ifndef MODELSERVICES_H
#define MODELSERVICES_H
#include <QVariant>

namespace ModelServices {
/**
 * @brief Retreives CPU information from the underlying OS
 *
 * @return CPU text descriptions
 */
QVariantList GetProcessors(void);
/**
 * @brief Deletes property objects in each core
 *
 * @param coreLst list of cores to delete whose properties
 */
void DeleteCoreList(const QVariantList &coreLst);
}
#endif // MODELSERVICES_H
