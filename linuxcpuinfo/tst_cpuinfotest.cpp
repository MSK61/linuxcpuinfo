#include "cpuinfoutils.h"
#include <gtest/gtest.h>
#include <QLinkedList>
using CpuInfoUtils::CoreDefinition;
using namespace testing;

/**
 * @brief Core splitting test record containing run parameters
 */
struct SplitTestRec
{
    /**
     * @brief Unified text description for all cores
     */
    QString unifiedTxt;
    /**
     * @brief Lists of core properties
     */
    QLinkedList<CoreDefinition> coreDefs;
};

/**
 * @brief Core splitting test fixture
 */
class SplitTest : public TestWithParam<SplitTestRec>
{
};

namespace {
using CpuInfoUtils::CoreProperty;

/**
 * @brief Data of all core splitting tests
 */
static const SplitTestRec splitTests[] = {
    {QStringLiteral(""), QLinkedList<CoreDefinition>()},
    {"processor\t: 0", {{CoreProperty("processor", "0")}}},
    {QStringLiteral("vendor_id\t: GenuineIntel"), QLinkedList<CoreDefinition>(
     )}, {QStringLiteral("processor\t: 0\nvendor_id\t: GenuineIntel"),
          {{CoreProperty("processor", "0"),
            CoreProperty("vendor_id", "GenuineIntel")}}}};
}

TEST_P(SplitTest, run)
{
    SplitTestRec testData = GetParam();

    EXPECT_EQ(CpuInfoUtils::SplitCores(testData.unifiedTxt), testData.coreDefs);

}

INSTANTIATE_TEST_CASE_P(Splitting, SplitTest, ValuesIn(splitTests));
