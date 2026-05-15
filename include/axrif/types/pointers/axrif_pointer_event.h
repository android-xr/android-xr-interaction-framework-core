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

#ifndef AXRIF_TYPES_POINTERS_AXRIF_POINTER_EVENT_H_
#define AXRIF_TYPES_POINTERS_AXRIF_POINTER_EVENT_H_

#include <cstdint>

#include "axrif/types/pointers/axrif_pointer.h"

extern "C" {

/*
 * Represents a snapshot of the pointers for a given interaction type.
 */
typedef struct Axrif_PointerEvent {
  /*
   * Indicates whether the PointerEvent is valid. A PointerEvent is valid
   * only if it contains at least one valid pointer.
   */
  bool is_valid;

  /*
   * The number of valid pointers in the `pointers` array.
   */
  int8_t valid_pointer_count;

  /*
   * A valid pointer event may contain up to 10 valid pointers. Each subsequent
   * pointer returned requires that all previous pointers are valid (but they
   * may be inactive). The `valid_pointer_count` field indicates the number of
   * valid pointers in the `pointers` array. There is no guarantee on the order
   * of the pointers returned in a PointerEvent. The individual pointer types
   * must be checked on each usage.
   *
   * Note: This manual array management is necessary to allow for type
   * marshalling across interface boundaries. Special care must be taken when
   * reading and writing pointers to avoid out of bounds access.
   */
  Axrif_Pointer_t pointers[10];
} Axrif_PointerEvent_t;

}  // extern "C"

#endif  // AXRIF_TYPES_POINTERS_AXRIF_POINTER_EVENT_H_
