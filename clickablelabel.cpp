#include "clickablelabel.h"

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent)
{

}

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent) : QLabel(parent)
{
    setText(text);
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}
