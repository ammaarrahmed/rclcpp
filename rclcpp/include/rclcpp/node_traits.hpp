// Copyright 2026 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLCPP__NODE_TRAITS_HPP_
#define RCLCPP__NODE_TRAITS_HPP_

#include <type_traits>

/** \file
 * Traits for identifying the concrete node class families at compile time.
 *
 * Both traits ignore cv-qualifiers and references. Pointers and smart pointers
 * are not unwrapped. Private, protected and ambiguous bases count as bases,
 * following std::is_base_of; a true result does not imply a public base conversion.
 * As with std::is_base_of, a queried non-union class type must be complete unless it is the
 * same type as the trait's base. Include the corresponding node header before
 * querying a derived class.
 *
 * These traits do not check node interfaces or runtime lifecycle state.
 * Use node interface traits or rclcpp::node_interfaces::NodeInterfaces for APIs
 * that accept node-like objects through their interfaces.
 */

namespace rclcpp_lifecycle
{
class LifecycleNode;
}  // namespace rclcpp_lifecycle

namespace rclcpp
{
class Node;

/// True for rclcpp::Node and classes derived from it.
/**
 * This checks inheritance from Node, independently of is_lifecycle_node.
 */
template<typename T>
struct is_node : std::is_base_of<Node, std::remove_cv_t<std::remove_reference_t<T>>>
{};

/// Convenience variable for is_node<T>::value.
template<typename T>
inline constexpr bool is_node_v = is_node<T>::value;

/// True for rclcpp_lifecycle::LifecycleNode and classes derived from it.
/**
 * This checks inheritance from LifecycleNode, independently of is_node.
 */
template<typename T>
struct is_lifecycle_node : std::is_base_of<
    rclcpp_lifecycle::LifecycleNode, std::remove_cv_t<std::remove_reference_t<T>>>
{};

/// Convenience variable for is_lifecycle_node<T>::value.
template<typename T>
inline constexpr bool is_lifecycle_node_v = is_lifecycle_node<T>::value;

}  // namespace rclcpp

#endif  // RCLCPP__NODE_TRAITS_HPP_
