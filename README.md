# Qt

### QT C++
* Faced Problem in running the QtCreator, the following error was generated when I run the application from Terminal.
* qt.qpa.plugin: Could not load the Qt platform plugin "xcb" in "" even though it was found.
* After enabling QT_DEBUG_PLUGINS by export QT_DEBUG_PLUGINS=1, I found that following library was missing "libxcb-xinerama0"
* Used the following command and after that it works fine "sudo apt-get install libxcb-xinerama0"
