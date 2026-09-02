#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to ch3_interfaces__msg__Weather
/// 天气消息：字段类型只支持 ROS 内置类型或其他消息类型

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Weather {
    /// 摄氏度
    pub temperature: f64,

    /// 相对湿度 0~1
    pub humidity: f64,

    /// 天气描述，如 sunny / rainy
    pub condition: std::string::String,

}



impl Default for Weather {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Weather::default())
  }
}

impl rosidl_runtime_rs::Message for Weather {
  type RmwMsg = super::msg::rmw::Weather;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        temperature: msg.temperature,
        humidity: msg.humidity,
        condition: msg.condition.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      temperature: msg.temperature,
      humidity: msg.humidity,
        condition: msg.condition.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      temperature: msg.temperature,
      humidity: msg.humidity,
      condition: msg.condition.to_string(),
    }
  }
}


