#include "cpuinfoutils.h"
#include <gtest/gtest.h>
#include <QStringList>
using namespace testing;

/**
 * @brief Core splitting test record containing run parameters
 */
struct SplitTestRec
{
    QString unifiedTxt;
    QStringList coreDefs;
};

/**
 * @brief Core splitting test fixture
 */
class SplitTest : public TestWithParam<SplitTestRec>
{
};

namespace {
/**
 * @brief Data of all core splitting tests
 */
static const SplitTestRec splitTests[] =
        {{QStringLiteral(""), {}},
         {"processor\t: 0", QStringList(QStringLiteral("processor\t: 0"))},
         {QStringLiteral("vendor_id\t: GenuineIntel"),{}},
         {QStringLiteral("processor\t: 0\nvendor_id\t: GenuineIntel"),
          QStringList(
          QStringLiteral("processor\t: 0\nvendor_id\t: GenuineIntel"))}};
}

TEST_P(SplitTest, run)
{
    SplitTestRec testData = GetParam();

    EXPECT_EQ(CpuInfoUtils::SplitCores(testData.unifiedTxt), testData.coreDefs);

}

INSTANTIATE_TEST_CASE_P(Splitting, SplitTest, ValuesIn(splitTests));
