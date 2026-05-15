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

#ifndef AXRIF_TYPES_SOURCES_AXRIF_MOUSE_SOURCE_STATE_H_
#define AXRIF_TYPES_SOURCES_AXRIF_MOUSE_SOURCE_STATE_H_

#include "axrif/types/axrif_pose.h"

extern "C" {

/*
 * Represents the state of the mouse input source for a given frame.
 */
typedef struct Axrif_MouseSourceState {
  /*
   * Indicates whether the mouse source state is valid.
   */
  bool is_valid;

  /*
   * The 6-dof pose of the mouse pointer aim. Can be used to cast a ray toward
   * potential interactable elements. The position component of the pose is
   * static, typically at the position of the user's head.
   */
  Axrif_Pose_t aim_pose;

  /*
   * Indicates whether the primary button on the mouse is clicking.
   */
  bool is_primary_clicking;

  /*
   * Indicates whether the secondary button on the mouse is clicking.
   */
  bool is_secondary_clicking;

  /*
   * Indicates whether the tertiary button on the mouse is clicking.
   */
  bool is_tertiary_clicking;

  /*
   * A value between -1 and 1 indicating the amount of scroll in the vertical
   * direction.
   */
  float vertical_scroll_value;

  /*
   * A value between -1 and 1 indicating the amount of scroll in the horizontal
   * direction.
   */
  float horizontal_scroll_value;
} Axrif_MouseSourceState_t;

}  // extern "C"

#endif  // AXRIF_TYPES_SOURCES_AXRIF_MOUSE_SOURCE_STATE_H_
