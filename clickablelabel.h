#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QObject>
#include <QLabel>
#include <QString>

class ClickableLabel : public QLabel
{
    Q_OBJECT
private:
    QString brand;

public:
    explicit ClickableLabel( QWidget* parent = 0 );
    explicit ClickableLabel( const QString& text = "", QWidget* parent = 0);
    void setBrand(QString br);
    ~ClickableLabel();

signals:
    void clicked(QString str = "");

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_H
