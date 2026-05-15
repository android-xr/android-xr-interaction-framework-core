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

#ifndef AXRIF_TYPES_AXRIF_CONFIGURATIONS_H_
#define AXRIF_TYPES_AXRIF_CONFIGURATIONS_H_

extern "C" {

/*
 * Contains information for configuring interaction modules and behaviors.
 */
typedef struct Axrif_Configurations {
  /*
   * Indicates whether the Controller interaction mode is enabled.
   */
  bool is_controller_enabled;

  /*
   * Indicates whether Gaze and Pinch interaction mode is enabled.
   */
  bool is_gaze_pinch_enabled;

  /*
   * Indicates whether to use Head for Gaze and Pinch interaction mode.
   */
  bool use_head_for_gaze_interaction;

  /*
   * Indicates whether the Hand Raycast interaction mode is enabled.
   */
  bool is_hand_raycast_enabled;

  /*
   * Indicates whether the Hand Poke interaction mode is enabled.
   */
  bool is_hand_poke_enabled;

  /*
   * Indicates whether the Mouse interaction mode is enabled.
   */
  bool is_mouse_enabled;

  /*
   * Indicates whether to use sensitive thresholds for Gaze and Pinch
   * transitions.
   */
  bool use_sensitive_transitions;
} Axrif_Configurations_t;

}  // extern "C"

#endif  // AXRIF_TYPES_AXRIF_CONFIGURATIONS_H_
