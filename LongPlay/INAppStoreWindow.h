//
//  INAppStoreWindow.h
//
//  Copyright 2011 Indragie Karunaratne. All rights reserved.
//
//  Licensed under the BSD License <http://www.opensource.org/licenses/bsd-license>
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
//  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <Cocoa/Cocoa.h>

#if __has_feature(objc_arc)
#define INAppStoreWindowCopy nonatomic, strong
#define INAppStoreWindowRetain nonatomic, strong
#else
#define INAppStoreWindowCopy nonatomic, copy
#define INAppStoreWindowRetain nonatomic, retain
#endif

/**
 A concrete NSButton subclass that allows to mimic standard window title bar "traffic light" buttons
 and replace their graphics with custom ones.
 */
@interface INWindowButton : NSButton

/**
 A group identifier the receiver was initialized with.
 */
@property (nonatomic, copy, readonly) NSString *groupIdentifier;

/**
 An image for the normal state.
 */
@property (nonatomic, strong) NSImage *activeImage;

/**
 An image for the normal state, but displayed when receiver's window in not a key.
 */
@property (nonatomic, strong) NSImage *activeNotKeyWindowImage;

/**
 An image used in disabled state.
 */
@property (nonatomic, strong) NSImage *inactiveImage;

/**
 An image used when user hovers receiver with mouse pointer.
 */
@property (nonatomic, strong) NSImage *rolloverImage;

/**
 An image for the pressed state.
 */
@property (nonatomic, strong) NSImage *pressedImage;

/**
 @param size Designated size of the button. System size is 14x16 and you are considered to use it.
 @param groupIdentifier ID of the group which will apply rollover effect to it's members. You may pass `nil`.
 @see initWithSize:groupIdentifier:
 */
+ (instancetype)windowButtonWithSize:(NSSize)size groupIdentifier:(NSString *)groupID;

/**
 @abstract Designated initializer.
 @discussion Initializes receiver with the given size and includes it to the group with the given identifier.
 Groups are used to apply rollover effect to all buttons that are inside the same group.
 E.g. close, minimize and zoom buttons should be inside the same group since they all get rollover effect
 when mouse pointer points to one of these buttons.
 @param size Designated size of the button. System size is 14x16 and you are considered to use it.
 @param groupIdentifier ID of the group which will apply rollover effect to it's members. You may pass `nil`.
 */
- (instancetype)initWithSize:(NSSize)size groupIdentifier:(NSString *)groupIdentifier;

@end

/** @class INTitlebarView
 Draws a default style Mac OS X title bar.
 */
@interface INTitlebarView : NSView
@end

/**
 @class INAppStoreWindow
 Creates a window similar to the Mac App Store window, with centered traffic lights and an 
 enlarged title bar. This does not handle creating the toolbar.
 */
@interface INAppStoreWindow : NSWindow

/** 
 The height of the title bar. By default, this is set to the standard title bar height. 
 */
@property (nonatomic) CGFloat titleBarHeight;

/** 
 The title bar view itself. Add subviews to this view that you want to show in the title bar
 (e.g. buttons, a toolbar, etc.). This view can also be set if you want to use a different 
 styled title bar aside from the default one (textured, etc.). 
 */
@property (INAppStoreWindowRetain) NSView *titleBarView;

/** 
 Set whether the fullscreen or traffic light buttons are horizontally centered 
 */
@property (nonatomic) BOOL centerFullScreenButton;
@property (nonatomic) BOOL centerTrafficLightButtons;

/**
 Whether the traffic light buttons are vertical
 */
@property (nonatomic) BOOL verticalTrafficLightButtons;

/** 
 If you want to hide the title bar in fullscreen mode, set this boolean to YES 
 */
@property (nonatomic) BOOL hideTitleBarInFullScreen;

/** 
 Use this API to hide the baseline INAppStoreWindow draws between itself and the main window contents. 
 */
@property (nonatomic) BOOL showsBaselineSeparator;

/** 
 Adjust the left padding of the traffic light buttons
 */
@property (nonatomic) CGFloat trafficLightButtonsLeftMargin;

/**
 Adjusts the top padding of the traffic light buttons
 */
@property (nonatomic) CGFloat trafficLightButtonsTopMargin;

/**
 Adjusts the right padding of the fullscreen button
 */
@property (nonatomic) CGFloat fullScreenButtonRightMargin;

/**
 Adjusts the top padding of the fullscreen button
 */
@property (nonatomic) CGFloat fullScreenButtonTopMargin;

/**
 Separation between traffic lights.
 */
@property (nonatomic) CGFloat trafficLightSeparation;

/** Adjust the visibility of the window's title. If `YES`, title will be shown even if titleBarDrawingBlock is set.
 To draw title on your own, set this property to `NO` and draw title inside titleBarDrawingBlock. */
@property (nonatomic) BOOL showsTitle;
@property (nonatomic) BOOL showsTitleInFullscreen;

/** 
 If not nil, default window buttons are hidden and the their provided alternatives is used. 
 */
@property (INAppStoreWindowRetain) INWindowButton *closeButton;
@property (INAppStoreWindowRetain) INWindowButton *minimizeButton;
@property (INAppStoreWindowRetain) INWindowButton *zoomButton;
@property (INAppStoreWindowRetain) INWindowButton *fullScreenButton;

/** 
 The colors of the title bar background gradient and baseline separator, in main and non-main variants. 
 */
@property (INAppStoreWindowRetain) NSColor *titleBarStartColor;
@property (INAppStoreWindowRetain) NSColor *titleBarEndColor;
@property (INAppStoreWindowRetain) NSColor *baselineSeparatorColor;
@property (INAppStoreWindowRetain) NSColor *titleTextColor;
@property (INAppStoreWindowRetain) NSShadow *titleTextShadow;

@property (INAppStoreWindowRetain) NSColor *inactiveTitleBarStartColor;
@property (INAppStoreWindowRetain) NSColor *inactiveTitleBarEndColor;
@property (INAppStoreWindowRetain) NSColor *inactiveBaselineSeparatorColor;
@property (INAppStoreWindowRetain) NSColor *inactiveTitleTextColor;
@property (INAppStoreWindowRetain) NSShadow *inactiveTitleTextShadow;

/**
 So much logic and work has gone into this window subclass to achieve a custom title bar,
 it would be a shame to have to re-invent that just to change the look. So this block can be used
 to override the default Mac App Store style titlebar drawing with your own drawing code!
 */
typedef void (^INAppStoreWindowTitleBarDrawingBlock)(BOOL drawsAsMainWindow, 
                                                     CGRect drawingRect, CGPathRef clippingPath);
@property (INAppStoreWindowCopy) INAppStoreWindowTitleBarDrawingBlock titleBarDrawingBlock;
@end
