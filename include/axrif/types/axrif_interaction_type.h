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

#ifndef AXRIF_TYPES_AXRIF_INTERACTION_TYPES_H_
#define AXRIF_TYPES_AXRIF_INTERACTION_TYPES_H_

#include <cstdint>

extern "C" {

/*
 * Represents a type of interaction that can be performed. These types map
 * directly to interaction modules.
 */
typedef enum : int8_t {
  /*
   * Either Eye or Head is used to point and hand pinches are used to select.
   */
  kAxrifInteractionTypeGazePinch = 0,
  /*
   * Hands are used to point and select from a distance.
   */
  kAxrifInteractionTypeHandRaycast = 1,
  /*
   * Hands are used to reach out and touch surfaces directly.
   */
  kAxrifInteractionTypeHandPoke = 2,
  /*
   * Hardware mouse is used to point and select.
   */
  kAxrifInteractionTypeMouse = 3,
  /*
   * 6DoF controllers are used to point and select.
   */
  kAxrifInteractionTypeController = 4
} Axrif_InteractionType_t;

}  // extern "C"

#endif  // AXRIF_TYPES_AXRIF_INTERACTION_TYPES_H_
