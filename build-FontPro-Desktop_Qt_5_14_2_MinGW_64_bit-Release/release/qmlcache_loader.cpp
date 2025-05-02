#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,8,0,0,0,1,0,0,0,
82,0,0,0,0,0,1,0,0,0,0,0,0,0,164,0,
0,0,0,0,1,0,0,0,0,0,0,0,202,0,0,0,
0,0,1,0,0,0,0,0,0,0,120,0,0,0,0,0,
1,0,0,0,0,0,0,1,12,0,0,0,0,0,1,0,
0,0,0,0,0,0,44,0,0,0,0,0,1,0,0,0,
0,0,0,0,8,0,0,0,0,0,1,0,0,0,0,0,
0,0,232,0,0,0,0,0,1,0,0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,15,13,106,132,252,0,77,0,
115,0,103,0,68,0,105,0,97,0,108,0,111,0,103,0,
48,0,50,0,46,0,113,0,109,0,108,0,16,10,53,8,
60,0,66,0,97,0,115,0,101,0,67,0,111,0,109,0,
98,0,111,0,66,0,111,0,120,0,46,0,113,0,109,0,
108,0,16,2,27,5,28,0,66,0,97,0,115,0,101,0,
66,0,117,0,116,0,116,0,111,0,110,0,48,0,49,0,
46,0,113,0,109,0,108,0,19,6,153,194,28,0,73,0,
109,0,97,0,103,0,101,0,67,0,104,0,101,0,99,0,
107,0,66,0,111,0,120,0,48,0,50,0,46,0,113,0,
109,0,108,0,16,2,30,5,28,0,66,0,97,0,115,0,
101,0,66,0,117,0,116,0,116,0,111,0,110,0,48,0,
50,0,46,0,113,0,109,0,108,0,12,5,186,83,188,0,
77,0,97,0,105,0,110,0,86,0,105,0,101,0,119,0,
46,0,113,0,109,0,108,0,15,14,87,66,124,0,82,0,
111,0,119,0,67,0,104,0,101,0,99,0,107,0,66,0,
111,0,120,0,46,0,113,0,109,0,108,0,8,8,1,90,
92,0,109,0,97,0,105,0,110,0,46,0,113,0,109,0,
108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f__main_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__RowCheckBox_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__MainView_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__BaseButton02_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__ImageCheckBox02_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__BaseButton01_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__BaseComboBox_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__MsgDialog02_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/main.qml"), &QmlCacheGeneratedCode::_0x5f__main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/RowCheckBox.qml"), &QmlCacheGeneratedCode::_0x5f__RowCheckBox_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MainView.qml"), &QmlCacheGeneratedCode::_0x5f__MainView_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/BaseButton02.qml"), &QmlCacheGeneratedCode::_0x5f__BaseButton02_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/ImageCheckBox02.qml"), &QmlCacheGeneratedCode::_0x5f__ImageCheckBox02_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/BaseButton01.qml"), &QmlCacheGeneratedCode::_0x5f__BaseButton01_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/BaseComboBox.qml"), &QmlCacheGeneratedCode::_0x5f__BaseComboBox_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MsgDialog02.qml"), &QmlCacheGeneratedCode::_0x5f__MsgDialog02_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    return 1;
}
