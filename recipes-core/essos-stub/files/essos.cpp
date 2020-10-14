#include "essos-app.h"
#include <stdio.h>

/**
 * EssContextCreate
 *
 * Create an Essos application context.
 */
EssCtx* EssContextCreate()
{
    return NULL;
}

/**
 * EssContextDestroy
 *
 * Destroy and application instance.  If the application is running
 * it will be stopped.  All resources will be freed.
 */
void EssContextDestroy( EssCtx *ctx )
{
}

/**
 * EssContextGetLastErrorDetail
 *
 * Returns a null terminated string giving information about the
 * last error that has occurred.  If any Essos API fails, this method
 * can be used to obtain a string that should be logged.
 */
const char *EssContextGetLastErrorDetail( EssCtx *ctx )
{
    return NULL;
}

/**
 * EssContextInit
 *
 * Initialize an application context.  Inititialization will be performed
 * by EssContextStart but for use cases where it is not desired to start
 * an application context, EssContextInit must be called before methods
 * such as EssContextGetEGLDisplayType or ESSContextCreateNativeWindow
 * can be called.
 */
bool EssContextInit( EssCtx *ctx )
{
    return true;
}

/**
 * EssContextGetEGLDisplayType
 *
 * Returns a NativeDisplayType value that can be used in an eglGetDisplay call.  This
 * API is for applications that wish to create their EGL environment rather than allowing Essos
 * to do so automatically.
 */
bool EssContextGetEGLDisplayType( EssCtx *ctx, NativeDisplayType *displayType )
{
    return true;
}

/**
 * EssContextCreateNativeWindow
 *
 * Creates a NativeWindowType value that can be used in an eglCreateWindowSurface call.  Passing
 * a NULL value for pointer to nativeWindow causes the EGL environment to be automtically
 * setup during the call to EssContextStart.
 */
bool EssContextCreateNativeWindow( EssCtx *ctx, int width, int h, NativeWindowType *nativeWindow )
{
    return true;
}

/**
 * EssContextDestroyNativeWindow
 *
 * Destroys a NativeWindowType value obtained from EssContextCreateNativeWindow.
 */
bool EssContextDestroyNativeWindow( EssCtx *ctx, NativeWindowType nativeWindow )
{
    return true;
}

/**
 * EssContextSetKeyListener
 *
 * Set a key listener (see EssKeyListener) to receive key event callbacks. Key
 * codes are Linux codes defined by linux/input.h
 */
bool EssContextSetKeyListener( EssCtx *ctx, void *userData, EssKeyListener *listener )
{
    return true;
}

/**
 * EssContextSetPointerListener
 *
 * Set a pointer listener (see EssPointerListener) to receive pointer event callbacks.
 * Button codes are Linux codes defined by linux/input.h
 */
bool EssContextSetPointerListener( EssCtx *ctx, void *userData, EssPointerListener *listener )
{
    return true;
}

/**
 * EssContextSetTouchListener
 *
 * Set a touch listener (see EssTouchListener) to receive touch event callbacks.
 */
bool EssContextSetTouchListener( EssCtx *ctx, void *userData, EssTouchListener *listener )
{
    return true;
}

/**
 * EssContextSetSettingsListener
 *
 * Set a settings listener (see EssSettingsListener) to receive settings event callbacks.
 */
bool EssContextSetSettingsListener( EssCtx *ctx, void *userData, EssSettingsListener *listener )
{
    return true;
}

/**
 * EssContextSetTerminateListener
 *
 * Set a terminate listener (see EssTerminateListener) to receive a callback when the
 * application is being terminated.  The registered terminate listener will be invoked
 * if some abnormal condition required the application to shutdown.
 */
bool EssContextSetTerminateListener( EssCtx *ctx, void *userData, EssTerminateListener *listener )
{
    return true;
}

/**
 * EssContextSetName
 *
 * Establish name of the application context.  This must be called
 * before initializing or starting the application
 */
bool EssContextSetName( EssCtx *ctx, const char *name )
{
    return true;
}

/**
 * EssContextGetDisplaySize
 *
 * Returns the width and height of the display.
 */
bool EssContextGetDisplaySize( EssCtx *ctx, int *width, int *height )
{
    return true;
}

/**
 * EssContextGetDisplaySafeArea
 *
 * Returns a rectangle giving the display safe area.  This is the region of the display
 * that is guaranteed to be visible to the user and not hidden by overscan.
 */
bool EssContextGetDisplaySafeArea( EssCtx *ctx, int *x, int *y, int *width, int *height )
{
    return true;
}

/**
 * EssContextStart
 *
 * Start an application context running.  Context initialization will be performed by this call
 * if it has not already been done with EssContextInit. For applications that allow Essos to perform EGL
 * setup, the EGL environment will be active after calling this method. GLES2 rendering can then
 * be performed on this thread with buffer flips triggered by calls to EssContextUpdateDisplay. For
 * aoolications that manually perform EGL creation the EGL creation must be done between calling
 * EssContextInit and EssContextStart.  When manual EGL setup is done (EssContextCreateNativeWindow has
 * been called), EssContextStart will skip automatic EGL setup.  EssContextStart will also perform
 * setup required for user input and any other required setup.
 *
 * While running the EssContextRunEventLoop method must be regularly called.  
 */
bool EssContextStart( EssCtx *ctx )
{
    return true;
}

/**
 * EssContextStop
 *
 * Stop an application context.
 */
void EssContextStop( EssCtx *ctx )
{
}

/**
 * EssContextResizeWindow
 *
 * Set a new window size.  This API may be called in response to a display size notification received
 * via an Essos settings listener.
 */
bool EssContextResizeWindow( EssCtx *ctx, int width, int height )
{
    return true;
}

/**
 * EssContextRunEventLoopOnce
 *
 * Perform event processing.  This API will not block if no events are pending.
 * It must be called regularly while the aoplication is running.
 */
void EssContextRunEventLoopOnce( EssCtx *ctx)
{
}

/**
 * EssContextUpdateDisplay
 *
 * Perform a buffer flip operation.
 */
void EssContextUpdateDisplay( EssCtx *ctx )
{
}