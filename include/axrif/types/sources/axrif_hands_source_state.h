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

#ifndef AXRIF_TYPES_SOURCES_AXRIF_HANDS_SOURCE_STATE_H_
#define AXRIF_TYPES_SOURCES_AXRIF_HANDS_SOURCE_STATE_H_

#include <cstdint>

#include "axrif/types/axrif_pose.h"
#include "axrif/types/math/axrif_vector3f.h"

extern "C" {

/*
 * Represents the state of a single hand for a given frame.
 */
typedef struct Axrif_HandState {
  /*
   * Indicates whether the hand is currently active.
   */
  bool is_active;

  /*
   * The 6-dof pose of the pinch, as defined by the OpenXR
   * EXT_hand_interaction spec.
   */
  Axrif_Pose_t pinch_pose;

  /*
   * The 6-dof pose of the hand aim, as defined by the OpenXR
   * EXT_hand_interaction spec.
   */
  Axrif_Pose_t aim_pose;

  /*
   * The 6-dof pose of the poke, as defined by the OpenXR
   * EXT_hand_interaction spec.
   */
  Axrif_Pose_t poke_pose;

  /*
   * The 6-dof pose of the hand grip, as defined by the OpenXR
   * EXT_hand_interaction spec.
   */
  Axrif_Pose_t grip_pose;

  /*
   * The floating point value of the pinch gesture, as defined by the OpenXR
   * EXT_hand_interaction spec.
   */
  float pinch_value;

  /*
   * The floating point value of the aim activate gesture, as defined by the
   * OpenXR EXT_hand_interaction spec.
   */
  float aim_activate_value;

  /*
   * A vector representing the linear velocity of the hand's palm joint, as
   * defined by the OpenXR XrHandJointVelocitiesEXT spec.
   */
  Axrif_Vector3f_t palm_joint_velocity;
} Axrif_HandState_t;

/*
 * Represents the state of the hands input source for a given frame.
 */
typedef struct Axrif_HandsSourceState {
  /*
   * Indicates whether the hands source state is valid.
   */
  bool is_valid;

  /*
   * The current state of the left hand.
   */
  Axrif_HandState_t left_hand;

  /*
   * The current state of the right hand.
   */
  Axrif_HandState_t right_hand;
} Axrif_HandsSourceState_t;

}  // extern "C"

#endif  // AXRIF_TYPES_SOURCES_AXRIF_HANDS_SOURCE_STATE_H_
