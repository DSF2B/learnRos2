# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A ROS 2 Humble (Ubuntu 22.04 / WSL2) learning workspace following the chapter structure of the
book 《ROS 2机器人开发：从入门到实践》(FishRos/桑欣, 2024): ch2 = nodes, ch3 = topics,
ch4 = services & params, ch5 = tools/TF, ch6 = URDF/Gazebo, ch7 = Nav2, ch8 = plugins,
ch9 = robot driver, ch10 = advanced. Not a git repository.

## Layout

- `cpp/` — colcon workspace. Source packages live in `cpp/src/`; `cpp/build/`, `cpp/install/`,
  `cpp/log/` are build artifacts (each contains a `COLCON_IGNORE` file) — never edit them.
- `docs/` — one Chinese learning doc per chapter (`docs/chXX_主题.md`, index at `docs/README.md`).
  Each doc pairs with the code package of the same chapter; code comments/log messages are Chinese.
- `py/` — loose Python ROS 2 scripts run directly with `python3`. NOT a colcon package
  (no `package.xml`/`setup.py`).
- `.vscode/` — IntelliSense config pointing at `/opt/ros/humble` (C++17, rclpy dist-packages).

Not installed locally (packages will fail to build/run until the user installs them; install
commands are in the chapter docs): nav2/slam_toolbox (ch7, ch8), gazebo/xacro/ros2_control (ch6).

## Environment

ROS 2 is NOT sourced in new shells (`ROS_DISTRO` is empty). Every build/run command needs it:

```bash
source /opt/ros/humble/setup.bash
```

All colcon commands must be run from `cpp/`.

## Build & run

```bash
source /opt/ros/humble/setup.bash
cd cpp
colcon build                                  # build all packages in src/
colcon build --packages-skip ch7_cpp_navigation ch8_custom_planner   # skip Nav2-dependent ones
colcon build --packages-select ch2_node       # build one package
source install/setup.bash
ros2 run ch2_node ch2_node                    # executable name == package name (set in CMakeLists)
python3 py/ch2_node.py                        # run the Python script directly (from repo root)
```

Tests (ament linters only, no unit tests yet):

```bash
colcon test --packages-select ch2_node
colcon test-result --verbose
```

## Adding a new C++ package

```bash
cd cpp/src
ros2 pkg create --build-type ament_cmake <name> --dependencies rclcpp
cd .. && colcon build --packages-select <name>
```

Packages follow the standard ament_cmake template: executable in `src/*.cpp`, registered via
`add_executable` + `ament_target_dependencies`, installed to `lib/${PROJECT_NAME}`. The template
skips cpplint/copyright lint because this is not a git repo.

## Notes

- `ch2_node` declares a workspace-internal dependency on `ch2_pkg` in its `package.xml` (the
  code doesn't use it yet), so colcon builds `ch2_pkg` first.
- `ch3_cpp_topic` is a scaffold for the topic (publisher/subscriber) chapter: `src/`/`include/`
  are empty and `CMakeLists.txt` has no `add_executable` yet; it depends on `example_interfaces`.
- Log messages in existing code are written in Chinese.
