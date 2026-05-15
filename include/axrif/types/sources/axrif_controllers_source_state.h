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

#ifndef AXRIF_TYPES_SOURCES_AXRIF_CONTROLLERS_SOURCE_STATE_H_
#define AXRIF_TYPES_SOURCES_AXRIF_CONTROLLERS_SOURCE_STATE_H_

#include "axrif/types/axrif_pose.h"

extern "C" {

/*
 * Represents the state of a single controller for a given frame.
 */
typedef struct Axrif_ControllerState {
  /*
   * Indicates whether the controller is currently active.
   */
  bool is_active;

  /*
   * The 6-dof pose of the controller aim, as defined by the OpenXR spec.
   */
  Axrif_Pose_t aim_pose;

  /*
   * The boolean state of the primary action (A or X), as defined by the OpenXR
   * spec.
   */
  bool is_primary_pressed;

  /*
   * The boolean state of the secondary action (B or Y), as defined by the
   * OpenXR spec.
   */
  bool is_secondary_pressed;

  /*
   * The X-axis value of the controller thumbstick.
   */
  float thumbstick_x_value;

  /*
   * The Y-axis value of the controller thumbstick.
   */
  float thumbstick_y_value;

  /*
   * The boolean state of the thumbstick press action.
   */
  bool is_thumbstick_pressed;

  /*
   * The trigger value of the controller.
   */
  float trigger_value;
} Axrif_ControllerState_t;

/*
 * Represents the state of the 6DoF controllers input source for a given frame.
 */
typedef struct Axrif_ControllersSourceState {
  /*
   * Indicates whether the controllers source state is valid.
   */
  bool is_valid;

  /*
   * The current state of the left controller.
   */
  Axrif_ControllerState_t left_controller;

  /*
   * The current state of the right controller.
   */
  Axrif_ControllerState_t right_controller;
} Axrif_ControllersSourceState_t;

}  // extern "C"

#endif  // AXRIF_TYPES_SOURCES_AXRIF_CONTROLLERS_SOURCE_STATE_H_
