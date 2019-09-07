//
// Created by ale19 on 16/08/19.
//

#include "ProgressDialog.h"
#include "ShowButton.h"
#include "TagReader.h"

//Constructor
ProgressDialog::ProgressDialog(ShowButton* button, QWidget *parent) : QProgressDialog(parent){
    this->setWindowModality(Qt::WindowModal);
    this->setFixedWidth(400);
    this->setMinimumDuration(0);
    this->text = "Progress Dialog";
    this->setLabelText(this->text);
    this->setValue(0);
    this->setAutoClose(false);
    this->setAutoReset(false);
    this->start_value = 1;
    this->myButton = button;
}

//This method update the dialog and the progress of the bar
void ProgressDialog::update(std::string progress) {
    if(maximum()==100)
        this->setMaximum(TagReader::getNFiles()+1);
    this->text = QString::fromStdString(progress);
    this->setLabelText(this->text);
    if (this->start_value < this->maximum()) {
        this->start_value++;
        this->setValue(this->start_value);
    }
    if(this->start_value == this->maximum()) {
        this->setLabelText("Result saved in metadata.txt");
        myButton->setEnabled(true);
    }
    this->text.clear();
}

//Destructor
ProgressDialog::~ProgressDialog(){
    delete this;
}
