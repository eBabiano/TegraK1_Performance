/********************************************************************************
** Form generated from reading UI file 'ModifyParametersWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYPARAMETERSWIDGET_H
#define UI_MODIFYPARAMETERSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyParametersWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *avListComboBox;
    QHBoxLayout *modifyParamLayout;

    void setupUi(QWidget *ModifyParametersWidget)
    {
        if (ModifyParametersWidget->objectName().isEmpty())
            ModifyParametersWidget->setObjectName(QStringLiteral("ModifyParametersWidget"));
        ModifyParametersWidget->resize(200, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ModifyParametersWidget->sizePolicy().hasHeightForWidth());
        ModifyParametersWidget->setSizePolicy(sizePolicy);
        ModifyParametersWidget->setMaximumSize(QSize(600, 500));
        verticalLayout = new QVBoxLayout(ModifyParametersWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        avListComboBox = new QComboBox(ModifyParametersWidget);
        avListComboBox->setObjectName(QStringLiteral("avListComboBox"));

        horizontalLayout->addWidget(avListComboBox);


        verticalLayout->addLayout(horizontalLayout);

        modifyParamLayout = new QHBoxLayout();
        modifyParamLayout->setObjectName(QStringLiteral("modifyParamLayout"));

        verticalLayout->addLayout(modifyParamLayout);


        retranslateUi(ModifyParametersWidget);

        QMetaObject::connectSlotsByName(ModifyParametersWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifyParametersWidget)
    {
        ModifyParametersWidget->setWindowTitle(QApplication::translate("ModifyParametersWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ModifyParametersWidget: public Ui_ModifyParametersWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYPARAMETERSWIDGET_H
