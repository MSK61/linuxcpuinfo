#include <QFile>
#include <QTextStream>

namespace CpuInfoUtils {
QString GetCpuInfo(void)
{
    QFile infoFile(QStringLiteral("/proc/cpuinfo"));

    infoFile.open(QIODevice::Text | QIODevice::ReadOnly);
    return QTextStream(&infoFile).readAll();

}
}
