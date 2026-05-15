// Copyright 2025 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef AXRIF_TYPES_POINTERS_AXRIF_POINTER_H_
#define AXRIF_TYPES_POINTERS_AXRIF_POINTER_H_

#include <cstdint>

#include "axrif/types/axrif_handedness.h"
#include "axrif/types/math/axrif_line.h"

extern "C" {

/*
 * Represents the type of the pointer held in a pointer event. Some interaction
 * modes may create multiple pointer types.
 */
typedef enum : int8_t {
  /*
   * Used by the Hand Raycast interaction type.
   */
  kAxrifPointerTypeHandRaycast = 0,
  /*
   * Used by the Hand Poke interaction type.
   */
  kAxrifPointerTypeHandPoke = 1,
  /*
   * Used by the Gaze Pinch interaction type. Gaze pointers are used to aim and
   * HandGazePinch pointers are used for selection.
   */
  kAxrifPointerTypeHandGazePinch = 2,
  kAxrifPointerTypeGaze = 3,
  /*
   * Used by the Mouse interaction type.
   */
  kAxrifPointerTypeMouse = 4,
  /*
   * Used by the Controller interaction type.
   */
  kAxrifPointerTypeController = 5
} Axrif_PointerType_t;

/*
 * Flags representing the current activation states for a pointer.
 */
typedef enum : int32_t {
  // Inactive flag.
  kAxrifPointerActivationFlagNone = 0,

  // The primary button (typically the Left Mouse Button). Used for selection,
  // clicking, and primary interactions.
  kAxrifPointerActivationFlagPrimaryButton = 1 << 0,

  // The secondary button (typically the Right Mouse Button). Used for context
  // menus or alternative interactions.
  kAxrifPointerActivationFlagSecondaryButton = 1 << 1,

  // The tertiary button (typically the Middle Mouse Button or Scroll Wheel
  // click). Used for advanced navigation, tab opening, or auxiliary actions.
  kAxrifPointerActivationFlagTertiaryButton = 1 << 2
} Axrif_PointerActivationFlagType_t;

/*
 * Represents a single pointer that can be dispatched from an interaction.
 */
typedef struct Axrif_Pointer {
  /*
   * Indicates whether the pointer is valid.
   */
  bool is_valid;

  /*
   * Indicates whether the pointer is active. A pointer may become inactive if
   * the underlying source data becomes invalid (i.e. due to tracking loss) or
   * if the interaction module determines that the pointer is not currently
   * needed.
   */
  bool is_active;

  /*
   * The type of the pointer.
   */
  Axrif_PointerType_t type;

  /*
   * The handedness of the pointer.
   */
  Axrif_Handedness_t handedness;

  /*
   * The line along which the pointer is cast.
   */
  Axrif_Line_t line;

  /*
   * A value from -1 to 1 indicating the amount of horizontal scrolling provided
   * by a device with built-in scrolling capabilities (e.g., a mouse).
   */
  float horizontal_scroll;

  /*
   * A value from -1 to 1 indicating the amount of vertical scrolling provided
   * by a device with built-in scrolling capabilities (e.g., a mouse).
   */
  float vertical_scroll;

  /*
   * The amount of activation from [0, 1]. 0 represents no activation, 1
   * represents full activation. Some interactions may choose to populate this
   * field as a simple boolean value.
   */
  float activation_amount;

  /*
   * Used to hold additional information about the pointer's activation, e.g.
   * additional or alternate buttons.
   */
  Axrif_PointerActivationFlagType_t activation_flags;
} Axrif_Pointer_t;

}  // extern "C"

#endif  // AXRIF_TYPES_POINTERS_AXRIF_POINTER_H_
