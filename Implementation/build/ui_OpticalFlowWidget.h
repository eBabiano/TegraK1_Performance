/********************************************************************************
** Form generated from reading UI file 'OpticalFlowWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTICALFLOWWIDGET_H
#define UI_OPTICALFLOWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpticalFlowWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *OpticalFlowWidget)
    {
        if (OpticalFlowWidget->objectName().isEmpty())
            OpticalFlowWidget->setObjectName(QStringLiteral("OpticalFlowWidget"));
        OpticalFlowWidget->resize(400, 300);
        gridLayout = new QGridLayout(OpticalFlowWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(OpticalFlowWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(OpticalFlowWidget);

        QMetaObject::connectSlotsByName(OpticalFlowWidget);
    } // setupUi

    void retranslateUi(QWidget *OpticalFlowWidget)
    {
        OpticalFlowWidget->setWindowTitle(QApplication::translate("OpticalFlowWidget", "Form", 0));
        label->setText(QApplication::translate("OpticalFlowWidget", "Optical Flow", 0));
    } // retranslateUi

};

namespace Ui {
    class OpticalFlowWidget: public Ui_OpticalFlowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTICALFLOWWIDGET_H
