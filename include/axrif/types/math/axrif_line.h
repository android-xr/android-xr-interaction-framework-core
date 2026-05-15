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

#ifndef AXRIF_TYPES_MATH_AXRIF_LINE_H_
#define AXRIF_TYPES_MATH_AXRIF_LINE_H_

#include "axrif/types/math/axrif_vector3f.h"

extern "C" {

/*
 * Represents a line with two endpoints.
 */
typedef struct Axrif_Line {
  /*
   * The starting point of the line.
   */
  Axrif_Vector3f_t start;

  /*
   * The end point of the line.
   */
  Axrif_Vector3f_t end;

  /*
   * The normalized direction vector of the line.
   */
  Axrif_Vector3f_t direction;

  /*
   * Whether the line is intended to extend to infinity.
   */
  bool to_infinity;
} Axrif_Line_t;

}  // extern "C"

#endif  // AXRIF_TYPES_MATH_AXRIF_LINE_H_
