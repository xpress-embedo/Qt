# Qt

### QT C++
* Faced Problem in running the QtCreator, the following error was generated when I run the application from Terminal.
* qt.qpa.plugin: Could not load the Qt platform plugin `xcb` in "" even though it was found.
* After enabling QT_DEBUG_PLUGINS by export QT_DEBUG_PLUGINS=1, I found that following library was missing `libxcb-xinerama0`
* Used the following command and after that it works fine `sudo apt-get install libxcb-xinerama0`  

### Designer is missing while working with `*.qml` files
In most cases this plugin is disabled by default, and to enable this plugin, first go to `Help` -> `About Plugins` -> `Search for Qt Quick`.  
Enable this and restart the Qt Creator IDE.  

### QML Designer Colors by default colors are not correct
Sometimes I have observed that whenever I am adding component in designer the color of the text is changed to white, and similarly the color which should be white changes to black and black changes to white, which gives quite an unpleasant feeling.  
I don't have the proper solution for this problem, but temporary solution is to change the theme let's say from `Dark` to `Flat Dark` and restart the Qt Creator, and next time when it opens the problem is gone.  



