#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to ch4_cpp_service__srv__TurtlePatrol_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TurtlePatrol_Request {
    /// 线速度 (m/s)
    pub linear_x: f64,

    /// 角速度 (rad/s)
    pub angular_z: f64,

    /// 持续时长 (s)
    pub duration: f64,

}



impl Default for TurtlePatrol_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::TurtlePatrol_Request::default())
  }
}

impl rosidl_runtime_rs::Message for TurtlePatrol_Request {
  type RmwMsg = super::srv::rmw::TurtlePatrol_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        linear_x: msg.linear_x,
        angular_z: msg.angular_z,
        duration: msg.duration,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      linear_x: msg.linear_x,
      angular_z: msg.angular_z,
      duration: msg.duration,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      linear_x: msg.linear_x,
      angular_z: msg.angular_z,
      duration: msg.duration,
    }
  }
}


// Corresponds to ch4_cpp_service__srv__TurtlePatrol_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TurtlePatrol_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for TurtlePatrol_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::TurtlePatrol_Response::default())
  }
}

impl rosidl_runtime_rs::Message for TurtlePatrol_Response {
  type RmwMsg = super::srv::rmw::TurtlePatrol_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}






#[link(name = "ch4_cpp_service__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ch4_cpp_service__srv__TurtlePatrol() -> *const std::ffi::c_void;
}

// Corresponds to ch4_cpp_service__srv__TurtlePatrol
#[allow(missing_docs, non_camel_case_types)]
pub struct TurtlePatrol;

impl rosidl_runtime_rs::Service for TurtlePatrol {
    type Request = TurtlePatrol_Request;
    type Response = TurtlePatrol_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ch4_cpp_service__srv__TurtlePatrol() }
    }
}


