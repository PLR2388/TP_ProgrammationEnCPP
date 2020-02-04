#ifndef CONFIRMATIONSUPPRESSION_H
#define CONFIRMATIONSUPPRESSION_H

#include <QtGui/QDialog>
#include "ui_confirmationsuppression.h"

class ConfirmationSuppression : public QDialog
{
    Q_OBJECT

public:
    ConfirmationSuppression(QWidget *parent = 0);
    ~ConfirmationSuppression();
private slots:
	void confirme_suppression();
private:
    Ui::ConfirmationSuppressionClass ui;

};

#endif // CONFIRMATIONSUPPRESSION_H
