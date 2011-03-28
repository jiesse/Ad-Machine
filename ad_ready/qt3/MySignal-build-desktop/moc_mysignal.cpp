/****************************************************************************
** Meta object code from reading C++ file 'mysignal.h'
**
** Created: Fri Mar 11 01:15:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MySignal/mysignal.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mysignal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mySignal[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      19,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_mySignal[] = {
    "mySignal\0\0my_sig()\0my_slot()\0"
};

const QMetaObject mySignal::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_mySignal,
      qt_meta_data_mySignal, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mySignal::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mySignal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mySignal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mySignal))
        return static_cast<void*>(const_cast< mySignal*>(this));
    return QObject::qt_metacast(_clname);
}

int mySignal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: my_sig(); break;
        case 1: my_slot(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void mySignal::my_sig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
