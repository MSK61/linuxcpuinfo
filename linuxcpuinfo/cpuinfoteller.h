#ifndef CPUINFOTELLER_H
#define CPUINFOTELLER_H

#include <QObject>

namespace CpuInfoUtils {
/**
 * @brief CPU information store
 */
class CpuInfoTeller : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Creates an empty CPU information store
     *
     * @param parent parent object
     */
    explicit CpuInfoTeller(QObject *parent = nullptr);

signals:

public slots:
protected:
    /**
     * @brief Retreives CPU information from the underlying OS
     *
     * @return CPU text descriptions
     */
    Q_INVOKABLE static QStringList getProcessors(void);
};
}
#endif // CPUINFOTELLER_H
