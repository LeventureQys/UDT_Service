/****************************************************************************
** Meta object code from reading C++ file 'UDT_Reciver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../UDT_Reciver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UDT_Reciver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UDT_Reciver_t {
    QByteArrayData data[12];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UDT_Reciver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UDT_Reciver_t qt_meta_stringdata_UDT_Reciver = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UDT_Reciver"
QT_MOC_LITERAL(1, 12, 7), // "sig_log"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 18), // "sig_file_recv_rate"
QT_MOC_LITERAL(4, 40, 12), // "sig_complete"
QT_MOC_LITERAL(5, 53, 7), // "LogSend"
QT_MOC_LITERAL(6, 61, 4), // "text"
QT_MOC_LITERAL(7, 66, 6), // "Listen"
QT_MOC_LITERAL(8, 73, 2), // "ip"
QT_MOC_LITERAL(9, 76, 4), // "port"
QT_MOC_LITERAL(10, 81, 9), // "save_path"
QT_MOC_LITERAL(11, 91, 10) // "close_file"

    },
    "UDT_Reciver\0sig_log\0\0sig_file_recv_rate\0"
    "sig_complete\0LogSend\0text\0Listen\0ip\0"
    "port\0save_path\0close_file"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UDT_Reciver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    4,   47,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   59,    2, 0x0a /* Public */,
       7,    3,   62,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::LongLong, QMetaType::LongLong, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void UDT_Reciver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UDT_Reciver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_log((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_file_recv_rate((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 2: _t->sig_complete((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->LogSend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Listen((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->close_file(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UDT_Reciver::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDT_Reciver::sig_log)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UDT_Reciver::*)(QString , qint64 , qint64 , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDT_Reciver::sig_file_recv_rate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UDT_Reciver::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&UDT_Reciver::sig_complete)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UDT_Reciver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_UDT_Reciver.data,
    qt_meta_data_UDT_Reciver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UDT_Reciver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDT_Reciver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UDT_Reciver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDT_Reciver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void UDT_Reciver::sig_log(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDT_Reciver::sig_file_recv_rate(QString _t1, qint64 _t2, qint64 _t3, double _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void UDT_Reciver::sig_complete(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
