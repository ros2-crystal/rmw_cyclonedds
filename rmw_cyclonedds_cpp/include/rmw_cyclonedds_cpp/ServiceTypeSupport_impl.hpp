// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

#ifndef RMW_CYCLONEDDS_CPP__SERVICETYPESUPPORT_IMPL_HPP_
#define RMW_CYCLONEDDS_CPP__SERVICETYPESUPPORT_IMPL_HPP_

#include <cassert>
#include <string>

#include "rmw_cyclonedds_cpp/ServiceTypeSupport.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"

namespace rmw_cyclonedds_cpp
{

template<typename MembersType>
ServiceTypeSupport<MembersType>::ServiceTypeSupport()
{
}

template<typename ServiceMembersType, typename MessageMembersType>
RequestTypeSupport<ServiceMembersType, MessageMembersType>::RequestTypeSupport(
  const ServiceMembersType * members)
{
  assert(members);
  this->members_ = members->request_members_;

  std::string name = std::string(members->package_name_) + "::srv::dds_::" +
    members->service_name_ + "_Request_";
  this->setName(name.c_str());
}

template<typename ServiceMembersType, typename MessageMembersType>
ResponseTypeSupport<ServiceMembersType, MessageMembersType>::ResponseTypeSupport(
  const ServiceMembersType * members)
{
  assert(members);
  this->members_ = members->response_members_;

  std::string name = std::string(members->package_name_) + "::srv::dds_::" +
    members->service_name_ + "_Response_";
  this->setName(name.c_str());
}

}  // namespace rmw_cyclonedds_cpp

#endif  // RMW_CYCLONEDDS_CPP__SERVICETYPESUPPORT_IMPL_HPP_
