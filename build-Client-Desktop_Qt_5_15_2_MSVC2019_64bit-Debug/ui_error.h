/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_error
{
public:

    void setupUi(QWidget *error)
    {
        if (error->objectName().isEmpty())
            error->setObjectName(QString::fromUtf8("error"));
        error->resize(400, 300);

        retranslateUi(error);

        QMetaObject::connectSlotsByName(error);
    } // setupUi

    void retranslateUi(QWidget *error)
    {
        error->setWindowTitle(QCoreApplication::translate("error", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class error: public Ui_error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
