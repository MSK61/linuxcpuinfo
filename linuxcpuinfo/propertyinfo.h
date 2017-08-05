#ifndef PROPERTYINFO_H
#define PROPERTYINFO_H

#include <QObject>

namespace ModelServices {
/**
 * @brief Property information
 */
class PropertyInfo : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Initializes property information
     *
     * @param propName  property name
     * @param propValue property value
     * @param parent    parent object
     */
    explicit PropertyInfo(const QString& propName, const QString& propValue,
                          QObject *parent = nullptr);
    Q_PROPERTY(QString name READ GetName CONSTANT)
    Q_PROPERTY(QString value READ GetValue CONSTANT)
signals:

public slots:
private:
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
    /**
     * @brief Property name
     */
    const QString itsName;
    /**
     * @brief Property value
     */
    const QString itsValue;
};
}
#endif // PROPERTYINFO_H
