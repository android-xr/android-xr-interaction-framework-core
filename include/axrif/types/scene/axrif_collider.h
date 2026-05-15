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

#ifndef AXRIF_TYPES_SCENE_AXRIF_COLLIDER_H_
#define AXRIF_TYPES_SCENE_AXRIF_COLLIDER_H_

#include <cstdint>

#include "axrif/types/math/axrif_quaternion.h"
#include "axrif/types/math/axrif_vector3f.h"

extern "C" {

/*
 * Represents a type of collider that can be represented in the scene graph.
 */
typedef enum : int8_t {
  /*
   * A 2D rectangle in 3D space.
   */
  kAxrifColliderTypeRect = 0,
  /*
   * A 3D rectangular prism.
   */
  kAxrifColliderTypeBox = 1,
  /*
   * A 3D sphere.
   */
  kAxrifColliderTypeSphere = 2
} Axrif_ColliderType_t;

/*
 * A collider in the scene graph.
 */
typedef struct Axrif_Collider {
  /*
   * The unique identifier for this collider.
   */
  int32_t id;

  /*
   * The type of the collider.
   */
  Axrif_ColliderType_t type;

  /*
   * Indicates whether the collider can be interacted with directly via poke.
   */
  bool is_touchable;

  /*
   * The center point of the collider.
   */
  Axrif_Vector3f_t center;

  /*
   * The rotation applied to the collider, in the form of a unit quaternion. The
   * identity quaternion represents no rotation.
   */
  Axrif_Quaternion_t rotation;

  /*
   * The length of the collider, along the local X axis.
   * Required for colliders of type: Rect, Box
   */
  float length;

  /*
   * The height of the collider, along the local Y axis.
   * Required for colliders of type: Rect, Box
   */
  float height;

  /*
   * The depth of the collider, along the local Z axis.
   * Required for colliders of type: Box
   */
  float depth;

  /*
   * The radius of the collider.
   * Required for colliders of type: Sphere
   */
  float radius;
} Axrif_Collider_t;

}  // extern "C"

#endif  // AXRIF_TYPES_SCENE_AXRIF_COLLIDER_H_
