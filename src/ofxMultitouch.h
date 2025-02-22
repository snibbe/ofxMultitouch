#pragma once
#include "ofMain.h"

/*
ofxWinTouchHook.
- using 'hooks' to catch touch events before the window processes the events
- no need to modify glfw source with hooks
- tested on win7+8 with OF 0.9

Ref:
- http://www.unknowncheats.me/forum/c-and-c/83707-setwindowshookex-example.html
- http://stackoverflow.com/questions/19776866/c-global-hooking-why-setwindowshookex-return-null
- http://stackoverflow.com/questions/21069643/is-it-possible-to-remove-touch-messages-wm-pointerdown-etc-that-an-applicatio
*/

#ifdef TARGET_WIN32
// toggle this to use only windows 8 wm_pointer events instead of wm_touch
#define USE_WM_POINTER_EVENTS
#endif
#ifdef TARGET_LINUX
#include "MultitouchReader.h"
#endif
class ofxMultitouch {

public:
	static void EnableTouch();
	static void DisableTouch();

#ifdef TARGET_WIN32
	// making our own events as ofApp is giving us duplicates
	static ofEvent<ofTouchEventArgs> touchDown;
	static ofEvent<ofTouchEventArgs> touchMoved;
	static ofEvent<ofTouchEventArgs> touchUp;
	static ofEvent<ofMouseEventArgs> mouseButtonDown;
	static ofEvent<ofMouseEventArgs> mouseButtonUp;
#endif

#ifdef TARGET_LINUX
private:
	static MultitouchReader multitouchReader;
#endif
};
