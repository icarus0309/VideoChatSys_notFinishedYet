/****************************************************************************
** Meta object code from reading C++ file 'ChatRoom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WebChatSystemClient/ChatRoom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChatRoom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatRoom_t {
    QByteArrayData data[18];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatRoom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatRoom_t qt_meta_stringdata_ChatRoom = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ChatRoom"
QT_MOC_LITERAL(1, 9, 8), // "sign_out"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "closeChatroom"
QT_MOC_LITERAL(4, 33, 11), // "sendAskInfo"
QT_MOC_LITERAL(5, 45, 9), // "showRooms"
QT_MOC_LITERAL(6, 55, 13), // "loginedInRoom"
QT_MOC_LITERAL(7, 69, 11), // "const Pack*"
QT_MOC_LITERAL(8, 81, 12), // "askTcpCreate"
QT_MOC_LITERAL(9, 94, 11), // "updateRooms"
QT_MOC_LITERAL(10, 106, 21), // "map<QString,QString>&"
QT_MOC_LITERAL(11, 128, 6), // "onRead"
QT_MOC_LITERAL(12, 135, 19), // "on_btn_exit_clicked"
QT_MOC_LITERAL(13, 155, 20), // "on_btn_cre_r_clicked"
QT_MOC_LITERAL(14, 176, 21), // "on_btn_show_r_clicked"
QT_MOC_LITERAL(15, 198, 9), // "showAgain"
QT_MOC_LITERAL(16, 208, 14), // "createRoomLive"
QT_MOC_LITERAL(17, 223, 14) // "selectRoomLive"

    },
    "ChatRoom\0sign_out\0\0closeChatroom\0"
    "sendAskInfo\0showRooms\0loginedInRoom\0"
    "const Pack*\0askTcpCreate\0updateRooms\0"
    "map<QString,QString>&\0onRead\0"
    "on_btn_exit_clicked\0on_btn_cre_r_clicked\0"
    "on_btn_show_r_clicked\0showAgain\0"
    "createRoomLive\0selectRoomLive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatRoom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    1,   86,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   90,    2, 0x0a /* Public */,
       8,    1,   93,    2, 0x0a /* Public */,
       9,    1,   96,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    1,  104,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void ChatRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatRoom *_t = static_cast<ChatRoom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sign_out(); break;
        case 1: _t->closeChatroom(); break;
        case 2: _t->sendAskInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->showRooms(); break;
        case 4: _t->loginedInRoom((*reinterpret_cast< const Pack*(*)>(_a[1]))); break;
        case 5: _t->askTcpCreate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->updateRooms((*reinterpret_cast< map<QString,QString>(*)>(_a[1]))); break;
        case 7: _t->onRead(); break;
        case 8: _t->on_btn_exit_clicked(); break;
        case 9: _t->on_btn_cre_r_clicked(); break;
        case 10: _t->on_btn_show_r_clicked(); break;
        case 11: _t->showAgain(); break;
        case 12: _t->selectRoomLive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ChatRoom::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatRoom::sign_out)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ChatRoom::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatRoom::closeChatroom)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ChatRoom::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatRoom::sendAskInfo)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ChatRoom::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChatRoom::showRooms)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject ChatRoom::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ChatRoom.data,
      qt_meta_data_ChatRoom,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChatRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatRoom.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ChatRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ChatRoom::sign_out()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ChatRoom::closeChatroom()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ChatRoom::sendAskInfo(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ChatRoom::showRooms()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
