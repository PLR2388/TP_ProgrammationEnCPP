#include "suppressioninterface.h"
#include "validationFormat.h"
#include "qmessagebox.h"

using namespace std;

SuppressionInterface::SuppressionInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.ValiderButton,SIGNAL(clicked()),this,SLOT(validerEnregistrement()));
}

SuppressionInterface::~SuppressionInterface()
{

}

QString SuppressionInterface::reqNiv() const{
	return ui.niv->text();
}

void SuppressionInterface::validerEnregistrement(){
	if(!util::validerNiv((string)reqNiv().toStdString())){
   		QString message("Le niv doit etre valide");
   		QMessageBox::information(this, "ERREUR", message);
   		return;
   	}
   	else{
   		accept();
   	}
}
