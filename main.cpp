#include <iostream>
#include <string>
#include "jni.h"

using namespace std;

int main() {
    std::cout << "Running...!" << std::endl;
    JavaVM *javaVM;
    JNIEnv *jniEnv;
    JavaVMInitArgs vmInitArgs;
    JavaVMOption *options = new JavaVMOption[1];
    options[0].optionString = "-Djava.class.path=C:\\dev\\workspace\\jni-helloworld\\out\\production\\jni-helloworld";
    options[1].optionString = "-Djava.library.path=C:\\dev\\workspace\\jni-helloworld\\out\\production\\jni-helloworld";
    vmInitArgs.version = JNI_VERSION_1_8;
    vmInitArgs.nOptions = 2;
    vmInitArgs.options = options;
    vmInitArgs.ignoreUnrecognized = false;

    jint jvmInt = JNI_CreateJavaVM(&javaVM, (void**)&jniEnv, &vmInitArgs);

    delete options;

    if (jvmInt != JNI_OK) {

        cin.get();
        exit(EXIT_FAILURE);
    }

    cout << "JVM loaded - version : ";
    jint version = jniEnv->GetVersion();
    cout << (version>>16) << "." << (version&0x0f) << 0x0f<< endl;
    jclass cls = jniEnv->FindClass("com/pigopoyo/jni/Main");

    jmethodID  jmethodID1 = jniEnv->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
    jobjectArray  array = jniEnv->NewObjectArray(1, jniEnv->FindClass("java/lang/String"), jniEnv->NewStringUTF("Test"));

    jniEnv->CallStaticVoidMethod(cls, jmethodID1, array);
    jniEnv->DeleteLocalRef(array);

    if(cls == nullptr) {
        cerr << "ERROR: class not found !" <<endl;
    }
    javaVM->DestroyJavaVM();
    //cin.get();
    return 0;
}