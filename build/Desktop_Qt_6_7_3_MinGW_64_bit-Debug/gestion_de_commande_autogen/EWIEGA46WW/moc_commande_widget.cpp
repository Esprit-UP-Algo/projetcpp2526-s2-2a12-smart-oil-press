/****************************************************************************
** Meta object code from reading C++ file 'commande_widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../commande_widget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commande_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCommandeWidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCommandeWidgetENDCLASS = QtMocHelpers::stringData(
    "CommandeWidget",
    "onAjouterCommande",
    "",
    "onSupprimerCommande",
    "onModifierCommande",
    "onApplySearch",
    "onResetSearch",
    "refreshTableCommandes",
    "onApplySorting",
    "updateStatistics",
    "loadPriceByMonth",
    "loadMostOrderedProducts",
    "onDisplayCalendar",
    "refreshCalendarAlerts",
    "onSendEmailNotification",
    "exportPDF",
    "onEnableEmailNotification",
    "enabled",
    "onResetAjouter"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCommandeWidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x08,    1 /* Private */,
       3,    0,  111,    2, 0x08,    2 /* Private */,
       4,    0,  112,    2, 0x08,    3 /* Private */,
       5,    0,  113,    2, 0x08,    4 /* Private */,
       6,    0,  114,    2, 0x08,    5 /* Private */,
       7,    0,  115,    2, 0x08,    6 /* Private */,
       8,    0,  116,    2, 0x08,    7 /* Private */,
       9,    0,  117,    2, 0x08,    8 /* Private */,
      10,    0,  118,    2, 0x08,    9 /* Private */,
      11,    0,  119,    2, 0x08,   10 /* Private */,
      12,    0,  120,    2, 0x08,   11 /* Private */,
      13,    0,  121,    2, 0x08,   12 /* Private */,
      14,    0,  122,    2, 0x08,   13 /* Private */,
      15,    0,  123,    2, 0x08,   14 /* Private */,
      16,    1,  124,    2, 0x08,   15 /* Private */,
      18,    0,  127,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CommandeWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCommandeWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCommandeWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCommandeWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CommandeWidget, std::true_type>,
        // method 'onAjouterCommande'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSupprimerCommande'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onModifierCommande'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onApplySearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onResetSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshTableCommandes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onApplySorting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateStatistics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadPriceByMonth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadMostOrderedProducts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisplayCalendar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshCalendarAlerts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSendEmailNotification'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exportPDF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEnableEmailNotification'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onResetAjouter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CommandeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandeWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onAjouterCommande(); break;
        case 1: _t->onSupprimerCommande(); break;
        case 2: _t->onModifierCommande(); break;
        case 3: _t->onApplySearch(); break;
        case 4: _t->onResetSearch(); break;
        case 5: _t->refreshTableCommandes(); break;
        case 6: _t->onApplySorting(); break;
        case 7: _t->updateStatistics(); break;
        case 8: _t->loadPriceByMonth(); break;
        case 9: _t->loadMostOrderedProducts(); break;
        case 10: _t->onDisplayCalendar(); break;
        case 11: _t->refreshCalendarAlerts(); break;
        case 12: _t->onSendEmailNotification(); break;
        case 13: _t->exportPDF(); break;
        case 14: _t->onEnableEmailNotification((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->onResetAjouter(); break;
        default: ;
        }
    }
}

const QMetaObject *CommandeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCommandeWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CommandeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
