# Config Para
CONFIG(debug, debug|release):{
        FILE_POSTFIX = D
        DIR_COMPILEMODE = Debug
}
else:CONFIG(release, debug|release):{
        FILE_POSTFIX =
        DIR_COMPILEMODE = Release
}

win32:{
        CONFIG(MinGW, MinGW|MSVC):{
                DIR_COMPILER = MinGW
                FILE_LIB_PREFIX = lib
                FILE_LIB_EXT = .a
        }
        else:CONFIG(MSVC, MinGW|MSVC):{
                DIR_COMPILER = MSVC
                FILE_LIB_PREFIX =
                FILE_LIB_EXT = .lib
        }

        DIR_PLATFORM = Win32
        FILE_DLL_PREFIX =
        FILE_DLL_EXT = .dll

        DESTDIR	= $$PWD/../Bin/$${DIR_PLATFORM}/Client/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
}
else:android:{
        CONFIG(ARM_GCC_4.4.3, ARM_GCC_4.4.3|ARM_GCC_4.6|ARM_GCC_4.7|ARM_GCC_4.8):{
                DIR_COMPILER = ARM_GCC_4.4.3
        }
        else:CONFIG(ARM_GCC_4.6, ARM_GCC_4.4.3|ARM_GCC_4.6|ARM_GCC_4.7|ARM_GCC_4.8):{
                DIR_COMPILER = ARM_GCC_4.6
        }
        else:CONFIG(ARM_GCC_4.7, ARM_GCC_4.4.3|ARM_GCC_4.6|ARM_GCC_4.7|ARM_GCC_4.8):{
                DIR_COMPILER = ARM_GCC_4.7
        }
        else:CONFIG(ARM_GCC_4.8, ARM_GCC_4.4.3|ARM_GCC_4.6|ARM_GCC_4.7|ARM_GCC_4.8):{
                DIR_COMPILER = ARM_GCC_4.8
        }

        CONFIG(X86_GCC_4.4.3, X86_GCC_4.4.3|X86_GCC_4.6|X86_GCC_4.7|X86_GCC_4.8):{
                DIR_COMPILER = X86_GCC_4.4.3
        }
        else:CONFIG(X86_GCC_4.6, X86_GCC_4.4.3|X86_GCC_4.6|X86_GCC_4.7|X86_GCC_4.8):{
                DIR_COMPILER = X86_GCC_4.6
        }
        else:CONFIG(X86_GCC_4.7, X86_GCC_4.4.3|X86_GCC_4.6|X86_GCC_4.7|X86_GCC_4.8):{
                DIR_COMPILER = X86_GCC_4.7
        }
        else:CONFIG(X86_GCC_4.8, X86_GCC_4.4.3|X86_GCC_4.6|X86_GCC_4.7|X86_GCC_4.8):{
                DIR_COMPILER = X86_GCC_4.8
        }

        DIR_PLATFORM = Android
        FILE_LIB_PREFIX = lib
        FILE_LIB_EXT = .a
        FILE_DLL_PREFIX = lib
        FILE_DLL_EXT = .so

        # 始终编译成静态库
        CONFIG += staticlib

        DESTDIR  = $$PWD/../Bin/$${DIR_PLATFORM}/Client/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
}
else:ios:{
        CONFIG(LLVM, LLVM):{
                DIR_COMPILER = LLVM
        }

        DEFINES += IOS
        DIR_PLATFORM = IOS
        FILE_LIB_PREFIX = lib
        FILE_LIB_EXT = .a
        FILE_DLL_PREFIX = lib
        FILE_DLL_EXT = .so

        # 始终编译成静态库
        CONFIG += staticlib

        DESTDIR  = $$PWD/../Bin/$${DIR_PLATFORM}/Client/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
}
else:mac:{
        CONFIG(clang, clang):{
                DIR_COMPILER = clang
        }

        DEFINES += MAC
        DIR_PLATFORM = MAC
        FILE_LIB_PREFIX = lib
        FILE_LIB_EXT = .a
        FILE_DLL_PREFIX = lib
        FILE_DLL_EXT = .so

        # 始终编译成静态库
        CONFIG += staticlib

        DESTDIR  = $$PWD/../Bin/$${DIR_PLATFORM}/Client/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
}
else:linux:{
        CONFIG(GCC, GCC|GCC32|GCC64):{
                        DIR_COMPILER = GCC32
                        DIR_PLATFORM = Linux32
        }
        else:CONFIG(GCC32, GCC|GCC32|GCC64):{
                        DIR_COMPILER = GCC32
                        DIR_PLATFORM = Linux32
        }
        else:CONFIG(GCC64, GCC|GCC32|GCC64):{
                        DIR_COMPILER = GCC64
                        DIR_PLATFORM = Linux64
        }

        FILE_LIB_PREFIX = lib
        FILE_LIB_EXT = .a
        FILE_DLL_PREFIX = lib
        FILE_DLL_EXT = .so

        DESTDIR  = $$PWD/../Bin/$${DIR_PLATFORM}/Client/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
}

DIR_DEPEND_DEST = $$PWD/../Bin/$${DIR_PLATFORM}/Client/$${DIR_COMPILER}/$${DIR_COMPILEMODE}
