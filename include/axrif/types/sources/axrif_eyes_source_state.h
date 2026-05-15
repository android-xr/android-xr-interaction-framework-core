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

#ifndef AXRIF_TYPES_SOURCES_AXRIF_EYES_SOURCE_STATE_H_
#define AXRIF_TYPES_SOURCES_AXRIF_EYES_SOURCE_STATE_H_

#include "axrif/types/axrif_pose.h"

extern "C" {

/*
 * Represents the state of the eyes input source for a given frame.
 */
typedef struct Axrif_EyesSourceState {
  /*
   * Indicates whether the eyes source state is valid.
   */
  bool is_valid;

  /*
   * The 6-dof pose of the eyes aim. Can be used to cast a ray toward
   * potential interactable elements.
   */
  Axrif_Pose_t aim_pose;
} Axrif_EyesSourceState_t;

}  // extern "C"

#endif  // AXRIF_TYPES_SOURCES_AXRIF_EYES_SOURCE_STATE_H_
