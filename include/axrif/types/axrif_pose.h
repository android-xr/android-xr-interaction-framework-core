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

#ifndef AXRIF_TYPES_AXRIF_POSE_H_
#define AXRIF_TYPES_AXRIF_POSE_H_

#include "axrif/types/math/axrif_quaternion.h"
#include "axrif/types/math/axrif_vector3f.h"

extern "C" {

/**
 * A 6-dof rigid transform comprising position and rotation.
 */
typedef struct Axrif_Pose {
  /**
   * 3-dof position component.
   */
  Axrif_Vector3f_t position;

  /**
   * 3-dof rotation component.
   */
  Axrif_Quaternion_t rotation;
} Axrif_Pose_t;

}  // extern "C"

#endif  // AXRIF_TYPES_AXRIF_POSE_H_
