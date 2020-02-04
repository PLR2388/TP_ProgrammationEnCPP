#include "confirmationsuppression.h"

ConfirmationSuppression::ConfirmationSuppression(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.YesButton,SIGNAL(clicked()),this,SLOT(confirme_suppression()));
}

ConfirmationSuppression::~ConfirmationSuppression()
{

}

void ConfirmationSuppression::confirme_suppression()
{
	accept();
}
