CONFIG(debug, debug|release):{
	FILE_POSTFIX = D
	DIR_COMPILEMODE = Debug
}
else:CONFIG(release, debug|release):{
	FILE_POSTFIX =
	DIR_COMPILEMODE = Release
}

win32:{
    CONFIG(MinGW, MinGW|MinGW32|MinGW64|MSVC|MSVC32|MSVC64):{
        DIR_PLATFORM = Win32
        DIR_COMPILER = MinGW
        FILE_LIB_PREFIX = lib
        FILE_LIB_EXT = .a
    }
    else:CONFIG(MinGW32, MinGW|MinGW32|MinGW64|MSVC|MSVC32|MSVC64):{
        DIR_PLATFORM = Win32
        DIR_COMPILER = MinGW
        FILE_LIB_PREFIX = lib
        FILE_LIB_EXT = .a
    }
    else:CONFIG(MinGW64, MinGW|MinGW32|MinGW64|MSVC|MSVC32|MSVC64):{
        DIR_PLATFORM = Win64
        DIR_COMPILER = MinGW
        FILE_LIB_PREFIX = lib
        FILE_LIB_EXT = .a
    }
    else:CONFIG(MSVC, MinGW|MinGW32|MinGW64|MSVC|MSVC32|MSVC64):{
        DIR_PLATFORM = Win32
        DIR_COMPILER = MSVC
        FILE_LIB_PREFIX =
        FILE_LIB_EXT = .lib
    }
    else:CONFIG(MSVC32, MinGW|MinGW32|MinGW64|MSVC|MSVC32|MSVC64):{
        DIR_PLATFORM = Win32
        DIR_COMPILER = MSVC
        FILE_LIB_PREFIX =
        FILE_LIB_EXT = .lib
    }
    else:CONFIG(MSVC64, MinGW|MinGW32|MinGW64|MSVC|MSVC32|MSVC64):{
        DIR_PLATFORM = Win64
        DIR_COMPILER = MSVC
        FILE_LIB_PREFIX =
        FILE_LIB_EXT = .lib
    }

    FILE_DLL_PREFIX =
    FILE_DLL_EXT = .dll
}
else:linux:{
    CONFIG(GCC, GCC|GCC32|GCC64):{
            DIR_PLATFORM = Linux32
            DIR_COMPILER = GCC32
    }
    else:CONFIG(GCC32, GCC|GCC32|GCC64):{
            DIR_PLATFORM = Linux32
            DIR_COMPILER = GCC32
    }
    else:CONFIG(GCC64, GCC|GCC32|GCC64):{
            DIR_PLATFORM = Linux64
            DIR_COMPILER = GCC64
    }

    FILE_LIB_PREFIX = lib
    FILE_LIB_EXT = .a
    FILE_DLL_PREFIX = lib
    FILE_DLL_EXT = .so
}

CONFIG(USE_LIBRARY_ABN):{
	FILE_ABN_PREFIX = $${FILE_LIB_PREFIX}
	FILE_ABN_EXT = $${FILE_LIB_EXT}
}
else:{
	FILE_ABN_PREFIX = $${FILE_DLL_PREFIX}
	FILE_ABN_EXT = $${FILE_DLL_EXT}
}


# 始终编译成静态库
CONFIG += staticlib

#QMAKE_LFLAGS += -static-libgcc
QMAKE_LFLAGS += --disable-sjlj-exceptions

CONFIG(staticlib, staticlib):{
	DIR_DEPEND_DEST = $$PWD/../Lib/$${DIR_PLATFORM}/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
	DESTDIR  = $$PWD/../Lib/$${DIR_PLATFORM}/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
}
else:{
	DIR_DEPEND_DEST = $$PWD/../Dll/$${DIR_PLATFORM}/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
	DESTDIR  = $$PWD/../Dll/$${DIR_PLATFORM}/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
}
