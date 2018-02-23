#ifndef JSONGENERATOR_H
#define JSONGENERATOR_H

#include <QObject>
#include <QStringList>
class JsonGenerator : public QObject {
    Q_OBJECT
public:
    JsonGenerator(QString type, QStringList args);
    JsonGenerator();
    QString output() const;

    void setType(const QString &type);
    void addArgument(const QString &arg);

signals:
private:
    QString m_output;
    QString m_type;
    QStringList m_args;
public slots:
};

#endif // JSONGENERATOR_H
