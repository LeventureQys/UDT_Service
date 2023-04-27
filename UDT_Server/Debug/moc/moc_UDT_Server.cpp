/****************************************************************************
** Meta object code from reading C++ file 'UDT_Server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UDT_Server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UDT_Server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UDT_Sender_t {
    QByteArrayData data[8];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDT_Sender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDT_Sender_t qt_meta_stringdata_UDT_Sender = {
    {
QT_MOC_LITERAL(0, 0, 10), // "UDT_Sender"
QT_MOC_LITERAL(1, 11, 19), // "sig_state_file_send"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 17), // "sig_send_complete"
QT_MOC_LITERAL(4, 50, 7), // "sig_log"
QT_MOC_LITERAL(5, 58, 9), // "send_file"
QT_MOC_LITERAL(6, 68, 4), // "file"
QT_MOC_LITERAL(7, 73, 5) // "close"

    },
    "UDT_Sender\0sig_state_file_send\0\0"
    "sig_send_complete\0sig_log\0send_file\0"
    "file\0close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDT_Sender[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       3,    0,   44,    2, 0x06 /* Public */,
       4,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void UDT_Sender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UDT_Sender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_state_file_send((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->sig_send_complete(); break;
        case 2: _t->sig_log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->send_file((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UDT_Sender::*)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDT_Sender::sig_state_file_send)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UDT_Sender::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDT_Sender::sig_send_complete)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UDT_Sender::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDT_Sender::sig_log)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UDT_Sender::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_UDT_Sender.data,
    qt_meta_data_UDT_Sender,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UDT_Sender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDT_Sender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDT_Sender.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDT_Sender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void UDT_Sender::sig_state_file_send(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDT_Sender::sig_send_complete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UDT_Sender::sig_log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
