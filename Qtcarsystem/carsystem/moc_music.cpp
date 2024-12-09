/****************************************************************************
** Meta object code from reading C++ file 'music.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "music.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'music.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Music_t {
    QByteArrayData data[18];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Music_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Music_t qt_meta_stringdata_Music = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Music"
QT_MOC_LITERAL(1, 6, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(4, 53, 31), // "on_listWidget_itemDoubleClicked"
QT_MOC_LITERAL(5, 85, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(6, 102, 4), // "item"
QT_MOC_LITERAL(7, 107, 26), // "on_pushButton_play_clicked"
QT_MOC_LITERAL(8, 134, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(9, 158, 29), // "on_verticalSlider_sliderMoved"
QT_MOC_LITERAL(10, 188, 8), // "position"
QT_MOC_LITERAL(11, 197, 14), // "on_del_clicked"
QT_MOC_LITERAL(12, 212, 26), // "on_pushButton_next_clicked"
QT_MOC_LITERAL(13, 239, 26), // "on_pushButton_prev_clicked"
QT_MOC_LITERAL(14, 266, 16), // "set_time_process"
QT_MOC_LITERAL(15, 283, 12), // "send_process"
QT_MOC_LITERAL(16, 296, 33), // "on_horizontalSlider_sliderPre..."
QT_MOC_LITERAL(17, 330, 34) // "on_horizontalSlider_sliderRel..."

    },
    "Music\0on_pushButton_clicked\0\0"
    "on_pushButton_2_clicked\0"
    "on_listWidget_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_pushButton_play_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_verticalSlider_sliderMoved\0position\0"
    "on_del_clicked\0on_pushButton_next_clicked\0"
    "on_pushButton_prev_clicked\0set_time_process\0"
    "send_process\0on_horizontalSlider_sliderPressed\0"
    "on_horizontalSlider_sliderReleased"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Music[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    1,   86,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,
      16,    0,   94,    2, 0x08 /* Private */,
      17,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Music::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Music *_t = static_cast<Music *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_play_clicked(); break;
        case 4: _t->on_pushButton_3_clicked(); break;
        case 5: _t->on_verticalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_del_clicked(); break;
        case 7: _t->on_pushButton_next_clicked(); break;
        case 8: _t->on_pushButton_prev_clicked(); break;
        case 9: _t->set_time_process(); break;
        case 10: _t->send_process(); break;
        case 11: _t->on_horizontalSlider_sliderPressed(); break;
        case 12: _t->on_horizontalSlider_sliderReleased(); break;
        default: ;
        }
    }
}

const QMetaObject Music::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Music.data,
      qt_meta_data_Music,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Music::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Music::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Music.stringdata0))
        return static_cast<void*>(const_cast< Music*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Music::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
