// Copyright 2015 Google Inc.

/** @cond ENABLE_FEATURE_GUI */

#import <GoogleCast/GCKDefines.h>

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * @file GCKUIDeviceVolumeController.h
 */

#ifdef USE_CAST_DYNAMIC_FRAMEWORK
#define GCKUIDeviceVolumeControllerClass NSClassFromString(@"GCKUIDeviceVolumeController")
#endif

@class GCKUIButton;

GCK_ASSUME_NONNULL_BEGIN

/**
 * @var GCKUIControlStateMuteOff
 * Custom <a href="https://goo.gl/tZWsqZ"><b>UIControlState</b></a> for the mute toggle button;
 * corresponds to "mute off".
 *
 * @since 3.0
 */
GCK_EXTERN
const UIControlState GCKUIControlStateMuteOff;

/**
 * @var GCKUIControlStateMuteOn
 * Custom <a href="https://goo.gl/tZWsqZ"><b>UIControlState</b></a> for the mute toggle button;
 * corresponds to "mute on".
 *
 * @since 3.0
 */
GCK_EXTERN
const UIControlState GCKUIControlStateMuteOn;

/**
 * A controller for UI views that are used to control or display the volume and mute state of a Cast
 * receiver. The calling application registers its volume-related UI controls with the controller by
 * setting the appropriate properties. The controller then responds to touch events on the controls
 * by issuing the appropriate volume commands to the receiver, and updates the controls based on
 * status information received from the receiver. The controller automatically enables and disables
 * the UI controls as appropriate for the current session and receiver state.
 *
 * @since 3.0
 */
GCK_EXPORT
@interface GCKUIDeviceVolumeController : NSObject

/**
 * A "volume up" button. When the button is tapped, the receiver's volume is increased by the
 * volume increment. The button will be disabled if there is no session currently active or if the
 * current session does not support volume adjustment.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *volumeUpButton;

/**
 * A "volume down" button. When the button is tapped, the receiver's volume is decreased by the
 * volume increment. The button will be disabled if there is no session currently active or if the
 * current session does not support volume adjustment.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UIButton *volumeDownButton;

/**
 * A slider for displaying and changing the current receiver volume. When the slider's value is
 * changed by the user, the volume is updated on the receiver. When a receiver status is received
 * that indicates a change in the receiver's volume, the slider value is updated accordingly. The
 * slider will be disabled if there is no session currently active or if the current session does
 * not support volume adjustment.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UISlider *volumeSlider;

/**
 * A switch for toggling the receiver's mute state. When the switch is toggled, the mute state is
 * updated on the receiver. When a receiver status is received that indicates a change in the
 * receiver's mute state, the switch is updated accordingly. The switch will be disabled if there is
 * no session currently active  or if the current session does not support muting.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) UISwitch *muteSwitch;

/**
 * A toggle button for muting/unmuting the receiver. The caller should set appropriate "muted" and
 * "unmuted" icons for the button's @ref GCKUIControlStateMuteOn and @ref GCKUIControlStateMuteOff
 * states, respectively. The button's state is automatically updated to reflect the current mute
 * state on the receiver. When the button is tapped, the mute state is updated on the receiver. The
 * button will be disabled if there is no session currently active or if the current session does
 * not support volume muting.
 */
@property(nonatomic, weak, readwrite, GCK_NULLABLE) GCKUIButton *muteToggleButton;

/**
 * Designated initializer.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * A convenience method for changing the receiver's volume.  Delegates to the currently active
 * GCKSession object.
 *
 * @param volume The new volume. Must be a value in the range [0.0, 1.0].
 */
- (void)setVolume:(float)volume;

/**
 * A convenience method for changing the receiver's mute state.  Delegates to the currently active
 * GCKSession object.
 *
 * @param muted The new mute state.
 */
- (void)setMuted:(BOOL)muted;

/**
 * A convenience method for increasing the receiver's volume by the volume increment. Delegates to
 * the currently active GCKSession object.
 */
- (void)volumeUp;

/**
 * A convenience method for decreasing the receiver's volume by the volume increment. Delegates to
 * the currently active GCKSession object.
 */
- (void)volumeDown;

/**
 * A convenience method for toggling the mute state. Delegates to the currently active GCKSession
 * object.
 */
- (void)toggleMuted;

@end

GCK_ASSUME_NONNULL_END

/** @endcond */
