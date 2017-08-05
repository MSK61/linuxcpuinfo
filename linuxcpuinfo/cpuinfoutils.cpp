#include <QFile>
#include <QRegularExpression>
#include <QTextStream>

namespace {
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
 * @brief Updates the list of cores
 *
 * @param cores      core list
 * @param globalDesc unified description of all cores
 * @param start      start index in the unified description of the core to add
 * @param end        end index in the unified description of the core to add
 */
void UpdateCores(QStringList& cores, const QString& globalDesc, int start, int end)
{

    if (start >= 0) cores.append(globalDesc.mid(start, end - start));

}

/**
 * @brief Handles a new core definition start
 *
 * @param cores      core list
 * @param globalDesc unified description of all cores
 * @param prevStart  start index in the unified description of the previous core
 * @param curStart   start index in the unified description of the new core
 * @return           @p curStart
 */
int HandleCoreStart(QStringList& cores, const QString& globalDesc,
                    int prevStart, int curStart)
{

    UpdateCores(cores, globalDesc, prevStart, curStart);
    return curStart;

}
}

namespace CpuInfoUtils {
QStringList SplitCores(const QString& unifiedDesc)
{
    QStringList cores;
    QRegularExpressionMatchIterator matches = QRegularExpression(
                QStringLiteral("^processor[[:blank:]]*: \\d+[[:blank:]]*$"),
                QRegularExpression::MultilineOption).globalMatch(unifiedDesc);
    int start = -1;

    while (matches.hasNext())
        start = HandleCoreStart(
                    cores, unifiedDesc, start, matches.next().capturedStart());

    UpdateCores(cores, unifiedDesc, start, unifiedDesc.size());
    return cores;

}

QStringList GetCpuInfo(void)
{

    return SplitCores(GetAllCores());

}
}
