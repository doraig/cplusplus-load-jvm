set(FIND_JVM_PATHS
        C:\\Program Files\\Java\\jdk1.8.0_121)

set(FIND_CLASS_PATH
        C:\\dev\\workspace\\jni-helloworld\\out\\production\\jni-helloworld)

find_path(CLASS_PATH_MAIN Main.class
        PATH_SUFFIXES com\\pigopoyo\\jni
        PATHS ${FIND_CLASS_PATH}
        )

find_library(JVM_LIBRARY
        NAMES jvm
        PATH_SUFFIXES lib
        PATHS ${FIND_JVM_PATHS})

message("hi -> " ${FIND_JVM_PATHS})