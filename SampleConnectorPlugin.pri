!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    QT += core gui widgets

    !include($$PWD/PluginInterface/UrgBenriPluginInterface.pri) {
            error("Unable to include Viewer Plugin Interface.")
    }

    DEPENDPATH += $$PWD
    INCLUDEPATH += $$PWD

    FORMS += \
        $$PWD/SampleConnectorPlugin.ui

    HEADERS += \
        $$PWD/SampleConnectorPlugin.h \
        $$PWD/SampleDataConverter.h

    SOURCES += \
        $$PWD/SampleConnectorPlugin.cpp \
        $$PWD/SampleDataConverter.cpp

    RESOURCES += \
        $$PWD/SampleConnectorPlugin.qrc

    TRANSLATIONS = $$PWD/i18n/plugin_fr.ts \
            $$PWD/i18n/plugin_en.ts \
            $$PWD/i18n/plugin_ja.ts

}
