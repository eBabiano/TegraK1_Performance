/****************************************************************************
** Meta object code from reading C++ file 'BackgroundSubstractorWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/view/gui/widgets/av/BackgroundSubstractorWidget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BackgroundSubstractorWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_src__view__gui__widgets__av__BackgroundSubstractorWidget_t {
    QByteArrayData data[4];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_src__view__gui__widgets__av__BackgroundSubstractorWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_src__view__gui__widgets__av__BackgroundSubstractorWidget_t qt_meta_stringdata_src__view__gui__widgets__av__BackgroundSubstractorWidget = {
    {
QT_MOC_LITERAL(0, 0, 56),
QT_MOC_LITERAL(1, 57, 32),
QT_MOC_LITERAL(2, 90, 0),
QT_MOC_LITERAL(3, 91, 5)
    },
    "src::view::gui::widgets::av::BackgroundSubstractorWidget\0"
    "on_horizontalSlider_valueChanged\0\0"
    "value\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_src__view__gui__widgets__av__BackgroundSubstractorWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void src::view::gui::widgets::av::BackgroundSubstractorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BackgroundSubstractorWidget *_t = static_cast<BackgroundSubstractorWidget *>(_o);
        switch (_id) {
        case 0: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject src::view::gui::widgets::av::BackgroundSubstractorWidget::staticMetaObject = {
    { &AVWidget::staticMetaObject, qt_meta_stringdata_src__view__gui__widgets__av__BackgroundSubstractorWidget.data,
      qt_meta_data_src__view__gui__widgets__av__BackgroundSubstractorWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *src::view::gui::widgets::av::BackgroundSubstractorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *src::view::gui::widgets::av::BackgroundSubstractorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_src__view__gui__widgets__av__BackgroundSubstractorWidget.stringdata))
        return static_cast<void*>(const_cast< BackgroundSubstractorWidget*>(this));
    return AVWidget::qt_metacast(_clname);
}

int src::view::gui::widgets::av::BackgroundSubstractorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AVWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
