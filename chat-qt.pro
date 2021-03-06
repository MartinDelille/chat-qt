QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    ContactModel.cpp \
    ConversationModel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$$TARGET/bin
else: unix:!android: target.path = /opt/$$TARGET/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ContactModel.h \
    ConversationModel.h

VERSION = $$system(git describe --abbrev=0 --tags)

BUNDLE_FILENAME = $${TARGET}.app
DMG_NAME = $${TARGET}_v$${VERSION}
DMG_FILENAME = $${DMG_NAME}.dmg

preparation.commands += echo "Preparation";
preparation.commands += rm -rf $$BUNDLE_FILENAME;

# Target for pretty DMG generation
dmg.commands += echo "Generate DMG";
dmg.commands += macdeployqt $$BUNDLE_FILENAME &&
dmg.commands += $$_PRO_FILE_PWD_/vendors/create-dmg/create-dmg \
        --volname $${DMG_NAME} \
        --background $${PWD}/images/dmg_bg.png \
        --icon $${BUNDLE_FILENAME} 150 218 \
        --window-pos 200 120 \
        --window-size 600 450 \
        --icon-size 100 \
        --hdiutil-quiet \
        --app-drop-link 450 218 \
        $${DMG_FILENAME} \
        $${BUNDLE_FILENAME}

QMAKE_EXTRA_TARGETS += preparation dmg
