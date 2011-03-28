/****************************************************************************
** Meta object code from reading C++ file 'managent.h'
**
** Created: Wed Mar 23 10:13:03 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../managent/managent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'managent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ManAgent[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,    9,   10,    9, 0x0a,
      33,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ManAgent[] = {
    "ManAgent\0\0int\0slotUdpReadReady()\0"
    "slotTcpReadReady()\0"
};

const QMetaObject ManAgent::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ManAgent,
      qt_meta_data_ManAgent, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ManAgent::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ManAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ManAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ManAgent))
        return static_cast<void*>(const_cast< ManAgent*>(this));
    return QObject::qt_metacast(_clname);
}

int ManAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { int _r = slotUdpReadReady();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: slotTcpReadReady(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
