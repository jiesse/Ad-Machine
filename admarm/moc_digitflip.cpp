/****************************************************************************
** Meta object code from reading C++ file 'digitflip.h'
**
** Created: Mon Mar 21 17:02:01 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "digitflip.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'digitflip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Digits[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_Digits[] = {
    "Digits\0"
};

const QMetaObject Digits::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Digits,
      qt_meta_data_Digits, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Digits::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Digits::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Digits::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Digits))
        return static_cast<void*>(const_cast< Digits*>(this));
    return QWidget::qt_metacast(_clname);
}

int Digits::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_DigiFlip[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      24,    9,    9,    9, 0x08,
      37,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DigiFlip[] = {
    "DigiFlip\0\0chooseSlide()\0chooseFlip()\0"
    "chooseRotate()\0"
};

const QMetaObject DigiFlip::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DigiFlip,
      qt_meta_data_DigiFlip, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DigiFlip::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DigiFlip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DigiFlip::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DigiFlip))
        return static_cast<void*>(const_cast< DigiFlip*>(this));
    return QWidget::qt_metacast(_clname);
}

int DigiFlip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: chooseSlide(); break;
        case 1: chooseFlip(); break;
        case 2: chooseRotate(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
