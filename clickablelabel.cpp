#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent)
{

}

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent) : QLabel(parent)
{
    setText(text);
}

void ClickableLabel::setBrand(QString br)
{
    brand = br;
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked(brand);
}
