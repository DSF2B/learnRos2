#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "ch4_cpp_service__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ch4_cpp_service__srv__TurtlePatrol_Request() -> *const std::ffi::c_void;
}

#[link(name = "ch4_cpp_service__rosidl_generator_c")]
extern "C" {
    fn ch4_cpp_service__srv__TurtlePatrol_Request__init(msg: *mut TurtlePatrol_Request) -> bool;
    fn ch4_cpp_service__srv__TurtlePatrol_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TurtlePatrol_Request>, size: usize) -> bool;
    fn ch4_cpp_service__srv__TurtlePatrol_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TurtlePatrol_Request>);
    fn ch4_cpp_service__srv__TurtlePatrol_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TurtlePatrol_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<TurtlePatrol_Request>) -> bool;
}

// Corresponds to ch4_cpp_service__srv__TurtlePatrol_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
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
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ch4_cpp_service__srv__TurtlePatrol_Request__init(&mut msg as *mut _) {
        panic!("Call to ch4_cpp_service__srv__TurtlePatrol_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TurtlePatrol_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch4_cpp_service__srv__TurtlePatrol_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch4_cpp_service__srv__TurtlePatrol_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch4_cpp_service__srv__TurtlePatrol_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TurtlePatrol_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TurtlePatrol_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ch4_cpp_service/srv/TurtlePatrol_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ch4_cpp_service__srv__TurtlePatrol_Request() }
  }
}


#[link(name = "ch4_cpp_service__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ch4_cpp_service__srv__TurtlePatrol_Response() -> *const std::ffi::c_void;
}

#[link(name = "ch4_cpp_service__rosidl_generator_c")]
extern "C" {
    fn ch4_cpp_service__srv__TurtlePatrol_Response__init(msg: *mut TurtlePatrol_Response) -> bool;
    fn ch4_cpp_service__srv__TurtlePatrol_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TurtlePatrol_Response>, size: usize) -> bool;
    fn ch4_cpp_service__srv__TurtlePatrol_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TurtlePatrol_Response>);
    fn ch4_cpp_service__srv__TurtlePatrol_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TurtlePatrol_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<TurtlePatrol_Response>) -> bool;
}

// Corresponds to ch4_cpp_service__srv__TurtlePatrol_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TurtlePatrol_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for TurtlePatrol_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ch4_cpp_service__srv__TurtlePatrol_Response__init(&mut msg as *mut _) {
        panic!("Call to ch4_cpp_service__srv__TurtlePatrol_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TurtlePatrol_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch4_cpp_service__srv__TurtlePatrol_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch4_cpp_service__srv__TurtlePatrol_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch4_cpp_service__srv__TurtlePatrol_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TurtlePatrol_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TurtlePatrol_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ch4_cpp_service/srv/TurtlePatrol_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ch4_cpp_service__srv__TurtlePatrol_Response() }
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


