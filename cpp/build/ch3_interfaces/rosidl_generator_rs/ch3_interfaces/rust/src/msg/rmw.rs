#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "ch3_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ch3_interfaces__msg__Weather() -> *const std::ffi::c_void;
}

#[link(name = "ch3_interfaces__rosidl_generator_c")]
extern "C" {
    fn ch3_interfaces__msg__Weather__init(msg: *mut Weather) -> bool;
    fn ch3_interfaces__msg__Weather__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Weather>, size: usize) -> bool;
    fn ch3_interfaces__msg__Weather__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Weather>);
    fn ch3_interfaces__msg__Weather__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Weather>, out_seq: *mut rosidl_runtime_rs::Sequence<Weather>) -> bool;
}

// Corresponds to ch3_interfaces__msg__Weather
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// 天气消息：字段类型只支持 ROS 内置类型或其他消息类型

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Weather {
    /// 摄氏度
    pub temperature: f64,

    /// 相对湿度 0~1
    pub humidity: f64,

    /// 天气描述，如 sunny / rainy
    pub condition: rosidl_runtime_rs::String,

}



impl Default for Weather {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ch3_interfaces__msg__Weather__init(&mut msg as *mut _) {
        panic!("Call to ch3_interfaces__msg__Weather__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Weather {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch3_interfaces__msg__Weather__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch3_interfaces__msg__Weather__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ch3_interfaces__msg__Weather__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Weather {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Weather where Self: Sized {
  const TYPE_NAME: &'static str = "ch3_interfaces/msg/Weather";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ch3_interfaces__msg__Weather() }
  }
}


