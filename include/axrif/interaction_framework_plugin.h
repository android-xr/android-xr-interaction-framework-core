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

#ifndef AXRIF_INTERACTION_FRAMEWORK_PLUGIN_H_
#define AXRIF_INTERACTION_FRAMEWORK_PLUGIN_H_

#include <cstdint>

#include "axrif/types/axrif_configurations.h"
#include "axrif/types/axrif_interaction_type.h"
#include "axrif/types/pointers/axrif_pointer_event.h"
#include "axrif/types/scene/axrif_collider.h"
#include "axrif/types/sources/axrif_controllers_source_state.h"
#include "axrif/types/sources/axrif_eyes_source_state.h"
#include "axrif/types/sources/axrif_hands_source_state.h"
#include "axrif/types/sources/axrif_head_source_state.h"
#include "axrif/types/sources/axrif_mouse_source_state.h"

/*
 * Context object used to facilitate calls to Interaction Framework methods.
 */
struct Axrif_Context_t;

extern "C" {

/*
 * Creates an instance of the Interaction Framework with the provided
 * `configurations`.
 *
 * @param @nonnull configurations The configurations used to initialize
 * interaction modules.
 * @param @nonnull out_context A pointer to the context object pointer used to
 * perform subsequent calls to Interaction Framework functions. `out_context`
 * *must* point to nullptr when provided to this function, otherwise creation is
 * skipped.
 */
void Axrif_Create(const Axrif_Configurations_t* configurations,
                  Axrif_Context_t** out_context);

/*
 * Updates the configurations used by the Interaction Framework. Note: This
 * method may delay transitions, so it should not be called per-frame.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param @nonnull configurations The new configurations to use.
 */
void Axrif_UpdateConfigurations(Axrif_Context_t* context,
                                const Axrif_Configurations_t* configurations);

/*
 * Cleans up memory and destroys the instance of the Interaction Framework. This
 * method should always be called before the retained context pointer goes out
 * of scope.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 */
void Axrif_Destroy(Axrif_Context_t* context);

/*
 * Adds a collider to the scene, or updates an existing collider with the same
 * id.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param @nonnull collider The collider to add or update.
 */
void Axrif_SetCollider(Axrif_Context_t* context,
                       const Axrif_Collider_t* collider);

/*
 * Removes a collider from the scene.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param collider_id The unique id of the collider to remove.
 */
void Axrif_RemoveCollider(Axrif_Context_t* context, int32_t collider_id);

/*
 * Clears all previously added colliders, leaving an empty scene.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 */
void Axrif_ClearAllColliders(Axrif_Context_t* context);

/*
 * Updates the state of the controllers input source.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param @nonnull controllers_source_state The new state of the controllers
 * input source.
 */
void Axrif_UpdateControllersSourceState(
    Axrif_Context_t* context,
    const Axrif_ControllersSourceState_t* controllers_source_state);

/*
 * Updates the state of the eyes input source.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param @nonnull eyes_source_state The new state of the eyes input source.
 */
void Axrif_UpdateEyesSourceState(
    Axrif_Context_t* context, const Axrif_EyesSourceState_t* eyes_source_state);

/*
 * Updates the state of the hands input source.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param @nonnull hands_source_state The new state of the hands input source.
 */
void Axrif_UpdateHandsSourceState(
    Axrif_Context_t* context,
    const Axrif_HandsSourceState_t* hands_source_state);

/*
 * Updates the state of the head input source.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param @nonnull head_source_state The new state of the head input source.
 */
void Axrif_UpdateHeadSourceState(
    Axrif_Context_t* context, const Axrif_HeadSourceState_t* head_source_state);

/*
 * Updates the state of the mouse input source.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param @nonnull mouse_source_state The new state of the mouse input source.
 */
void Axrif_UpdateMouseSourceState(
    Axrif_Context_t* context,
    const Axrif_MouseSourceState_t* mouse_source_state);

/*
 * Returns a PointerEvent containing all active pointers for the currently
 * selected interaction type for both hands, as determined by automatic
 * transitions.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param timestamp_ns The timestamp at which to get the PointerEvent, in
 * nanoseconds. For the vast majority of use cases, this should be the current
 * system time.
 * @param @nonnull out_pointer_event A pre-allocated PointerEvent to store the
 * results in.
 */
void Axrif_GetSelectedPointerEvent(Axrif_Context_t* context,
                                   int64_t timestamp_ns,
                                   Axrif_PointerEvent_t* out_pointer_event);

/*
 * Returns a PointerEvent containing all active pointers for the given
 * interaction type for both hands.
 *
 * @param @nonnull context The context handle used to identify the Interaction
 * Framework instance.
 * @param interaction_type The type of interaction to get the PointerEvent for.
 * @param timestamp_ns The timestamp at which to get the PointerEvent, in
 * nanoseconds. For the vast majority of use cases, this should be the current
 * system time.
 * @param @nonnull out_pointer_event A pre-allocated PointerEvent to store the
 * results in.
 */
void Axrif_GetPointerEvent(Axrif_Context_t* context,
                           Axrif_InteractionType_t interaction_type,
                           int64_t timestamp_ns,
                           Axrif_PointerEvent_t* out_pointer_event);

}  // extern "C"

#endif  // AXRIF_INTERACTION_FRAMEWORK_PLUGIN_H_
