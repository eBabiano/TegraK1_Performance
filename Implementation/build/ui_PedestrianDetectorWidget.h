/********************************************************************************
** Form generated from reading UI file 'PedestrianDetectorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEDESTRIANDETECTORWIDGET_H
#define UI_PEDESTRIANDETECTORWIDGET_H

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

class Ui_PedestrianDetectorWidget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QWidget *PedestrianDetectorWidget)
    {
        if (PedestrianDetectorWidget->objectName().isEmpty())
            PedestrianDetectorWidget->setObjectName(QStringLiteral("PedestrianDetectorWidget"));
        PedestrianDetectorWidget->resize(400, 300);
        gridLayout = new QGridLayout(PedestrianDetectorWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(PedestrianDetectorWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(PedestrianDetectorWidget);

        QMetaObject::connectSlotsByName(PedestrianDetectorWidget);
    } // setupUi

    void retranslateUi(QWidget *PedestrianDetectorWidget)
    {
        PedestrianDetectorWidget->setWindowTitle(QApplication::translate("PedestrianDetectorWidget", "Form", 0));
        label->setText(QApplication::translate("PedestrianDetectorWidget", "Pedestrian Detector", 0));
    } // retranslateUi

};

namespace Ui {
    class PedestrianDetectorWidget: public Ui_PedestrianDetectorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEDESTRIANDETECTORWIDGET_H
