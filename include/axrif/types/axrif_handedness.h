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

#ifndef AXRIF_TYPES_AXRIF_HANDEDNESS_H_
#define AXRIF_TYPES_AXRIF_HANDEDNESS_H_

#include <cstdint>

extern "C" {

/*
 * Represents which hand is being used to interact.
 */
typedef enum : int8_t {
  /*
   * The left hand is being used to interact.
   */
  kAxrifHandednessLeft = 0,
  /*
   * The right hand is being used to interact.
   */
  kAxrifHandednessRight = 1,
  /*
   * Both hands are being used to interact.
   */
  kAxrifHandednessBoth = 2
} Axrif_Handedness_t;

}  // extern "C"

#endif  // AXRIF_TYPES_AXRIF_HANDEDNESS_H_
